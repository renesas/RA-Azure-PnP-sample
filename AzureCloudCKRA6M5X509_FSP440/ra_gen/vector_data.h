/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (16)
#endif
/* ISR prototypes */
void r_icu_isr(void);
void gpt_counter_overflow_isr(void);
void ether_eint_isr(void);
void iic_master_rxi_isr(void);
void iic_master_txi_isr(void);
void iic_master_tei_isr(void);
void iic_master_eri_isr(void);
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void fcu_frdyi_isr(void);
void fcu_fiferr_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_ICU_IRQ14 ((IRQn_Type) 0) /* ICU IRQ14 (External pin interrupt 14) */
#define ICU_IRQ14_IRQn          ((IRQn_Type) 0) /* ICU IRQ14 (External pin interrupt 14) */
#define VECTOR_NUMBER_GPT2_COUNTER_OVERFLOW ((IRQn_Type) 1) /* GPT2 COUNTER OVERFLOW (Overflow) */
#define GPT2_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 1) /* GPT2 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW ((IRQn_Type) 2) /* GPT0 COUNTER OVERFLOW (Overflow) */
#define GPT0_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 2) /* GPT0 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_EDMAC0_EINT ((IRQn_Type) 3) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define EDMAC0_EINT_IRQn          ((IRQn_Type) 3) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define VECTOR_NUMBER_IIC0_RXI ((IRQn_Type) 4) /* IIC0 RXI (Receive data full) */
#define IIC0_RXI_IRQn          ((IRQn_Type) 4) /* IIC0 RXI (Receive data full) */
#define VECTOR_NUMBER_IIC0_TXI ((IRQn_Type) 5) /* IIC0 TXI (Transmit data empty) */
#define IIC0_TXI_IRQn          ((IRQn_Type) 5) /* IIC0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_IIC0_TEI ((IRQn_Type) 6) /* IIC0 TEI (Transmit end) */
#define IIC0_TEI_IRQn          ((IRQn_Type) 6) /* IIC0 TEI (Transmit end) */
#define VECTOR_NUMBER_IIC0_ERI ((IRQn_Type) 7) /* IIC0 ERI (Transfer error) */
#define IIC0_ERI_IRQn          ((IRQn_Type) 7) /* IIC0 ERI (Transfer error) */
#define VECTOR_NUMBER_ICU_IRQ4 ((IRQn_Type) 8) /* ICU IRQ4 (External pin interrupt 4) */
#define ICU_IRQ4_IRQn          ((IRQn_Type) 8) /* ICU IRQ4 (External pin interrupt 4) */
#define VECTOR_NUMBER_ICU_IRQ15 ((IRQn_Type) 9) /* ICU IRQ15 (External pin interrupt 15) */
#define ICU_IRQ15_IRQn          ((IRQn_Type) 9) /* ICU IRQ15 (External pin interrupt 15) */
#define VECTOR_NUMBER_SCI5_RXI ((IRQn_Type) 10) /* SCI5 RXI (Received data full) */
#define SCI5_RXI_IRQn          ((IRQn_Type) 10) /* SCI5 RXI (Received data full) */
#define VECTOR_NUMBER_SCI5_TXI ((IRQn_Type) 11) /* SCI5 TXI (Transmit data empty) */
#define SCI5_TXI_IRQn          ((IRQn_Type) 11) /* SCI5 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI5_TEI ((IRQn_Type) 12) /* SCI5 TEI (Transmit end) */
#define SCI5_TEI_IRQn          ((IRQn_Type) 12) /* SCI5 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI5_ERI ((IRQn_Type) 13) /* SCI5 ERI (Receive error) */
#define SCI5_ERI_IRQn          ((IRQn_Type) 13) /* SCI5 ERI (Receive error) */
#define VECTOR_NUMBER_FCU_FRDYI ((IRQn_Type) 14) /* FCU FRDYI (Flash ready interrupt) */
#define FCU_FRDYI_IRQn          ((IRQn_Type) 14) /* FCU FRDYI (Flash ready interrupt) */
#define VECTOR_NUMBER_FCU_FIFERR ((IRQn_Type) 15) /* FCU FIFERR (Flash access error interrupt) */
#define FCU_FIFERR_IRQn          ((IRQn_Type) 15) /* FCU FIFERR (Flash access error interrupt) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
