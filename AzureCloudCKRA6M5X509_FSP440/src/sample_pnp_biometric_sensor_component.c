/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

#include <math.h>
#include "nx_api.h"
#include "nx_azure_iot_hub_client.h"
#include "nx_azure_iot_json_reader.h"
#include "nx_azure_iot_json_writer.h"
#include "nx_azure_iot_provisioning_client.h"
#include "sample_config.h"

#define SAMPLE_PNP_OXYGEN_COMPONENT_NAME                                "oxygen_saturation"
#define SAMPLE_PNP_HEART_COMPONENT_NAME                         	     "heart_rate"
#define SAMPLE_PNP_RESPIRATION_COMPONENT_NAME                            "respiration_rate"

#define DOUBLE_DECIMAL_PLACE_DIGITS                                     (2)
#define FOUR_DECIMAL_PLACE_DIGITS                                       (4)

#define SAMPLE_PNP_BIOMETRIC_COMPONENT_NAME                       "Biometric"
/* TODO : Add property name */
static const CHAR sample_pnp_oxygen_name_property_name[] = "oxygen_saturation";
static const CHAR sample_pnp_heart_property_name[] = "heart_rate";
static const CHAR sample_pnp_respiration_property_name[] = "respiration_rate";
static const CHAR sample_pnp_perfusionIndex_property_name[] = "perfusionIndex";
static CHAR telemetry_buffer[256];

extern uint16_t spo2_val;
extern uint16_t heart_Rate_Val;
extern uint16_t breathing_rate;
extern uint16_t r_p2p;

extern SAMPLE_CLIENT  client;
#define iothub_client client.iothub_client

UINT sample_biometric_telemetry_messages_send(void);

UINT sample_biometric_telemetry_messages_send(void)
{
	UINT status;
	NX_PACKET *packet_ptr;
	UINT data_length;
	NX_AZURE_IOT_JSON_WRITER json_writer;

    /* Create a telemetry message packet.  */
    if ((status = nx_azure_iot_hub_client_telemetry_message_create(&iothub_client, &packet_ptr, NX_WAIT_FOREVER)))
    {
        return (status);
    }

/*    if ((status = (nx_azure_iot_hub_client_telemetry_component_set(packet_ptr, SAMPLE_PNP_BIOMETRIC_COMPONENT_NAME, sizeof(SAMPLE_PNP_BIOMETRIC_COMPONENT_NAME) - 1, NX_WAIT_FOREVER))))
    {
        return(status);
    }
*/
     /* Build telemetry JSON payload.  */
     if (nx_azure_iot_json_writer_with_buffer_init(&json_writer, telemetry_buffer, sizeof(telemetry_buffer)))
     {
         nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
         return(NX_NOT_SUCCESSFUL);
     }

     /* Append ambient light property name and value.  */
     /* TODO : Replace real data from temp.*/
     if (nx_azure_iot_json_writer_append_begin_object(&json_writer) ||
    		 nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																		  (UCHAR *)sample_pnp_oxygen_name_property_name,
																		  sizeof(sample_pnp_oxygen_name_property_name) - 1,
																		  spo2_val
																		  ) ||
		    nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	  	  (UCHAR *)sample_pnp_heart_property_name,
																		  sizeof(sample_pnp_heart_property_name) - 1,
																		  heart_Rate_Val
																	  	  ) ||
            nx_azure_iot_json_writer_append_property_with_int32_value(&json_writer,
																	 	 (UCHAR *)sample_pnp_respiration_property_name,
																		 sizeof(sample_pnp_respiration_property_name) - 1,
																		 breathing_rate
																	 	 ) ||
		    nx_azure_iot_json_writer_append_property_with_double_value(&json_writer,
																	  	  (UCHAR *)sample_pnp_perfusionIndex_property_name,
																		  sizeof(sample_pnp_perfusionIndex_property_name) - 1,
																		  r_p2p,
																		  FOUR_DECIMAL_PLACE_DIGITS) ||
         nx_azure_iot_json_writer_append_end_object(&json_writer))
     {
         nx_azure_iot_json_writer_deinit(&json_writer);
         nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
         return(NX_NOT_SUCCESSFUL);
     }

     data_length = nx_azure_iot_json_writer_get_bytes_used(&json_writer);
     if ((status = nx_azure_iot_hub_client_telemetry_send(&iothub_client, packet_ptr,
                                                          (UCHAR *)telemetry_buffer, data_length, NX_WAIT_FOREVER)))
     {
         nx_azure_iot_json_writer_deinit(&json_writer);
         nx_azure_iot_hub_client_telemetry_message_delete(packet_ptr);
         return(status);
     }

     nx_azure_iot_json_writer_deinit(&json_writer);
     /* TODO : ADD output data.*/
#if ENABLE_SENSORS_MQTT_PRINTS
     demo_printf("\r\nTelemetry message sent: oxygen saturation = %d, ", ob_Data.ob_spo2);
     demo_printf("heart rate = %d,", ob_Data.ob_hr );
     demo_printf("respiration rate = %d, ", ob_Data.ob_rr);
     demo_printf("perfusion Index = %f, ", ob_Data.ob_pi);
#endif
    return(NX_AZURE_IOT_SUCCESS);
}
