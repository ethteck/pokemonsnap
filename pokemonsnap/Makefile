
BUILD_DIR = build

##################### Compiler Options #######################
CROSS = mips-linux-gnu-
AS = $(CROSS)as
CC = $(CROSS)gcc
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy

ASFLAGS = -EB -mtune=vr4300 -march=vr4300
CFLAGS  = -Wall -O2 -mtune=vr4300 -march=vr4300 -G 0 -c
LDFLAGS = -T undefined_syms.txt -T $(LD_SCRIPT) -Map $(BUILD_DIR)/pokemonsnap.map

####################### Other Tools #########################

# N64 tools
TOOLS_DIR = ../tools
MIO0TOOL = $(TOOLS_DIR)/mio0
N64CKSUM = $(TOOLS_DIR)/n64cksum

######################## Targets #############################

default: all

TARGET = pokemonsnap
LD_SCRIPT = $(TARGET).ld

all: $(BUILD_DIR) $(TARGET).z64 verify

clean:
	rm -rf build

$(MIO0_DIR)/%.mio0: $(MIO0_DIR)/%.bin
	$(MIO0TOOL) $< $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET).o: $(TARGET).s Makefile $(MAKEFILE_SPLIT) $(MIO0_FILES) $(LEVEL_FILES) $(MUSIC_FILES) | $(BUILD_DIR)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.c Makefile.as | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/$(TARGET).elf: $(BUILD_DIR)/$(TARGET).o $(LD_SCRIPT)
	$(LD) $(LDFLAGS) -o $@ $< $(LIBS)

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary

# final z64 updates checksum
$(TARGET).z64: $(BUILD_DIR)/$(TARGET).bin
	@cp $< $@
	#$(N64CKSUM) $@ todo add this sometime

verify: $(TARGET).z64
	md5sum -c checksum.md5

.PHONY: all clean default
