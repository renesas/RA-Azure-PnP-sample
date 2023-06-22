/***********************************************************************************************************************
 * File Name    : RA_ZMOD4XXX_IAQ1stGen.c
 * Description  : Contains data structures and function definitions
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
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 ***********************************************************************************************************************/

#include "hal_data.h"
#include "RA_ZMOD4XXX_Common.h"
#include "common_utils.h"
#include "user_choice.h"

volatile iaq_demo_data_t g_iaq_data;
static demo_sequence_t sequence = DEMO_SEQUENCE_1;
rm_zmod4xxx_raw_data_t raw_data;

/*******************************************************************************************************************//**
 * @brief       Start reading ZMOD4510 data
 * @param[in]
 * @retval
 * @retval
 ***********************************************************************************************************************/
void start_iaq_1st_gen(void)
{
    fsp_err_t err;
    rm_zmod4xxx_iaq_1st_data_t zmod4xxx_data;
    switch (sequence)
    {
        case DEMO_SEQUENCE_1:
        {
            /* Clear status */
            g_i2c_callback_status = DEMO_CALLBACK_STATUS_WAIT;
#if DEMO_IRQ_ENABLE
            g_irq_callback_status = DEMO_CALLBACK_STATUS_WAIT;
#endif

            /* Start measurement */
            err = g_zmod4xxx_sensor0.p_api->measurementStart (g_zmod4xxx_sensor0.p_ctrl);
            if (FSP_SUCCESS == err)
            {
                sequence = DEMO_SEQUENCE_2;
            }
            else
            {
                APP_DBG_PRINT("\r\nTask zmod4410 task error in seq 1:%d\r\n", err);
            }
        }
        break;

        case DEMO_SEQUENCE_2:
        {
            /* Check I2C callback status */
            switch (g_i2c_callback_status)
            {
                case DEMO_CALLBACK_STATUS_WAIT:
                break;
                case DEMO_CALLBACK_STATUS_SUCCESS:
                    sequence = DEMO_SEQUENCE_3;
                break;
                case DEMO_CALLBACK_STATUS_REPEAT:
                    sequence = DEMO_SEQUENCE_1;
                break;
                default:
                break;
            }
           R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_MILLISECONDS); // vTaskDelay (5);
        }
        break;

#if DEMO_IRQ_ENABLE
        case DEMO_SEQUENCE_3:
        {
            /* Check IRQ callback status */
            switch (g_irq_callback_status)
            {
                case DEMO_CALLBACK_STATUS_WAIT:
                break;
                case DEMO_CALLBACK_STATUS_SUCCESS:
                    sequence = DEMO_SEQUENCE_5;
                break;
                default:
                break;
            }
            R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_MILLISECONDS); //vTaskDelay (5);
        }
        break;
#else
        case DEMO_SEQUENCE_3 :
        {
            /* Clear status */
            g_i2c_callback_status = DEMO_CALLBACK_STATUS_WAIT;

            /* Get status */
            err = g_zmod4xxx_sensor0.p_api->statusCheck(g_zmod4xxx_sensor0.p_ctrl);
            if (FSP_SUCCESS == err)
            {
                sequence = DEMO_SEQUENCE_4;
                APP_PRINT ("\r\nTask zmod4410 status Successful:%d\r\n",err);
            }
            else
            {
                APP_PRINT ("\r\nTask zmod4410 task delete in seq 3:%d\r\n",err);
            }
        }
        break;

        case DEMO_SEQUENCE_4 :
        {
            /* Check I2C callback status */
            switch (g_i2c_callback_status)
            {
                case DEMO_CALLBACK_STATUS_WAIT :
                    break;
                case DEMO_CALLBACK_STATUS_SUCCESS :
                    sequence = DEMO_SEQUENCE_5;
                    break;
                case DEMO_CALLBACK_STATUS_REPEAT :
                    sequence = DEMO_SEQUENCE_3;
                    break;
                default :
                    APP_PRINT ("\r\nTask zmod4410 task delete in seq 4:%d\r\n",err);
                    break;
            }
        }
        break;
#endif
        case DEMO_SEQUENCE_5:
        {
            /* Clear status */
            g_i2c_callback_status = DEMO_CALLBACK_STATUS_WAIT;

            /* Read data */
            err = g_zmod4xxx_sensor0.p_api->read (g_zmod4xxx_sensor0.p_ctrl, &raw_data);
            if (FSP_SUCCESS == err)
            {
                sequence = DEMO_SEQUENCE_6;
            }
            else if (FSP_ERR_SENSOR_MEASUREMENT_NOT_FINISHED == err)
            {
                sequence = DEMO_SEQUENCE_3;
                /* Delay 5ms */
                 R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_MILLISECONDS);//vTaskDelay (5);
                APP_DBG_PRINT("\r\nTask zmod4410 task read failed in seq 5:%d\r\n", err);
            }
        }
        break;

        case DEMO_SEQUENCE_6:
        {
            /* Check I2C callback status */
            switch (g_i2c_callback_status)
            {
                case DEMO_CALLBACK_STATUS_WAIT:
                break;
                case DEMO_CALLBACK_STATUS_SUCCESS:
                    sequence = DEMO_SEQUENCE_7;
                break;
                case DEMO_CALLBACK_STATUS_REPEAT:
                    sequence = DEMO_SEQUENCE_5;
                break;
                default:
                break;
            }
             R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_MILLISECONDS);//vTaskDelay (5);
        }
        break;

        case DEMO_SEQUENCE_7:
        {
            /* Calculate data */
            err = g_zmod4xxx_sensor0.p_api->iaq1stGenDataCalculate (g_zmod4xxx_sensor0.p_ctrl, &raw_data,
                                                                    &zmod4xxx_data);
            if (FSP_SUCCESS == err)
            {
#if RM_ZMOD4XXX_CFG_OPERATION_MODE == 6
                sequence = DEMO_SEQUENCE_3;
#if DEMO_IRQ_ENABLE
                g_irq_callback_status = DEMO_CALLBACK_STATUS_WAIT;
#endif
#elif RM_ZMOD4XXX_CFG_OPERATION_MODE == 2
                sequence = DEMO_SEQUENCE_1;
#endif

                /* Set data */
                g_iaq_data.gs_demo_etoh = zmod4xxx_data.etoh;
                g_iaq_data.gs_demo_eco2 = zmod4xxx_data.eco2;
                g_iaq_data.gs_demo_tvoc = zmod4xxx_data.tvoc;
            }
            else if (FSP_ERR_SENSOR_IN_STABILIZATION == err)
            {
#if RM_ZMOD4XXX_CFG_OPERATION_MODE == 6
                sequence = DEMO_SEQUENCE_3;
#if DEMO_IRQ_ENABLE
                g_irq_callback_status = DEMO_CALLBACK_STATUS_WAIT;
#endif
#elif RM_ZMOD4XXX_CFG_OPERATION_MODE == 2
                sequence = DEMO_SEQUENCE_1;
#endif
            }
            else
            {
                APP_DBG_PRINT("\r\nTask zmod4410 task delete in seq 7:%d\r\n", err);
            }
            sequence = DEMO_SEQUENCE_3;
            /* Delay required time */
            R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_MILLISECONDS); //vTaskDelay (5);
        }
        break;

        default:
        {
            APP_DBG_PRINT("\r\nTask zmod4410 task delete in default case:%d\r\n", err);
        }
        break;
    }
}

