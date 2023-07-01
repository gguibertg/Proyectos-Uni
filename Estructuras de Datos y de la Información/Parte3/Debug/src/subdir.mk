################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Arbol.cpp \
../src/Barrio.cpp \
../src/ConjuntoBarrios.cpp \
../src/PruebasArbol.cpp \
../src/PruebasBarrio.cpp \
../src/PruebasConjuntoBarrios.cpp \
../src/PruebasVia.cpp \
../src/Via.cpp \
../src/algoritmos.cpp 

OBJS += \
./src/Arbol.o \
./src/Barrio.o \
./src/ConjuntoBarrios.o \
./src/PruebasArbol.o \
./src/PruebasBarrio.o \
./src/PruebasConjuntoBarrios.o \
./src/PruebasVia.o \
./src/Via.o \
./src/algoritmos.o 

CPP_DEPS += \
./src/Arbol.d \
./src/Barrio.d \
./src/ConjuntoBarrios.d \
./src/PruebasArbol.d \
./src/PruebasBarrio.d \
./src/PruebasConjuntoBarrios.d \
./src/PruebasVia.d \
./src/Via.d \
./src/algoritmos.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


