/***********************************************************************************************************************
 * File Name    : flash_hp.h
 * Description  : Contains macros, data structures and functions used in flash_hp.h
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

#include "common_utils.h"

#ifndef FLASH_HP_EP_H_
#define FLASH_HP_EP_H_

typedef enum e_credentials
{
    CERTIFICATE = 0,
    PRIVATE_KEY,
	MQTT_ENDPOINT,
	IOT_THING_NAME
}credentials_t;

typedef struct s_credentials_mem_map
{
	uint32_t num_bytes;
	uint32_t addr;
	uint8_t num_block;
	bool stored_in_flash;
	uint32_t length;
}credentials_mem_map_t;

typedef struct s_credentials_stored_info
{
	bool stored_in_flash;
	uint32_t num_bytes;
}credentials_stored_info_t;

#define FLASH_HP_DF_BLOCK_SIZE            (64)

/* Data Flash */
#define FLASH_HP_DF_BLOCK_0               0x08001000U /*   64 B:    0x80001000 - 0x8000103F */
#define FLASH_HP_DF_BLOCK_CERTIFICATE     0x08001040U /*   1536 B:  0x08001040 - 0x0800163F */
#define FLASH_HP_DF_BLOCK_KEY             0x08001640U /*   2048 B:  0x08001640 - 0x08001E3F */
#define FLASH_HP_DF_MQTT_END_POINT        0x08001E40U /*   128 B:   0x08001E40 - 0x08001EBF */
#define FLASH_HP_DF_IOT_THING_NAME        0x08001EC0U /*   128 B:   0x08001EC0 - 0x08001F3F */
#define FLASH_HP_DF_DATA_INFO             0x08001F40U /*   128 B:   0x08001F40 - 0x08001FBF */


#define TOTAL_BLOCK_SIZE                  (3968)
#define TOTAL_BLOCK_NUM					  (62)

#define BLOCK_SIZE_CERT                   (1536)
#define BLOCK_NUM_CERT			          (24)

#define BLOCK_SIZE_KEY                    (2048)
#define BLOCK_NUM_KEY			          (32)

#define BLOCK_SIZE_MQTT_ENDPOINT          (128)
#define BLOCK_NUM_MQTT_ENDPOINT	          (2)

#define BLOCK_SIZE_IOT_THING              (128)
#define BLOCK_NUM_IOT_THING		          (2)

#define BLOCK_SIZE_DATA_INFO              (128)
#define BLOCK_NUM_DATA_INFO		          (2)
//
#define BUFFER_SIZE                       (2048)

#define CREDENTIAL_COUNT                  (4)

#define MODULE_NAME_FLASH_INFO         "\r\nDATA FLASH INFO\r\n"
#define FLASH_WRITE_CERT_MENU          "\r\nDATA FLASH WRITE CERTIFICATE\r\n"
#define FLASH_WRITE_KEY_MENU           "\r\nDATA FLASH WRITE PRIVATE KEY\r\n"
#define FLASH_WRITE_THING_NAME          "\r\nDATA FLASH WRITE THING NAME\r\n"
#define FLASH_WRITE_MQTT_END_POINT     "\r\nDATA FLASH WRITE MQTT END POINT\r\n"
#define FLASH_CHECK_CREDENTIALS        "\r\nCHECK CREDENTIALS STORED IN DATA FLASH\r\n"
#define OPTIONS_SELECT                 "\r\n> Select from the options in the menu below:\r\n"
#define SELECT_FILE                    "\r\n Select the file to write data in data flash \r\n"
#define TYPE_CREDENTIALS               "\r\n Type or Paste credential and press enter to save credentials in flash\r\n"
#define MODULE_NAME_FLASH_READ         "\r\nDATA FLASH READ\r\n"
#define MODULE_NAME_FLASH_HELP         "\r\nHELP\r\n\r\n"
#define FLASH_HELP_TAG1                "  Please type a for flash memory information\r\n"
#define FLASH_HELP_TAG2                "  Please type b to save AZURE certificate\r\n"
#define FLASH_HELP_TAG3                "  Please type c to save AZURE private key\r\n"
#define FLASH_HELP_TAG4                "  Please type d to save MQTT broker end point\r\n"
#define FLASH_HELP_TAG5                "  Please type e to save IOT thing name\r\n"
#define FLASH_HELP_TAG6                "  Please type f to read data saved in flash\r\n"
#define FLASH_HELP_TAG7                "  Please type g to check and validate credentials saved\r\n"
#define END_OF_AWS_CERTIFICATE         "-----END CERTIFICATE-----"
#define END_OF_AWS_PRIVATE_KEY         "-----END RSA PRIVATE KEY-----"
#define CERTIFICATE                    (0)
#define PRIVATE_KEY                    (1)
#define MQTT_ENDPOINT                  (2)
#define IOT_THING_NAME                 (3)
#define FLASH_DATA_INFO                (4)

/* Switch Commands */
#define CODE_FLASH                     (1U)
#define DATA_FLASH                     (2U)
#define EXIT						   (3U)
#define BUFF_SIZE					   0x0F
#define BUFF_INDEX					   0x00

/*flash_hp operating functions */
fsp_err_t aws_certficate_write(uint8_t cert_type);
fsp_err_t flash_data_write(void);
fsp_err_t store_flashed_data_info (uint8_t cert_type);
fsp_err_t flash_hp_data_read(bool print_data);
fsp_err_t flash_hp_data_flash_operations(void);
void flash_hp_deinit(void);
void exit_flash_hp(void);
void flash_display_menu(uint8_t credential_type);
void flash_info(void);
void flash_memory_mapping(void);
fsp_err_t flash_mem_init(void);
fsp_err_t flash_stored_data_info (void);
fsp_err_t check_credentials_stored (void);
void help_menu(void);
test_fn TCP_Send_performance_server_IP_address(void);
/*******************************************************************************************************************//**
 * @} (end defgroup FLASH_HP_EP)
 **********************************************************************************************************************/

#endif /* FLASH_HP_H_ */
