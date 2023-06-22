/* generated common source file - do not edit */
#include "common_data.h"

icu_instance_ctrl_t g_external_irq1_ctrl;
const external_irq_cfg_t g_external_irq1_cfg =
{ .channel = 15,
  .trigger = EXTERNAL_IRQ_TRIG_FALLING,
  .filter_enable = false,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .p_callback = rm_zmod4xxx_irq_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = NULL,
  .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ15)
    .irq                 = VECTOR_NUMBER_ICU_IRQ15,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq1 =
{ .p_ctrl = &g_external_irq1_ctrl, .p_cfg = &g_external_irq1_cfg, .p_api = &g_external_irq_on_icu };
icu_instance_ctrl_t g_external_irq0_ctrl;
const external_irq_cfg_t g_external_irq0_cfg =
{ .channel = 4,
  .trigger = EXTERNAL_IRQ_TRIG_RISING,
  .filter_enable = false,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .p_callback = rm_zmod4xxx_irq_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = NULL,
  .ipl = (5),
#if defined(VECTOR_NUMBER_ICU_IRQ4)
    .irq                 = VECTOR_NUMBER_ICU_IRQ4,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq0 =
{ .p_ctrl = &g_external_irq0_ctrl, .p_cfg = &g_external_irq0_cfg, .p_api = &g_external_irq_on_icu };
iic_master_instance_ctrl_t g_i2c_master0_ctrl;
const iic_master_extended_cfg_t g_i2c_master0_extend =
{ .timeout_mode = IIC_MASTER_TIMEOUT_MODE_SHORT, .timeout_scl_low = IIC_MASTER_TIMEOUT_SCL_LOW_ENABLED,
/* Actual calculated bitrate: 396825. Actual calculated duty cycle: 51%. */.clock_settings.brl_value = 25,
  .clock_settings.brh_value = 26, .clock_settings.cks_value = 1, };
const i2c_master_cfg_t g_i2c_master0_cfg =
{ .channel = 0, .rate = I2C_MASTER_RATE_FAST, .slave = 0x00, .addr_mode = I2C_MASTER_ADDR_MODE_7BIT,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .p_callback = rm_comms_i2c_callback,
  .p_context = NULL,
#if defined(VECTOR_NUMBER_IIC0_RXI)
    .rxi_irq             = VECTOR_NUMBER_IIC0_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC0_TXI)
    .txi_irq             = VECTOR_NUMBER_IIC0_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC0_TEI)
    .tei_irq             = VECTOR_NUMBER_IIC0_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC0_ERI)
    .eri_irq             = VECTOR_NUMBER_IIC0_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
  .ipl = (12),
  .p_extend = &g_i2c_master0_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_master0 =
{ .p_ctrl = &g_i2c_master0_ctrl, .p_cfg = &g_i2c_master0_cfg, .p_api = &g_i2c_master_on_iic };
#if BSP_CFG_RTOS
#if BSP_CFG_RTOS == 1
#if !defined(g_comms_i2c_bus0_recursive_mutex)
TX_MUTEX g_comms_i2c_bus0_recursive_mutex_handle;
CHAR g_comms_i2c_bus0_recursive_mutex_name[] = "g_comms_i2c_bus0 recursive mutex";
#endif
#if !defined(g_comms_i2c_bus0_blocking_semaphore)
TX_SEMAPHORE g_comms_i2c_bus0_blocking_semaphore_handle;
CHAR g_comms_i2c_bus0_blocking_semaphore_name[] = "g_comms_i2c_bus0 blocking semaphore";
#endif
#elif BSP_CFG_RTOS == 2
#if !defined(g_comms_i2c_bus0_recursive_mutex)
SemaphoreHandle_t g_comms_i2c_bus0_recursive_mutex_handle;
StaticSemaphore_t g_comms_i2c_bus0_recursive_mutex_memory;
#endif
#if !defined(g_comms_i2c_bus0_blocking_semaphore)
SemaphoreHandle_t g_comms_i2c_bus0_blocking_semaphore_handle;
StaticSemaphore_t g_comms_i2c_bus0_blocking_semaphore_memory;
#endif
#endif

#if !defined(g_comms_i2c_bus0_recursive_mutex)
/* Recursive Mutex for I2C bus */
rm_comms_i2c_mutex_t g_comms_i2c_bus0_recursive_mutex =
{
    .p_mutex_handle = &g_comms_i2c_bus0_recursive_mutex_handle,
#if BSP_CFG_RTOS == 1 // ThradX
    .p_mutex_name = &g_comms_i2c_bus0_recursive_mutex_name[0],
#elif BSP_CFG_RTOS == 2 // FreeRTOS
    .p_mutex_memory = &g_comms_i2c_bus0_recursive_mutex_memory,
#endif
};
#endif

#if !defined(g_comms_i2c_bus0_blocking_semaphore)
/* Semaphore for blocking */
rm_comms_i2c_semaphore_t g_comms_i2c_bus0_blocking_semaphore =
{
    .p_semaphore_handle = &g_comms_i2c_bus0_blocking_semaphore_handle,
#if BSP_CFG_RTOS == 1 // ThreadX
    .p_semaphore_name = &g_comms_i2c_bus0_blocking_semaphore_name[0],
#elif BSP_CFG_RTOS == 2 // FreeRTOS
    .p_semaphore_memory = &g_comms_i2c_bus0_blocking_semaphore_memory,
#endif
};
#endif
#endif

/* Shared I2C Bus */
#define RA_NOT_DEFINED (1)
rm_comms_i2c_bus_extended_cfg_t g_comms_i2c_bus0_extended_cfg =
{
#if !defined(g_i2c_master0)
  .p_driver_instance = (void*) &g_i2c_master0,
#elif !defined(RA_NOT_DEFINED)
    .p_driver_instance      = (void*)&RA_NOT_DEFINED,
#endif
  .p_current_ctrl = NULL,
  .bus_timeout = 0xFFFFFFFF,
#if BSP_CFG_RTOS
#if !defined(g_comms_i2c_bus0_blocking_semaphore)
    .p_blocking_semaphore = &g_comms_i2c_bus0_blocking_semaphore,
#if !defined(g_comms_i2c_bus0_recursive_mutex)
    .p_bus_recursive_mutex = &g_comms_i2c_bus0_recursive_mutex,
#else
    .p_bus_recursive_mutex = NULL,
#endif
#else
    .p_bus_recursive_mutex = NULL,
    .p_blocking_semaphore = NULL,
#endif
#else
#endif
        };
ether_phy_instance_ctrl_t g_ether_phy0_ctrl;

const ether_phy_cfg_t g_ether_phy0_cfg =
{

.channel = 0,
  .phy_lsi_address = 5, .phy_reset_wait_time = 0x00020000, .mii_bit_access_wait_time = 8, .phy_lsi_type =
          ETHER_PHY_LSI_TYPE_KIT_COMPONENT,
  .flow_control = ETHER_PHY_FLOW_CONTROL_DISABLE, .mii_type = ETHER_PHY_MII_TYPE_RMII, .p_context = NULL, .p_extend =
          NULL,

};
/* Instance structure to use this module. */
const ether_phy_instance_t g_ether_phy0 =
{ .p_ctrl = &g_ether_phy0_ctrl, .p_cfg = &g_ether_phy0_cfg, .p_api = &g_ether_phy_on_ether_phy };
ether_instance_ctrl_t g_ether0_ctrl;

uint8_t g_ether0_mac_address[6] =
{ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55 };

__attribute__((__aligned__(16))) ether_instance_descriptor_t g_ether0_tx_descriptors[4] ETHER_BUFFER_PLACE_IN_SECTION;
__attribute__((__aligned__(16))) ether_instance_descriptor_t g_ether0_rx_descriptors[4] ETHER_BUFFER_PLACE_IN_SECTION;

const ether_extended_cfg_t g_ether0_extended_cfg_t =
{ .p_rx_descriptors = g_ether0_rx_descriptors, .p_tx_descriptors = g_ether0_tx_descriptors, };

const ether_cfg_t g_ether0_cfg =
        { .channel = 0,
          .zerocopy = ETHER_ZEROCOPY_ENABLE,
          .multicast = ETHER_MULTICAST_ENABLE,
          .promiscuous = ETHER_PROMISCUOUS_DISABLE,
          .flow_control = ETHER_FLOW_CONTROL_DISABLE,
          .padding = ETHER_PADDING_2BYTE,
          .padding_offset = 14,
          .broadcast_filter = 0,
          .p_mac_address = g_ether0_mac_address,

          .num_tx_descriptors = 4,
          .num_rx_descriptors = 4,

          .pp_ether_buffers = NULL,

          .ether_buffer_size = 1536,

#if defined(VECTOR_NUMBER_EDMAC0_EINT)
                .irq                = VECTOR_NUMBER_EDMAC0_EINT,
#else
          .irq = FSP_INVALID_VECTOR,
#endif

          .interrupt_priority = (12),

          .p_callback = rm_netxduo_ether_callback,
          .p_ether_phy_instance = &g_ether_phy0,
          .p_context = &g_netxduo_ether_0_instance,
          .p_extend = &g_ether0_extended_cfg_t, };

/* Instance structure to use this module. */
const ether_instance_t g_ether0 =
{ .p_ctrl = &g_ether0_ctrl, .p_cfg = &g_ether0_cfg, .p_api = &g_ether_on_ether };
static NX_PACKET *g_netxduo_ether_0_tx_packets[4];
static NX_PACKET *g_netxduo_ether_0_rx_packets[4];

static rm_netxduo_ether_ctrl_t g_netxduo_ether_0_ctrl;
static rm_netxduo_ether_cfg_t g_netxduo_ether_0_cfg =
{ .p_ether_instance = &g_ether0, .mtu = 1500, .p_tx_packets = g_netxduo_ether_0_tx_packets, .p_rx_packets =
          g_netxduo_ether_0_rx_packets };

rm_netxduo_ether_instance_t g_netxduo_ether_0_instance =
{ .p_ctrl = &g_netxduo_ether_0_ctrl, .p_cfg = &g_netxduo_ether_0_cfg };

/*
 * NetX Duo Driver: g_netxduo_ether_0
 * Passes rm_netxduo_ether instance and driver request into the rm_netxduo_ether driver.
 */
void g_netxduo_ether_0(NX_IP_DRIVER *driver_req_ptr)
{
    rm_netxduo_ether (driver_req_ptr, &g_netxduo_ether_0_instance);
}
#ifndef NX_DISABLE_IPV6
NXD_ADDRESS g_ip0_ipv6_global_address =
{ .nxd_ip_version = NX_IP_VERSION_V6, .nxd_ip_address.v6 =
{ ((0x2001 << 16) | 0x0), ((0x0 << 16) | 0x0), ((0x0 << 16) | 0x0), ((0x0 << 16) | 0x1) } };

NXD_ADDRESS g_ip0_ipv6_link_local_address =
{ .nxd_ip_version = NX_IP_VERSION_V6, .nxd_ip_address.v6 =
{ ((0x0 << 16) | 0x0), ((0x0 << 16) | 0x0), ((0x0 << 16) | 0x0), ((0x0 << 16) | 0x0) } };

#endif
NX_AZURE_IOT nx_azure_iot;
icu_instance_ctrl_t g_sensorIRQ_ctrl;
const external_irq_cfg_t g_sensorIRQ_cfg =
{ .channel = 14,
  .trigger = EXTERNAL_IRQ_TRIG_FALLING,
  .filter_enable = false,
  .pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64,
  .p_callback = sensorOBIRQCallback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = NULL,
  .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ14)
    .irq                 = VECTOR_NUMBER_ICU_IRQ14,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const external_irq_instance_t g_sensorIRQ =
{ .p_ctrl = &g_sensorIRQ_ctrl, .p_cfg = &g_sensorIRQ_cfg, .p_api = &g_external_irq_on_icu };
ioport_instance_ctrl_t g_ioport_ctrl;
const ioport_instance_t g_ioport =
{ .p_api = &g_ioport_on_ioport, .p_ctrl = &g_ioport_ctrl, .p_cfg = &g_bsp_pin_cfg, };
TX_QUEUE g_topic_queue;
static uint8_t queue_memory_g_topic_queue[64];
void tx_startup_err_callback(void *p_instance, void *p_data);
TX_MUTEX consolprint_mutex;
void tx_startup_err_callback(void *p_instance, void *p_data);
void g_common_init(void)
{
    UINT err_g_topic_queue;
    err_g_topic_queue = tx_queue_create (&g_topic_queue, (CHAR*) "Topic Queue", 16, &queue_memory_g_topic_queue,
                                         sizeof(queue_memory_g_topic_queue));
    if (TX_SUCCESS != err_g_topic_queue)
    {
        tx_startup_err_callback (&g_topic_queue, 0);
    }
    UINT err_consolprint_mutex;
    err_consolprint_mutex = tx_mutex_create (&consolprint_mutex, (CHAR*) "consolprint_mutex", TX_NO_INHERIT);
    if (TX_SUCCESS != err_consolprint_mutex)
    {
        tx_startup_err_callback (&consolprint_mutex, 0);
    }
}
