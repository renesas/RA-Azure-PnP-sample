/* generated thread header file - do not edit */
#ifndef HS3001_THREAD_H_
#define HS3001_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void HS3001_Thread_entry(void);
                #else
extern void HS3001_Thread_entry(void);
#endif
#include "rm_comms_i2c.h"
#include "rm_comms_api.h"
#include "rm_hs300x.h"
#include "rm_hs300x_api.h"
FSP_HEADER
/* I2C Communication Device */
extern const rm_comms_instance_t g_comms_i2c_device0;
extern rm_comms_i2c_instance_ctrl_t g_comms_i2c_device0_ctrl;
extern const rm_comms_cfg_t g_comms_i2c_device0_cfg;
#ifndef rm_hs300x_callback
void rm_hs300x_callback(rm_comms_callback_args_t *p_args);
#endif
/* HS300X Sensor */
extern const rm_hs300x_instance_t g_hs300x_sensor0;
extern rm_hs300x_instance_ctrl_t g_hs300x_sensor0_ctrl;
extern const rm_hs300x_cfg_t g_hs300x_sensor0_cfg;
#ifndef hs300x_callback
void hs300x_callback(rm_hs300x_callback_args_t *p_args);
#endif
FSP_FOOTER
#endif /* HS3001_THREAD_H_ */
