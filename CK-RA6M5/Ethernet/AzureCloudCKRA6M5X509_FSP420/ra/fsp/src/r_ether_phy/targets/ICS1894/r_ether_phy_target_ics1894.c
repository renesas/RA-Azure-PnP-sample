/***********************************************************************************************************************
 * Copyright [2020-2023] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/

/* Access to peripherals and board defines. */
#include "bsp_api.h"
#include "r_ether_phy.h"

#if (ETHER_PHY_CFG_TARGET_ICS1894_ENABLE)

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/* Vendor Specific PHY Registers */
 #define ETHER_PHY_REG_PHY_CONTROL_20    (0x14)

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global function
 ***********************************************************************************************************************/
void ether_phy_target_ics1894_initialize(ether_phy_instance_ctrl_t * p_instance_ctrl);
bool ether_phy_target_ics1894_is_support_link_partner_ability(ether_phy_instance_ctrl_t * p_instance_ctrl,
                                                              uint32_t                    line_speed_duplex);
extern uint32_t ether_phy_read(ether_phy_instance_ctrl_t * p_instance_ctrl, uint32_t reg_addr);
extern void     ether_phy_write(ether_phy_instance_ctrl_t * p_instance_ctrl, uint32_t reg_addr, uint32_t data);

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Function Name: ether_phy_targets_initialize
 * Description  : PHY-LSI specific initialization processing
 * Arguments    : p_instance_ctrl -
 *                    Ethernet control block
 * Return Value : none
 ***********************************************************************************************************************/
void ether_phy_target_ics1894_initialize (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    uint32_t reg;

    /*
     * When ICS1894NL of the the Renesas Electronics Corporation. is used,
     * the pin that outputs the state of LINK is used combinedly with ACTIVITY in default.
     * The setting of the pin is changed so that only the state of LINK is output.
     */
    reg  = ether_phy_read(p_instance_ctrl, ETHER_PHY_REG_PHY_CONTROL_20);
    reg |= 0x0007U;
    ether_phy_write(p_instance_ctrl, ETHER_PHY_REG_PHY_CONTROL_20, reg);
}                                      /* End of function ether_phy_targets_initialize() */

/***********************************************************************************************************************
 * Function Name: ether_phy_targets_is_support_link_partner_ability
 * Description  : Check if the PHY-LSI connected Ethernet controller supports link ability
 * Arguments    : p_instance_ctrl -
 *                    Ethernet control block
 *                line_speed_duplex -
 *                    Line speed duplex of link partner PHY-LSI
 * Return Value : bool
 ***********************************************************************************************************************/
bool ether_phy_target_ics1894_is_support_link_partner_ability (ether_phy_instance_ctrl_t * p_instance_ctrl,
                                                               uint32_t                    line_speed_duplex)
{
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    bool ret = false;

    /* This PHY-LSI only supports full duplex mode. */
    switch (line_speed_duplex)
    {
        /* 10Mbps full duplex */
        case ETHER_PHY_LINK_SPEED_10F:
        {
            ret = true;
            break;
        }

        /* 100Mbps full duplex */
        case ETHER_PHY_LINK_SPEED_100F:
        {
            ret = true;
            break;
        }

        /* Half duplex is not supported */
        default:
        {
            break;
        }
    }

    return ret;
}                                      /* End of function ether_phy_targets_is_support_link_partner_ability() */

#endif /* ETHER_PHY_CFG_TARGET_ICS1894_ENABLE */
