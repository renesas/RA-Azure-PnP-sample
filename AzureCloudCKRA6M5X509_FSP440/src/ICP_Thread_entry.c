#include "ICP_Thread.h"
#include "ICP_10101.h"
#include "user_choice.h"
/* ICP_Thread entry function */
void ICP_Thread_entry(void)
{
    /* TODO: add your own code here */
    while (1)
    {
#if _ICP10101_SENSOR_ENABLE_
        ICP_10101_get ();
#endif
        tx_thread_sleep (70);
    }
}
