################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CommandRX_Thread_entry.c \
../src/Console_Thread_entry.c \
../src/HS3001_Thread_entry.c \
../src/ICM_20948.c \
../src/ICM_Thread_entry.c \
../src/ICP_10101.c \
../src/ICP_Thread_entry.c \
../src/OB_1203_Thread_entry.c \
../src/RA_HS3001.c \
../src/RA_ZMOD4XXX_Common.c \
../src/RA_ZMOD4XXX_IAQ1stGen.c \
../src/RA_ZMOD4XXX_OAQ1stGen.c \
../src/RmcI2C.c \
../src/ZMOD4410_Thread_entry.c \
../src/ZMOD4510_Thread_entry.c \
../src/application_thread_entry.c \
../src/base64_decode.c \
../src/c2d_thread_entry.c \
../src/common_utils.c \
../src/hal_entry.c \
../src/nx_azure_iot_cert.c \
../src/nx_azure_iot_ciphersuites.c \
../src/oximeter.c \
../src/sample_azure_iot_embedded_sdk.c \
../src/sample_device_identity.c \
../src/sample_pnp_barometric_pressure_sensor_component.c \
../src/sample_pnp_biometric_sensor_component.c \
../src/sample_pnp_environmental_sensor_component.c \
../src/sample_pnp_gas_component.c \
../src/sample_pnp_gas_oaq.c \
../src/sample_pnp_inertial_sensor_component.c \
../src/usr_app.c \
../src/usr_hal.c \
../src/usr_network.c 

C_DEPS += \
./src/CommandRX_Thread_entry.d \
./src/Console_Thread_entry.d \
./src/HS3001_Thread_entry.d \
./src/ICM_20948.d \
./src/ICM_Thread_entry.d \
./src/ICP_10101.d \
./src/ICP_Thread_entry.d \
./src/OB_1203_Thread_entry.d \
./src/RA_HS3001.d \
./src/RA_ZMOD4XXX_Common.d \
./src/RA_ZMOD4XXX_IAQ1stGen.d \
./src/RA_ZMOD4XXX_OAQ1stGen.d \
./src/RmcI2C.d \
./src/ZMOD4410_Thread_entry.d \
./src/ZMOD4510_Thread_entry.d \
./src/application_thread_entry.d \
./src/base64_decode.d \
./src/c2d_thread_entry.d \
./src/common_utils.d \
./src/hal_entry.d \
./src/nx_azure_iot_cert.d \
./src/nx_azure_iot_ciphersuites.d \
./src/oximeter.d \
./src/sample_azure_iot_embedded_sdk.d \
./src/sample_device_identity.d \
./src/sample_pnp_barometric_pressure_sensor_component.d \
./src/sample_pnp_biometric_sensor_component.d \
./src/sample_pnp_environmental_sensor_component.d \
./src/sample_pnp_gas_component.d \
./src/sample_pnp_gas_oaq.d \
./src/sample_pnp_inertial_sensor_component.d \
./src/usr_app.d \
./src/usr_hal.d \
./src/usr_network.d 

OBJS += \
./src/CommandRX_Thread_entry.o \
./src/Console_Thread_entry.o \
./src/HS3001_Thread_entry.o \
./src/ICM_20948.o \
./src/ICM_Thread_entry.o \
./src/ICP_10101.o \
./src/ICP_Thread_entry.o \
./src/OB_1203_Thread_entry.o \
./src/RA_HS3001.o \
./src/RA_ZMOD4XXX_Common.o \
./src/RA_ZMOD4XXX_IAQ1stGen.o \
./src/RA_ZMOD4XXX_OAQ1stGen.o \
./src/RmcI2C.o \
./src/ZMOD4410_Thread_entry.o \
./src/ZMOD4510_Thread_entry.o \
./src/application_thread_entry.o \
./src/base64_decode.o \
./src/c2d_thread_entry.o \
./src/common_utils.o \
./src/hal_entry.o \
./src/nx_azure_iot_cert.o \
./src/nx_azure_iot_ciphersuites.o \
./src/oximeter.o \
./src/sample_azure_iot_embedded_sdk.o \
./src/sample_device_identity.o \
./src/sample_pnp_barometric_pressure_sensor_component.o \
./src/sample_pnp_biometric_sensor_component.o \
./src/sample_pnp_environmental_sensor_component.o \
./src/sample_pnp_gas_component.o \
./src/sample_pnp_gas_oaq.o \
./src/sample_pnp_inertial_sensor_component.o \
./src/usr_app.o \
./src/usr_hal.o \
./src/usr_network.o 

SREC += \
AzureCloudCKRA6M5X509_FSP440.srec 

MAP += \
AzureCloudCKRA6M5X509_FSP440.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RA_CORE=CM33 -D_RENESAS_RA_ -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/src" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/inc/api" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/inc/instances" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/rm_threadx_port" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/threadx/common/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_gen" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg/bsp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg/azure/tx" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/pop3" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/snmp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/nat" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/mqtt" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/ftp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/tftp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/sntp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/smtp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/web" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/auto_ip" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/telnet" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/dns" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/dhcp" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/http" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/common/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/ports/cortex_m4" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/cloud" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/rm_netxduo_ether" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg/middleware" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra_cfg/fsp_cfg/azure/nxd" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/iot-security-module-core/deps/flatcc/include" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc/configs/RTOS_BASE" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/src" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure-sdk-for-c/sdk/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/crypto_libraries/src" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/crypto_libraries/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/nx_secure/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/private/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/public/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce/crypto_procedures/src/sce9/plainkey/primitive" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce/common" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/r_sce" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/rm_netx_secure_crypto/inc/crypto_common" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/fsp/src/rm_netx_secure_crypto/inc" -I"D:/WS_440_ETH_RECREATION/AzureCloudCKRA6M5X509_FSP440/ra/microsoft/azure-rtos/netxduo/addons/azure_iot/azure_iot_security_module/inc/iot_security_module/model/objects" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

