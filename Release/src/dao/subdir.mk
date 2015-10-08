################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dao/DBConn.cpp 

OBJS += \
./src/dao/DBConn.o 

CPP_DEPS += \
./src/dao/DBConn.d 


# Each subdirectory must supply rules for building sources it contributes
src/dao/%.o: ../src/dao/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


