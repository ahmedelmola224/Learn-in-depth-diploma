#@copyrigths ahmed essam
project_name=output
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)#add the path
ASOBJ=$(AS:.s=.o)

all:$(project_name).bin
	@echo "=====Building done====="

%.o:%.c
	$(CC)gcc.exe    $(CFLAGS)    $(INCS)  -mthumb -c $<  -o  $@ 
	
%.o:%.s
	$(CC)as.exe     $(CFLAGS)     $<   -o     $@

$(project_name).elf: $(ASOBJ) $(OBJ)
	$(CC)ld.exe -T linkerscript.ld   $(LIBS)  $(ASOBJ)   $(OBJ)  -o   $@   -Map=mapfile.map

$(project_name).bin:$(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm -rf $(wildcard *.bin *.elf *.o) 
	@echo "All is cleaned"
clean:
	rm -rf $(wildcard *.bin *.elf) 
	@echo "elf and bin are cleaned"
