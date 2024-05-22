/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
//#include "peripheral/ports/plib_ports.h"
//#include "peripheral/tmr/plib_tmr.h"


#ifndef _BSP_CONFIG_H
#define _BSP_CONFIG_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
/* Oscillator Frequency

  Summary:
    Defines frequency value of crystal/oscillator used on the board

  Description:
    Defines frequency value of crystal/oscillator used on the board
*/

#define BSP_OSC_FREQUENCY 8000000      // 8 MHz

// Ajout définition direct des E/S du Kit 32MX795F512L
// ===================================================

/*--------------------------------------------------------*/
// Touches
/*--------------------------------------------------------*/
// Definitions directes
#define S_SW1         PORTDbits.RD10
#define S_SW2         PORTDbits.RD9
#define S_SW3         PORTDbits.RD8
#define S_SW4         PORTDbits.RD0

//Definitions pour fonctions PLIB_PORTS 
#define S_SW1_PORT         PORT_CHANNEL_D
#define S_SW1_BIT          PORT_BIT_POS_10
#define S_SW2_PORT         PORT_CHANNEL_D
#define S_SW2_BIT          PORT_BIT_POS_9
#define S_SW3_PORT         PORT_CHANNEL_D
#define S_SW3_BIT          PORT_BIT_POS_8
#define S_SW4_MENU_PORT    PORT_CHANNEL_D
#define S_SW4_BIT          PORT_BIT_POS_0


// Definitions dans le fichier XML (bsp.xml)
// <function name="SW_1" pin="RD10" mode="digital" pullup="true"/>
// <function name="SW_2" pin="RD9" mode="digital" pullup="true"/>
// <function name="SW_3" pin="RD8" mode="digital" pullup="true"/>
// <function name="SW_4" pin="RD0" mode="digital" pullup="true"/>

/*--------------------------------------------------------*/
// Ethernet
/*--------------------------------------------------------*/
// Uniquement pour info
//PORT B 
#define ETH_MDC             PORTBbits.RB15
//PORT D 
#define ETH_MDIO            PORTDbits.RD1
#define ETH_POWERDOWN_INT   PORTDbits.RD11
//PORT E 
#define ETH_RX_D1           PORTEbits.RE0
#define ETH_RX_D0           PORTEbits.RE1
#define ETH_CRS_DV          PORTEbits.RE2
#define ETH_REF_CLK         PORTEbits.RE3
#define ETH_RX_ER           PORTEbits.RE4
#define ETH_TX_EN           PORTEbits.RE5
#define ETH_TX_D0           PORTEbits.RE6
#define ETH_TX_D1           PORTEbits.RE7

/*--------------------------------------------------------*/
// LCD
/*--------------------------------------------------------*/
//On écrit dans le latch pour éviter les problèmes de R/W
#define LCD_RS_W       LATBbits.LATB2
#define LCD_RW_W       LATBbits.LATB3
#define LCD_E_W        LATBbits.LATB4
#define LCD_BL_W       LATBbits.LATB9
#define LCD_DB4_W      LATBbits.LATB5
#define LCD_DB5_W      LATBbits.LATB6
#define LCD_DB6_W      LATBbits.LATB7
#define LCD_DB7_W      LATBbits.LATB8

//On lit directement sur le port, sinon on obtient la valeur
//précédemment écrite dans le latch!!
#define LCD_RS_R       PORTBbits.RB2
#define LCD_RW_R       PORTBbits.RB3
#define LCD_E_R        PORTBbits.RB4
#define LCD_BL_R       PORTBbits.RB9
#define LCD_DB4_R      PORTBbits.RB5
#define LCD_DB5_R      PORTBbits.RB6
#define LCD_DB6_R      PORTBbits.RB7
#define LCD_DB7_R      PORTBbits.RB8

#define LCD_RS_T     TRISBbits.TRISB2
#define LCD_RW_T     TRISBbits.TRISB3
#define LCD_E_T      TRISBbits.TRISB4
#define LCD_BL_T     TRISBbits.TRISB9
#define LCD_DB4_T    TRISBbits.TRISB5
#define LCD_DB5_T    TRISBbits.TRISB6
#define LCD_DB6_T    TRISBbits.TRISB7
#define LCD_DB7_T    TRISBbits.TRISB8

// Definitions pour fonctions PLIB_PORTS
#define LCD_RS_PORT   PORT_CHANNEL_B
#define LCD_RS_BIT    PORTS_BIT_POS_2
#define LCD_RW_PORT   PORT_CHANNEL_B
#define LCD_RW_BIT    PORTS_BIT_POS_3
#define LCD_E_PORT    PORT_CHANNEL_B
#define LCD_E_BIT     PORTS_BIT_POS_4
#define LCD_BL_PORT   PORT_CHANNEL_B
#define LCD_BL_BIT    PORTS_BIT_POS_9
#define LCD_DB4_PORT   PORT_CHANNEL_B
#define LCD_DB4_BIT    PORTS_BIT_POS_5
#define LCD_DB5_PORT   PORT_CHANNEL_B
#define LCD_DB5_BIT    PORTS_BIT_POS_6
#define LCD_DB6_PORT   PORT_CHANNEL_B
#define LCD_DB6_BIT    PORTS_BIT_POS_7
#define LCD_DB7_PORT   PORT_CHANNEL_B
#define LCD_DB7_BIT    PORTS_BIT_POS_8

// Definitions dans le fichier XML (bsp.xml)
// <function name="LCD_RS" pin="RB2" mode="digital" direction="out"/>
// <function name="LCD_RW" pin="RB3" mode="digital" direction="out"/>
// <function name="LCD_E" pin="RB4" mode="digital" direction="out"/>
// <function name="LCD_BL" pin="RB9" mode="digital" direction="out"/ latch="low">
// <function name="LCD_DB4" pin="RB5" mode="digital" direction="out" latch="high"/>
// <function name="LCD_DB5" pin="RB6" mode="digital" direction="out" latch="high"/>
// <function name="LCD_DB6" pin="RB7" mode="digital" direction="out" latch="high"/>
// <function name="LCD_DB7" pin="RB8" mode="digital" direction="out" latch="high"/>


/*--------------------------------------------------------*/
// Signal DCF 
/*--------------------------------------------------------*/
#define P_DCF           PORTDbits.RD2
#define P_DCF_W         LATDbits.LATD2
#define P_DCF_R         PORTDbits.RD2

/*--------------------------------------------------------*/
// Analog Switch 
/*--------------------------------------------------------*/
#define CMD_SW          PORTDbits.RD3
#define CMD_SW_W        LATDbits.LATD3
#define CMD_SW_R        PORTDbits.RD3

#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
