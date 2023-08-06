CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)

project_name=learn-in-depth-cortex-m3

all: $(project_name).bin
	@echo "Done"

UART.o: UART.c
	$(CC)gcc.exe -c $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $< -o $@

startup.o: startup.s
	$(CC)as.exe -c $(CFLAGS) $< -o $@


$(project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map



$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@	



clean: 
	rm *.bin *.elf *.o

	