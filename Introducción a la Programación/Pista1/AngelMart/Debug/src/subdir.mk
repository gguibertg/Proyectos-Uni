################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Celda.cpp \
../src/Juego.cpp \
../src/PruebasTablero.cpp \
../src/Tablero.cpp \
../src/angelMartBase.cpp \
../src/entorno.cpp \
../src/pruebasCelda.cpp 

OBJS += \
./src/Celda.o \
./src/Juego.o \
./src/PruebasTablero.o \
./src/Tablero.o \
./src/angelMartBase.o \
./src/entorno.o \
./src/pruebasCelda.o 

CPP_DEPS += \
./src/Celda.d \
./src/Juego.d \
./src/PruebasTablero.d \
./src/Tablero.d \
./src/angelMartBase.d \
./src/entorno.d \
./src/pruebasCelda.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


