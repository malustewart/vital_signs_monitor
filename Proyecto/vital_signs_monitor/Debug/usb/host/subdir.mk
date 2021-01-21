################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../usb/host/usb_host_devices.c \
../usb/host/usb_host_framework.c \
../usb/host/usb_host_hci.c \
../usb/host/usb_host_khci.c 

OBJS += \
./usb/host/usb_host_devices.o \
./usb/host/usb_host_framework.o \
./usb/host/usb_host_hci.o \
./usb/host/usb_host_khci.o 

C_DEPS += \
./usb/host/usb_host_devices.d \
./usb/host/usb_host_framework.d \
./usb/host/usb_host_hci.d \
./usb/host/usb_host_khci.d 


# Each subdirectory must supply rules for building sources it contributes
usb/host/%.o: ../usb/host/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Archivos\workspaceMcu\vital_signs_monitor\board" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\startup" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\source" -I"D:\Archivos\workspaceMcu\vital_signs_monitor" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\drivers" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\device" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\CMSIS" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\uart" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\utilities" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\serial_manager" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\lists" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\sdmmc\inc" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\sdmmc\host" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\sdmmc\osa" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\osa" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\usb\host\class" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\usb\host" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\source\generated" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\usb\include" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_ram_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_mmc_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_sd_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_sdspi_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_usb_disk" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


