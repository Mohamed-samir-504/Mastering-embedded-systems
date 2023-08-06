CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)

project_name=lab-4-cortex-M4

all: $(project_name).bin
	@echo "Done"

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $< -o $@

%.o: %.s
	$(CC)as.exe -c $(CFLAGS) $< -o $@


$(project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf


$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@	



clean: 
	rm *.bin *.elf *.o

	