################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MED_Tester

dependents:
	-cd /home/waida/workspace/finalProject/stringdatabase/Debug && $(MAKE) all
	-cd /home/waida/workspace/finalProject/crypto/Debug && $(MAKE) all
	-cd /home/waida/workspace/finalProject/datastore/Debug && $(MAKE) all

# Tool invocations
MED_Tester: $(OBJS) $(USER_OBJS) /home/waida/workspace/finalProject/stringdatabase/Debug/libstringdatabase.a /home/waida/workspace/finalProject/crypto/Debug/libcrypto.a /home/waida/workspace/finalProject/datastore/Debug/libdatastore.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/home/waida/workspace/finalProject/stringdatabase/Debug" -L"/home/waida/workspace/finalProject/crypto/Debug" -L"/home/waida/workspace/finalProject/datastore/Debug" -o "MED_Tester" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) MED_Tester
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/home/waida/workspace/finalProject/stringdatabase/Debug/libstringdatabase.a:
/home/waida/workspace/finalProject/crypto/Debug/libcrypto.a:
/home/waida/workspace/finalProject/datastore/Debug/libdatastore.a:

-include ../makefile.targets
