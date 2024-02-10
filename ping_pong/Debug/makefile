################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ping_pong_Game.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ping_pong_Game.elf secondary-outputs

# Tool invocations
ping_pong_Game.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ping_pong_Game.map -mmcu=atmega32 -o "ping_pong_Game.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ping_pong_Game.lss: ping_pong_Game.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ping_pong_Game.elf  >"ping_pong_Game.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ping_pong_Game.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ping_pong_Game.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ping_pong_Game.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
