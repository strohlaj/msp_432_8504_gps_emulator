################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
MSP432P4xx/%.o: ../MSP432P4xx/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccs1031/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-gcc-9.2.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__MSP432P401R__ -Dgcc -I"C:/ti/ccs1031/ccs/ccs_base/arm/include" -I"C:/ti/ccs1031/ccs/ccs_base/arm/include/CMSIS" -I"C:/Users/AaronStrohl/workspace_v10/Test" -I"C:/ti/ccs1031/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/arm-none-eabi/include" -Og -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"MSP432P4xx/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


