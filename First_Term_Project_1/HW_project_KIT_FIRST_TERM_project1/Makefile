#@copyright : Taha    

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -mthumb -gdwarf-2 -g
INCS=-I . -std=c99
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=Pressure_Controller_TM
	
all: $(Project_name).bin
    
	@echo "------Build is Done---------"

   	 
%.o: 	%.c 
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@	
	 

$(Project_name).elf:  $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS)  $(OBJ) $(AsOBJ) -specs=nosys.specs -o $@ -Map=Map_file.map 
	cp $(Project_name).elf $(Project_name).axf
	 
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	 
clean-all: 
	rm *.o *.elf *.bin
	
clean: 
	rm *.elf *.bin 



