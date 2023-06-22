/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_gpt.h"
#include "r_timer_api.h"
FSP_HEADER
/** Timer on GPT Instance. */
extern const timer_instance_t gpt;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t gpt_ctrl;
extern const timer_cfg_t gpt_cfg;

#ifndef g_gpt_timer_cb
void g_gpt_timer_cb(timer_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer2;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t g_timer2_ctrl;
extern const timer_cfg_t g_timer2_cfg;

#ifndef TimerCallback
void TimerCallback(timer_callback_args_t *p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
