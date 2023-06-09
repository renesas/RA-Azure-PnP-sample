/***********************************************************************************************************************
 * File Name    : OB_1203_Thread_entry.c
 * Description  : Contains entry function of OB sensor Thread .
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

#include "OB_1203_Thread.h"
#include "oximeter.h"
#include "user_choice.h"

extern void (*p_IntB_Event)(void);

void g_ob1203_sensor0_quick_setup(void);
/* OB_1203_Thread entry function */
void OB_1203_Thread_entry(void)
{
    /* TODO: add your own code here */
    fsp_err_t err = FSP_SUCCESS;
    /* opening ExternalIRQ for IRQ14 P403 for OB1203 */
    err = R_ICU_ExternalIrqOpen (&g_sensorIRQ_ctrl, &g_sensorIRQ_cfg);
    if (FSP_SUCCESS != err)
    {
        APP_DBG_PRINT("\r\nOB1203 Sensor External Irq Open failed \r\n");
        APP_ERR_TRAP(err);
    }
    else
    {
    	APP_PRINT("\r\nOB1203 Sensor External Irq Open success \r\n");
    }
    /* Open OB1203 */
    g_ob1203_sensor0_quick_setup();
    /* OB1203 configuration */
    /* do initial configuration of OB1203, Kalman filters, algorithm, etc. */
    main_init(&ox,&sp,&ob);
    while (1)
    {
#if _OB1203_SENSOR_ENABLE_
        ob1203_spo2_main(&ox, &sp, &ob);
#endif
        tx_thread_sleep (10);
    }
}


void g_ob1203_sensor0_quick_setup(void)
{
    fsp_err_t err = FSP_SUCCESS;
    err = g_comms_i2c_device3.p_api->open (g_comms_i2c_device3.p_ctrl, g_comms_i2c_device3.p_cfg);
    if (FSP_SUCCESS == err)
    {
        APP_PRINT("\r\nOB1203 sensor setup success \r\n");
    }
    else
    {
        APP_DBG_PRINT("\r\nOB1203 Sensor open fail\r\n");
        APP_ERR_TRAP(err);
    }
}


void sensorOBIRQCallback(external_irq_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);

    if (p_IntB_Event != NULL)
    {
        p_IntB_Event ();
    }
}
