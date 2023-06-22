/* generated thread source file - do not edit */
#include "ZMOD4410_Thread.h"

TX_THREAD ZMOD4410_Thread;
void ZMOD4410_Thread_create(void);
static void ZMOD4410_Thread_func(ULONG thread_input);
static uint8_t ZMOD4410_Thread_stack[2048] BSP_PLACE_IN_SECTION(".stack.ZMOD4410_Thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
/* I2C Communication Device */
#define RA_NOT_DEFINED (1)
rm_comms_i2c_instance_ctrl_t g_comms_i2c_device1_ctrl;

/* Lower level driver configuration */
const i2c_master_cfg_t g_comms_i2c_device1_lower_level_cfg =
{ .slave = 0x32, .addr_mode = I2C_MASTER_ADDR_MODE_7BIT, };

const rm_comms_cfg_t g_comms_i2c_device1_cfg =
{ .semaphore_timeout = 0xFFFFFFFF, .p_lower_level_cfg = (void*) &g_comms_i2c_device1_lower_level_cfg, .p_extend =
          (void*) &g_comms_i2c_bus0_extended_cfg,
  .p_callback = rm_zmod4xxx_comms_i2c_callback,
#if defined(g_zmod4xxx_sensor0_ctrl)
    .p_context          = g_zmod4xxx_sensor0_ctrl,
#else
  .p_context = (void*) &g_zmod4xxx_sensor0_ctrl,
#endif
        };

const rm_comms_instance_t g_comms_i2c_device1 =
{ .p_ctrl = &g_comms_i2c_device1_ctrl, .p_cfg = &g_comms_i2c_device1_cfg, .p_api = &g_comms_on_comms_i2c, };
zmod4xxx_dev_t g_zmod4xxx_sensor0_dev;
iaq_1st_gen_handle_t g_zmod4xxx_sensor0_lib_handle;
iaq_1st_gen_results_t g_zmod4xxx_sensor0_lib_results;
uint8_t g_zmod4xxx_sensor0_product_data[6];
extern rm_zmod4xxx_api_t const g_zmod4xxx_on_zmod4410_iaq_1st_gen;
extern zmod4xxx_conf g_zmod4410_iaq_1st_gen_sensor_type[];
rm_zmod4xxx_lib_extended_cfg_t g_zmod4xxx_sensor0_extended_cfg =
        {
#if (1 == 1) // Continuous mode
          .lib_type = RM_ZMOD4410_LIB_TYPE_IAQ_1ST_GEN_CONTINUOUS,
          .sample_period = 2.0F,
#else                                                   // Low Power mode
    .lib_type = RM_ZMOD4410_LIB_TYPE_IAQ_1ST_GEN_LOW_POWER,
    .sample_period = 6.0F,
#endif
          .product_id = 0x2310,
          .p_api = (void*) &g_zmod4xxx_on_zmod4410_iaq_1st_gen, .p_data_set = (void*) g_zmod4410_iaq_1st_gen_sensor_type, .p_product_data =
                  g_zmod4xxx_sensor0_product_data,
          .p_device = (void*) &g_zmod4xxx_sensor0_dev, .p_handle = (void*) &g_zmod4xxx_sensor0_lib_handle, .p_results =
                  (void*) &g_zmod4xxx_sensor0_lib_results, };
rm_zmod4xxx_instance_ctrl_t g_zmod4xxx_sensor0_ctrl;
const rm_zmod4xxx_cfg_t g_zmod4xxx_sensor0_cfg =
{ .p_comms_instance = &g_comms_i2c_device1,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == g_external_irq0)
    .p_irq_instance = NULL,
    .p_irq_callback = NULL,
#else
  .p_irq_instance = &g_external_irq0,
  .p_irq_callback = zmod4xxx_irq0_callback,
#endif
#undef RA_NOT_DEFINED
  .p_comms_callback = zmod4xxx_comms_i2c0_callback,
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = (void*) &g_zmod4xxx_sensor0_extended_cfg, };

const rm_zmod4xxx_instance_t g_zmod4xxx_sensor0 =
{ .p_ctrl = &g_zmod4xxx_sensor0_ctrl, .p_cfg = &g_zmod4xxx_sensor0_cfg, .p_api = &g_zmod4xxx_on_zmod4xxx, };
extern bool g_fsp_common_initialized;
extern uint32_t g_fsp_common_thread_count;
extern TX_SEMAPHORE g_fsp_common_initialized_semaphore;

void ZMOD4410_Thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_fsp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&ZMOD4410_Thread, (CHAR*) "ZMOD4410_Thread", ZMOD4410_Thread_func, (ULONG) NULL,
                            &ZMOD4410_Thread_stack, 2048, 3, 3, 1, TX_DONT_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&ZMOD4410_Thread, 0);
    }
}

static void ZMOD4410_Thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    FSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    ZMOD4410_Thread_entry ();
}
