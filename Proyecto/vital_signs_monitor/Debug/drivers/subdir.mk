################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_adc16.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_dac.c \
../drivers/fsl_dmamux.c \
../drivers/fsl_dspi.c \
../drivers/fsl_dspi_edma.c \
../drivers/fsl_edma.c \
../drivers/fsl_ftfx_cache.c \
../drivers/fsl_ftfx_controller.c \
../drivers/fsl_ftfx_flash.c \
../drivers/fsl_ftfx_flexnvm.c \
../drivers/fsl_ftm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_pit.c \
../drivers/fsl_sai.c \
../drivers/fsl_sai_edma.c \
../drivers/fsl_sdhc.c \
../drivers/fsl_smc.c \
../drivers/fsl_sysmpu.c \
../drivers/fsl_uart.c 

OBJS += \
./drivers/fsl_adc16.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_dac.o \
./drivers/fsl_dmamux.o \
./drivers/fsl_dspi.o \
./drivers/fsl_dspi_edma.o \
./drivers/fsl_edma.o \
./drivers/fsl_ftfx_cache.o \
./drivers/fsl_ftfx_controller.o \
./drivers/fsl_ftfx_flash.o \
./drivers/fsl_ftfx_flexnvm.o \
./drivers/fsl_ftm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_pit.o \
./drivers/fsl_sai.o \
./drivers/fsl_sai_edma.o \
./drivers/fsl_sdhc.o \
./drivers/fsl_smc.o \
./drivers/fsl_sysmpu.o \
./drivers/fsl_uart.o 

C_DEPS += \
./drivers/fsl_adc16.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_dac.d \
./drivers/fsl_dmamux.d \
./drivers/fsl_dspi.d \
./drivers/fsl_dspi_edma.d \
./drivers/fsl_edma.d \
./drivers/fsl_ftfx_cache.d \
./drivers/fsl_ftfx_controller.d \
./drivers/fsl_ftfx_flash.d \
./drivers/fsl_ftfx_flexnvm.d \
./drivers/fsl_ftm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_pit.d \
./drivers/fsl_sai.d \
./drivers/fsl_sai_edma.d \
./drivers/fsl_sdhc.d \
./drivers/fsl_smc.d \
./drivers/fsl_sysmpu.d \
./drivers/fsl_uart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Archivos\workspaceMcu\vital_signs_monitor\board" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\startup" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\source" -I"D:\Archivos\workspaceMcu\vital_signs_monitor" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\drivers" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\device" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\CMSIS" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\uart" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\utilities" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\serial_manager" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\lists" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\sdmmc\inc" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\sdmmc\host" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\sdmmc\osa" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\component\osa" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\usb\host\class" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\usb\host" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\source\generated" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\usb\include" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_ram_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_mmc_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_sd_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_sdspi_disk" -I"D:\Archivos\workspaceMcu\vital_signs_monitor\fatfs\source\fsl_usb_disk" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


