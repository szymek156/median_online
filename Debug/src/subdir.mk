################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Executor.cpp \
../src/MedianDummy.cpp \
../src/MedianPrioQueue.cpp \
../src/Parser.cpp \
../src/ParserGenerator.cpp \
../src/median_online.cpp 

OBJS += \
./src/Executor.o \
./src/MedianDummy.o \
./src/MedianPrioQueue.o \
./src/Parser.o \
./src/ParserGenerator.o \
./src/median_online.o 

CPP_DEPS += \
./src/Executor.d \
./src/MedianDummy.d \
./src/MedianPrioQueue.d \
./src/Parser.d \
./src/ParserGenerator.d \
./src/median_online.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


