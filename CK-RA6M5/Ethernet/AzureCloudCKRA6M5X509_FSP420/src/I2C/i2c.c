 /* File Name    : i2c.c
 * Description  : File contains i2c functions and structures
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

/***********************************************************************************************************************
 Includes
 ***********************************************************************************************************************/
#include "bsp_api.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "i2c.h"
#include "hal_data.h"
#include "common_utils.h"
#include "hs3001_thread.h"
#include "OB_1203_Thread.h"
//#include "usr_app.h"
/***********************************************************************************************************************
 Global variables and functions
 ***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
static uint8_t transmit_complete_flag;

/*******************************************************************************************************************//**
 * @brief This function write-reads data from I2C bus
 * @param[IN]   addr           salve address
 * @param[IN]   reg            register value
 * @param[IN]   val            pointer to value
 * @param[IN]   num            numer of bytes to read/write
 * @retval      FSP_SUCCESS             Upon successful FLash_HP data flash operations.
 * @retval      Any Other Error code    Upon unsuccessful Flash_HP data flash operations.
 **********************************************************************************************************************/
int8_t I2C_r(uint8_t addr, uint8_t reg, uint8_t *val, char num)
{
    (void)(addr);
    uint16_t timeout = 1000;
    fsp_err_t err;
     transmit_complete_flag = I2C_TRANSMISSION_IN_PROGRESS;
    rm_comms_write_read_params_t write_read_params;
    write_read_params.p_src=&reg;
    write_read_params.src_bytes  = 1;
    write_read_params.p_dest     = val;
    write_read_params.dest_bytes = (uint8_t)num;
     //I2C write read data
    err=g_comms_i2c_device3.p_api->writeRead(g_comms_i2c_device3.p_ctrl,write_read_params);
    //IotLog("\r\nI2C_r  g_comms_i2c_device3.p_api->writeRead  %u",err);
    if (err == FSP_SUCCESS)
    {
         //wait till data transmit is coplete
        while (transmit_complete_flag == I2C_TRANSMISSION_IN_PROGRESS)
        {
            if (--timeout == 0)
            {
                break;
            }
            //delayMicroseconds(1);
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
        }

        transmit_complete_flag = I2C_TRANSMISSION_IN_PROGRESS;
    }

    if (transmit_complete_flag == I2C_TRANSMISSION_ABORTED)
    {
        err = FSP_ERR_ABORTED;
    }

    //IotLog("\r\nI2C_r  addr  %x reg %u  num %u \r\n",addr,reg,num);
    for(int t=0;t<=num;t++)
    {
        //IotLog("val[%d]= %x ",t,val[t]);
    }
    //IotLog("\r\n");
    return err;

}

/*******************************************************************************************************************//**
 * @brief This function write data to slave using I2C bus
 * @param[IN]   addr           salve address
 * @param[IN]   reg            register value
 * @param[IN]   val            pointer to value
 * @param[IN]   num            numer of bytes to read/write
 * @retval      FSP_SUCCESS             Upon successful FLash_HP data flash operations.
 * @retval      Any Other Error code    Upon unsuccessful Flash_HP data flash operations.
 **********************************************************************************************************************/
int8_t I2C_w(uint8_t addr, uint8_t reg, uint8_t *val, char num)
{
    (void)(addr);
    uint16_t timeout = 1000;
    int8_t err;
      static uint8_t data[50];
    data[0] = reg;
    memcpy(&(data[1]), val, (size_t)num);
    transmit_complete_flag = I2C_TRANSMISSION_IN_PROGRESS;
     //I2C write data
    err=g_comms_i2c_device3.p_api->write(g_comms_i2c_device3.p_ctrl,data, (uint32_t)(num+1));
    //IotLog("\r\nI2C_w  g_comms_i2c_device3.p_api->write  %u",err);
    if (err == FSP_SUCCESS)
    {
         //wait till data transmit is coplete
        while (transmit_complete_flag == I2C_TRANSMISSION_IN_PROGRESS)
        {
            if (--timeout == 0)
            {
                break;
            }
            //delayMicroseconds(1);
            R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
        }

        transmit_complete_flag = I2C_TRANSMISSION_IN_PROGRESS;
    }

    if (transmit_complete_flag == I2C_TRANSMISSION_ABORTED)
    {
        err = FSP_ERR_ABORTED;
    }

   //IotLog("\r\nI2C_w  addr  %x reg %u  num %u \r\n",addr,reg,num);
    for(int t=0;t<=num;t++)
        {
           // IotLog("val[%d]= %x ",t,val[t]);
        }
    //IotLog("\r\n");
    return err;
}

/*******************************************************************************************************************//**
 * @brief I2c callback
 * @param[IN]   p_args         pointer to i2c callback parameters
 **********************************************************************************************************************/
void comms_i2c_callback(rm_comms_callback_args_t * p_args)
{
    if (p_args->event == RM_COMMS_EVENT_OPERATION_COMPLETE)
    {
        transmit_complete_flag = I2C_TRANSMISSION_COMPLETE;
    }
    else
    {
        transmit_complete_flag = I2C_TRANSMISSION_ABORTED;
    }
}

