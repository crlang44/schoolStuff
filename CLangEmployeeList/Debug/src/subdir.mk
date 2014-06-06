################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Company.cpp \
../src/Employee.cpp \
../src/Main.cpp \
../src/Manager.cpp \
../src/SalesPerson.cpp \
../src/WageEarner.cpp 

OBJS += \
./src/Company.o \
./src/Employee.o \
./src/Main.o \
./src/Manager.o \
./src/SalesPerson.o \
./src/WageEarner.o 

CPP_DEPS += \
./src/Company.d \
./src/Employee.d \
./src/Main.d \
./src/Manager.d \
./src/SalesPerson.d \
./src/WageEarner.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


