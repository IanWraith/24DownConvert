# **************************************************************************** #
#                                                                              #
# Copyright (c) 2017 Andrea Loi                                                #
#                                                                              #
# Permission is hereby granted, free of charge, to any person obtaining a      #
# copy of this software and associated documentation files (the "Software"),   #
# to deal in the Software without restriction, including without limitation    #
# the rights to use, copy, modify, merge, publish, distribute, sublicense,     #
# and/or sell copies of the Software, and to permit persons to whom the        #
# Software is furnished to do so, subject to the following conditions:         #
#                                                                              #
# The above copyright notice and this permission notice shall be included      #
# in all copies or substantial portions of the Software.                       #
#                                                                              #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL      #
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER   #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      #
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER          #
# DEALINGS IN THE SOFTWARE.                                                    #
#                                                                              #
# **************************************************************************** #



# **************************************************************************** #
#                     < Project configuration variables >                      #
# **************************************************************************** #
# You probably need to change these.                                           #
# **************************************************************************** #



# **************************************************************************** #
# TARGET: This sets the name of the program.                                   #
#         It's used as a prefix for the output files.                          #
# **************************************************************************** #
TARGET = downconvert



# **************************************************************************** #
# OTHER_SRCS: List here all the .c files that needs to be compiled.            #
#             You can separete them using a space.                             #
# **************************************************************************** #
OTHER_SRCS = main.c



# **************************************************************************** #
# OPTFLAGS: Select GCC optimization level.                                     #
#           This is only used for the release build ("make").                  #
#           The debug build ("make debug") optimization flags are set          #
#           in DBG_OPTFLAGS down below.                                        #
#           Also be aware that some levels (usually -O3) may require you to    #
#           add additional support functions like memcpy and memset.           #
# **************************************************************************** #
OPTFLAGS = -O0



# **************************************************************************** #
#                     < Advanced configuration variables >                     #
# **************************************************************************** #
# You probably don't need to change these.                                     #
# **************************************************************************** #
INIT_SRC = init.c
LINKER_SCRIPT = STM32F103C8.ld
STUTIL_PORT = 4242
DBG_OPTFLAGS = -O0
REMOVE_OBJS = Y
VERBOSE = N
CROSS_COMPILE = arm-none-eabi-
STFLASH = st-flash
STUTIL = st-util
OPENOCD = openocd



# **************************************************************************** #
#                              < Makefile guts >                               #
# **************************************************************************** #
#           DON'T CHANGE ANYTHING UNLESS YOU KNOW WHAT YOU'RE DOING            #
# **************************************************************************** #

SRCS += $(INIT_SRC)
SRCS += $(OTHER_SRCS)

OBJS = $(addsuffix .o,  $(basename $(SRCS)))
SUS  = $(addsuffix .su, $(basename $(OBJS)))

CFLAGS += -mcpu=cortex-m3 -mthumb -mabi=aapcs
CFLAGS += -Wall -Wextra
CFLAGS += -fno-common -static
CFLAGS += -ffunction-sections -fdata-sections -Wl,--gc-sections

LDFLAGS += -march=armv7-m -mabi=aapcs
LDFLAGS += -nostartfiles -nostdlib -lgcc
LDFLAGS += -T$(LINKER_SCRIPT)

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJDUMP = $(CROSS_COMPILE)objdump
OBJCOPY = $(CROSS_COMPILE)objcopy
SIZE = $(CROSS_COMPILE)size
GDB = $(CROSS_COMPILE)gdb

ECHO = echo
RM = rm

ifeq ($(VERBOSE),Y)
SILENCE =
else
SILENCE = @
endif

GDB_PARAM = -quiet --eval-command="target extended-remote localhost:$(STUTIL_PORT)"

.PHONY: all debug build debug_build output info size flash erase server gdb clean_objs clean

all: clean $(SRCS) build clean_objs output size

debug: clean $(SRCS) debug_build info output size

build: COMFLAGS = $(OPTFLAGS)
build: $(TARGET).elf

debug_build: COMFLAGS = $(DBG_OPTFLAGS) -ggdb3
debug_build: CFLAGS += -fstack-usage
debug_build: LDFLAGS += -Xlinker -Map=$(TARGET).map
debug_build: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(SILENCE)$(CC) $(LDFLAGS) $(COMFLAGS) $(OBJS) -o "$@"

.SECONDARY: $(OBJS)

%.o: %.c
	$(SILENCE)$(CC) $(CFLAGS) $(COMFLAGS) -c "$<" -o "$@"

output: $(TARGET).hex $(TARGET).bin

$(TARGET).hex: $(TARGET).elf
	$(SILENCE)$(OBJCOPY) -O ihex $< $@

$(TARGET).bin: $(TARGET).elf
	$(SILENCE)$(OBJCOPY) -O binary $< $@

info: $(TARGET).elf
	$(SILENCE)$(OBJDUMP) -x -S $(TARGET).elf > $(TARGET).lst
	$(SILENCE)$(OBJDUMP) -D $(TARGET).elf > $(TARGET).dis
	$(SILENCE)$(SIZE) $(TARGET).elf > $(TARGET).size

size: $(TARGET).elf
	$(SILENCE)$(SIZE) $(TARGET).elf

flash: $(TARGET).bin
	$(OPENOCD) -f /home/ianw/STM/opendps/openocd/scripts/interface/stlink-v2.cfg -f /home/ianw/STM/opendps/openocd/scripts/target/stm32f1x.cfg -c "program $(TARGET).bin verify reset exit 0x8000000"

erase:
	$(OPENOCD) -f /home/ianw/STM/opendps/openocd/scripts/interface/stlink-v2.cfg -f /home/ianw/STM/opendps/openocd/scripts/target/stm32f1x.cfg -c "flash erase_address unlock 0x08000000 0x10000"

server: $(TARGET).elf
	$(SILENCE)$(ECHO) "On another terminal run \"make gdb\""
	$(SILENCE)$(STUTIL) -p $(STUTIL_PORT)

gdb: $(TARGET).elf
	$(SILENCE)$(ECHO) "Run \"load\" to start debugging."
	$(SILENCE)$(GDB) $(GDB_PARAM) $(TARGET).elf

clean_objs:
ifeq ($(REMOVE_OBJS),Y)
	$(SILENCE)$(RM) -f $(OBJS)
endif

clean:
	$(SILENCE)$(RM) -f $(TARGET).elf
	$(SILENCE)$(RM) -f $(TARGET).bin
	$(SILENCE)$(RM) -f $(TARGET).hex
	$(SILENCE)$(RM) -f $(TARGET).size
	$(SILENCE)$(RM) -f $(TARGET).lst
	$(SILENCE)$(RM) -f $(TARGET).dis
	$(SILENCE)$(RM) -f $(TARGET).map
	$(SILENCE)$(RM) -f $(OBJS)
	$(SILENCE)$(RM) -f $(SUS)


