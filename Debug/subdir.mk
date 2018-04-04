################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Dijkstra.cpp \
../Graph.cpp \
../PriorityQueue.cpp \
../ShortestPath.cpp 

OBJS += \
./Dijkstra.o \
./Graph.o \
./PriorityQueue.o \
./ShortestPath.o 

CPP_DEPS += \
./Dijkstra.d \
./Graph.d \
./PriorityQueue.d \
./ShortestPath.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


