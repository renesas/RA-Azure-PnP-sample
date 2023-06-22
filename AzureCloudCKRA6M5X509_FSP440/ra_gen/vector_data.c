/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = r_icu_isr, /* ICU IRQ14 (External pin interrupt 14) */
            [1] = gpt_counter_overflow_isr, /* GPT2 COUNTER OVERFLOW (Overflow) */
            [2] = gpt_counter_overflow_isr, /* GPT0 COUNTER OVERFLOW (Overflow) */
            [3] = ether_eint_isr, /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [4] = iic_master_rxi_isr, /* IIC0 RXI (Receive data full) */
            [5] = iic_master_txi_isr, /* IIC0 TXI (Transmit data empty) */
            [6] = iic_master_tei_isr, /* IIC0 TEI (Transmit end) */
            [7] = iic_master_eri_isr, /* IIC0 ERI (Transfer error) */
            [8] = r_icu_isr, /* ICU IRQ4 (External pin interrupt 4) */
            [9] = r_icu_isr, /* ICU IRQ15 (External pin interrupt 15) */
            [10] = sci_uart_rxi_isr, /* SCI5 RXI (Received data full) */
            [11] = sci_uart_txi_isr, /* SCI5 TXI (Transmit data empty) */
            [12] = sci_uart_tei_isr, /* SCI5 TEI (Transmit end) */
            [13] = sci_uart_eri_isr, /* SCI5 ERI (Receive error) */
            [14] = fcu_frdyi_isr, /* FCU FRDYI (Flash ready interrupt) */
            [15] = fcu_fiferr_isr, /* FCU FIFERR (Flash access error interrupt) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ14), /* ICU IRQ14 (External pin interrupt 14) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_GPT2_COUNTER_OVERFLOW), /* GPT2 COUNTER OVERFLOW (Overflow) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_GPT0_COUNTER_OVERFLOW), /* GPT0 COUNTER OVERFLOW (Overflow) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_EDMAC0_EINT), /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_IIC0_RXI), /* IIC0 RXI (Receive data full) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_IIC0_TXI), /* IIC0 TXI (Transmit data empty) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_IIC0_TEI), /* IIC0 TEI (Transmit end) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_IIC0_ERI), /* IIC0 ERI (Transfer error) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ4), /* ICU IRQ4 (External pin interrupt 4) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ15), /* ICU IRQ15 (External pin interrupt 15) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_SCI5_RXI), /* SCI5 RXI (Received data full) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_SCI5_TXI), /* SCI5 TXI (Transmit data empty) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_SCI5_TEI), /* SCI5 TEI (Transmit end) */
            [13] = BSP_PRV_IELS_ENUM(EVENT_SCI5_ERI), /* SCI5 ERI (Receive error) */
            [14] = BSP_PRV_IELS_ENUM(EVENT_FCU_FRDYI), /* FCU FRDYI (Flash ready interrupt) */
            [15] = BSP_PRV_IELS_ENUM(EVENT_FCU_FIFERR), /* FCU FIFERR (Flash access error interrupt) */
        };
        #endif
