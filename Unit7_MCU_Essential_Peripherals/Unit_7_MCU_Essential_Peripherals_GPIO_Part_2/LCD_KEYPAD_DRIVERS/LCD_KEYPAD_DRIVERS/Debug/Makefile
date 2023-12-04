################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../LCD_Driver \
../KEYPAD_Driver


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../KEYPAD_Driver/keypad.c \
../LCD_Driver/lcd.c \
../main.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
KEYPAD_Driver/keypad.o \
LCD_Driver/lcd.o \
main.o

OBJS_AS_ARGS +=  \
KEYPAD_Driver/keypad.o \
LCD_Driver/lcd.o \
main.o

C_DEPS +=  \
KEYPAD_Driver/keypad.d \
LCD_Driver/lcd.d \
main.d

C_DEPS_AS_ARGS +=  \
KEYPAD_Driver/keypad.d \
LCD_Driver/lcd.d \
main.d

OUTPUT_FILE_PATH +=LCD_KEYPAD_DRIVERS.elf

OUTPUT_FILE_PATH_AS_ARGS +=LCD_KEYPAD_DRIVERS.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
KEYPAD_Driver/keypad.o: ../KEYPAD_Driver/keypad.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\7.0\Packs\atmel\ATmega_DFP\1.7.374\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

LCD_Driver/lcd.o: ../LCD_Driver/lcd.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\7.0\Packs\atmel\ATmega_DFP\1.7.374\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\7.0\Packs\atmel\ATmega_DFP\1.7.374\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "D:\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="LCD_KEYPAD_DRIVERS.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "D:\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"D:\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "LCD_KEYPAD_DRIVERS.elf" "LCD_KEYPAD_DRIVERS.hex"
	"D:\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "LCD_KEYPAD_DRIVERS.elf" "LCD_KEYPAD_DRIVERS.eep" || exit 0
	"D:\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "LCD_KEYPAD_DRIVERS.elf" > "LCD_KEYPAD_DRIVERS.lss"
	"D:\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "LCD_KEYPAD_DRIVERS.elf" "LCD_KEYPAD_DRIVERS.srec"
	"D:\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "LCD_KEYPAD_DRIVERS.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "LCD_KEYPAD_DRIVERS.elf" "LCD_KEYPAD_DRIVERS.a" "LCD_KEYPAD_DRIVERS.hex" "LCD_KEYPAD_DRIVERS.lss" "LCD_KEYPAD_DRIVERS.eep" "LCD_KEYPAD_DRIVERS.map" "LCD_KEYPAD_DRIVERS.srec" "LCD_KEYPAD_DRIVERS.usersignatures"
	