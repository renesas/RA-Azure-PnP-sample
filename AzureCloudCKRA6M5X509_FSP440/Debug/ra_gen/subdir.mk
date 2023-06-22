################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra_gen/CommandRX_Thread.c \
../ra_gen/Console_Thread.c \
../ra_gen/HS3001_Thread.c \
../ra_gen/ICM_Thread.c \
../ra_gen/ICP_Thread.c \
../ra_gen/OB_1203_Thread.c \
../ra_gen/ZMOD4410_Thread.c \
../ra_gen/ZMOD4510_Thread.c \
../ra_gen/application_thread.c \
../ra_gen/c2d_thread.c \
../ra_gen/common_data.c \
../ra_gen/hal_data.c \
../ra_gen/main.c \
../ra_gen/pin_data.c \
../ra_gen/vector_data.c 

C_DEPS += \
./ra_gen/CommandRX_Thread.d \
./ra_gen/Console_Thread.d \
./ra_gen/HS3001_Thread.d \
./ra_gen/ICM_Thread.d \
./ra_gen/ICP_Thread.d \
./ra_gen/OB_1203_Thread.d \
./ra_gen/ZMOD4410_Thread.d \
./ra_gen/ZMOD4510_Thread.d \
./ra_gen/application_thread.d \
./ra_gen/c2d_thread.d \
./ra_gen/common_data.d \
./ra_gen/hal_data.d \
./ra_gen/main.d \
./ra_gen/pin_data.d \
./ra_gen/vector_data.d 

OBJS += \
./ra_gen/CommandRX_Thread.o \
./ra_gen/Console_Thread.o \
./ra_gen/HS3001_Thread.o \
./ra_gen/ICM_Thread.o \
./ra_gen/ICP_Thread.o \
./ra_gen/OB_1203_Thread.o \
./ra_gen/ZMOD4410_Thread.o \
./ra_gen/ZMOD4510_Thread.o \
./ra_gen/application_thread.o \
./ra_gen/c2d_thread.o \
./ra_gen/common_data.o \
./ra_gen/hal_data.o \
./ra_gen/main.o \
./ra_gen/pin_data.o \
./ra_gen/vector_data.o 

SREC += \
AzureCloudCKRA6M5X509_FSP440.srec 

MAP += \
AzureCloudCKRA6M5X509_FSP440.map 


# Each subdirectory must supply rules for building sources it contributes
ra_gen/%.o: ../ra_gen/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RA_CORE=CM33 -D_RENESAS_RA_ -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/src" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/inc/api" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/inc/instances" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/rm_threadx_port" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/threadx/common/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_gen" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg/bsp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg/azure/tx" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/pop3" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/snmp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/nat" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/mqtt" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/ftp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/tftp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/sntp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/smtp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/web" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/auto_ip" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/telnet" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/dns" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/dhcp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/http" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/common/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/ports/cortex_m4" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/cloud" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/rm_netxduo_ether" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg/middleware" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg/azure/nxd" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/deps/flatcc/include" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc/configs/RTOS_BASE" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/crypto_libraries/src" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/crypto_libraries/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/nx_secure/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/private/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/public/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce/common" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/rm_netx_secure_crypto/inc/crypto_common" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/rm_netx_secure_crypto/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc/iot_security_module/model/objects" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

