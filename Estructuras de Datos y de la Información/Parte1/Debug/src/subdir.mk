################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Barrio.cpp \
../src/ConjuntoBarrios.cpp \
../src/ConjuntoVias.cpp \
../src/Via.cpp \
../src/algoritmos.cpp 

OBJS += \
./src/Barrio.o \
./src/ConjuntoBarrios.o \
./src/ConjuntoVias.o \
./src/Via.o \
./src/algoritmos.o 

CPP_DEPS += \
./src/Barrio.d \
./src/ConjuntoBarrios.d \
./src/ConjuntoVias.d \
./src/Via.d \
./src/algoritmos.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


