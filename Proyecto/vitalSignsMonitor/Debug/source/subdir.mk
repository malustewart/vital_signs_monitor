################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/App.c \
../source/MAX30102.c \
../source/PIT.c \
../source/adc.c \
../source/algorithm_by_RF.c \
../source/demCircBuffer.c \
../source/ecg_afe.c \
../source/gpio.c \
../source/i2c_sdk.c \
../source/pulse_oximeter.c \
../source/semihost_hardfault.c \
../source/send_package.c \
../source/temperature_sensor.c \
../source/uart_micros.c \
../source/vitalSignsMonitor.c 

OBJS += \
./source/App.o \
./source/MAX30102.o \
./source/PIT.o \
./source/adc.o \
./source/algorithm_by_RF.o \
./source/demCircBuffer.o \
./source/ecg_afe.o \
./source/gpio.o \
./source/i2c_sdk.o \
./source/pulse_oximeter.o \
./source/semihost_hardfault.o \
./source/send_package.o \
./source/temperature_sensor.o \
./source/uart_micros.o \
./source/vitalSignsMonitor.o 

C_DEPS += \
./source/App.d \
./source/MAX30102.d \
./source/PIT.d \
./source/adc.d \
./source/algorithm_by_RF.d \
./source/demCircBuffer.d \
./source/ecg_afe.d \
./source/gpio.d \
./source/i2c_sdk.d \
./source/pulse_oximeter.d \
./source/semihost_hardfault.d \
./source/send_package.d \
./source/temperature_sensor.d \
./source/uart_micros.d \
./source/vitalSignsMonitor.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\board" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\startup" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\source" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\drivers" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\device" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\CMSIS" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\component\uart" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\utilities" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\component\serial_manager" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\component\lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


