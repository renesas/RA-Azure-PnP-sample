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

#define DOUBLE_DECIMAL_PLACE_DIGITS                                     (2)
#define THREE_DECIMAL_PLACE_DIGITS                                      (3)

#define SAMPLE_PNP_ENVIRONMENTAL_COMPONENT_NAME                       "Barometric"

/* TODO : Add property name */
static const CHAR sample_pnp_icp_pressure_name_property_name[] = "ICP10101_Pressure";
static const CHAR sample_pnp_icp_temperature_property_name[] = "ICP10101_Temperature";


static CHAR telemetry_buffer[256];

extern float Temperature,ChPressure;

extern SAMPLE_CLIENT  client;
#define iothub_client client.iothub_client

UINT sample_barometric_sensor_telemetry_messages_send(void);

UINT sample_barometric_sensor_telemetry_messages_send(void)
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

 /*   if ((status = (nx_azure_iot_hub_client_telemetry_component_set(packet_ptr, SAMPLE_PNP_ENVIRONMENTAL_COMPONENT_NAME, sizeof(SAMPLE_PNP_ENVIRONMENTAL_COMPONENT_NAME) - 1, NX_WAIT_FOREVER))))
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

     /* Append ambient light property name and value. */
     /* TODO : Replace real data from temp.*/
     if (nx_azure_iot_json_writer_append_begin_object(&json_writer) ||

            nx_azure_iot_json_writer_append_property_with_double_value(&json_writer,
                                                                          (UCHAR *)sample_pnp_icp_pressure_name_property_name,
                                                                          sizeof(sample_pnp_icp_pressure_name_property_name) - 1,
                                                                          ChPressure,
																		  THREE_DECIMAL_PLACE_DIGITS) ||
            nx_azure_iot_json_writer_append_property_with_double_value(&json_writer,
                                                                      (UCHAR *)sample_pnp_icp_temperature_property_name,
                                                                      sizeof(sample_pnp_icp_temperature_property_name) - 1,
                                                                      Temperature,
																	  THREE_DECIMAL_PLACE_DIGITS) ||

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
     /* TODO : Replace real data from temp.*/
#if ENABLE_SENSORS_MQTT_PRINTS
     demo_printf("\r\nTelemetry message sent: ICP-Pressure = %f, ", icp10101_Data.pressureicp);
     demo_printf("ICP-Temperature = %f,", icp10101_Data.temperatureicp);
#endif
    return(NX_AZURE_IOT_SUCCESS);
}
