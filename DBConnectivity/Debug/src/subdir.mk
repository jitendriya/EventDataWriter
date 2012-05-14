################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Dbconnect.cpp \
../src/Dbmain.cpp 

OBJS += \
./src/Dbconnect.o \
./src/Dbmain.o 

CPP_DEPS += \
./src/Dbconnect.d \
./src/Dbmain.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++   -g -I"/home/jitendriya/EventDataWriter/Cppunit/inc" -I"/home/jitendriya/EventDataWriter/DBConnectivity/inc" -I"/home/jitendriya/EventDataWriter/Cppunit/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


