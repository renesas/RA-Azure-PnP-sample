/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * File Name    : menu_kis.h
 * Description  : Main menu information
 *********************************************************************************************************************/

#ifndef MENU_KIS_H_
#define MENU_KIS_H_

#define MODULE_NAME_VERSION      "\r\n%d. GET FSP VERSION\r\n\r\n"
#define MODULE_NAME_UUID         "\r\n%d. GET UUID\r\n\r\n"
#define MODULE_NAME_HELP         "\r\n%d. HELP\r\n\r\n"
#define MODULE_START_APP         "\r\n%d. STARTING APPLICATION\r\n\r\n"
#define UUID_TAG                 "   RA MCU 128-bit Unique ID (hex) : "
#define HELP_TAG1                "  Please type 1 for FSP version details\r\n"
#define HELP_TAG2                "  Please type 2 for flash memory related operations\r\n"
#define HELP_TAG3                "  Please type 3 for UUID\r\n"

#define CONNECTION_ABORT_CRTL    (0x00)
#define MENU_EXIT_CRTL           (0x20)

extern test_fn kis_display_menu (void);
test_fn get_version(void);
test_fn get_uuid (void);
test_fn help (void);
test_fn start_app (void);

#endif /* MENU_KIS_H_ */
