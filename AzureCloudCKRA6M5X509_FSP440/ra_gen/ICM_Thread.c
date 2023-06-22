/* generated thread source file - do not edit */
#include "ICM_Thread.h"

TX_THREAD ICM_Thread;
void ICM_Thread_create(void);
static void ICM_Thread_func(ULONG thread_input);
static uint8_t ICM_Thread_stack[2048] BSP_PLACE_IN_SECTION(".stack.ICM_Thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
/* I2C Communication Device */
#define RA_NOT_DEFINED (1)
rm_comms_i2c_instance_ctrl_t g_comms_i2c_device5_ctrl;

/* Lower level driver configuration */
const i2c_master_cfg_t g_comms_i2c_device5_lower_level_cfg =
{ .slave = 0x68, .addr_mode = I2C_MASTER_ADDR_MODE_7BIT, };

const rm_comms_cfg_t g_comms_i2c_device5_cfg =
{ .semaphore_timeout = 0xFFFFFFFF, .p_lower_level_cfg = (void*) &g_comms_i2c_device5_lower_level_cfg, .p_extend =
          (void*) &g_comms_i2c_bus0_extended_cfg,
  .p_callback = ICM_comms_i2c_callback,
#if defined(NULL)
    .p_context          = NULL,
#else
  .p_context = (void*) &NULL,
#endif
        };

const rm_comms_instance_t g_comms_i2c_device5 =
{ .p_ctrl = &g_comms_i2c_device5_ctrl, .p_cfg = &g_comms_i2c_device5_cfg, .p_api = &g_comms_on_comms_i2c, };
extern bool g_fsp_common_initialized;
extern uint32_t g_fsp_common_thread_count;
extern TX_SEMAPHORE g_fsp_common_initialized_semaphore;

void ICM_Thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_fsp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&ICM_Thread, (CHAR*) "ICM_Thread", ICM_Thread_func, (ULONG) NULL, &ICM_Thread_stack, 2048,
                            3, 3, 1, TX_DONT_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&ICM_Thread, 0);
    }
}

static void ICM_Thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    FSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    ICM_Thread_entry ();
}
