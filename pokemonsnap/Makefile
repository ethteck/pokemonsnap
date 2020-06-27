
BUILD_DIR = build
ASM_DIRS := asm
DATA_DIRS := bin

S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
DATA_FILES := $(foreach dir,$(DATA_DIRS),$(wildcard $(dir)/*.bin))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(DATA_FILES),$(BUILD_DIR)/$(file:.bin=.o)) \
           $(foreach file,$(COMPRESSED_FILES),$(BUILD_DIR)/$(file:.yay0=.yay0.o)) \
           $(foreach file,$(MAP_FILES),$(BUILD_DIR)/$(file:.FS=.FS.o)) \
           $(foreach file,$(BGM_FILES),$(BUILD_DIR)/$(file:.bgm=.bgm.o))

##################### Compiler Options #######################
CROSS = mips-linux-gnu-
AS = $(CROSS)as
CC = $(CROSS)gcc
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy

ASFLAGS = -EB -mtune=vr4300 -march=vr4300
CFLAGS  = -Wall -O2 -mtune=vr4300 -march=vr4300 -G 0 -c
LDFLAGS = -T undefined_syms.txt -T $(LD_SCRIPT) -Map $(BUILD_DIR)/pokemonsnap.map --no-check-sections

####################### Other Tools #########################

# N64 tools
TOOLS_DIR = ../tools

######################## Targets #############################

$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(DATA_DIRS) $(COMPRESSED_DIRS) $(MAP_DIRS) $(BGM_DIRS),$(shell mkdir -p build/$(dir)))

default: all

TARGET = pokemonsnap
LD_SCRIPT = $(TARGET).ld

all: $(BUILD_DIR) $(TARGET).z64 verify

clean:
	rm -rf build
	rm -f pokemonsnap.z64

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET).elf: $(O_FILES) $(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@ $(O_FILES)

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

# final z64 updates checksum
$(TARGET).z64: $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@

verify: $(TARGET).z64
	md5sum -c checksum.md5

.PHONY: all clean default
