CC=arm-none-eabi-
CFALGS=-g -mcpu=arm926ej-s

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)

project_name=Test

all: $(project_name).bin
	@echo "Done"

UART.o: UART.c
	$(CC)gcc.exe -c $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $< -o $@

startup.o: startup.s
	$(CC)as.exe -c $(CFLAGS) $< -o $@


$(project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@



$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@	



clean: 
	rm *.bin *.elf *.o

	