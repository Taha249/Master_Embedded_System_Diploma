#@copyright : Taha    

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -mthumb -gdwarf-2 -g
INCS=-I . -std=c99
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
Project_name=learn_in_depth_unit3_lesson5
	
all: $(Project_name).bin
    
	@echo "------Build is Done---------"

   	 
%.o: 	%.c 
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@	
	 

$(Project_name).elf:  $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld $(LIBS)  $(OBJ) startup.o -o $@ -Map=Map_file.map 
	 
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	 
clean-all: 
	rm *.o *.elf *.bin
	
clean: 
	rm *.elf *.bin 



