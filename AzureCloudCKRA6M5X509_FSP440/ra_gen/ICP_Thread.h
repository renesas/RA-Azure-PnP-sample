/* generated thread header file - do not edit */
#ifndef ICP_THREAD_H_
#define ICP_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void ICP_Thread_entry(void);
                #else
extern void ICP_Thread_entry(void);
#endif
#include "rm_comms_i2c.h"
#include "rm_comms_api.h"
FSP_HEADER
/* I2C Communication Device */
extern const rm_comms_instance_t g_comms_i2c_device4;
extern rm_comms_i2c_instance_ctrl_t g_comms_i2c_device4_ctrl;
extern const rm_comms_cfg_t g_comms_i2c_device4_cfg;
#ifndef ICP_comms_i2c_callback
void ICP_comms_i2c_callback(rm_comms_callback_args_t *p_args);
#endif
FSP_FOOTER
#endif /* ICP_THREAD_H_ */
