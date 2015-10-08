################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/service/AdminService.cpp \
../src/service/FacilityService.cpp \
../src/service/FileService.cpp \
../src/service/HistoryService.cpp \
../src/service/UserService.cpp 

OBJS += \
./src/service/AdminService.o \
./src/service/FacilityService.o \
./src/service/FileService.o \
./src/service/HistoryService.o \
./src/service/UserService.o 

CPP_DEPS += \
./src/service/AdminService.d \
./src/service/FacilityService.d \
./src/service/FileService.d \
./src/service/HistoryService.d \
./src/service/UserService.d 


# Each subdirectory must supply rules for building sources it contributes
src/service/%.o: ../src/service/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


