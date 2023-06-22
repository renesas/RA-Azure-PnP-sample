/***********************************************************************************************************************
 * File Name    : cellular_setup.c
 * Description  : Contains Function for setting up the Cellular Modem 
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
 * SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2023 Renesas Electronics Corporation. All rights reserved.
 ***********************************************************************************************************************/

#include "common_utils.h"
#include <usr_app.h>
#include <usr_hal.h>
#include <usr_network.h>
#include "user_choice.h"
#include <ewf.h>
#include "ewf_adapter_sequans.h"

ewf_allocator* message_allocator_ptr = NULL;
ewf_interface* interface_ptr = NULL;
ewf_adapter* adapter_ptr = NULL;
ewf_result result;

/** @brief The SIM PIN for the modem */
#define CELLULAR_APN "iot.truphone.com"  /* APN : Truphone SIM Card */
#define EWF_CONFIG_SIM_PIN                     ("0000")
#define EWF_MODEM_NETWORK_WAIT_TIME_SECONDS    (120)
#define CELLULAR_CONTEX_ID (1)
#define CELLULAR_PDP_TYPE "IPV4V6"

uint32_t modem_ip_addr;
ULONG g_dns_address = 0;
ULONG g_network_mask = 0xffffff00;
ULONG g_gateway_address = 0;
ULONG host_ip_address = 0;

ewf_result cellular_init();

ewf_result cellular_init()
{
    EWF_ALLOCATOR_THREADX_STATIC_DECLARE(message_allocator_ptr, message_allocator,16,1500 );

    /* This is for the communications interface using R_UART */
    EWF_INTERFACE_RA_UART_STATIC_DECLARE(interface_ptr, sci_uart);

    /* This is for the adapter instance on RYZ */
    EWF_ADAPTER_RENESAS_RYZ014_STATIC_DECLARE(adapter_ptr, renesas_ryz014, message_allocator_ptr, NULL, interface_ptr);

    ewf_platform_sleep(50);
    R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_07_PIN_08, BSP_IO_LEVEL_LOW);
    IotLog("Waiting for the module to Power Reset!\r\n");
    ewf_platform_sleep(300);

    /* Start the adapter */
    if (ewf_result_failed(result = ewf_adapter_start(adapter_ptr)))
    {
        IotLogErr("ewf_adapter_start  failed: %u\r\n", result);
        return result;
    }

    /* Set the ME functionality */
    if (ewf_result_failed(result = ewf_adapter_modem_functionality_set(adapter_ptr, "1")))
    {
        IotLogErr("ewf_adapter_modem_functionality_set  failed: %u\r\n", result);
        return result;
    }
    if (ewf_result_failed(result = ewf_adapter_sequans_configure_pdp_context(adapter_ptr, CELLULAR_CONTEX_ID, CELLULAR_APN, CELLULAR_PDP_TYPE)))
    {
        IotLogErr("ewf_adapter_sequans_configure_pdp_context  failed: %u\r\n", result);
        return result;
    }
    /* Wait for the modem functionality to be up */
    ewf_platform_sleep(200);

    if (ewf_result_failed(result = ewf_adapter_modem_network_registration_check(adapter_ptr, EWF_ADAPTER_MODEM_CMD_QUERY_NETWORK_REG,EWF_MODEM_NETWORK_WAIT_TIME_SECONDS)))
    {
        IotLogErr("ewf_adapter_modem_network_registration_check  failed: %u\r\n", result);
        return result;
    }

    /* Disable network Registration URC */
    if (ewf_result_failed(result = ewf_adapter_modem_network_registration_urc_set(adapter_ptr, "0")))
    {
        IotLog("ewf_adapter_modem_network_registration_urc_set failed, ewf_result %d.\n", result);
        return result;
    }

    /* Disable EPS network Registration URC */
    if (ewf_result_failed(result = ewf_adapter_modem_eps_network_registration_urc_set(adapter_ptr, "0")))
    {
        IotLog("ewf_adapter_modem_eps_network_registration_urc_set failed, ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_modem_sim_pin_enter(adapter_ptr, EWF_CONFIG_SIM_PIN)))
    {
        IotLog("ewf_adapter_modem_sim_pin_enter failed, ewf_result %d.\n", result);
        return result;
    }

    /* Do a service activate to set context num correctly */
    if (ewf_result_failed(result = ewf_adapter_modem_packet_service_activate(adapter_ptr, 1)))
    {
        IotLog("ewf_adapter_modem_packet_service_activate failed, ewf_result %d.\n", result);
        return result;
    }
    /* Get modem IP */
    if (ewf_result_failed(result = ewf_adapter_get_ipv4_address(adapter_ptr, &modem_ip_addr)))
    {
        IotLog("ewf_adapter_get_ipv4_address failed, ewf_result %d.\n", result);
        return result;
    }
#if 0
    if (ewf_result_failed(result = ewf_adapter_get_ipv4_netmask(adapter_ptr,(uint32_t*)g_network_mask)))
    {
        IotLog("Failed to get the adapter IPv4 netmask: ewf_result %d.\n", result);
        return result;
    }
#endif
    if (ewf_result_failed(result = ewf_adapter_get_ipv4_gateway(adapter_ptr, (uint32_t*)&g_gateway_address)))
    {
        IotLog("Failed to get the adapter IPv4 gateway: ewf_result %d.\n", result);
        return result;
    }

    if (ewf_result_failed(result = ewf_adapter_get_ipv4_dns(adapter_ptr, (uint32_t*)&g_dns_address)))
    {
        IotLog("Failed to get the adapter IPv4 DNS: ewf_result %d.\n", result);
        return result;
    }
    return result;
}
