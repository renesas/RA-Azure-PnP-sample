#include "application_thread.h"
#include "common_utils.h"
#include <usr_app.h>
#include <usr_hal.h>
#include <usr_network.h>
#include "user_choice.h"
#include "ICM_20948.h"

extern UINT unix_time_get(ULONG *unix_time);
static double mcu_temp __attribute__ ((used)) = RESET_VALUE;

extern TX_THREAD c2d_thread;

extern volatile sensor_demo_data_t g_demo_data;
extern volatile iaq_demo_data_t g_iaq_data;
extern volatile float gs_demo_air_quality;
extern float Temperature,ChPressure;
extern uint16_t spo2_val;
extern uint16_t heart_Rate_Val;
extern uint16_t breathing_rate;
extern uint16_t r_p2p;
extern xyzFloat corrAccRaw;
extern xyzFloat gyr;
extern xyzFloat magValue;

extern UINT sample_environmental_sensor_telemetry_messages_send (void);
extern UINT sample_barometric_sensor_telemetry_messages_send(void);
extern UINT sample_gas_telemetry_messages_send(void);
extern UINT sample_inertial_sensor_telemetry_messages_send(void);
extern UINT sample_gas_oaq_sensor_telemetry_messages_send(void);
extern UINT sample_biometric_telemetry_messages_send(void);

void temp_cold(void);
void temp_warm(void);
void temp_hot(void);
void TricolorLEDOFF(void);
void TC_RED_ON (void);
void TC_RED_OFF (void);
void TC_BLUE_ON (void);
void TC_BLUE_OFF (void);
void TC_GREEN_ON (void);
void TC_GREEN_OFF (void);
extern  unsigned int DecodeBASE64(char *incertbuff,unsigned char *outcerthexbuff);
extern char g_certificate[];
extern char g_private_key[];

UCHAR sample_device_cert_ptr[1024];
unsigned int sample_device_cert_len=0;
UCHAR sample_device_private_key_ptr[2048];
unsigned int sample_device_private_key_len=0;

char tempstaring[20]="\0";

/* application_thread_entry function */
void application_thread_entry(void)
{
    UINT status = EXIT_SUCCESS;
    mqtt_rx_payload_t mq_data =  { RESET_VALUE };
    fsp_pack_version_t version = {RESET_VALUE};
    TricolorLEDOFF();
    //version get API for FLEX pack information
    R_FSP_VersionGet(&version);

    //Example Project information printed on the Console
    APP_PRINT(BANNER_INFO, AP_VERSION, version.version_id_b.major, version.version_id_b.minor, version.version_id_b.patch);
    APP_PRINT(AP_INFO);

    IotLog("HAL Initialization  \r\n");
    status = usr_hal_init ();
    if (EXIT_SUCCESS != status)
    {
        //IotLogErr("HAL Initialization  failed: %u\r\n", status);
        IotLogErrTrap(status);
    }

    status = _nx_crypto_initialize ();
    if (EXIT_SUCCESS != status)
    {
        //IotLogErr("_nx_crypto_initialize  failed: %u\r\n", status);
        IotLogErrTrap(status);
    }

    status = usr_packet_pool_init ();
    if (EXIT_SUCCESS != status)
    {
        //IotLogErr("Packet Pool Creation failed: %u\r\n", status);
        IotLogErrTrap(status);
    }

    status = usr_netx_init ();
    if (EXIT_SUCCESS != status)
    {
        //IotLogErr("NetX Initialization failed: %u\r\n", status);
        IotLogErrTrap(status);
    }


    sample_device_cert_len= DecodeBASE64(&g_certificate[0],&sample_device_cert_ptr[0]);
    sample_device_private_key_len= DecodeBASE64(&g_private_key[0],&sample_device_private_key_ptr[0]);

    sample_entry (&g_ip0, &g_packet_pool0, &g_dns0, unix_time_get);

     //Resume the thread represented by "c2d_thread".
    status = tx_thread_resume (&c2d_thread);

    do
    {
       status = tx_queue_receive (&g_topic_queue, (VOID*) &mq_data, TX_WAIT_FOREVER);

        if (TX_SUCCESS == status)
        {
            switch (mq_data.id)
            {
                case ID_HS3001:
                {
#if _HS3001_SENSOR_ENABLE_
                    IotLog("\n HS3001 DATA SEND \r\n");
                    if (EXIT_SUCCESS != sample_environmental_sensor_telemetry_messages_send ())
                    {
                        IotLogErr("** HS3001 Sensor Message Publish failed **\r\n");
                        FAILURE_INDICATION
                    }
                    else
                    {
                        ACTIVITY_INDICATION
                    }
#endif
                }
                break;

                case ID_ZMOD4410:
                {
#if _ZMOD4410_SENSOR_ENABLE_
                    IotLog("\n ZMOD4410 DATA SEND  \r\n");
                    if (EXIT_SUCCESS != sample_gas_telemetry_messages_send ())
                    {
                        IotLogErr("** ZMOD4410 Sensor Message Publish failed **\r\n");
                        FAILURE_INDICATION
                    }
                    else
                    {
                        ACTIVITY_INDICATION
                    }
#endif
                }
                break;

                case ID_ICP10101:
                {
#if _ICP10101_SENSOR_ENABLE_
                    IotLog("\n ICP DATA SEND  \r\n");

                    if (EXIT_SUCCESS != sample_barometric_sensor_telemetry_messages_send ())
                    {
                        IotLogErr("** ICP10101 Sensor Message Publish failed **\r\n");
                        FAILURE_INDICATION
                    }
                    else
                    {
                        ACTIVITY_INDICATION
                    }
#endif
                }
                break;

                case ID_ICM20948:
                {
#if _ICM20948_SENSOR_ENABLE_
                    IotLog("\n ICM DATA SEND  \r\n");

                    if (EXIT_SUCCESS != sample_inertial_sensor_telemetry_messages_send ())
                    {
                        IotLogErr("** ICM20948 Sensor Message Publish failed **\r\n");
                        FAILURE_INDICATION
                    }
                    else
                    {
                        ACTIVITY_INDICATION
                    }
#endif
                }
                break;

                case ID_ZMOD4510:
                {
#if _ZMOD4510_SENSOR_ENABLE_
                    IotLog("\n ZMOD4510 DATA SEND  \r\n");

                    if (EXIT_SUCCESS != sample_gas_oaq_sensor_telemetry_messages_send ())
                    {
                        IotLogErr("** ZMOD4510 Sensor Message Publish failed **\r\n");
                        FAILURE_INDICATION
                    }
                    else
                    {
                        ACTIVITY_INDICATION
                    }
#endif
                }
                break;

                case ID_OB1203:
                    {
#if _OB1203_SENSOR_ENABLE_
                        IotLog("\n OB1203 DATA SEND  \r\n");

                        if (EXIT_SUCCESS != sample_biometric_telemetry_messages_send ())
                        {
                            IotLogErr("** OB1203 Sensor Message Publish failed **\r\n");
                            FAILURE_INDICATION
                        }
                        else
                        {
                            ACTIVITY_INDICATION
                        }
#endif
                    }
                    break;

                case ID_LED_ACT:
                {
                    IotLog("Topic Received from Cloud %s \r\n",mq_data.value.led_data.led_act_topic_msg);
                    if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "TC_BLUE_ON"))
                    {
                        TC_BLUE_ON();
                        IotLog("\r\n 3CBLUE LED ON\r\n");
                    }
                    else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "TC_BLUE_OFF"))
                    {
                        TC_BLUE_OFF();
                        IotLog("\r\n 3CBLUE LED OFF\r\n");
                    }
                    else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "TC_GREEN_ON"))
                    {
                        TC_GREEN_ON();
                        IotLog("\r\n 3CGREEN LED ON\r\n");
                    }
                    else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "TC_GREEN_OFF"))
                    {
                        TC_GREEN_OFF();
                        IotLog("\r\n 3CGREEN LED OFF\r\n");
                    }
                    else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "TC_RED_ON"))
                    {
                        TC_RED_ON();
                         IotLog("\r\n 3CRED LED ON\r\n");
                    }
                    else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "TC_RED_OFF"))
                    {
                        TC_RED_OFF();
                         IotLog("\r\n 3CRED LED OFF\r\n");
                    }
                    else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "TC_NONE"))
                    {
                        TricolorLEDOFF();
                         IotLog("\r\n TC ALL LED OFF\r\n");
                    }
                    else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "BLUE_ON"))
                    {
                        led_on_off(LED_BLUE,LED_ON);
                         IotLog("\r\n BLUE LED ON\r\n");
                    }
                    else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "BLUE_OFF"))
                    {
                        led_on_off(LED_BLUE,LED_OFF);
                         IotLog("\r\n BLUE LED OFF\r\n");
                    }
                    else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "RED_ON"))
					 {
						 led_on_off(LED_RED,LED_ON);
						  IotLog("\r\n RED LED ON\r\n");
					 }
					 else if (RESET_VALUE == strcmp ((char*) mq_data.value.led_data.led_act_topic_msg, "RED_OFF"))
					 {
						 led_on_off(LED_RED,LED_OFF);
						  IotLog("\r\n RED LED OFF\r\n");
					 }
                    else
                    {
                        IotLog("\r\nMsg Topic didn't match !!!\r\n");
                    }
                    ACTIVITY_INDICATION
                }
                break;

                case ID_DISPLAY_HS3001:
				   {

#if _HS3001_SENSOR_ENABLE_
                        print_float (tempstaring, sizeof(tempstaring), g_demo_data.gs_demo_temperature);
                        APP_PRINT("\n HS3001 \r\n TEMP = %s \r\n", tempstaring);
                        print_float (tempstaring, sizeof(tempstaring), g_demo_data.gs_demo_humidity);
                        APP_PRINT(" HUMIDITY = %s \r\n", tempstaring);
#endif
					}
					break;

				case ID_DISPLAY_ICM20948:
				   {
#if _ICM20948_SENSOR_ENABLE_
                        print_float (tempstaring, sizeof(tempstaring), corrAccRaw.x);
                        APP_PRINT("\n ICM20948 \r\n accelerometerX = %s \r\n", tempstaring);
                        print_float (tempstaring, sizeof(tempstaring), corrAccRaw.y);
                        APP_PRINT(" accelerometerY = %s \r\n", tempstaring);
                        print_float (tempstaring, sizeof(tempstaring), corrAccRaw.z);
                        APP_PRINT(" accelerometerZ = %s \r\n", tempstaring);

						print_float (tempstaring, sizeof(tempstaring), gyr.x);
						APP_PRINT(" gyroscopeX = %s \r\n", tempstaring);
						print_float (tempstaring, sizeof(tempstaring), gyr.y);
						APP_PRINT(" gyroscopeX = %s \r\n", tempstaring);
						print_float (tempstaring, sizeof(tempstaring), gyr.z);
						APP_PRINT(" gyroscopeX = %s \r\n", tempstaring);

						print_float (tempstaring, sizeof(tempstaring), magValue.x);
						APP_PRINT(" magX = %s \r\n", tempstaring);
						print_float (tempstaring, sizeof(tempstaring), magValue.y);
						APP_PRINT(" magX = %s \r\n", tempstaring);
						print_float (tempstaring, sizeof(tempstaring), magValue.z);
						APP_PRINT(" magX = %s \r\n", tempstaring);
#endif
					}
					break;

				case ID_DISPLAY_ICP10101:
				   {
#if _ICP10101_SENSOR_ENABLE_
                        print_float (tempstaring, sizeof(tempstaring), Temperature);
                        APP_PRINT("\n ICP10101 \r\n TEMP = %s \r\n", tempstaring);
                        print_float (tempstaring, sizeof(tempstaring), ChPressure);
                        APP_PRINT(" ChPressure = %s \r\n", tempstaring);
#endif
				   }
					break;

				case ID_DISPLAY_OB1203:
				   {
#if _OB1203_SENSOR_ENABLE_
                        print_float (tempstaring, sizeof(tempstaring), spo2_val);
                        APP_PRINT("\n OB1203 \r\n spo2_val = %s \r\n", tempstaring);
                        print_float (tempstaring, sizeof(tempstaring), heart_Rate_Val);
                        APP_PRINT(" heart_rate_Val = %s \r\n", tempstaring);
                        print_float (tempstaring, sizeof(tempstaring), breathing_rate);
                        APP_PRINT(" breathing_rate = %s \r\n", tempstaring);
                        print_float (tempstaring, sizeof(tempstaring), r_p2p);
                        APP_PRINT(" r_p2p = %s \r\n", tempstaring);
#endif
				   }
					break;

				case ID_DISPLAY_ZMOD4410:
				   {
#if _ZMOD4410_SENSOR_ENABLE_
                        print_float (tempstaring, sizeof(tempstaring), g_iaq_data.gs_demo_eco2);
                        APP_PRINT("\n ZMOD4410 \r\n ECO2 = %s \r\n", tempstaring);
                        print_float (tempstaring, sizeof(tempstaring), g_iaq_data.gs_demo_etoh);
                        APP_PRINT(" ETOH = %s \r\n", tempstaring);
                        print_float (tempstaring, sizeof(tempstaring), g_iaq_data.gs_demo_tvoc);
                        APP_PRINT(" TVOC = %s \r\n", tempstaring);
#endif
				   }
					break;

				case ID_DISPLAY_ZMOD4510:
				   {
#if _ZMOD4510_SENSOR_ENABLE_
                        print_float (tempstaring, sizeof(tempstaring), gs_demo_air_quality);
                        APP_PRINT("\n ZMOD4510 \r\n OAQ = %s \r\n", tempstaring);
#endif
				   }
					break;

                default:
                {
                    IotLogErr("** Error in MQTT Messages.. MQTT Client Cleanup started  **\r\n");
                    FAILURE_INDICATION
                }
                break;
            }
            memset (&mq_data.value.led_data.led_act_topic_msg, '\0', sizeof(mqtt_rx_payload_t));
        }


    }    while (1);

}


void temp_cold(void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_02, BSP_IO_LEVEL_HIGH); // red
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_03, BSP_IO_LEVEL_HIGH); // green
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_05, BSP_IO_LEVEL_LOW); // BLUE
    tx_thread_sleep (10);
    R_BSP_PinAccessDisable ();

}

void temp_warm(void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_02, BSP_IO_LEVEL_HIGH); // red
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_03, BSP_IO_LEVEL_LOW); // green
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_05, BSP_IO_LEVEL_HIGH); // BLUE
    tx_thread_sleep (10);
    R_BSP_PinAccessDisable ();
}

void temp_hot(void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_02, BSP_IO_LEVEL_LOW); // red
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_03, BSP_IO_LEVEL_HIGH); // green
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_05, BSP_IO_LEVEL_HIGH); // BLUE
    tx_thread_sleep (10);
    R_BSP_PinAccessDisable ();
}

void TricolorLEDOFF(void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_02, BSP_IO_LEVEL_HIGH); // red
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_03, BSP_IO_LEVEL_HIGH); // green
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_05, BSP_IO_LEVEL_HIGH); // BLUE
    tx_thread_sleep (10);
    R_BSP_PinAccessDisable ();

}

void TC_RED_ON (void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_02, BSP_IO_LEVEL_LOW); // red
    R_BSP_PinAccessDisable ();
}

void TC_RED_OFF (void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_02, BSP_IO_LEVEL_HIGH); // red
    R_BSP_PinAccessDisable ();
}

void TC_BLUE_ON (void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_05, BSP_IO_LEVEL_LOW); // blue
    R_BSP_PinAccessDisable ();
}

void TC_BLUE_OFF (void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_05, BSP_IO_LEVEL_HIGH); // blue
    R_BSP_PinAccessDisable ();
}

void TC_GREEN_ON (void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_03, BSP_IO_LEVEL_LOW); // green
    R_BSP_PinAccessDisable ();
}

void TC_GREEN_OFF (void)
{
    R_BSP_PinAccessEnable ();
    tx_thread_sleep (10);
    R_BSP_PinWrite ((bsp_io_port_pin_t) BSP_IO_PORT_06_PIN_03, BSP_IO_LEVEL_HIGH); // green
    R_BSP_PinAccessDisable ();
}
