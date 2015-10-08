################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bean/Admin.cpp \
../src/bean/Facility.cpp \
../src/bean/File.cpp \
../src/bean/History.cpp \
../src/bean/Meetroom.cpp \
../src/bean/User.cpp 

OBJS += \
./src/bean/Admin.o \
./src/bean/Facility.o \
./src/bean/File.o \
./src/bean/History.o \
./src/bean/Meetroom.o \
./src/bean/User.o 

CPP_DEPS += \
./src/bean/Admin.d \
./src/bean/Facility.d \
./src/bean/File.d \
./src/bean/History.d \
./src/bean/Meetroom.d \
./src/bean/User.d 


# Each subdirectory must supply rules for building sources it contributes
src/bean/%.o: ../src/bean/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


