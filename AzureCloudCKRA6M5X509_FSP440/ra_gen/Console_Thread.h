/* generated thread header file - do not edit */
#ifndef CONSOLE_THREAD_H_
#define CONSOLE_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void Console_Thread_entry(void);
                #else
extern void Console_Thread_entry(void);
#endif
#include "r_flash_hp.h"
#include "r_flash_api.h"
#include "r_sci_uart.h"
#include "r_uart_api.h"
FSP_HEADER
/* Flash on Flash HP Instance */
extern const flash_instance_t user_flash;

/** Access the Flash HP instance using these structures when calling API functions directly (::p_api is not used). */
extern flash_hp_instance_ctrl_t user_flash_ctrl;
extern const flash_cfg_t user_flash_cfg;

#ifndef flash_callback
void flash_callback(flash_callback_args_t *p_args);
#endif
/** UART on SCI Instance. */
extern const uart_instance_t g_console_uart;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern sci_uart_instance_ctrl_t g_console_uart_ctrl;
extern const uart_cfg_t g_console_uart_cfg;
extern const sci_uart_extended_cfg_t g_console_uart_cfg_extend;

#ifndef user_uart_callback
void user_uart_callback(uart_callback_args_t *p_args);
#endif
FSP_FOOTER
#endif /* CONSOLE_THREAD_H_ */
