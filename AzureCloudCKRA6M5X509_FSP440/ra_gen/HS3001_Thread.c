/* generated thread source file - do not edit */
#include "HS3001_Thread.h"

TX_THREAD HS3001_Thread;
void HS3001_Thread_create(void);
static void HS3001_Thread_func(ULONG thread_input);
static uint8_t HS3001_Thread_stack[4096] BSP_PLACE_IN_SECTION(".stack.HS3001_Thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
/* I2C Communication Device */
#define RA_NOT_DEFINED (1)
rm_comms_i2c_instance_ctrl_t g_comms_i2c_device0_ctrl;

/* Lower level driver configuration */
const i2c_master_cfg_t g_comms_i2c_device0_lower_level_cfg =
{ .slave = 0x44, .addr_mode = I2C_MASTER_ADDR_MODE_7BIT, };

const rm_comms_cfg_t g_comms_i2c_device0_cfg =
{ .semaphore_timeout = 0xFFFFFFFF, .p_lower_level_cfg = (void*) &g_comms_i2c_device0_lower_level_cfg, .p_extend =
          (void*) &g_comms_i2c_bus0_extended_cfg,
  .p_callback = rm_hs300x_callback,
#if defined(g_hs300x_sensor0_ctrl)
    .p_context          = g_hs300x_sensor0_ctrl,
#else
  .p_context = (void*) &g_hs300x_sensor0_ctrl,
#endif
        };

const rm_comms_instance_t g_comms_i2c_device0 =
{ .p_ctrl = &g_comms_i2c_device0_ctrl, .p_cfg = &g_comms_i2c_device0_cfg, .p_api = &g_comms_on_comms_i2c, };
rm_hs300x_instance_ctrl_t g_hs300x_sensor0_ctrl;
const rm_hs300x_cfg_t g_hs300x_sensor0_cfg =
{ .p_instance = &g_comms_i2c_device0, .p_callback = hs300x_callback,
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
        };

const rm_hs300x_instance_t g_hs300x_sensor0 =
{ .p_ctrl = &g_hs300x_sensor0_ctrl, .p_cfg = &g_hs300x_sensor0_cfg, .p_api = &g_hs300x_on_hs300x, };
extern bool g_fsp_common_initialized;
extern uint32_t g_fsp_common_thread_count;
extern TX_SEMAPHORE g_fsp_common_initialized_semaphore;

void HS3001_Thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_fsp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&HS3001_Thread, (CHAR*) "HS3001_Thread", HS3001_Thread_func, (ULONG) NULL,
                            &HS3001_Thread_stack, 4096, 3, 3, 1, TX_DONT_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&HS3001_Thread, 0);
    }
}

static void HS3001_Thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    FSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    HS3001_Thread_entry ();
}
