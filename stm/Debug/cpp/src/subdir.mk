################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp/src/main.cpp \
../cpp/src/modbus.cpp \
../cpp/src/modbus_handler.cpp \
../cpp/src/mySerial.cpp \
../cpp/src/request_type.cpp 

OBJS += \
./cpp/src/main.o \
./cpp/src/modbus.o \
./cpp/src/modbus_handler.o \
./cpp/src/mySerial.o \
./cpp/src/request_type.o 

CPP_DEPS += \
./cpp/src/main.d \
./cpp/src/modbus.d \
./cpp/src/modbus_handler.d \
./cpp/src/mySerial.d \
./cpp/src/request_type.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/src/main.o: ../cpp/src/main.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"C:/Users/Admin/Documents/GitHub/download/stm/cpp/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"cpp/src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
cpp/src/modbus.o: ../cpp/src/modbus.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"C:/Users/Admin/Documents/GitHub/download/stm/cpp/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"cpp/src/modbus.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
cpp/src/modbus_handler.o: ../cpp/src/modbus_handler.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"C:/Users/Admin/Documents/GitHub/download/stm/cpp/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"cpp/src/modbus_handler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
cpp/src/mySerial.o: ../cpp/src/mySerial.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"C:/Users/Admin/Documents/GitHub/download/stm/cpp/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"cpp/src/mySerial.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
cpp/src/request_type.o: ../cpp/src/request_type.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"C:/Users/Admin/Documents/GitHub/download/stm/cpp/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"cpp/src/request_type.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

