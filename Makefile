### Build Options ###

BASEROM         := pokemonsnap.z64
TARGET          := pokemonsnap
COMPARE         ?= 1
NON_MATCHING    ?= 0
CHECK           ?= 1
VERBOSE         ?= 1
PRETTY_PRINTING ?= 0

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

# NON_MATCHING=1 implies COMPARE=0
ifeq ($(NON_MATCHING),1)
override COMPARE=0
endif

ifeq ($(VERBOSE),0)
V := @
endif

ifeq ($(PRETTY_PRINTING),0)
P := true ||
endif

### Output ###

BUILD_DIR := build
ROM       := $(BUILD_DIR)/$(TARGET).z64
ELF       := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := $(TARGET).ld
LD_MAP    := $(BUILD_DIR)/$(TARGET).map

### Tools ###

ifeq ($(OS),Windows_NT)
    OS = windows
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        OS = linux
    endif
    ifeq ($(UNAME_S),Darwin)
        OS = macos
        MAKE=gmake
        CPPFLAGS += -xc++
    endif
endif

PYTHON     := python3
N64CKSUM   := $(PYTHON) tools/n64cksum.py
SPLAT_YAML := splat.yaml
SPLAT      := $(PYTHON) tools/splat/split.py $(SPLAT_YAML)
DIFF       := diff

CROSS    := mips-linux-gnu-
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJDUMP  := $(CROSS)objdump
OBJCOPY  := $(CROSS)objcopy
STRIP    := $(CROSS)strip

CC       := tools/ido_recomp/$(OS)/7.1/cc
CC_OLD   := tools/ido_recomp/$(OS)/5.3/cc
CC_HOST  := gcc
CPP      := cpp -P

PRINT := printf '
 ENDCOLOR := \033[0m
 WHITE     := \033[0m
 ENDWHITE  := $(ENDCOLOR)
 GREEN     := \033[0;32m
 ENDGREEN  := $(ENDCOLOR)
 BLUE      := \033[0;34m
 ENDBLUE   := $(ENDCOLOR)
 YELLOW    := \033[0;33m
 ENDYELLOW := $(ENDCOLOR)
ENDLINE := \n'

### Compiler Options ###

IINC           := -I include -I $(BUILD_DIR)/include -I src

ASFLAGS        := -G 0 -I include -EB -mtune=vr4300 -march=vr4300
CFLAGS         := -G 0 -non_shared -fullwarn -verbose -Xcpluscomm -nostdinc -Wab,-r4300_mul
CPPFLAGS       := $(IINC) -DF3DEX_GBI_2 -D_LANGUAGE_C
LDFLAGS        := -T undefined_syms.txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -T undefined_funcs.txt -T $(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections

# Add -woff + numbers here to disable IDO warnings
IDO_WARNINGS   :=
CHECK_WARNINGS := -Wall -Wextra -Wno-format-security -Wno-unused-parameter -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -Wno-unknown-pragmas -Wunused-variable
CFLAGS_CHECK   := -fno-builtin -fsyntax-only -funsigned-char -nostdinc -std=gnu89 -D CC_CHECK $(CHECK_WARNINGS) -m32

OPTFLAGS := -O2

ifneq ($(CHECK),1)
CFLAGS_CHECK += -w
endif

### Sources ###

# Empty file used to track the time that splat was most recently run
SPLAT_TIMESTAMP := asm/splat_timestamp

# Object files
OBJECTS := $(shell $(PYTHON) tools/splat_objects.py $(SPLAT_YAML))
DEPENDS := $(OBJECTS:=.d)

### Targets ###

all: $(ROM)

-include $(DEPENDS)

clean:
	$(V)rm -rf build
	$(info $(MAKEFLAGS))

distclean: clean
	$(V)rm -rf asm
	$(V)rm -rf assets
	$(V)rm -f *auto.txt
	$(V)rm -f pokemonsnap.ld
	$(V)rm -f include/ld_addrs.h

setup: distclean split

split:
	$(V)$(SPLAT)
	@touch $(SPLAT_TIMESTAMP)

# Run splat and update the timestamp
$(SPLAT_TIMESTAMP) : $(SPLAT_YAML) | $(BUILD_DIR)
	@$(P)$(PRINT)$(GREEN)Running splat$(ENDGREEN)$(ENDLINE)
	$(V)$(SPLAT)
	@touch $@

# Disassemble asm files with splat (just update the timestamp so it's newer than the time splat was run)
asm/%.s: $(SPLAT_TIMESTAMP)
	@touch $@

# Extract bin files with splat (same as above)
assets/%.bin: $(SPLAT_TIMESTAMP)
	@touch $@

# Create the build directory
$(BUILD_DIR):
	@$(P)$(PRINT)$(GREEN)Making build folder$(ENDGREEN)$(ENDLINE)
	@mkdir -p $@

# Compile .c files with ido
$(BUILD_DIR)/src/%.c.o: src/%.c $(SPLAT_TIMESTAMP) | $(BUILD_DIR)
	@$(P)$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d $<
	$(V)$(CC) $(CFLAGS) $(OPTFLAGS) $(CPPFLAGS) -c -o $@ $<

# Assemble .s files with modern gnu as
$(BUILD_DIR)/asm/%.s.o: asm/%.s | $(BUILD_DIR)
	@$(P)$(PRINT)$(GREEN)Assembling asm file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(AS) $(ASFLAGS) -o $@ $<

# Create .o files from .bin files.
$(BUILD_DIR)/%.bin.o: %.bin | $(BUILD_DIR)
	@$(P)$(PRINT)$(GREEN)Objcopying binary file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(LD) -r -b binary -o $@ $<

# Link the .o files into the .elf
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	@$(P)$(PRINT)$(GREEN)Linking elf file: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(LD) $(LDFLAGS) -o $@

# Convert the .elf to the final rom
$(ROM): $(BUILD_DIR)/$(TARGET).elf
	@$(P)$(PRINT)$(GREEN)Creating z64: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(OBJCOPY) $< $@ -O binary
	$(V)$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0x1000000 $< $@
ifeq ($(COMPARE),1)
	@$(DIFF) $(BASEROM) $(ROM) && $(PRINT)OK$(ENDLINE) || ($(PRINT)FAILED (ROM BUILT, BUT DIFFERS FROM BASEROM)$(ENDLINE) && false)
endif

### File-Specific Rules ###
build/src/os/O1/%.o: OPTFLAGS := -O1
build/src/%.o: CC := python3 tools/asm_processor/build.py $(CC) -- $(AS) $(ASFLAGS) --

### Make Settings ###

# Prevent removing intermediate files
.SECONDARY:

# Specify which targets don't have a corresponding file
.PHONY: all clean distclean test setup split

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
