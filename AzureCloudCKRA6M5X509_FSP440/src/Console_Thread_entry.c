#include "Console_Thread.h"
#include "console_menu/menu_main.h"
#include "common_utils.h"
#include "base64.h"

#define CERT_1ST_LINE_LENGTH 50
#define CERT_BASE64_DATA_MAX_LENGTH 5000

uint8_t certPEM[4096];
unsigned int certDER[4096];
void console_init(void);
void flash_init(void);
unsigned int DecodeBASE64(char *incertbuff,unsigned char*outcerthexbuff);
/* Console_Thread entry function */
void Console_Thread_entry(void)
{
    /* TODO: add your own code here */
    console_init();

    while (1)
    {
        main_display_menu();
        tx_thread_sleep (10);
    }
}


void console_init(void)
{
    fsp_err_t err = FSP_SUCCESS;
    /* Version get API for FLEX pack information */
    /* Initializing UART */
    err = uart_initialize();
    if (FSP_SUCCESS != err)
    {
        APP_ERR_PRINT ("\r\nUART INIT FAILED\r\n");
        APP_ERR_TRAP(err);
    }
    else
    {
       APP_DBG_PRINT ("\r\nUART INIT SUCCESS\r\n");
    }

    flash_init();
}

void flash_init(void)
{
     fsp_err_t err = FSP_SUCCESS;
    /* Open Flash_HP */
    err = R_FLASH_HP_Open(&user_flash_ctrl, &user_flash_cfg);
    /* Handle Error */
    if (FSP_SUCCESS != err)
    {
        APP_ERR_PRINT("\r\n Flah_HP_Open API failed");
        APP_ERR_TRAP(err);
    }
}

/* @brief  DecodeBASE64 function
*
* This function gets the rootCA certificate from the user and store in the internal flash.
*********************************************************************************************************************/
 unsigned int DecodeBASE64(char *incertbuff,unsigned char*outcerthexbuff)
{
	  memset(outcerthexbuff,0,CERT_BASE64_DATA_MAX_LENGTH);
      memset(certPEM,0,sizeof(certPEM));

      unsigned long int t=0;
      unsigned long int t2=0;
      unsigned long int t3=0;

/*Remove 1st line of certificate ,skip till \r */
      for (t=0;t<CERT_1ST_LINE_LENGTH;t++)
      {
          if(incertbuff[t]=='\r')
          {break;}
      }
   	  t++;

/*Copy BASE64 data till certificate's last line's 1st character '-' */
     for(;t<CERT_BASE64_DATA_MAX_LENGTH;t++)
      {
         if(incertbuff[t]=='-')
         {
             break;
         }
         if((incertbuff[t]!='\r')&&(incertbuff[t]!='\n'))
         {
             certPEM[t2]=incertbuff[t];

              t2++;
         }

       }

/*Generate hex data from BASE64 data*/
  t3= base64_decode(&certPEM[0], t2 ,&outcerthexbuff[0]);

   /*Return  hex data len*/
   return(t3);
}
