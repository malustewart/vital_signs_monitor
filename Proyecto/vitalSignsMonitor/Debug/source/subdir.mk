################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/App.c \
../source/i2c_sdk.c \
../source/semihost_hardfault.c \
../source/temperature_sensor.c \
../source/vitalSignsMonitor.c 

OBJS += \
./source/App.o \
./source/i2c_sdk.o \
./source/semihost_hardfault.o \
./source/temperature_sensor.o \
./source/vitalSignsMonitor.o 

C_DEPS += \
./source/App.d \
./source/i2c_sdk.d \
./source/semihost_hardfault.d \
./source/temperature_sensor.d \
./source/vitalSignsMonitor.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\board" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\startup" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\source" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\drivers" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\device" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\CMSIS" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\component\uart" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\utilities" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\component\serial_manager" -I"D:\Archivos\workspaceMcu\vitalSignsMonitor\component\lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


