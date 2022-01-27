CC =arm-none-eabi-
CFlags =-mthumb -mcpu=cortex-m3 -gdwarf-2 -g
INC =-I.
LIBS=
Project_name=pressure_detect
SRC =$(wildcard *.c)
AS =$(wildcard *.s)
OBJ=$(SRC:.c=.o)
ASOBJ=$(AS:.s=.o)

all: $(Project_name).bin
	@echo "==============Bild is Done=============="
%.o: %.c
	$(CC)gcc.exe -c $(CFlags) $(INC) $< -o $@
%.o: %.s
	$(CC)as.exe $(CFlags) $< -o $@
$(Project_name).elf: $(OBJ) $(ASOBJ) $(LIBS)
	$(CC)ld.exe -T linker_script.ld -Map=$(Project_name).map $(OBJ) $(ASOBJ) $(LIBS) -o $@
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary  $< $@
clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin
