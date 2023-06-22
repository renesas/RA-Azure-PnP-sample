#include "ICM_Thread.h"
#include "ICM_20948.h"
#include "usr_app.h"
#include "user_choice.h"
/* ICM_Thread entry function */
void ICM_Thread_entry(void)
{
    /* TODO: add your own code here */
    while (1)
    {
#if _ICM20948_SENSOR_ENABLE_
        ICM_20948_get ();
#endif
        tx_thread_sleep (60);

    }
}
