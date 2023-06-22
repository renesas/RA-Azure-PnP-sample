/* generated thread source file - do not edit */
#include "CommandRX_Thread.h"

TX_THREAD CommandRX_Thread;
void CommandRX_Thread_create(void);
static void CommandRX_Thread_func(ULONG thread_input);
static uint8_t CommandRX_Thread_stack[2048] BSP_PLACE_IN_SECTION(".stack.CommandRX_Thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
extern bool g_fsp_common_initialized;
extern uint32_t g_fsp_common_thread_count;
extern TX_SEMAPHORE g_fsp_common_initialized_semaphore;

void CommandRX_Thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_fsp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&CommandRX_Thread, (CHAR*) "CommandRX_Thread", CommandRX_Thread_func, (ULONG) NULL,
                            &CommandRX_Thread_stack, 2048, 4, 4, 40, TX_DONT_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&CommandRX_Thread, 0);
    }
}

static void CommandRX_Thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    FSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    CommandRX_Thread_entry ();
}
