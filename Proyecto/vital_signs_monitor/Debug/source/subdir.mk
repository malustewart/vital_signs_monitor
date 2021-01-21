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
../source/vital_signs_monitor.c 

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
./source/vital_signs_monitor.o 

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
./source/vital_signs_monitor.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Archivos\workspaceMcu\vital_signs_monitor\board" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\startup" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\source" -I"D:\Archivos\workspaceMcu\vital_signs_monitor" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\drivers" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\device" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\CMSIS" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\uart" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\utilities" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\serial_manager" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\lists" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\sdmmc\inc" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\sdmmc\host" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\sdmmc\osa" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\osa" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\usb\host\class" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\usb\host" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\source\generated" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\usb\include" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_ram_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_mmc_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_sd_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_sdspi_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_usb_disk" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


