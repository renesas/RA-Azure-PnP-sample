/***********************************************************************************************************************
 * File Name    : HS3001_Thread_entry.c
 * Description  : Contains entry function for the HS3001 sensor Thread .
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

#include "HS3001_Thread.h"
#include "RA_HS3001.h"
#include "RA_ZMOD4XXX_Common.h"
#include "ICP_10101.h"
#include "RmcI2C.h"
#include "usr_app.h"
#include "user_choice.h"

extern TX_THREAD ZMOD4410_Thread;
extern TX_THREAD ICP_Thread;
extern TX_THREAD ICM_Thread;
extern TX_THREAD OB_1203_Thread;
extern TX_THREAD ZMOD4510_Thread;


UINT status1 = EXIT_SUCCESS;

void g_comms_i2c_bus0_quick_setup(void);
static void reset_zmod_sensor(void);
void start_periodic_msg_sending(void);

/* HS3001_Thread entry function */
void HS3001_Thread_entry(void)
{
    /* TODO: add your own code here */
    reset_zmod_sensor();
    g_comms_i2c_bus0_quick_setup();
    tx_thread_sleep (200);

#if _HS3001_SENSOR_ENABLE_
    g_hs300x_sensor0_quick_setup();
    tx_thread_sleep (500);
#endif

#if _ZMOD4410_SENSOR_ENABLE_
    g_zmod4xxx_sensor0_quick_setup();
    R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
    status1 = tx_thread_resume (&ZMOD4410_Thread);
    R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
#endif

#if _ICP10101_SENSOR_ENABLE_
    RmComDevice_init ();
    begin ();
    measureStart (VERY_ACCURATE);
    R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
    status1 = tx_thread_resume (&ICP_Thread);
    R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
#endif

#if _ICM20948_SENSOR_ENABLE_
    RmComDevice_init_Icm ();
    ICM20948_Sensor_init ();
    R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
    status1 = tx_thread_resume (&ICM_Thread);
    R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
#endif

#if _OB1203_SENSOR_ENABLE_
    status1 = tx_thread_resume (&OB_1203_Thread);
    R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
#endif

#if _ZMOD4510_SENSOR_ENABLE_
    status1 = tx_thread_resume (&ZMOD4510_Thread);
    R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
#endif
    start_periodic_msg_sending();

    while (1)
    {
#if _HS3001_SENSOR_ENABLE_
        hs3001_get();
#endif
        tx_thread_sleep (50);
    }
}

void start_periodic_msg_sending(void)
{
	fsp_err_t status = FSP_SUCCESS;
    R_GPT_Start (&gpt_ctrl);

    if (FSP_SUCCESS == status)
    {
        IotLog("\n** Periodic MSG Sending TIMER Start  %u **\r\n",status);

    }
    else
    {
    	IotLog("\n** Periodic MSG Sending TIMER Failed  %u **\r\n",status);
    }
}

/* Quick setup for g_comms_i2c_bus0. */
void g_comms_i2c_bus0_quick_setup(void)
{
    fsp_err_t err;
    i2c_master_instance_t * p_driver_instance = (i2c_master_instance_t *) g_comms_i2c_bus0_extended_cfg.p_driver_instance;

    /* Open I2C driver, this must be done before calling any COMMS API */
    err = p_driver_instance->p_api->open(p_driver_instance->p_ctrl, p_driver_instance->p_cfg);
    assert(FSP_SUCCESS == err);

#if BSP_CFG_RTOS
    /* Create a semaphore for blocking if a semaphore is not NULL */
    if (NULL != g_comms_i2c_bus0_extended_cfg.p_blocking_semaphore)
    {
#if BSP_CFG_RTOS == 1 // AzureOS
        tx_semaphore_create(g_comms_i2c_bus0_extended_cfg.p_blocking_semaphore->p_semaphore_handle,
                            g_comms_i2c_bus0_extended_cfg.p_blocking_semaphore->p_semaphore_name,
                            (ULONG) 0);
#elif BSP_CFG_RTOS == 2 // FreeRTOS
        *(g_comms_i2c_bus0_extended_cfg.p_blocking_semaphore->p_semaphore_handle)
            = xSemaphoreCreateCountingStatic((UBaseType_t) 1, (UBaseType_t) 0, g_comms_i2c_bus0_extended_cfg.p_blocking_semaphore->p_semaphore_memory);
#endif
    }

    /* Create a recursive mutex for bus lock if a recursive mutex is not NULL */
    if (NULL != g_comms_i2c_bus0_extended_cfg.p_bus_recursive_mutex)
    {
#if BSP_CFG_RTOS == 1 // AzureOS
        tx_mutex_create(g_comms_i2c_bus0_extended_cfg.p_bus_recursive_mutex->p_mutex_handle,
                        g_comms_i2c_bus0_extended_cfg.p_bus_recursive_mutex->p_mutex_name,
                        TX_INHERIT);
#elif BSP_CFG_RTOS == 2 // FreeRTOS
        *(g_comms_i2c_bus0_extended_cfg.p_bus_recursive_mutex->p_mutex_handle)
            = xSemaphoreCreateRecursiveMutexStatic(g_comms_i2c_bus0_extended_cfg.p_bus_recursive_mutex->p_mutex_memory);
#endif
    }
#endif
}

static void reset_zmod_sensor(void)
{
    R_BSP_PinAccessEnable ();

    /* ZMOD Reset for CK-RA5M5 */
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_03_PIN_06, BSP_IO_LEVEL_HIGH); // 4510
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_03_PIN_07, BSP_IO_LEVEL_HIGH); // 4410
    R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);

    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_03_PIN_06, BSP_IO_LEVEL_LOW); // 4510
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_03_PIN_07, BSP_IO_LEVEL_LOW); // 4410
    R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);

    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_03_PIN_06, BSP_IO_LEVEL_HIGH); // 4510
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_03_PIN_07, BSP_IO_LEVEL_HIGH); // 4410
    R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);

    R_BSP_PinAccessDisable ();
}
