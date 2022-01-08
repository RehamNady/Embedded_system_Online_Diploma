#@copyright :Reham Nady
CC =arm-none-eabi-
CFLAGS=-mthumb -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
AS= $(wildcard *.s)
OBJ= $(SRC:.c=.o)
AsOBJ= $(AS:.s=.o)
poject_name = learn_in_depth_cortex_m3

all: $(poject_name).bin
	@echo "==============Bild is Done=============="
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
$(poject_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=out.map $(LIBS) $(OBJ) $(AsOBJ) -o $@
$(poject_name).bin: $(poject_name).elf
	$(CC)objcopy.exe -O binary $< $@
clean_all:
	rm *.o *.elf *.bin *.map
clean:
	rm *.bin *.elf
