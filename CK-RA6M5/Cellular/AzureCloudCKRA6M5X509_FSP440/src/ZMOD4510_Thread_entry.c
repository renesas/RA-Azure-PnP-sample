/***********************************************************************************************************************
 * File Name    : ZMOD4510_Thread_entry.c
 * Description  : Contains functions used in Zmod4510 related application
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * Copyright [2023] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas FSP license agreement. Unless otherwise agreed in an FSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/
#include "ZMOD4510_Thread.h"
#include "RA_ZMOD4XXX_Common.h"
#include "user_choice.h"

/* ZMOD4510_Thread entry function */
void ZMOD4510_Thread_entry(void)
{
    /* TODO: add your own code here */
    g_zmod4xxx_sensor1_quick_setup();
    while (1)
    {
#if _ZMOD4510_SENSOR_ENABLE_
        start_oaq_1st_gen();
#endif
        tx_thread_sleep (30);
    }
}
