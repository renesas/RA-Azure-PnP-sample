#include "ZMOD4410_Thread.h"
#include "RA_ZMOD4XXX_Common.h"
#include "common_utils.h"
#include "user_choice.h"

/* ZMOD4410_Thread entry function */
void ZMOD4410_Thread_entry(void)
{
    /* TODO: add your own code here */
    while (1)
    {
#if _ZMOD4410_SENSOR_ENABLE_
        start_iaq_1st_gen();
#endif
        tx_thread_sleep (60);
    }
}
