/********************************************************************/
/*  <Define rule I> set or clr _ regsiter name _ register bit name  */
/********************************************************************/
/******************************************************************************/
/*                         Keil C51 include files                            */
/******************************************************************************/
// msr - Commented out header files we are not using.
#include <intrins.h>
//#include <stdio.h>
//#include <absacc.h>
//#include <string.h>

/******************************************************************************/
/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/

#include "ML56_XSFR.h"
#include "Function_define_ML56.h"

// msr - Commented out header files we are not using.
//#include "acmp.h"
//#include "adc.h"
//#include "capture.h"
//#include "delay.h"
//#include "eeprom.h"
//#include "eeprom_sprom.h"
//#include "exint.h"
#include "gpio.h"
//#include "i2c.h"
//#include "IAP.h"
//#include "IAP_sprom.h"
//#include "isp_uart0.h"
//#include "isp_uart1.h"
//#include "lowpower.h"
//#include "pdma.h"
//#include "pinint.h"
//#include "power.h"
//#include "pwm0.h"
//#include "rtc.h"
//#include "spi0.h"
#include "sys.h"
//#include "TrimLIRC.h"
//#include "uart.h"
//#include "uart2.h"
//#include "uart3.h"
//#include "vref.h"
//#include "wdt.h"
//#include "wkt.h"
//#include "rtc.h"
//#include "tk.h"

/********SFR ALL PAGES*************/
/**** PCON  87H  PAGE A ****/
#define set_PCON_SMOD                    PCON|=SET_BIT7
#define set_PCON_SMOD0                   PCON|=SET_BIT6
#define set_PCON_LPR                     PCON|=SET_BIT5
#define set_PCON_POF                     PCON|=SET_BIT4
#define set_PCON_GF1                     PCON|=SET_BIT3
#define set_PCON_GF0                     PCON|=SET_BIT2//@
#define set_PCON_PD                      PCON|=SET_BIT1
#define set_PCON_IDL                     PCON|=SET_BIT0

#define clr_PCON_SMOD                    PCON&=CLR_BIT7
#define clr_PCON_SMOD0                   PCON&=CLR_BIT6
#define clr_PCON_LPR                     PCON&=CLR_BIT5
#define clr_PCON_POF                     PCON&=CLR_BIT4
#define clr_PCON_GF1                     PCON&=CLR_BIT3
#define clr_PCON_GF0                     PCON&=CLR_BIT2
#define clr_PCON_PD                      PCON&=CLR_BIT1
#define clr_PCON_IDL                     PCON&=CLR_BIT0

/**** TCON  88H  PAGE A ****/
#define set_TCON_TF1                     TCON|=SET_BIT7
#define set_TCON_TR1                     TCON|=SET_BIT6
#define set_TCON_TF0                     TCON|=SET_BIT5
#define set_TCON_TR0                     TCON|=SET_BIT4
#define set_TCON_IE1                     TCON|=SET_BIT3//@
#define set_TCON_IT1                     TCON|=SET_BIT2
#define set_TCON_IE0                     TCON|=SET_BIT1
#define set_TCON_IT0                     TCON|=SET_BIT0

#define clr_TCON_TF1                     TCON&=CLR_BIT7
#define clr_TCON_TR1                     TCON&=CLR_BIT6
#define clr_TCON_TF0                     TCON&=CLR_BIT5
#define clr_TCON_TR0                     TCON&=CLR_BIT4
#define clr_TCON_IE1                     TCON&=CLR_BIT3
#define clr_TCON_IT1                     TCON&=CLR_BIT2
#define clr_TCON_IE0                     TCON&=CLR_BIT1
#define clr_TCON_IT0                     TCON&=CLR_BIT0

/**** TMOD  89H  PAGE A ****/
#define set_T1MOD_GATE                    TMOD|=SET_BIT7
#define set_T1MOD_C_T                     TMOD|=SET_BIT6
#define set_T1MOD_M1                      TMOD|=SET_BIT5
#define set_T1MOD_M0                      TMOD|=SET_BIT4
#define set_T0MOD_GATE                    TMOD|=SET_BIT3//@
#define set_T0MOD_C_T                     TMOD|=SET_BIT2//@
#define set_T0MOD_M1                      TMOD|=SET_BIT1
#define set_T0MOD_M0                      TMOD|=SET_BIT0

#define clr_T1MOD_GATE                    TMOD&=CLR_BIT7
#define clr_T1MOD_C_T                     TMOD&=CLR_BIT6
#define clr_T1MOD_M1                      TMOD&=CLR_BIT5
#define clr_T1MOD_M0                      TMOD&=CLR_BIT4
#define clr_T0MOD_GATE                    TMOD&=CLR_BIT3
#define clr_T0MOD_C_T                     TMOD&=CLR_BIT2
#define clr_T0MOD_M1                      TMOD&=CLR_BIT1
#define clr_T0MOD_M0                      TMOD&=CLR_BIT0

/**** P1  90H  PAGE A ****/
#define set_P1_7                         P1|=SET_BIT7
#define set_P1_6                         P1|=SET_BIT6
#define set_P1_5                         P1|=SET_BIT5
#define set_P1_4                         P1|=SET_BIT4
#define set_P1_3                         P1|=SET_BIT3//@
#define set_P1_2                         P1|=SET_BIT2//@
#define set_P1_1                         P1|=SET_BIT1
#define set_P1_0                         P1|=SET_BIT0

#define clr_P1_7                         P1&=CLR_BIT7
#define clr_P1_6                         P1&=CLR_BIT6
#define clr_P1_5                         P1&=CLR_BIT5
#define clr_P1_4                         P1&=CLR_BIT4
#define clr_P1_3                         P1&=CLR_BIT3
#define clr_P1_2                         P1&=CLR_BIT2
#define clr_P1_1                         P1&=CLR_BIT1
#define clr_P1_0                         P1&=CLR_BIT0

/**** SCON  98H  PAGE A ****/
#define set_SCON_SM0                     SCON|=SET_BIT7
#define set_SCON_FE                      SCON|=SET_BIT7
#define set_SCON_SM1                     SCON|=SET_BIT6
#define set_SCON_SM2                     SCON|=SET_BIT5
#define set_SCON_REN                     SCON|=SET_BIT4
#define set_SCON_TB8                     SCON|=SET_BIT3//@
#define set_SCON_RB8                     SCON|=SET_BIT2//@
#define set_SCON_TI                      SCON|=SET_BIT1
#define set_SCON_RI                      SCON|=SET_BIT0

#define clr_SCON_SM0                     SCON&=CLR_BIT7
#define clr_SCON_FE                      SCON&=CLR_BIT7
#define clr_SCON_SM1                     SCON&=CLR_BIT6
#define clr_SCON_SM2                     SCON&=CLR_BIT5
#define clr_SCON_REN                     SCON&=CLR_BIT4
#define clr_SCON_TB8                     SCON&=CLR_BIT3
#define clr_SCON_RB8                     SCON&=CLR_BIT2
#define clr_SCON_TI                      SCON&=CLR_BIT1
#define clr_SCON_RI                      SCON&=CLR_BIT0

/**** P2  A0H  PAGE A ****/
#define set_P2_7                         P2|=SET_BIT7
#define set_P2_6                         P2|=SET_BIT6
#define set_P2_5                         P2|=SET_BIT5
#define set_P2_4                         P2|=SET_BIT4
#define set_P2_3                         P2|=SET_BIT3//@
#define set_P2_2                         P2|=SET_BIT2//@
#define set_P2_1                         P2|=SET_BIT1
#define set_P2_0                         P2|=SET_BIT0

#define clr_P2_7                         P2&=CLR_BIT7
#define clr_P2_6                         P2&=CLR_BIT6
#define clr_P2_5                         P2&=CLR_BIT5
#define clr_P2_4                         P2&=CLR_BIT4
#define clr_P2_3                         P2&=CLR_BIT3
#define clr_P2_2                         P2&=CLR_BIT2
#define clr_P2_1                         P2&=CLR_BIT1
#define clr_P2_0                         P2&=CLR_BIT0

/**** IE  A8H  PAGE A ****/
#define set_IE_EA                        IE|=SET_BIT7
#define set_IE_EADC                      IE|=SET_BIT6
#define set_IE_EBOD                      IE|=SET_BIT5
#define set_IE_ES                        IE|=SET_BIT4
#define set_IE_ET1                       IE|=SET_BIT3//@
#define set_IE_EX1                       IE|=SET_BIT2//@
#define set_IE_ET0                       IE|=SET_BIT1
#define set_IE_EX0                       IE|=SET_BIT0

#define clr_IE_EA                        IE&=CLR_BIT7
#define clr_IE_EADC                      IE&=CLR_BIT6
#define clr_IE_EBOD                      IE&=CLR_BIT5
#define clr_IE_ES                        IE&=CLR_BIT4
#define clr_IE_ET1                       IE&=CLR_BIT3
#define clr_IE_EX1                       IE&=CLR_BIT2
#define clr_IE_ET0                       IE&=CLR_BIT1
#define clr_IE_EX0                       IE&=CLR_BIT0

/**** P3  B0H  PAGE A ****/
#define set_P3_7                         P3|=SET_BIT7
#define set_P3_6                         P3|=SET_BIT6
#define set_P3_5                         P3|=SET_BIT5
#define set_P3_4                         P3|=SET_BIT4
#define set_P3_3                         P3|=SET_BIT3//@
#define set_P3_2                         P3|=SET_BIT2//@
#define set_P3_1                         P3|=SET_BIT1
#define set_P3_0                         P3|=SET_BIT0

#define clr_P3_7                         P3&=CLR_BIT7
#define clr_P3_6                         P3&=CLR_BIT6
#define clr_P3_5                         P3&=CLR_BIT5
#define clr_P3_4                         P3&=CLR_BIT4
#define clr_P3_3                         P3&=CLR_BIT3
#define clr_P3_2                         P3&=CLR_BIT2
#define clr_P3_1                         P3&=CLR_BIT1
#define clr_P3_0                         P3&=CLR_BIT0

/**** IP  B8H  PAGE A ****/
#define set_IP_PADC                      IP|=SET_BIT6
#define set_IP_PBOD                      IP|=SET_BIT5
#define set_IP_PS                        IP|=SET_BIT4
#define set_IP_PT1                       IP|=SET_BIT3//@
#define set_IP_PX1                       IP|=SET_BIT2//@
#define set_IP_PT0                       IP|=SET_BIT1
#define set_IP_PX0                       IP|=SET_BIT0

#define clr_IP_PADC                      IP&=CLR_BIT6
#define clr_IP_PBOD                      IP&=CLR_BIT5
#define clr_IP_PS                        IP&=CLR_BIT4
#define clr_IP_PT1                       IP&=CLR_BIT3
#define clr_IP_PX1                       IP&=CLR_BIT2
#define clr_IP_PT0                       IP&=CLR_BIT1
#define clr_IP_PX0                       IP&=CLR_BIT0

/**** I2C0CON  C0H  PAGE A ****/
#define set_I2C0CON_I                      I2C0CON|=SET_BIT7
#define set_I2C0CON_I2CEN                  I2C0CON|=SET_BIT6
#define set_I2C0CON_STA                    I2C0CON|=SET_BIT5
#define set_I2C0CON_STO                    I2C0CON|=SET_BIT4
#define set_I2C0CON_SI                     I2C0CON|=SET_BIT3
#define set_I2C0CON_AA                     I2C0CON|=SET_BIT2


#define clr_I2C0CON_I                       I2C0CON&=CLR_BIT7
#define clr_I2C0CON_I2CEN                  I2C0CON&=CLR_BIT6
#define clr_I2C0CON_STA                    I2C0CON&=CLR_BIT5
#define clr_I2C0CON_STO                    I2C0CON&=CLR_BIT4
#define clr_I2C0CON_SI                     I2C0CON&=CLR_BIT3
#define clr_I2C0CON_AA                     I2C0CON&=CLR_BIT2


/**** T2CON  C8H  PAGE A ****/
#define set_T2CON_TF2                    T2CON|=SET_BIT7
#define set_T2CON_TR2                    T2CON|=SET_BIT2//@
#define set_T2CON_CMRL2                  T2CON|=SET_BIT0

#define clr_T2CON_TF2                    T2CON&=CLR_BIT7
#define clr_T2CON_TR2                    T2CON&=CLR_BIT2
#define clr_T2CON_CMRL2                  T2CON&=CLR_BIT0

/**** PSW  D0H  PAGE A ****/
#define set_PSW_CY                       PSW|=SET_BIT7
#define set_PSW_AC                       PSW|=SET_BIT6
#define set_PSW_F0                       PSW|=SET_BIT5
#define set_PSW_RS1                      PSW|=SET_BIT4
#define set_PSW_RS0                      PSW|=SET_BIT3//@
#define set_PSW_OV                       PSW|=SET_BIT2//@
#define set_PSW_F1                       PSW|=SET_BIT1//@

#define clr_PSW_CY                       PSW&=CLR_BIT7
#define clr_PSW_AC                       PSW&=CLR_BIT6
#define clr_PSW_F0                       PSW&=CLR_BIT5
#define clr_PSW_RS1                      PSW&=CLR_BIT4
#define clr_PSW_RS0                      PSW&=CLR_BIT3
#define clr_PSW_OV                       PSW&=CLR_BIT2
#define clr_PSW_F1                       PSW&=CLR_BIT1//@

/**** P4  D8H  PAGE A ****/
#define set_P4_7                         P4|=SET_BIT7
#define set_P4_6                         P4|=SET_BIT6
#define set_P4_5                         P4|=SET_BIT5
#define set_P4_4                         P4|=SET_BIT4
#define set_P4_3                         P4|=SET_BIT3//@
#define set_P4_2                         P4|=SET_BIT2//@
#define set_P4_1                         P4|=SET_BIT1
#define set_P4_0                         P4|=SET_BIT0

#define clr_P4_7                         P4&=CLR_BIT7
#define clr_P4_6                         P4&=CLR_BIT6
#define clr_P4_5                         P4&=CLR_BIT5
#define clr_P4_4                         P4&=CLR_BIT4
#define clr_P4_3                         P4&=CLR_BIT3
#define clr_P4_2                         P4&=CLR_BIT2
#define clr_P4_1                         P4&=CLR_BIT1
#define clr_P4_0                         P4&=CLR_BIT0

/**** ACC  E0H  PAGE A ****/
#define set_ACC_7                        ACC|=SET_BIT7
#define set_ACC_6                        ACC|=SET_BIT6
#define set_ACC_5                        ACC|=SET_BIT5
#define set_ACC_4                        ACC|=SET_BIT4
#define set_ACC_3                        ACC|=SET_BIT3//@
#define set_ACC_2                        ACC|=SET_BIT2//@
#define set_ACC_1                        ACC|=SET_BIT1
#define set_ACC_0                        ACC|=SET_BIT0

#define clr_ACC_7                        ACC&=CLR_BIT7
#define clr_ACC_6                        ACC&=CLR_BIT6
#define clr_ACC_5                        ACC&=CLR_BIT5
#define clr_ACC_4                        ACC&=CLR_BIT4
#define clr_ACC_3                        ACC&=CLR_BIT3
#define clr_ACC_2                        ACC&=CLR_BIT2
#define clr_ACC_1                        ACC&=CLR_BIT1
#define clr_ACC_0                        ACC&=CLR_BIT0

/**** I2C1CON  E8H  PAGE A ****/
#define set_I2C1CON_I                    I2C1CON|=SET_BIT7
#define set_I2C1CON_I2CEN                I2C1CON|=SET_BIT6
#define set_I2C1CON_STA                  I2C1CON|=SET_BIT5
#define set_I2C1CON_STO                  I2C1CON|=SET_BIT4
#define set_I2C1CON_SI                   I2C1CON|=SET_BIT3//@
#define set_I2C1CON_AA                   I2C1CON|=SET_BIT2//@

#define clr_I2C1CON_I                    I2C1CON&=CLR_BIT7
#define clr_I2C1CON_I2CEN                I2C1CON&=CLR_BIT6
#define clr_I2C1CON_STA                  I2C1CON&=CLR_BIT5
#define clr_I2C1CON_STO                  I2C1CON&=CLR_BIT4
#define clr_I2C1CON_SI                   I2C1CON&=CLR_BIT3
#define clr_I2C1CON_AA                   I2C1CON&=CLR_BIT2


#define set_S1CON_SM0_1                  S1CON|=SET_BIT7
#define set_S1CON_FE_1                   S1CON|=SET_BIT7
#define set_S1CON_SM1_1                  S1CON|=SET_BIT6
#define set_S1CON_SM2_1                  S1CON|=SET_BIT5
#define set_S1CON_REN_1                  S1CON|=SET_BIT4
#define set_S1CON_TB8_1                  S1CON|=SET_BIT3//@
#define set_S1CON_RB8_1                  S1CON|=SET_BIT2//@
#define set_S1CON_TI_1                   S1CON|=SET_BIT1
#define set_S1CON_RI_1                   S1CON|=SET_BIT0

#define clr_S1CON_SM0_1                  S1CON&=CLR_BIT7
#define clr_S1CON_FE_1                   S1CON&=CLR_BIT7
#define clr_S1CON_SM1_1                  S1CON&=CLR_BIT6
#define clr_S1CON_SM2_1                  S1CON&=CLR_BIT5
#define clr_S1CON_REN_1                  S1CON&=CLR_BIT4
#define clr_S1CON_TB8_1                  S1CON&=CLR_BIT3
#define clr_S1CON_RB8_1                  S1CON&=CLR_BIT2
#define clr_S1CON_TI_1                   S1CON&=CLR_BIT1
#define clr_S1CON_RI_1                   S1CON&=CLR_BIT0

/********SFR PAGE0*************/
/**** RCTRIM1  84H  PAGE0 TA protect register ****/
/**** RCTRIM1  85H  PAGE0 TA protect register ****/
/**** RWKL   86H  PAGE0  ****/
/**** TL0   8AH  PAGE0  ****/
/**** TL1   8BH  PAGE0  ****/
/**** TH0   8CH  PAGE0  ****/
/**** TH1   8DH  PAGE0  ****/

/**** CKCON  8EH  PAGE0 ****/
#define set_CKCON_FASTWK                 SFRS=0;CKCON|=SET_BIT7
#define set_CKCON_PWMCKS                 SFRS=0;CKCON|=SET_BIT6
#define set_CKCON_T1OE                   SFRS=0;CKCON|=SET_BIT5
#define set_CKCON_T1M                    SFRS=0;CKCON|=SET_BIT4
#define set_CKCON_T0M                    SFRS=0;CKCON|=SET_BIT3//
#define set_CKCON_T0OE                   SFRS=0;CKCON|=SET_BIT2//@
#define set_CKCON_CLOEN                  SFRS=0;CKCON|=SET_BIT1

#define clr_CKCON_FASTWK                 SFRS=0;CKCON&=CLR_BIT7
#define clr_CKCON_PWMCKS                 SFRS=0;CKCON&=CLR_BIT6
#define clr_CKCON_T1OE                   SFRS=0;CKCON&=CLR_BIT5
#define clr_CKCON_T1M                    SFRS=0;CKCON&=CLR_BIT4
#define clr_CKCON_T0M                    SFRS=0;CKCON&=CLR_BIT3
#define clr_CKCON_T0OE                   SFRS=0;CKCON&=CLR_BIT2
#define clr_CKCON_CLOEN                  SFRS=0;CKCON&=CLR_BIT1

/**** WKCON  8FH  PAGE0 ****/
#define set_WKCON_WKTCK                  SFRS=0;WKCON|=SET_BIT5//@
#define set_WKCON_WKTF                   SFRS=0;WKCON|=SET_BIT4
#define set_WKCON_WKTR                   SFRS=0;WKCON|=SET_BIT3//@
#define set_WKCON_WKPS_2                 SFRS=0;WKCON|=SET_BIT2//@
#define set_WKCON_WKPS_1                 SFRS=0;WKCON|=SET_BIT1
#define set_WKCON_WKPS_0                 SFRS=0;WKCON|=SET_BIT0

#define clr_WKCON_WKTCK                  SFRS=0;WKCON&=CLR_BIT5//@
#define clr_WKCON_WKTF                   SFRS=0;WKCON&=CLR_BIT4
#define clr_WKCON_WKTR                   SFRS=0;WKCON&=CLR_BIT3
#define clr_WKCON_WKPS_2                 SFRS=0;WKCON&=CLR_BIT2
#define clr_WKCON_WKPS_1                 SFRS=0;WKCON&=CLR_BIT1
#define clr_WKCON_WKPS_0                 SFRS=0;WKCON&=CLR_BIT0

/**** DMA0CR  92H  PAGE0 ****/
#define set_DMA0CR_PSSEL_3               SFRS=0;DMA0CR|=SET_BIT7
#define set_DMA0CR_PSSEL_2               SFRS=0;DMA0CR|=SET_BIT6
#define set_DMA0CR_PSSEL_1               SFRS=0;DMA0CR|=SET_BIT5
#define set_DMA0CR_PSSEL_0               SFRS=0;DMA0CR|=SET_BIT4
#define set_DMA0CR_HIE                   SFRS=0;DMA0CR|=SET_BIT3//@
#define set_DMA0CR_FIE                   SFRS=0;DMA0CR|=SET_BIT2//@
#define set_DMA0CR_RUN                   SFRS=0;DMA0CR|=SET_BIT1
#define set_DMA0CR_EN                    SFRS=0;DMA0CR|=SET_BIT0

#define clr_DMA0CR_PSSEL_3               SFRS=0;DMA0CR&=CLR_BIT7
#define clr_DMA0CR_PSSEL_2               SFRS=0;DMA0CR&=CLR_BIT6
#define clr_DMA0CR_PSSEL_1               SFRS=0;DMA0CR&=CLR_BIT5
#define clr_DMA0CR_PSSEL_0               SFRS=0;DMA0CR&=CLR_BIT4
#define clr_DMA0CR_HIE                   SFRS=0;DMA0CR&=CLR_BIT3
#define clr_DMA0CR_FIE                   SFRS=0;DMA0CR&=CLR_BIT2
#define clr_DMA0CR_RUN                   SFRS=0;DMA0CR&=CLR_BIT1
#define clr_DMA0CR_EN                    SFRS=0;DMA0CR&=CLR_BIT0

/**** DMA0MA   93H  PAGE0 ****/
/**** DMA0CNT   94H  PAGE0 ****/
/**** DMA0CCNT   95H  PAGE0 ****/

/**** CKSWT  96H  PAGE0 ****/
#define set_CKSWT_HXTST                  SFRS=0;CKSWT|=SET_BIT7
#define set_CKSWT_LXTST                  SFRS=0;CKSWT|=SET_BIT6
#define set_CKSWT_HIRCST                 SFRS=0;CKSWT|=SET_BIT5
#define set_CKSWT_LIRCST                 SFRS=0;CKSWT|=SET_BIT4
#define set_CKSWT_ECLKST                 SFRS=0;CKSWT|=SET_BIT3//@
#define set_CKSWT_OSC_2                  SFRS=0;CKSWT|=SET_BIT2//@
#define set_CKSWT_OSC_1                  SFRS=0;CKSWT|=SET_BIT1
#define set_CKSWT_OSC_0                  SFRS=0;CKSWT|=SET_BIT0

#define clr_CKSWT_HXTST                  SFRS=0;CKSWT&=CLR_BIT7
#define clr_CKSWT_LXTST                  SFRS=0;CKSWT&=CLR_BIT6
#define clr_CKSWT_HIRCST                 SFRS=0;CKSWT&=CLR_BIT5
#define clr_CKSWT_LIRCST                 SFRS=0;CKSWT&=CLR_BIT4
#define clr_CKSWT_ECLKST                 SFRS=0;CKSWT&=CLR_BIT3
#define clr_CKSWT_OSC_2                  SFRS=0;CKSWT&=CLR_BIT2
#define clr_CKSWT_OSC_1                  SFRS=0;CKSWT&=CLR_BIT1
#define clr_CKSWT_OSC_0                  SFRS=0;CKSWT&=CLR_BIT0

/**** CKEN  97H  PAGE0 TA protect register ****/
#define set_CKEN_EHXTEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT7;EA=BIT_TMP
#define set_CKEN_ELXTEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT6;EA=BIT_TMP
#define set_CKEN_HIRCEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT5;EA=BIT_TMP
#define set_CKEN_LIRCEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT4;EA=BIT_TMP
#define set_CKEN_ECLKEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT4;EA=BIT_TMP
#define set_CKEN_CKSWTF                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN|=SET_BIT0;EA=BIT_TMP
                                        
#define clr_CKEN_EHXTEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=CLR_BIT7;EA=BIT_TMP
#define clr_CKEN_ELXTEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=CLR_BIT6;EA=BIT_TMP
#define clr_CKEN_HIRCEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=CLR_BIT5;EA=BIT_TMP
#define clr_CKEN_LIRCEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=CLR_BIT4;EA=BIT_TMP
#define clr_CKEN_ECLKEN                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=CLR_BIT3;EA=BIT_TMP
#define clr_CKEN_CKSWTF                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CKEN&=CLR_BIT0;EA=BIT_TMP

/**** SBUF  99H  PAGE0 ****/
/**** SBUF1  9AH  PAGE0 ****/

/**** EIE0  9BH  PAGE0 ****/
#define set_EIE0_ET2                     SFRS=0;EIE0|=SET_BIT7
#define set_EIE0_ESPI0                   SFRS=0;EIE0|=SET_BIT6
#define set_EIE0_EFB0                    SFRS=0;EIE0|=SET_BIT5
#define set_EIE0_EWDT                    SFRS=0;EIE0|=SET_BIT4
#define set_EIE0_EPWM0                   SFRS=0;EIE0|=SET_BIT3//@
#define set_EIE0_ECAP                    SFRS=0;EIE0|=SET_BIT2//@
#define set_EIE0_EPI                     SFRS=0;EIE0|=SET_BIT1
#define set_EIE0_EI2C0                   SFRS=0;EIE0|=SET_BIT0

#define clr_EIE0_ET2                     SFRS=0;EIE0&=CLR_BIT7
#define clr_EIE0_ESPI0                   SFRS=0;EIE0&=CLR_BIT6
#define clr_EIE0_EFB0                    SFRS=0;EIE0&=CLR_BIT5
#define clr_EIE0_EWDT                    SFRS=0;EIE0&=CLR_BIT4
#define clr_EIE0_EPWM0                   SFRS=0;EIE0&=CLR_BIT3
#define clr_EIE0_ECAP                    SFRS=0;EIE0&=CLR_BIT2
#define clr_EIE0_EPI                     SFRS=0;EIE0&=CLR_BIT1
#define clr_EIE0_EI2C0                   SFRS=0;EIE0&=CLR_BIT0

/**** EIE1  9CH  PAGE0 ****/
#define set_EIE1_EPWM123                 SFRS=0;EIE1|=SET_BIT6
#define set_EIE1_EI2C1                   SFRS=0;EIE1|=SET_BIT5
#define set_EIE1_ESPI1                   SFRS=0;EIE1|=SET_BIT4
#define set_EIE1_EHFI                    SFRS=0;EIE1|=SET_BIT3//@
#define set_EIE1_EWKT                    SFRS=0;EIE1|=SET_BIT2//@
#define set_EIE1_ET3                     SFRS=0;EIE1|=SET_BIT1
#define set_EIE1_ES1                     SFRS=0;EIE1|=SET_BIT0

#define clr_EIE1_EPWM123                 SFRS=0;EIE1&=CLR_BIT6
#define clr_EIE1_EI2C1                   SFRS=0;EIE1&=CLR_BIT5
#define clr_EIE1_ESPI1                   SFRS=0;EIE1&=CLR_BIT4
#define clr_EIE1_EHFI                    SFRS=0;EIE1&=CLR_BIT3
#define clr_EIE1_EWKT                    SFRS=0;EIE1&=CLR_BIT2
#define clr_EIE1_ET3                     SFRS=0;EIE1&=CLR_BIT1
#define clr_EIE1_ES1                     SFRS=0;EIE1&=CLR_BIT0

/**** RSR  9DH  PAGE0 ****/
#define set_RSR_LVRF                     SFRS=0;RSR|=SET_BIT7
#define set_RSR_PORF                     SFRS=0;RSR|=SET_BIT6
#define set_RSR_HFRF                     SFRS=0;RSR|=SET_BIT5
#define set_RSR_POF                      SFRS=0;RSR|=SET_BIT4
#define set_RSR_RSTPINF                  SFRS=0;RSR|=SET_BIT3//@
#define set_RSR_BOR                      SFRS=0;RSR|=SET_BIT2//@
#define set_RSR_WDTRF                    SFRS=0;RSR|=SET_BIT1
#define set_RSR_SWRF                     SFRS=0;RSR|=SET_BIT0

#define clr_RSR_LVRF                     SFRS=0;RSR&=CLR_BIT7
#define clr_RSR_PORF                     SFRS=0;RSR&=CLR_BIT6
#define clr_RSR_HFRF                     SFRS=0;RSR&=CLR_BIT5
#define clr_RSR_POF                      SFRS=0;RSR&=CLR_BIT4
#define clr_RSR_RSTPINF                  SFRS=0;RSR&=CLR_BIT3
#define clr_RSR_BOR                      SFRS=0;RSR&=CLR_BIT2
#define clr_RSR_WDTRF                    SFRS=0;RSR&=CLR_BIT1
#define clr_RSR_SWRF                     SFRS=0;RSR&=CLR_BIT0

/**** CHPCON  9FH  PAGE0 TA protect register ****/
#define set_CHPCON_SWRST                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT7;EA=BIT_TMP
#define set_CHPCON_IAPFF                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT6;EA=BIT_TMP
#define set_CHPCON_BS                    SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT1;EA=BIT_TMP
#define set_CHPCON_IAPEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON|=SET_BIT0;EA=BIT_TMP
                                        
#define clr_CHPCON_SWRST                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=CLR_BIT7;EA=BIT_TMP
#define clr_CHPCON_IAPFF                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=CLR_BIT6;EA=BIT_TMP
#define clr_CHPCON_BS                    SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=CLR_BIT1;EA=BIT_TMP
#define clr_CHPCON_IAPEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;CHPCON&=CLR_BIT0;EA=BIT_TMP

/**** ADCCON0  A0H  PAGE0 ****/
#define set_ADCCON0_ADCF                 SFRS=0;ADCCON0|=SET_BIT7
#define set_ADCCON0_ADCS                 SFRS=0;ADCCON0|=SET_BIT6
#define set_ADCCON0_ETGSEL_1             SFRS=0;ADCCON0|=SET_BIT5
#define set_ADCCON0_ETGSEL_0             SFRS=0;ADCCON0|=SET_BIT4
#define set_ADCCON0_ADCHS_3              SFRS=0;ADCCON0|=SET_BIT3//@
#define set_ADCCON0_ADCHS_2              SFRS=0;ADCCON0|=SET_BIT2//@
#define set_ADCCON0_ADCHS_1              SFRS=0;ADCCON0|=SET_BIT1
#define set_ADCCON0_ADCHS_0              SFRS=0;ADCCON0|=SET_BIT0

#define clr_ADCCON0_ADCF                 SFRS=0;ADCCON0&=CLR_BIT7
#define clr_ADCCON0_ADCS                 SFRS=0;ADCCON0&=CLR_BIT6
#define clr_ADCCON0_ETGSEL_1             SFRS=0;ADCCON0&=CLR_BIT5
#define clr_ADCCON0_ETGSEL_0             SFRS=0;ADCCON0&=CLR_BIT4
#define clr_ADCCON0_ADCHS_3              SFRS=0;ADCCON0&=CLR_BIT3
#define clr_ADCCON0_ADCHS_2              SFRS=0;ADCCON0&=CLR_BIT2
#define clr_ADCCON0_ADCHS_1              SFRS=0;ADCCON0&=CLR_BIT1
#define clr_ADCCON0_ADCHS_0              SFRS=0;ADCCON0&=CLR_BIT0

/**** AUXR0  A2H  PAGE0 ****/
#define set_AUXR0_SWRF                   SFRS=0;AUXR0|=SET_BIT7
#define set_AUXR0_RSTPINF                SFRS=0;AUXR0|=SET_BIT6
#define set_AUXR0_HFRF                   SFRS=0;AUXR0|=SET_BIT5
#define set_AUXR0_HFIF                   SFRS=0;AUXR0|=SET_BIT4
#define set_AUXR0_GF2                    SFRS=0;AUXR0|=SET_BIT3//@
#define set_AUXR0_DPS                    SFRS=0;AUXR0|=SET_BIT0

#define clr_AUXR0_SWRF                   SFRS=0;AUXR0&=CLR_BIT7
#define clr_AUXR0_RSTPINF                SFRS=0;AUXR0&=CLR_BIT6
#define clr_AUXR0_HFRF                   SFRS=0;AUXR0&=CLR_BIT5
#define clr_AUXR0_HFIF                   SFRS=0;AUXR0&=CLR_BIT4
#define clr_AUXR0_GF2                    SFRS=0;AUXR0&=CLR_BIT3
#define clr_AUXR0_DPS                    SFRS=0;AUXR0&=CLR_BIT0

/**** BODCON0  A3H  PAGE0 TA protect register ****/
#define set_BODCON0_BODEN                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT7;EA=BIT_TMP
#define set_BODCON0_BOV_2                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT6;EA=BIT_TMP
#define set_BODCON0_BOV_1                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT5;EA=BIT_TMP
#define set_BODCON0_BOV_0                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT4;EA=BIT_TMP
#define set_BODCON0_BOF                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT4;EA=BIT_TMP
#define set_BODCON0_BORST                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT3;EA=BIT_TMP
#define set_BODCON0_BORF                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT1;EA=BIT_TMP
#define set_BODCON0_BOS                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0|=SET_BIT0;EA=BIT_TMP
                                     
#define clr_BODCON0_BODEN                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=CLR_BIT7;EA=BIT_TMP
#define clr_BODCON0_BOV_2                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=CLR_BIT6;EA=BIT_TMP
#define clr_BODCON0_BOV_1                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=CLR_BIT5;EA=BIT_TMP
#define clr_BODCON0_BOV_0                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=CLR_BIT4;EA=BIT_TMP
#define clr_BODCON0_BOF                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=CLR_BIT3;EA=BIT_TMP
#define clr_BODCON0_BORST                SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=CLR_BIT2;EA=BIT_TMP
#define clr_BODCON0_BORF                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=CLR_BIT1;EA=BIT_TMP
#define clr_BODCON0_BOS                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON0&=CLR_BIT0;EA=BIT_TMP

/**** IAPTRG  A4H  PAGE0 TA protect register ****/
#define set_IAPTRG_IAPGO                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPTRG|=SET_BIT0;EA=BIT_TMP
#define clr_IAPTRG_IAPGO                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPTRG&=CLR_BIT0;EA=BIT_TMP

/**** IAPUEN  A5H  PAGE0 TA protect register ****/
#define set_IAPUEN_SPMEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT4;EA=BIT_TMP
#define set_IAPUEN_SPUEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT4;EA=BIT_TMP
#define set_IAPUEN_CFUEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT3;EA=BIT_TMP
#define set_IAPUEN_LDUEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT1;EA=BIT_TMP
#define set_IAPUEN_APUEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN|=SET_BIT0;EA=BIT_TMP
                                     
#define clr_IAPUEN_SPMEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=CLR_BIT4;EA=BIT_TMP
#define clr_IAPUEN_SPUEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=CLR_BIT3;EA=BIT_TMP
#define clr_IAPUEN_CFUEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=CLR_BIT2;EA=BIT_TMP
#define clr_IAPUEN_LDUEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=CLR_BIT1;EA=BIT_TMP
#define clr_IAPUEN_APUEN                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;IAPUEN&=CLR_BIT0;EA=BIT_TMP

/**** IAPAL    A6H  PAGE0  ****/
/**** IAPAG    A7H  PAGE0  ****/
/**** SADDR    A9H  PAGE0  ****

/**** WDCON    AAH  PAGE0 TA protect register* ***/
#define set_WDCON_WDTR                   SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT7;EA=BIT_TMP
#define set_WDCON_WDCLR                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT6;EA=BIT_TMP
#define set_WDCON_WDTF                   SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT5;EA=BIT_TMP
#define set_WDCON_WIDPD                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT4;EA=BIT_TMP
#define set_WDCON_WDTRF                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT4;EA=BIT_TMP
#define set_WDCON_WDPS_2                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT3;EA=BIT_TMP
#define set_WDCON_WDPS_1                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT1;EA=BIT_TMP
#define set_WDCON_WDPS_0                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON|=SET_BIT0;EA=BIT_TMP

#define clr_WDCON_WDTR                   SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=CLR_BIT7;EA=BIT_TMP
#define clr_WDCON_WDCLR                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=CLR_BIT6;EA=BIT_TMP
#define clr_WDCON_WDTF                   SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=CLR_BIT5;EA=BIT_TMP
#define clr_WDCON_WIDPD                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=CLR_BIT4;EA=BIT_TMP
#define clr_WDCON_WDTRF                  SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=CLR_BIT3;EA=BIT_TMP
#define clr_WDCON_WDPS_2                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=CLR_BIT2;EA=BIT_TMP
#define clr_WDCON_WDPS_1                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=CLR_BIT1;EA=BIT_TMP
#define clr_WDCON_WDPS_0                 SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;WDCON&=CLR_BIT0;EA=BIT_TMP

/**** BODCON1  ABH  PAGE0 ****/
#define set_BODCON1_LPBOD1               SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1|=SET_BIT3;EA=BIT_TMP
#define set_BODCON1_LPBOD0               SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1|=SET_BIT1;EA=BIT_TMP
#define set_BODCON1_BODFLT               SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1|=SET_BIT0;EA=BIT_TMP

#define clr_BODCON1_LPBOD1               SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1&=CLR_BIT2;EA=BIT_TMP
#define clr_BODCON1_LPBOD0               SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1&=CLR_BIT1;EA=BIT_TMP
#define clr_BODCON1_BODFLT               SFRS=0;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BODCON1&=CLR_BIT0;EA=BIT_TMP

/**** EIP2  ACH  PAGE0 ****/
#define set_EIP2_RTC                     SFRS=0;EIP2|=SET_BIT7
#define set_EIP2_PDMA3                   SFRS=0;EIP2|=SET_BIT6
#define set_EIP2_PDMA2                   SFRS=0;EIP2|=SET_BIT5
#define set_EIP2_SMC1                    SFRS=0;EIP2|=SET_BIT4
#define set_EIP2_TK                      SFRS=0;EIP2|=SET_BIT3//@
#define set_EIP2_PPWM1                   SFRS=0;EIP2|=SET_BIT2//@
#define set_EIP2_PI2C1                   SFRS=0;EIP2|=SET_BIT1
#define set_EIP2_PACMP                   SFRS=0;EIP2|=SET_BIT0

#define clr_EIP2_RTC                     SFRS=0;EIP2&=CLR_BIT7
#define clr_EIP2_PDMA3                   SFRS=0;EIP2&=CLR_BIT6
#define clr_EIP2_PDMA2                   SFRS=0;EIP2&=CLR_BIT5
#define clr_EIP2_SMC1                    SFRS=0;EIP2&=CLR_BIT4
#define clr_EIP2_TK                      SFRS=0;EIP2&=CLR_BIT3
#define clr_EIP2_PPWM1                   SFRS=0;EIP2&=CLR_BIT2
#define clr_EIP2_PI2C1                   SFRS=0;EIP2&=CLR_BIT1
#define clr_EIP2_PACMP                   SFRS=0;EIP2&=CLR_BIT0

/**** EIPH2  ADH  PAGE0 ****/
#define set_EIPH2_RTCH                   SFRS=0;EIPH2|=SET_BIT7
#define set_EIPH2_PDMA3H                 SFRS=0;EIPH2|=SET_BIT6
#define set_EIPH2_PDMA2H                 SFRS=0;EIPH2|=SET_BIT5
#define set_EIPH2_SMC1H                  SFRS=0;EIPH2|=SET_BIT4
#define set_EIPH2_TKH                    SFRS=0;EIPH2|=SET_BIT3//@
#define set_EIPH2_PPWM1H                 SFRS=0;EIPH2|=SET_BIT2//@
#define set_EIPH2_PI2C1H                 SFRS=0;EIPH2|=SET_BIT1
#define set_EIPH2_PACMPH                 SFRS=0;EIPH2|=SET_BIT0

#define clr_EIPH2_RTCH                   SFRS=0;EIPH2&=CLR_BIT7
#define clr_EIPH2_PDMA3H                 SFRS=0;EIPH2&=CLR_BIT6
#define clr_EIPH2_PDMA2H                 SFRS=0;EIPH2&=CLR_BIT5
#define clr_EIPH2_SMC1H                  SFRS=0;EIPH2&=CLR_BIT4
#define clr_EIPH2_TKH                    SFRS=0;EIPH2&=CLR_BIT3
#define clr_EIPH2_PPWM1H                 SFRS=0;EIPH2&=CLR_BIT2
#define clr_EIPH2_PI2C1H                 SFRS=0;EIPH2&=CLR_BIT1
#define clr_EIPH2_PACMPH                 SFRS=0;EIPH2&=CLR_BIT0

/**** IAPFD  AEH  PAGE0 ****/
/**** IAPCN  AFH  PAGE0 ****/
#define set_IAPCN_FOEN                   SFRS=0;IAPCN|=SET_BIT5
#define set_IAPCN_FCEN                   SFRS=0;IAPCN|=SET_BIT4
#define set_IAPCN_FCTRL3                 SFRS=0;IAPCN|=SET_BIT3//@
#define set_IAPCN_FCTRL2                 SFRS=0;IAPCN|=SET_BIT2//@
#define set_IAPCN_FCTRL1                 SFRS=0;IAPCN|=SET_BIT1
#define set_IAPCN_FCTRL0                 SFRS=0;IAPCN|=SET_BIT0

#define clr_IAPCN_FOEN                   SFRS=0;IAPCN&=CLR_BIT5
#define clr_IAPCN_FCEN                   SFRS=0;IAPCN&=CLR_BIT4
#define clr_IAPCN_FCTRL3                 SFRS=0;IAPCN&=CLR_BIT3
#define clr_IAPCN_FCTRL2                 SFRS=0;IAPCN&=CLR_BIT2
#define clr_IAPCN_FCTRL1                 SFRS=0;IAPCN&=CLR_BIT1
#define clr_IAPCN_FCTRL0                 SFRS=0;IAPCN&=CLR_BIT0

/**** P5  B1H  PAGE0 ****/
#define set_P5_7                         SFRS=0;P5|=SET_BIT7
#define set_P5_6                         SFRS=0;P5|=SET_BIT6
#define set_P5_5                         SFRS=0;P5|=SET_BIT5
#define set_P5_4                         SFRS=0;P5|=SET_BIT4
#define set_P5_3                         SFRS=0;P5|=SET_BIT3//@
#define set_P5_2                         SFRS=0;P5|=SET_BIT2//@
#define set_P5_1                         SFRS=0;P5|=SET_BIT1
#define set_P5_0                         SFRS=0;P5|=SET_BIT0

#define clr_P5_7                         SFRS=0;P5&=CLR_BIT7
#define clr_P5_6                         SFRS=0;P5&=CLR_BIT6
#define clr_P5_5                         SFRS=0;P5&=CLR_BIT5
#define clr_P5_4                         SFRS=0;P5&=CLR_BIT4
#define clr_P5_3                         SFRS=0;P5&=CLR_BIT3
#define clr_P5_2                         SFRS=0;P5&=CLR_BIT2
#define clr_P5_1                         SFRS=0;P5&=CLR_BIT1
#define clr_P5_0                         SFRS=0;P5&=CLR_BIT0

#define set_P57                          SFRS=0;P5|=SET_BIT7
#define set_P56                          SFRS=0;P5|=SET_BIT6
#define set_P55                          SFRS=0;P5|=SET_BIT5
#define set_P54                          SFRS=0;P5|=SET_BIT4
#define set_P53                          SFRS=0;P5|=SET_BIT3//@
#define set_P52                          SFRS=0;P5|=SET_BIT2//@
#define set_P51                          SFRS=0;P5|=SET_BIT1
#define set_P50                          SFRS=0;P5|=SET_BIT0
                                                        
#define clr_P57                          SFRS=0;P5&=CLR_BIT7
#define clr_P56                          SFRS=0;P5&=CLR_BIT6
#define clr_P55                          SFRS=0;P5&=CLR_BIT5
#define clr_P54                          SFRS=0;P5&=CLR_BIT4
#define clr_P53                          SFRS=0;P5&=CLR_BIT3
#define clr_P52                          SFRS=0;P5&=CLR_BIT2
#define clr_P51                          SFRS=0;P5&=CLR_BIT1
#define clr_P50                          SFRS=0;P5&=CLR_BIT0

/**** I2C1ADDR  B2H  PAGE0 ****/
#define set_I2C1ADDR_GC                  SFRS=0;I2C1ADDR|=SET_BIT0
#define clr_I2C1ADDR_GC                  SFRS=0;I2C1ADDR&=CLR_BIT0

/**** I2C1DAT  B3H  PAGE0 ****/
/**** I2C1STAT  B4H  PAGE0 ****/
/**** I2C1CLK  B5H  PAGE0 ****/

/**** I2C1TOC  B6H  PAGE0 ****/
#define set_I2C1TOC_I2TOCEN              SFRS=0;I2C1TOC|=SET_BIT2//@
#define set_I2C1TOC_DIV                  SFRS=0;I2C1TOC|=SET_BIT1
#define set_I2C1TOC_I2TOF                SFRS=0;I2C1TOC|=SET_BIT0

#define clr_I2C1TOC_I2TOCEN              SFRS=0;I2C1TOC&=CLR_BIT2
#define clr_I2C1TOC_DIV                  SFRS=0;I2C1TOC&=CLR_BIT1
#define clr_I2C1TOC_I2TOF                SFRS=0;I2C1TOC&=CLR_BIT0

/**** IPH  B7H  PAGE0 ****/
#define set_IPH_PADCH                    SFRS=0;IPH|=SET_BIT6
#define set_IPH_PBODH                    SFRS=0;IPH|=SET_BIT5
#define set_IPH_PSH                      SFRS=0;IPH|=SET_BIT4
#define set_IPH_PT1H                     SFRS=0;IPH|=SET_BIT3//@
#define set_IPH_PX1H                     SFRS=0;IPH|=SET_BIT2//@
#define set_IPH_PT0H                     SFRS=0;IPH|=SET_BIT1
#define set_IPH_PX0H                     SFRS=0;IPH|=SET_BIT0

#define clr_IPH_PADCH                    SFRS=0;IPH&=CLR_BIT6
#define clr_IPH_PBODH                    SFRS=0;IPH&=CLR_BIT5
#define clr_IPH_PSH                      SFRS=0;IPH&=CLR_BIT4
#define clr_IPH_PT1H                     SFRS=0;IPH&=CLR_BIT3
#define clr_IPH_PX1H                     SFRS=0;IPH&=CLR_BIT2
#define clr_IPH_PT0H                     SFRS=0;IPH&=CLR_BIT1
#define clr_IPH_PX0H                     SFRS=0;IPH&=CLR_BIT0

/**** SADEN  B9H  PAGE0 ****/
/**** SADEN1  BAH  PAGE0 ****/
/**** SADDR1  BBH  PAGE0 ****/
/**** I2C0DAT  BCH  PAGE0 ****/
/**** I2C0STAT  BDH  PAGE0 ****/
/**** I2C0CLK  BEH  PAGE0 ****/

/**** I2C0TOC  BFH  PAGE0 ****/
#define set_I2C0TOC_I2TOCEN              SFRS=0;I2C0TOC|=SET_BIT2//@
#define set_I2C0TOC_DIV                  SFRS=0;I2C0TOC|=SET_BIT1
#define set_I2C0TOC_I2TOF                SFRS=0;I2C0TOC|=SET_BIT0

#define clr_I2C0TOC_I2TOCEN              SFRS=0;I2C0TOC&=CLR_BIT2
#define clr_I2C0TOC_DIV                  SFRS=0;I2C0TOC&=CLR_BIT1
#define clr_I2C0TOC_I2TOF                SFRS=0;I2C0TOC&=CLR_BIT0

/**** I2ADDR  C1H  PAGE 0 ****/
#define set_I2ADDR_GC                    SFRS=0;I2ADDR|=SET_BIT0
#define clr_I2ADDR_GC                    SFRS=0;I2ADDR&=CLR_BIT0

/**** ADCRL  C2H  PAGE 0 ****/
#define set_ADCRL_ADCR3                  SFRS=0;ADCRL|=SET_BIT3//@
#define set_ADCRL_ADCR2                  SFRS=0;ADCRL|=SET_BIT2//@
#define set_ADCRL_ADCR1                  SFRS=0;ADCRL|=SET_BIT1
#define set_ADCRL_ADCR0                  SFRS=0;ADCRL|=SET_BIT0

#define clr_ADCRL_ADCR3                  SFRS=0;ADCRL&=CLR_BIT3
#define clr_ADCRL_ADCR2                  SFRS=0;ADCRL&=CLR_BIT2
#define clr_ADCRL_ADCR1                  SFRS=0;ADCRL&=CLR_BIT1
#define clr_ADCRL_ADCR0                  SFRS=0;ADCRL&=CLR_BIT0

/**** T3CON  C4H  PAGE 0 ****/
#define set_T3CON_SMOD_1                 SFRS=0;T3CON|=SET_BIT7
#define set_T3CON_SMOD0_1                SFRS=0;T3CON|=SET_BIT6
#define set_T3CON_BRCK                   SFRS=0;T3CON|=SET_BIT5
#define set_T3CON_TF3                    SFRS=0;T3CON|=SET_BIT4
#define set_T3CON_TR3                    SFRS=0;T3CON|=SET_BIT3//@
#define set_T3CON_T3PS2                  SFRS=0;T3CON|=SET_BIT2//@
#define set_T3CON_T3PS1                  SFRS=0;T3CON|=SET_BIT1
#define set_T3CON_T3PS0                  SFRS=0;T3CON|=SET_BIT0

#define clr_T3CON_SMOD_1                 SFRS=0;T3CON&=CLR_BIT7
#define clr_T3CON_SMOD0_1                SFRS=0;T3CON&=CLR_BIT6
#define clr_T3CON_BRCK                   SFRS=0;T3CON&=CLR_BIT5
#define clr_T3CON_TF3                    SFRS=0;T3CON&=CLR_BIT4
#define clr_T3CON_TR3                    SFRS=0;T3CON&=CLR_BIT3
#define clr_T3CON_T3PS2                  SFRS=0;T3CON&=CLR_BIT2
#define clr_T3CON_T3PS1                  SFRS=0;T3CON&=CLR_BIT1
#define clr_T3CON_T3PS0                  SFRS=0;T3CON&=CLR_BIT0

/**** T2MOD  C9H  PAGE 0 ****/
#define set_T2MOD_LDEN                   SFRS=0;T2MOD|=SET_BIT7
#define set_T2MOD_T2DIV2                 SFRS=0;T2MOD|=SET_BIT6
#define set_T2MOD_T2DIV1                 SFRS=0;T2MOD|=SET_BIT5
#define set_T2MOD_T2DIV0                 SFRS=0;T2MOD|=SET_BIT4
#define set_T2MOD_CAPCR                  SFRS=0;T2MOD|=SET_BIT3//@
#define set_T2MOD_CMPCR                  SFRS=0;T2MOD|=SET_BIT2//@
#define set_T2MOD_LDTS1                  SFRS=0;T2MOD|=SET_BIT1
#define set_T2MOD_LDTS0                  SFRS=0;T2MOD|=SET_BIT0

#define clr_T2MOD_LDEN                   SFRS=0;T2MOD&=CLR_BIT7
#define clr_T2MOD_T2DIV2                 SFRS=0;T2MOD&=CLR_BIT6
#define clr_T2MOD_T2DIV1                 SFRS=0;T2MOD&=CLR_BIT5
#define clr_T2MOD_T2DIV0                 SFRS=0;T2MOD&=CLR_BIT4
#define clr_T2MOD_CAPCR                  SFRS=0;T2MOD&=CLR_BIT3
#define clr_T2MOD_CMPCR                  SFRS=0;T2MOD&=CLR_BIT2
#define clr_T2MOD_LDTS1                  SFRS=0;T2MOD&=CLR_BIT1
#define clr_T2MOD_LDTS0                  SFRS=0;T2MOD&=CLR_BIT0

/**** PIF  CAH  PAGE 0 ****/
#define set_PIF_PIF7                     SFRS=0;PIF|=SET_BIT7
#define set_PIF_PIF6                     SFRS=0;PIF|=SET_BIT6
#define set_PIF_PIF5                     SFRS=0;PIF|=SET_BIT5
#define set_PIF_PIF4                     SFRS=0;PIF|=SET_BIT4
#define set_PIF_PIF3                     SFRS=0;PIF|=SET_BIT3//@
#define set_PIF_PIF2                     SFRS=0;PIF|=SET_BIT2//@
#define set_PIF_PIF1                     SFRS=0;PIF|=SET_BIT1
#define set_PIF_PIF0                     SFRS=0;PIF|=SET_BIT0

#define clr_PIF_PIF7                     SFRS=0;PIF&=CLR_BIT7
#define clr_PIF_PIF6                     SFRS=0;PIF&=CLR_BIT6
#define clr_PIF_PIF5                     SFRS=0;PIF&=CLR_BIT5
#define clr_PIF_PIF4                     SFRS=0;PIF&=CLR_BIT4
#define clr_PIF_PIF3                     SFRS=0;PIF&=CLR_BIT3
#define clr_PIF_PIF2                     SFRS=0;PIF&=CLR_BIT2
#define clr_PIF_PIF1                     SFRS=0;PIF&=CLR_BIT1
#define clr_PIF_PIF0                     SFRS=0;PIF&=CLR_BIT0

/**** ADCMPL  CEH  PAGE 0 ****/
#define set_ADCMPL_ADCMP3                SFRS=0;ADCMPL|=SET_BIT3//@
#define set_ADCMPL_ADCMP2                SFRS=0;ADCMPL|=SET_BIT2//@
#define set_ADCMPL_ADCMP1                SFRS=0;ADCMPL|=SET_BIT1
#define set_ADCMPL_ADCMP0                SFRS=0;ADCMPL|=SET_BIT0

#define clr_ADCMPL_ADCMP3                SFRS=0;ADCMPL&=CLR_BIT3
#define clr_ADCMPL_ADCMP2                SFRS=0;ADCMPL&=CLR_BIT2
#define clr_ADCMPL_ADCMP1                SFRS=0;ADCMPL&=CLR_BIT1
#define clr_ADCMPL_ADCMP0                SFRS=0;ADCMPL&=CLR_BIT0

/**** PWM0CON0  D1H  PAGE 0 ****/
#define set_PWM0CON0_PWMRUN              SFRS=0;PWM0CON0|=SET_BIT7
#define set_PWM0CON0_LOAD                SFRS=0;PWM0CON0|=SET_BIT6
#define set_PWM0CON0_PWMF                SFRS=0;PWM0CON0|=SET_BIT5
#define set_PWM0CON0_CLRPWM              SFRS=0;PWM0CON0|=SET_BIT4

#define clr_PWM0CON0_PWMRUN              SFRS=0;PWM0CON0&=CLR_BIT7
#define clr_PWM0CON0_LOAD                SFRS=0;PWM0CON0&=CLR_BIT6
#define clr_PWM0CON0_PWMF                SFRS=0;PWM0CON0&=CLR_BIT5
#define clr_PWM0CON0_CLRPWM              SFRS=0;PWM0CON0&=CLR_BIT4

/**** ACMPCR0  D2H  PAGE 0 ****/
#define set_ACMPCR0_POSSEL               SFRS=0;ACMPCR0|=SET_BIT7
#define set_ACMPCR0_NEGSEL               SFRS=0;ACMPCR0|=SET_BIT5
#define set_ACMPCR0_WKEN                 SFRS=0;ACMPCR0|=SET_BIT3//@
#define set_ACMPCR0_HYSEN                SFRS=0;ACMPCR0|=SET_BIT2//@
#define set_ACMPCR0_ACMPIE               SFRS=0;ACMPCR0|=SET_BIT1
#define set_ACMPCR0_ACMPEN               SFRS=0;ACMPCR0|=SET_BIT0

#define clr_ACMPCR0_POSSEL               SFRS=0;ACMPCR0&=CLR_BIT7
#define clr_ACMPCR0_NEGSEL               SFRS=0;ACMPCR0&=CLR_BIT5
#define clr_ACMPCR0_WKEN                 SFRS=0;ACMPCR0&=CLR_BIT3
#define clr_ACMPCR0_HYSEN                SFRS=0;ACMPCR0&=CLR_BIT2
#define clr_ACMPCR0_ACMPIE               SFRS=0;ACMPCR0&=CLR_BIT1
#define clr_ACMPCR0_ACMPEN               SFRS=0;ACMPCR0&=CLR_BIT0

/**** ACMPCR1  D3H  PAGE 0 ****/
#define set_ACMPCR1_POSSEL               SFRS=0;ACMPCR1|=SET_BIT7
#define set_ACMPCR1_NEGSEL               SFRS=0;ACMPCR1|=SET_BIT5
#define set_ACMPCR1_WKEN                 SFRS=0;ACMPCR1|=SET_BIT3//@
#define set_ACMPCR1_HYSEN                SFRS=0;ACMPCR1|=SET_BIT2//@
#define set_ACMPCR1_ACMPIE               SFRS=0;ACMPCR1|=SET_BIT1
#define set_ACMPCR1_ACMPEN               SFRS=0;ACMPCR1|=SET_BIT0

#define clr_ACMPCR1_POSSEL               SFRS=0;ACMPCR1&=CLR_BIT7
#define clr_ACMPCR1_NEGSEL               SFRS=0;ACMPCR1&=CLR_BIT5
#define clr_ACMPCR1_WKEN                 SFRS=0;ACMPCR1&=CLR_BIT3
#define clr_ACMPCR1_HYSEN                SFRS=0;ACMPCR1&=CLR_BIT2
#define clr_ACMPCR1_ACMPIE               SFRS=0;ACMPCR1&=CLR_BIT1
#define clr_ACMPCR1_ACMPEN               SFRS=0;ACMPCR1&=CLR_BIT0

/**** ACMPSR  D4H  PAGE 0 ****/
#define set_ACMPSR_ACMP1O                SFRS=0;ACMPSR|=SET_BIT3//@
#define set_ACMPSR_ACMP1IF               SFRS=0;ACMPSR|=SET_BIT2//@
#define set_ACMPSR_ACMP0O                SFRS=0;ACMPSR|=SET_BIT1
#define set_ACMPSR_ACMP0IF               SFRS=0;ACMPSR|=SET_BIT0

#define clr_ACMPSR_ACMP1O                SFRS=0;ACMPSR&=CLR_BIT3
#define clr_ACMPSR_ACMP1IF               SFRS=0;ACMPSR&=CLR_BIT2
#define clr_ACMPSR_ACMP0O                SFRS=0;ACMPSR&=CLR_BIT1
#define clr_ACMPSR_ACMP0IF               SFRS=0;ACMPSR&=CLR_BIT0

/**** ACMPVREF  D5H  PAGE 0 ****/
#define set_ACMPVREF_AO1PIV              SFRS=0;ACMPVREF|=SET_BIT7
#define set_ACMPVREF_CRV1CTL_2           SFRS=0;ACMPVREF|=SET_BIT6
#define set_ACMPVREF_CRV1CTL_1           SFRS=0;ACMPVREF|=SET_BIT5
#define set_ACMPVREF_CRV1CTL_0           SFRS=0;ACMPVREF|=SET_BIT4
#define set_ACMPVREF_AO0PIV              SFRS=0;ACMPVREF|=SET_BIT3
#define set_ACMPVREF_CRV0CTL_2           SFRS=0;ACMPVREF|=SET_BIT2
#define set_ACMPVREF_CRV0CTL_1           SFRS=0;ACMPVREF|=SET_BIT1
#define set_ACMPVREF_CRV0CTL_0           SFRS=0;ACMPVREF|=SET_BIT0
                                                                  
#define clr_ACMPVREF_AO1PIV              SFRS=0;ACMPVREF&=CLR_BIT7
#define clr_ACMPVREF_CRV1CTL_2           SFRS=0;ACMPVREF&=CLR_BIT6
#define clr_ACMPVREF_CRV1CTL_1           SFRS=0;ACMPVREF&=CLR_BIT5
#define clr_ACMPVREF_CRV1CTL_0           SFRS=0;ACMPVREF&=CLR_BIT4
#define clr_ACMPVREF_AO0PIV              SFRS=0;ACMPVREF&=CLR_BIT3
#define clr_ACMPVREF_CRV0CTL_2           SFRS=0;ACMPVREF&=CLR_BIT2
#define clr_ACMPVREF_CRV0CTL_1           SFRS=0;ACMPVREF&=CLR_BIT1
#define clr_ACMPVREF_CRV0CTL_0           SFRS=0;ACMPVREF&=CLR_BIT0


/**** SC0CR0  D6H  PAGE 0 ****/
#define set_SC0CR0_NSB                   SFRS=0;SC0CR0|=SET_BIT7
#define set_SC0CR0_T                     SFRS=0;SC0CR0|=SET_BIT6
#define set_SC0CR0_RXBGTEN               SFRS=0;SC0CR0|=SET_BIT5
#define set_SC0CR0_CONSEL                SFRS=0;SC0CR0|=SET_BIT4
#define set_SC0CR0_AUTOCEN               SFRS=0;SC0CR0|=SET_BIT3//@
#define set_SC0CR0_TXOFF                 SFRS=0;SC0CR0|=SET_BIT2//@
#define set_SC0CR0_RXOFF                 SFRS=0;SC0CR0|=SET_BIT1
#define set_SC0CR0_SCEN                  SFRS=0;SC0CR0|=SET_BIT0

#define clr_SC0CR0_NSB                   SFRS=0;SC0CR0&=CLR_BIT7
#define clr_SC0CR0_T                     SFRS=0;SC0CR0&=CLR_BIT6
#define clr_SC0CR0_RXBGTEN               SFRS=0;SC0CR0&=CLR_BIT5
#define clr_SC0CR0_CONSEL                SFRS=0;SC0CR0&=CLR_BIT4
#define clr_SC0CR0_AUTOCEN               SFRS=0;SC0CR0&=CLR_BIT3
#define clr_SC0CR0_TXOFF                 SFRS=0;SC0CR0&=CLR_BIT2
#define clr_SC0CR0_RXOFF                 SFRS=0;SC0CR0&=CLR_BIT1
#define clr_SC0CR0_SCEN                  SFRS=0;SC0CR0&=CLR_BIT0

/**** SC0CR1  D7H  PAGE 0 ****/
#define set_SC0CR1_OPE                   SFRS=0;SC0CR1|=SET_BIT7
#define set_SC0CR1_PBOFF                 SFRS=0;SC0CR1|=SET_BIT6
#define set_SC0CR1_WLS                   SFRS=0;SC0CR1|=SET_BIT5
#define set_SC0CR1_TXDMAEN               SFRS=0;SC0CR1|=SET_BIT3//@
#define set_SC0CR1_RXDMAEN               SFRS=0;SC0CR1|=SET_BIT2//@
#define set_SC0CR1_CLKKEEP               SFRS=0;SC0CR1|=SET_BIT1
#define set_SC0CR1_UARTEN                SFRS=0;SC0CR1|=SET_BIT0

#define clr_SC0CR1_OPE                   SFRS=0;SC0CR1&=CLR_BIT7
#define clr_SC0CR1_PBOFF                 SFRS=0;SC0CR1&=CLR_BIT6
#define clr_SC0CR1_WLS                   SFRS=0;SC0CR1&=CLR_BIT5
#define clr_SC0CR1_TXDMAEN               SFRS=0;SC0CR1&=CLR_BIT3
#define clr_SC0CR1_RXDMAEN               SFRS=0;SC0CR1&=CLR_BIT2
#define clr_SC0CR1_CLKKEEP               SFRS=0;SC0CR1&=CLR_BIT1
#define clr_SC0CR1_UARTEN                SFRS=0;SC0CR1&=CLR_BIT0

/**** SC0ETURD1  DCH  PAGE 0 ****/
#define set_SC0ETURD1_SCDIV_2            SFRS=0;SC0ETURD1|=SET_BIT6
#define set_SC0ETURD1_SCDIV_1            SFRS=0;SC0ETURD1|=SET_BIT5
#define set_SC0ETURD1_SCDIV_0            SFRS=0;SC0ETURD1|=SET_BIT4
#define set_SC0ETURD1_ETURDIV_10         SFRS=0;SC0ETURD1|=SET_BIT3
#define set_SC0ETURD1_ETURDIV_11         SFRS=0;SC0ETURD1|=SET_BIT2
#define set_SC0ETURD1_ETURDIV_9          SFRS=0;SC0ETURD1|=SET_BIT1
#define set_SC0ETURD1_ETURDIV_8          SFRS=0;SC0ETURD1|=SET_BIT0
                                                                   
#define clr_SC0ETURD1_SCDIV_2            SFRS=0;SC0ETURD1&=CLR_BIT6
#define clr_SC0ETURD1_SCDIV_1            SFRS=0;SC0ETURD1&=CLR_BIT5
#define clr_SC0ETURD1_SCDIV_0            SFRS=0;SC0ETURD1&=CLR_BIT4
#define clr_SC0ETURD1_ETURDIV_10         SFRS=0;SC0ETURD1&=CLR_BIT3
#define clr_SC0ETURD1_ETURDIV_11         SFRS=0;SC0ETURD1&=CLR_BIT2
#define clr_SC0ETURD1_ETURDIV_9          SFRS=0;SC0ETURD1&=CLR_BIT1
#define clr_SC0ETURD1_ETURDIV_8          SFRS=0;SC0ETURD1&=CLR_BIT0


/**** SC0IE  DDH  PAGE 0 ****/
#define set_SC0IE_ACERRIEN               SFRS=0;SC0IE|=SET_BIT4
#define set_SC0IE_BGTIEN                 SFRS=0;SC0IE|=SET_BIT3//@
#define set_SC0IE_TERRIEN                SFRS=0;SC0IE|=SET_BIT2//@
#define set_SC0IE_TBEIEN                 SFRS=0;SC0IE|=SET_BIT1
#define set_SC0IE_RDAIEN                 SFRS=0;SC0IE|=SET_BIT0

#define clr_SC0IE_ACERRIEN               SFRS=0;SC0IE&=CLR_BIT4
#define clr_SC0IE_BGTIEN                 SFRS=0;SC0IE&=CLR_BIT3
#define clr_SC0IE_TERRIEN                SFRS=0;SC0IE&=CLR_BIT2
#define clr_SC0IE_TBEIEN                 SFRS=0;SC0IE&=CLR_BIT1
#define clr_SC0IE_RDAIEN                 SFRS=0;SC0IE&=CLR_BIT0

/**** SC0IS  DEH  PAGE 0 ****/
#define set_SC0IS_ACERRIF                SFRS=0;SC0IS|=SET_BIT4
#define set_SC0IS_BGTIF                  SFRS=0;SC0IS|=SET_BIT3//@
#define set_SC0IS_TERRIF                 SFRS=0;SC0IS|=SET_BIT2//@
#define set_SC0IS_TBEIF                  SFRS=0;SC0IS|=SET_BIT1
#define set_SC0IS_RDAIF                  SFRS=0;SC0IS|=SET_BIT0

#define clr_SC0IS_ACERRIF                SFRS=0;SC0IS&=CLR_BIT4
#define clr_SC0IS_BGTIF                  SFRS=0;SC0IS&=CLR_BIT3
#define clr_SC0IS_TERRIF                 SFRS=0;SC0IS&=CLR_BIT2
#define clr_SC0IS_TBEIF                  SFRS=0;SC0IS&=CLR_BIT1
#define clr_SC0IS_RDAIF                  SFRS=0;SC0IS&=CLR_BIT0

/**** SC0TSR  DFH  PAGE 0 ****/
#define set_SC0TSR_ACT                   SFRS=0;SC0TSR|=SET_BIT7
#define set_SC0TSR_BEF                   SFRS=0;SC0TSR|=SET_BIT6
#define set_SC0TSR_FEF                   SFRS=0;SC0TSR|=SET_BIT5
#define set_SC0TSR_PEF                   SFRS=0;SC0TSR|=SET_BIT4
#define set_SC0TSR_TXEMPTY               SFRS=0;SC0TSR|=SET_BIT3//@
#define set_SC0TSR_TXOV                  SFRS=0;SC0TSR|=SET_BIT2//@
#define set_SC0TSR_RXEMPTY               SFRS=0;SC0TSR|=SET_BIT1
#define set_SC0TSR_RXOV                  SFRS=0;SC0TSR|=SET_BIT0

#define clr_SC0TSR_ACT                   SFRS=0;SC0TSR&=CLR_BIT7
#define clr_SC0TSR_BEF                   SFRS=0;SC0TSR&=CLR_BIT6
#define clr_SC0TSR_FEF                   SFRS=0;SC0TSR&=CLR_BIT5
#define clr_SC0TSR_PEF                   SFRS=0;SC0TSR&=CLR_BIT4
#define clr_SC0TSR_TXEMPTY               SFRS=0;SC0TSR&=CLR_BIT3
#define clr_SC0TSR_TXOV                  SFRS=0;SC0TSR&=CLR_BIT2
#define clr_SC0TSR_RXEMPTY               SFRS=0;SC0TSR&=CLR_BIT1
#define clr_SC0TSR_RXOV                  SFRS=0;SC0TSR&=CLR_BIT0

/**** ADCCON1  E1H  PAGE 0 ****/
#define set_ADCCON1_HIE                  SFRS=0;ADCCON1|=SET_BIT5
#define set_ADCCON1_CONT                 SFRS=0;ADCCON1|=SET_BIT4
#define set_ADCCON1_ETGTYP1              SFRS=0;ADCCON1|=SET_BIT3
#define set_ADCCON1_ETGTYP0              SFRS=0;ADCCON1|=SET_BIT2
#define set_ADCCON1_ADCEX                SFRS=0;ADCCON1|=SET_BIT1
#define set_ADCCON1_ADCEN                SFRS=0;ADCCON1|=SET_BIT0
                                                  
#define clr_ADCCON1_HIE                  SFRS=0;ADCCON1&=CLR_BIT5
#define clr_ADCCON1_CONT                 SFRS=0;ADCCON1&=CLR_BIT4
#define clr_ADCCON1_ETGTYP1              SFRS=0;ADCCON1&=CLR_BIT3
#define clr_ADCCON1_ETGTYP0              SFRS=0;ADCCON1&=CLR_BIT2
#define clr_ADCCON1_ADCEX                SFRS=0;ADCCON1&=CLR_BIT1
#define clr_ADCCON1_ADCEN                SFRS=0;ADCCON1&=CLR_BIT0

/**** ADCCON2  E2H  PAGE 0 ****/
#define set_ADCCON2_ADFBEN               SFRS=0;ADCCON2|=SET_BIT7
#define set_ADCCON2_ADCMPOP              SFRS=0;ADCCON2|=SET_BIT6
#define set_ADCCON2_ADCMPEN              SFRS=0;ADCCON2|=SET_BIT5
#define set_ADCCON2_ADCMPO               SFRS=0;ADCCON2|=SET_BIT4
#define set_ADCCON2_ADCDLY.8             SFRS=0;ADCCON2|=SET_BIT0

#define clr_ADCCON2_ADFBEN               SFRS=0;ADCCON2&=CLR_BIT7
#define clr_ADCCON2_ADCMPOP              SFRS=0;ADCCON2&=CLR_BIT6
#define clr_ADCCON2_ADCMPEN              SFRS=0;ADCCON2&=CLR_BIT5
#define clr_ADCCON2_ADCMPO               SFRS=0;ADCCON2&=CLR_BIT4
#define clr_ADCCON2_ADCDLY.8             SFRS=0;ADCCON2&=CLR_BIT0

/**** ADCBAH  E4H  PAGE 0 ****/

/**** ADCSR  E7H  PAGE 0 ****/
#define set_ADCSR_SLOW                   SFRS=0;ADCSR|=SET_BIT7
#define set_ADCSR_ADCDIV_2               SFRS=0;ADCSR|=SET_BIT6
#define set_ADCSR_ADCDIV_1               SFRS=0;ADCSR|=SET_BIT5
#define set_ADCSR_ADCDIV_0               SFRS=0;ADCSR|=SET_BIT4
#define set_ADCSR_CMPHIT                 SFRS=0;ADCSR|=SET_BIT2
#define set_ADCSR_HDONE                  SFRS=0;ADCSR|=SET_BIT1
#define set_ADCSR_FDONE                  SFRS=0;ADCSR|=SET_BIT0

#define clr_ADCSR_SLOW                   SFRS=0;ADCSR&=CLR_BIT7
#define clr_ADCSR_ADCDIV_2               SFRS=0;ADCSR&=CLR_BIT6
#define clr_ADCSR_ADCDIV_1               SFRS=0;ADCSR&=CLR_BIT5
#define clr_ADCSR_ADCDIV_0               SFRS=0;ADCSR&=CLR_BIT4
#define clr_ADCSR_CMPHIT                 SFRS=0;ADCSR&=CLR_BIT2
#define clr_ADCSR_HDONE                  SFRS=0;ADCSR&=CLR_BIT1
#define clr_ADCSR_FDONE                  SFRS=0;ADCSR&=CLR_BIT0

/**** DMA0TSR  E9H  PAGE 0 ****/
#define set_DMA0TSR_ACT                  SFRS=0;DMA0TSR|=SET_BIT2//@
#define set_DMA0TSR_HDONE                SFRS=0;DMA0TSR|=SET_BIT1
#define set_DMA0TSR_FDONE                SFRS=0;DMA0TSR|=SET_BIT0

#define clr_DMA0TSR_ACT                  SFRS=0;DMA0TSR&=CLR_BIT2
#define clr_DMA0TSR_HDONE                SFRS=0;DMA0TSR&=CLR_BIT1
#define clr_DMA0TSR_FDONE                SFRS=0;DMA0TSR&=CLR_BIT0

/**** DMA1CR  EBH  PAGE 0 ****/
#define set_DMA1CR_PSSEL_3                SFRS=0;DMA1CR|=SET_BIT7//@
#define set_DMA1CR_PSSEL_2                SFRS=0;DMA1CR|=SET_BIT6//@
#define set_DMA1CR_PSSEL_1                SFRS=0;DMA1CR|=SET_BIT5//@
#define set_DMA1CR_PSSEL_0                SFRS=0;DMA1CR|=SET_BIT4//@
#define set_DMA1CR_HIE                    SFRS=0;DMA1CR|=SET_BIT3
#define set_DMA1CR_FIE                    SFRS=0;DMA1CR|=SET_BIT2
#define set_DMA1CR_RUN                    SFRS=0;DMA1CR|=SET_BIT1
#define set_DMA1CR_EN                     SFRS=0;DMA1CR|=SET_BIT0

#define clr_DMA1CR_PSSEL_3                SFRS=0;DMA1CR&=CLR_BIT7//@
#define clr_DMA1CR_PSSEL_2                SFRS=0;DMA1CR&=CLR_BIT6//@
#define clr_DMA1CR_PSSEL_1                SFRS=0;DMA1CR&=CLR_BIT5//@
#define clr_DMA1CR_PSSEL_0                SFRS=0;DMA1CR&=CLR_BIT4//@
#define clr_DMA1CR_HIE                    SFRS=0;DMA1CR&=CLR_BIT3
#define clr_DMA1CR_FIE                    SFRS=0;DMA1CR&=CLR_BIT2
#define clr_DMA1CR_RUN                    SFRS=0;DMA1CR&=CLR_BIT1
#define clr_DMA1CR_EN                     SFRS=0;DMA1CR&=CLR_BIT0

/**** EIP0  EFH  PAGE 0 ****/
#define set_EIP0_PT2                     SFRS=0;EIP0|=SET_BIT7
#define set_EIP0_PSPI                    SFRS=0;EIP0|=SET_BIT6
#define set_EIP0_PFB                     SFRS=0;EIP0|=SET_BIT5
#define set_EIP0_PWDT                    SFRS=0;EIP0|=SET_BIT4
#define set_EIP0_PPWM                    SFRS=0;EIP0|=SET_BIT3//@
#define set_EIP0_PCAP                    SFRS=0;EIP0|=SET_BIT2//@
#define set_EIP0_PPI                     SFRS=0;EIP0|=SET_BIT1
#define set_EIP0_PI2C                    SFRS=0;EIP0|=SET_BIT0

#define clr_EIP0_PT2                     SFRS=0;EIP0&=CLR_BIT7
#define clr_EIP0_PSPI                    SFRS=0;EIP0&=CLR_BIT6
#define clr_EIP0_PFB                     SFRS=0;EIP0&=CLR_BIT5
#define clr_EIP0_PWDT                    SFRS=0;EIP0&=CLR_BIT4
#define clr_EIP0_PPWM                    SFRS=0;EIP0&=CLR_BIT3
#define clr_EIP0_PCAP                    SFRS=0;EIP0&=CLR_BIT2
#define clr_EIP0_PPI                     SFRS=0;EIP0&=CLR_BIT1
#define clr_EIP0_PI2C                    SFRS=0;EIP0&=CLR_BIT0

/**** DMA1TSR  F1H  PAGE 0 ****/
#define set_DMA1TSR_ACT                  SFRS=0;DMA1TSR|=SET_BIT2//@
#define set_DMA1TSR_HDONE                SFRS=0;DMA1TSR|=SET_BIT1
#define set_DMA1TSR_FDONE                SFRS=0;DMA1TSR|=SET_BIT0

#define clr_DMA1TSR_ACT                  SFRS=0;DMA1TSR&=CLR_BIT2
#define clr_DMA1TSR_HDONE                SFRS=0;DMA1TSR&=CLR_BIT1
#define clr_DMA1TSR_FDONE                SFRS=0;DMA1TSR&=CLR_BIT0

/**** SPI0CR0  F3H  PAGE 0 ****/
#define set_SPI0CR0_SSOE                 SFRS=0;SPI0CR0|=SET_BIT7
#define set_SPI0CR0_SPIEN                SFRS=0;SPI0CR0|=SET_BIT6
#define set_SPI0CR0_LSBFE                SFRS=0;SPI0CR0|=SET_BIT5
#define set_SPI0CR0_MSTR                 SFRS=0;SPI0CR0|=SET_BIT4
#define set_SPI0CR0_CPOL                 SFRS=0;SPI0CR0|=SET_BIT3//@
#define set_SPI0CR0_CPHA                 SFRS=0;SPI0CR0|=SET_BIT2//@
#define set_SPI0CR0_SPR1                SFRS=0;SPI0CR0|=SET_BIT1
#define set_SPI0CR0_SPR0                SFRS=0;SPI0CR0|=SET_BIT0

#define clr_SPI0CR0_SSOE                 SFRS=0;SPI0CR0&=CLR_BIT7
#define clr_SPI0CR0_SPIEN                SFRS=0;SPI0CR0&=CLR_BIT6
#define clr_SPI0CR0_LSBFE                SFRS=0;SPI0CR0&=CLR_BIT5
#define clr_SPI0CR0_MSTR                 SFRS=0;SPI0CR0&=CLR_BIT4
#define clr_SPI0CR0_CPOL                 SFRS=0;SPI0CR0&=CLR_BIT3
#define clr_SPI0CR0_CPHA                 SFRS=0;SPI0CR0&=CLR_BIT2
#define clr_SPI0CR0_SPR1                 SFRS=0;SPI0CR0&=CLR_BIT1
#define clr_SPI0CR0_SPR0                 SFRS=0;SPI0CR0&=CLR_BIT0

/**** SPI0SR  F4H  PAGE 0 ****/
#define set_SPI0SR_SPIF                  SFRS=0;SPI0SR|=SET_BIT7
#define set_SPI0SR_WCOL                  SFRS=0;SPI0SR|=SET_BIT6
#define set_SPI0SR_SPIOVF                SFRS=0;SPI0SR|=SET_BIT5
#define set_SPI0SR_MODF                  SFRS=0;SPI0SR|=SET_BIT4
#define set_SPI0SR_DISMODF               SFRS=0;SPI0SR|=SET_BIT3//@
#define set_SPI0SR_DISSPIF               SFRS=0;SPI0SR|=SET_BIT2//@
#define set_SPI0SR_TXBUF                 SFRS=0;SPI0SR|=SET_BIT1//@

#define clr_SPI0SR_SPIF                  SFRS=0;SPI0SR&=CLR_BIT7
#define clr_SPI0SR_WCOL                  SFRS=0;SPI0SR&=CLR_BIT6
#define clr_SPI0SR_SPIOVF                SFRS=0;SPI0SR&=CLR_BIT5
#define clr_SPI0SR_MODF                  SFRS=0;SPI0SR&=CLR_BIT4
#define clr_SPI0SR_DISMODF               SFRS=0;SPI0SR&=CLR_BIT3
#define clr_SPI0SR_DISSPIF                SFRS=0;SPI0SR&=CLR_BIT2//@
#define clr_SPI0SR_TXBUF                 SFRS=0;SPI0SR&=CLR_BIT1

/**** DMA0BAH  F6H  PAGE 0 ****/

/**** EIPH0  F7H  PAGE 0 ****/
#define set_EIPH0_PT2H                   SFRS=0;EIPH0|=SET_BIT7
#define set_EIPH0_PSPIH                  SFRS=0;EIPH0|=SET_BIT6
#define set_EIPH0_PFBH                   SFRS=0;EIPH0|=SET_BIT5
#define set_EIPH0_PWDTH                  SFRS=0;EIPH0|=SET_BIT4
#define set_EIPH0_PPWMH                  SFRS=0;EIPH0|=SET_BIT3//@
#define set_EIPH0_PCAPH                  SFRS=0;EIPH0|=SET_BIT2//@
#define set_EIPH0_PPIH                   SFRS=0;EIPH0|=SET_BIT1
#define set_EIPH0_PI2CH                  SFRS=0;EIPH0|=SET_BIT0

#define clr_EIPH0_PT2H                   SFRS=0;EIPH0&=CLR_BIT7
#define clr_EIPH0_PSPIH                  SFRS=0;EIPH0&=CLR_BIT6
#define clr_EIPH0_PFBH                   SFRS=0;EIPH0&=CLR_BIT5
#define clr_EIPH0_PWDTH                  SFRS=0;EIPH0&=CLR_BIT4
#define clr_EIPH0_PPWMH                  SFRS=0;EIPH0&=CLR_BIT3
#define clr_EIPH0_PCAPH                  SFRS=0;EIPH0&=CLR_BIT2
#define clr_EIPH0_PPIH                   SFRS=0;EIPH0&=CLR_BIT1
#define clr_EIPH0_PI2CH                  SFRS=0;EIPH0&=CLR_BIT0

/**** SPI1CR0  F9H  PAGE 0 ****/
#define set_SPI1CR0_SSOE                 SFRS=0;SPI1CR0|=SET_BIT7
#define set_SPI1CR0_SPIEN                SFRS=0;SPI1CR0|=SET_BIT6
#define set_SPI1CR0_LSBFE                SFRS=0;SPI1CR0|=SET_BIT5
#define set_SPI1CR0_MSTR                 SFRS=0;SPI1CR0|=SET_BIT4
#define set_SPI1CR0_CPOL                 SFRS=0;SPI1CR0|=SET_BIT3//@
#define set_SPI1CR0_CPHA                 SFRS=0;SPI1CR0|=SET_BIT2//@
#define set_SPI1CR0_SPR1                 SFRS=0;SPI1CR0|=SET_BIT1
#define set_SPI1CR0_SPR0                 SFRS=0;SPI1CR0|=SET_BIT0

#define clr_SPI1CR0_SSOE                 SFRS=0;SPI1CR0&=CLR_BIT7
#define clr_SPI1CR0_SPIEN                SFRS=0;SPI1CR0&=CLR_BIT6
#define clr_SPI1CR0_LSBFE                SFRS=0;SPI1CR0&=CLR_BIT5
#define clr_SPI1CR0_MSTR                 SFRS=0;SPI1CR0&=CLR_BIT4
#define clr_SPI1CR0_CPOL                 SFRS=0;SPI1CR0&=CLR_BIT3
#define clr_SPI1CR0_CPHA                 SFRS=0;SPI1CR0&=CLR_BIT2
#define clr_SPI1CR0_SPR1                 SFRS=0;SPI1CR0&=CLR_BIT1
#define clr_SPI1CR0_SPR0                 SFRS=0;SPI1CR0&=CLR_BIT0

/**** SPI1CR1  FAH  PAGE 0 ****/
#define set_SPI1CR1_SPR3                 SFRS=0;SPI1CR1|=SET_BIT5
#define set_SPI1CR1_SPR2                 SFRS=0;SPI1CR1|=SET_BIT4
#define set_SPI1CR1_TXDMAEN              SFRS=0;SPI1CR1|=SET_BIT3//@
#define set_SPI1CR1_RXDMAEN              SFRS=0;SPI1CR1|=SET_BIT2//@
#define set_SPI1CR1_SPIS1                SFRS=0;SPI1CR1|=SET_BIT1
#define set_SPI1CR1_SPIS0                SFRS=0;SPI1CR1|=SET_BIT0

#define clr_SPI1CR1_SPR3                 SFRS=0;SPI1CR1&=CLR_BIT5
#define clr_SPI1CR1_SPR2                 SFRS=0;SPI1CR1&=CLR_BIT4
#define clr_SPI1CR1_TXDMAEN              SFRS=0;SPI1CR1&=CLR_BIT3
#define clr_SPI1CR1_RXDMAEN              SFRS=0;SPI1CR1&=CLR_BIT2
#define clr_SPI1CR1_SPIS1                SFRS=0;SPI1CR1&=CLR_BIT1
#define clr_SPI1CR1_SPIS0                SFRS=0;SPI1CR1&=CLR_BIT0

/**** SPI1SR  FBH  PAGE 0 ****/
#define set_SPI1SR_SPIF                  SFRS=0;SPI1SR|=SET_BIT7
#define set_SPI1SR_WCOL                  SFRS=0;SPI1SR|=SET_BIT6
#define set_SPI1SR_SPIOVF                SFRS=0;SPI1SR|=SET_BIT5
#define set_SPI1SR_MODF                  SFRS=0;SPI1SR|=SET_BIT4
#define set_SPI1SR_DISMODF               SFRS=0;SPI1SR|=SET_BIT3//@
#define set_SPI1SR_DISSPIF               SFRS=0;SPI1SR|=SET_BIT2//@
#define set_SPI1SR_TXBFF                 SFRS=0;SPI1SR|=SET_BIT1

#define clr_SPI1SR_SPIF                  SFRS=0;SPI1SR&=CLR_BIT7
#define clr_SPI1SR_WCOL                  SFRS=0;SPI1SR&=CLR_BIT6
#define clr_SPI1SR_SPIOVF                SFRS=0;SPI1SR&=CLR_BIT5
#define clr_SPI1SR_MODF                  SFRS=0;SPI1SR&=CLR_BIT4
#define clr_SPI1SR_DISMODF               SFRS=0;SPI1SR&=CLR_BIT3
#define clr_SPI1SR_DISSPIF               SFRS=0;SPI1SR&=CLR_BIT2
#define clr_SPI1SR_TXBFF                 SFRS=0;SPI1SR&=CLR_BIT1

/**** DMA1BAH  FDH  PAGE 0 ****/

/**** EIP1  FEH  PAGE 0 ****/
#define set_EIP1_PWKT                    SFRS=0;EIP1|=SET_BIT2//@
#define set_EIP1_PT3                     SFRS=0;EIP1|=SET_BIT1
#define set_EIP1_PS_1                    SFRS=0;EIP1|=SET_BIT0

#define clr_EIP1_PWKT                    SFRS=0;EIP1&=CLR_BIT2
#define clr_EIP1_PT3                     SFRS=0;EIP1&=CLR_BIT1
#define clr_EIP1_PS_1                    SFRS=0;EIP1&=CLR_BIT0

/**** EIPH1  FFH  PAGE 0 ****/
#define set_EIPH1_PWKTH                  SFRS=0;EIPH1|=SET_BIT2//@
#define set_EIPH1_PT3H                   SFRS=0;EIPH1|=SET_BIT1
#define set_EIPH1_PSH_1                  SFRS=0;EIPH1|=SET_BIT0

#define clr_EIPH1_PWKTH                  SFRS=0;EIPH1&=CLR_BIT2
#define clr_EIPH1_PT3H                   SFRS=0;EIPH1&=CLR_BIT1
#define clr_EIPH1_PSH_1                  SFRS=0;EIPH1&=CLR_BIT0

/**** EIPH1  FFH  PAGE 0 ****/
#define set_EIPH1_7                      SFRS=0;EIPH1|=SET_BIT7
#define set_EIPH1_6                      SFRS=0;EIPH1|=SET_BIT6
#define set_EIPH1_5                      SFRS=0;EIPH1|=SET_BIT5
#define set_EIPH1_4                      SFRS=0;EIPH1|=SET_BIT4
#define set_EIPH1_3                      SFRS=0;EIPH1|=SET_BIT3//@
#define set_EIPH1_2                      SFRS=0;EIPH1|=SET_BIT2//@
#define set_EIPH1_1                      SFRS=0;EIPH1|=SET_BIT1
#define set_EIPH1_0                      SFRS=0;EIPH1|=SET_BIT0

#define clr_EIPH1_7                      SFRS=0;EIPH1&=CLR_BIT7
#define clr_EIPH1_6                      SFRS=0;EIPH1&=CLR_BIT6
#define clr_EIPH1_5                      SFRS=0;EIPH1&=CLR_BIT5
#define clr_EIPH1_4                      SFRS=0;EIPH1&=CLR_BIT4
#define clr_EIPH1_3                      SFRS=0;EIPH1&=CLR_BIT3
#define clr_EIPH1_2                      SFRS=0;EIPH1&=CLR_BIT2
#define clr_EIPH1_1                      SFRS=0;EIPH1&=CLR_BIT1
#define clr_EIPH1_0                      SFRS=0;EIPH1&=CLR_BIT0

/********SFR PAGE 1*************/
/**** P1DW  8BH  PAGE 1 ****/
#define set_P1DW_7                       SFRS=1;P1DW|=SET_BIT7
#define set_P1DW_6                       SFRS=1;P1DW|=SET_BIT6
#define set_P1DW_5                       SFRS=1;P1DW|=SET_BIT5
#define set_P1DW_4                       SFRS=1;P1DW|=SET_BIT4
#define set_P1DW_3                       SFRS=1;P1DW|=SET_BIT3//@
#define set_P1DW_2                       SFRS=1;P1DW|=SET_BIT2//@
#define set_P1DW_1                       SFRS=1;P1DW|=SET_BIT1
#define set_P1DW_0                       SFRS=1;P1DW|=SET_BIT0

#define clr_P1DW_7                       SFRS=1;P1DW&=CLR_BIT7
#define clr_P1DW_6                       SFRS=1;P1DW&=CLR_BIT6
#define clr_P1DW_5                       SFRS=1;P1DW&=CLR_BIT5
#define clr_P1DW_4                       SFRS=1;P1DW&=CLR_BIT4
#define clr_P1DW_3                       SFRS=1;P1DW&=CLR_BIT3
#define clr_P1DW_2                       SFRS=1;P1DW&=CLR_BIT2
#define clr_P1DW_1                       SFRS=1;P1DW&=CLR_BIT1
#define clr_P1DW_0                       SFRS=1;P1DW&=CLR_BIT0

/**** P2DW  8CH  PAGE 1 ****/
#define set_P2DW_7                       SFRS=1;P2DW|=SET_BIT7
#define set_P2DW_6                       SFRS=1;P2DW|=SET_BIT6
#define set_P2DW_5                       SFRS=1;P2DW|=SET_BIT5
#define set_P2DW_4                       SFRS=1;P2DW|=SET_BIT4
#define set_P2DW_3                       SFRS=1;P2DW|=SET_BIT3//@
#define set_P2DW_2                       SFRS=1;P2DW|=SET_BIT2//@
#define set_P2DW_1                       SFRS=1;P2DW|=SET_BIT1
#define set_P2DW_0                       SFRS=1;P2DW|=SET_BIT0

#define clr_P2DW_7                       SFRS=1;P2DW&=CLR_BIT7
#define clr_P2DW_6                       SFRS=1;P2DW&=CLR_BIT6
#define clr_P2DW_5                       SFRS=1;P2DW&=CLR_BIT5
#define clr_P2DW_4                       SFRS=1;P2DW&=CLR_BIT4
#define clr_P2DW_3                       SFRS=1;P2DW&=CLR_BIT3
#define clr_P2DW_2                       SFRS=1;P2DW&=CLR_BIT2
#define clr_P2DW_1                       SFRS=1;P2DW&=CLR_BIT1
#define clr_P2DW_0                       SFRS=1;P2DW&=CLR_BIT0

/**** P3DW  8DH  PAGE 1 ****/
#define set_P3DW_7                       SFRS=1;P3DW|=SET_BIT7
#define set_P3DW_6                       SFRS=1;P3DW|=SET_BIT6
#define set_P3DW_5                       SFRS=1;P3DW|=SET_BIT5
#define set_P3DW_4                       SFRS=1;P3DW|=SET_BIT4
#define set_P3DW_3                       SFRS=1;P3DW|=SET_BIT3//@
#define set_P3DW_2                       SFRS=1;P3DW|=SET_BIT2//@
#define set_P3DW_1                       SFRS=1;P3DW|=SET_BIT1
#define set_P3DW_0                       SFRS=1;P3DW|=SET_BIT0

#define clr_P3DW_7                       SFRS=1;P3DW&=CLR_BIT7
#define clr_P3DW_6                       SFRS=1;P3DW&=CLR_BIT6
#define clr_P3DW_5                       SFRS=1;P3DW&=CLR_BIT5
#define clr_P3DW_4                       SFRS=1;P3DW&=CLR_BIT4
#define clr_P3DW_3                       SFRS=1;P3DW&=CLR_BIT3
#define clr_P3DW_2                       SFRS=1;P3DW&=CLR_BIT2
#define clr_P3DW_1                       SFRS=1;P3DW&=CLR_BIT1
#define clr_P3DW_0                       SFRS=1;P3DW&=CLR_BIT0

/**** P4DW  8EH  PAGE 1 ****/
#define set_P4DW_7                       SFRS=1;P4DW|=SET_BIT7
#define set_P4DW_6                       SFRS=1;P4DW|=SET_BIT6
#define set_P4DW_5                       SFRS=1;P4DW|=SET_BIT5
#define set_P4DW_4                       SFRS=1;P4DW|=SET_BIT4
#define set_P4DW_3                       SFRS=1;P4DW|=SET_BIT3//@
#define set_P4DW_2                       SFRS=1;P4DW|=SET_BIT2//@
#define set_P4DW_1                       SFRS=1;P4DW|=SET_BIT1
#define set_P4DW_0                       SFRS=1;P4DW|=SET_BIT0

#define clr_P4DW_7                       SFRS=1;P4DW&=CLR_BIT7
#define clr_P4DW_6                       SFRS=1;P4DW&=CLR_BIT6
#define clr_P4DW_5                       SFRS=1;P4DW&=CLR_BIT5
#define clr_P4DW_4                       SFRS=1;P4DW&=CLR_BIT4
#define clr_P4DW_3                       SFRS=1;P4DW&=CLR_BIT3
#define clr_P4DW_2                       SFRS=1;P4DW&=CLR_BIT2
#define clr_P4DW_1                       SFRS=1;P4DW&=CLR_BIT1
#define clr_P4DW_0                       SFRS=1;P4DW&=CLR_BIT0

/**** P5DW  8FH  PAGE 1 ****/
#define set_P5DW_7                       SFRS=1;P5DW|=SET_BIT7
#define set_P5DW_6                       SFRS=1;P5DW|=SET_BIT6
#define set_P5DW_5                       SFRS=1;P5DW|=SET_BIT5
#define set_P5DW_4                       SFRS=1;P5DW|=SET_BIT4
#define set_P5DW_3                       SFRS=1;P5DW|=SET_BIT3//@
#define set_P5DW_2                       SFRS=1;P5DW|=SET_BIT2//@
#define set_P5DW_1                       SFRS=1;P5DW|=SET_BIT1
#define set_P5DW_0                       SFRS=1;P5DW|=SET_BIT0

#define clr_P5DW_7                       SFRS=1;P5DW&=CLR_BIT7
#define clr_P5DW_6                       SFRS=1;P5DW&=CLR_BIT6
#define clr_P5DW_5                       SFRS=1;P5DW&=CLR_BIT5
#define clr_P5DW_4                       SFRS=1;P5DW&=CLR_BIT4
#define clr_P5DW_3                       SFRS=1;P5DW&=CLR_BIT3
#define clr_P5DW_2                       SFRS=1;P5DW&=CLR_BIT2
#define clr_P5DW_1                       SFRS=1;P5DW&=CLR_BIT1
#define clr_P5DW_0                       SFRS=1;P5DW&=CLR_BIT0

/**** P0SR  92H  PAGE 1 ****/
#define set_P0SR_7                       SFRS=1;P0SR|=SET_BIT7
#define set_P0SR_6                       SFRS=1;P0SR|=SET_BIT6
#define set_P0SR_5                       SFRS=1;P0SR|=SET_BIT5
#define set_P0SR_4                       SFRS=1;P0SR|=SET_BIT4
#define set_P0SR_3                       SFRS=1;P0SR|=SET_BIT3//@
#define set_P0SR_2                       SFRS=1;P0SR|=SET_BIT2//@
#define set_P0SR_1                       SFRS=1;P0SR|=SET_BIT1
#define set_P0SR_0                       SFRS=1;P0SR|=SET_BIT0

#define clr_P0SR_7                       SFRS=1;P0SR&=CLR_BIT7
#define clr_P0SR_6                       SFRS=1;P0SR&=CLR_BIT6
#define clr_P0SR_5                       SFRS=1;P0SR&=CLR_BIT5
#define clr_P0SR_4                       SFRS=1;P0SR&=CLR_BIT4
#define clr_P0SR_3                       SFRS=1;P0SR&=CLR_BIT3
#define clr_P0SR_2                       SFRS=1;P0SR&=CLR_BIT2
#define clr_P0SR_1                       SFRS=1;P0SR&=CLR_BIT1
#define clr_P0SR_0                       SFRS=1;P0SR&=CLR_BIT0

/**** P1UP  93H  PAGE 1 ****/
#define set_P1UP_7                       SFRS=1;P1UP|=SET_BIT7
#define set_P1UP_6                       SFRS=1;P1UP|=SET_BIT6
#define set_P1UP_5                       SFRS=1;P1UP|=SET_BIT5
#define set_P1UP_4                       SFRS=1;P1UP|=SET_BIT4
#define set_P1UP_3                       SFRS=1;P1UP|=SET_BIT3//@
#define set_P1UP_2                       SFRS=1;P1UP|=SET_BIT2//@
#define set_P1UP_1                       SFRS=1;P1UP|=SET_BIT1
#define set_P1UP_0                       SFRS=1;P1UP|=SET_BIT0

#define clr_P1UP_7                       SFRS=1;P1UP&=CLR_BIT7
#define clr_P1UP_6                       SFRS=1;P1UP&=CLR_BIT6
#define clr_P1UP_5                       SFRS=1;P1UP&=CLR_BIT5
#define clr_P1UP_4                       SFRS=1;P1UP&=CLR_BIT4
#define clr_P1UP_3                       SFRS=1;P1UP&=CLR_BIT3
#define clr_P1UP_2                       SFRS=1;P1UP&=CLR_BIT2
#define clr_P1UP_1                       SFRS=1;P1UP&=CLR_BIT1
#define clr_P1UP_0                       SFRS=1;P1UP&=CLR_BIT0

/**** P2UP  94H  PAGE 1 ****/
#define set_P2UP_7                       SFRS=1;P2UP|=SET_BIT7
#define set_P2UP_6                       SFRS=1;P2UP|=SET_BIT6
#define set_P2UP_5                       SFRS=1;P2UP|=SET_BIT5
#define set_P2UP_4                       SFRS=1;P2UP|=SET_BIT4
#define set_P2UP_3                       SFRS=1;P2UP|=SET_BIT3//@
#define set_P2UP_2                       SFRS=1;P2UP|=SET_BIT2//@
#define set_P2UP_1                       SFRS=1;P2UP|=SET_BIT1
#define set_P2UP_0                       SFRS=1;P2UP|=SET_BIT0

#define clr_P2UP_7                       SFRS=1;P2UP&=CLR_BIT7
#define clr_P2UP_6                       SFRS=1;P2UP&=CLR_BIT6
#define clr_P2UP_5                       SFRS=1;P2UP&=CLR_BIT5
#define clr_P2UP_4                       SFRS=1;P2UP&=CLR_BIT4
#define clr_P2UP_3                       SFRS=1;P2UP&=CLR_BIT3
#define clr_P2UP_2                       SFRS=1;P2UP&=CLR_BIT2
#define clr_P2UP_1                       SFRS=1;P2UP&=CLR_BIT1
#define clr_P2UP_0                       SFRS=1;P2UP&=CLR_BIT0

/**** P3UP  95H  PAGE 1 ****/
#define set_P3UP_7                       SFRS=1;P3UP|=SET_BIT7
#define set_P3UP_6                       SFRS=1;P3UP|=SET_BIT6
#define set_P3UP_5                       SFRS=1;P3UP|=SET_BIT5
#define set_P3UP_4                       SFRS=1;P3UP|=SET_BIT4
#define set_P3UP_3                       SFRS=1;P3UP|=SET_BIT3//@
#define set_P3UP_2                       SFRS=1;P3UP|=SET_BIT2//@
#define set_P3UP_1                       SFRS=1;P3UP|=SET_BIT1
#define set_P3UP_0                       SFRS=1;P3UP|=SET_BIT0

#define clr_P3UP_7                       SFRS=1;P3UP&=CLR_BIT7
#define clr_P3UP_6                       SFRS=1;P3UP&=CLR_BIT6
#define clr_P3UP_5                       SFRS=1;P3UP&=CLR_BIT5
#define clr_P3UP_4                       SFRS=1;P3UP&=CLR_BIT4
#define clr_P3UP_3                       SFRS=1;P3UP&=CLR_BIT3
#define clr_P3UP_2                       SFRS=1;P3UP&=CLR_BIT2
#define clr_P3UP_1                       SFRS=1;P3UP&=CLR_BIT1
#define clr_P3UP_0                       SFRS=1;P3UP&=CLR_BIT0

/**** P4UP  96H  PAGE 1 ****/
#define set_P4UP_7                       SFRS=1;P4UP|=SET_BIT7
#define set_P4UP_6                       SFRS=1;P4UP|=SET_BIT6
#define set_P4UP_5                       SFRS=1;P4UP|=SET_BIT5
#define set_P4UP_4                       SFRS=1;P4UP|=SET_BIT4
#define set_P4UP_3                       SFRS=1;P4UP|=SET_BIT3//@
#define set_P4UP_2                       SFRS=1;P4UP|=SET_BIT2//@
#define set_P4UP_1                       SFRS=1;P4UP|=SET_BIT1
#define set_P4UP_0                       SFRS=1;P4UP|=SET_BIT0

#define clr_P4UP_7                       SFRS=1;P4UP&=CLR_BIT7
#define clr_P4UP_6                       SFRS=1;P4UP&=CLR_BIT6
#define clr_P4UP_5                       SFRS=1;P4UP&=CLR_BIT5
#define clr_P4UP_4                       SFRS=1;P4UP&=CLR_BIT4
#define clr_P4UP_3                       SFRS=1;P4UP&=CLR_BIT3
#define clr_P4UP_2                       SFRS=1;P4UP&=CLR_BIT2
#define clr_P4UP_1                       SFRS=1;P4UP&=CLR_BIT1
#define clr_P4UP_0                       SFRS=1;P4UP&=CLR_BIT0

/**** P5UP  97H  PAGE 1 ****/
#define set_P5UP_7                       SFRS=1;P5UP|=SET_BIT7
#define set_P5UP_6                       SFRS=1;P5UP|=SET_BIT6
#define set_P5UP_5                       SFRS=1;P5UP|=SET_BIT5
#define set_P5UP_4                       SFRS=1;P5UP|=SET_BIT4
#define set_P5UP_P4UP.3                  SFRS=1;P5UP|=SET_BIT3//@
#define set_P5UP_2                       SFRS=1;P5UP|=SET_BIT2//@
#define set_P5UP_1                       SFRS=1;P5UP|=SET_BIT1
#define set_P5UP_0                       SFRS=1;P5UP|=SET_BIT0

#define clr_P5UP_7                       SFRS=1;P5UP&=CLR_BIT7
#define clr_P5UP_6                       SFRS=1;P5UP&=CLR_BIT6
#define clr_P5UP_5                       SFRS=1;P5UP&=CLR_BIT5
#define clr_P5UP_4                       SFRS=1;P5UP&=CLR_BIT4
#define clr_P5UP_P4UP.3                  SFRS=1;P5UP&=CLR_BIT3
#define clr_P5UP_2                       SFRS=1;P5UP&=CLR_BIT2
#define clr_P5UP_1                       SFRS=1;P5UP&=CLR_BIT1
#define clr_P5UP_0                       SFRS=1;P5UP&=CLR_BIT0

// /**** P0S  99H  PAGE 1 ****/
// #define set_P0S_P0SR.7                   SFRS=1;P0S|=SET_BIT7
// #define set_P0S_P0SR.6                   SFRS=1;P0S|=SET_BIT6
// #define set_P0S_P0SR.5                   SFRS=1;P0S|=SET_BIT5
// #define set_P0S_P0SR.4                   SFRS=1;P0S|=SET_BIT4
// #define set_P0S_P0SR.3                   SFRS=1;P0S|=SET_BIT4
// #define set_P0S_P0SR.2                   SFRS=1;P0S|=SET_BIT3
// #define set_P0S_P0SR.1                   SFRS=1;P0S|=SET_BIT1
// #define set_P0S_P0SR.0                   SFRS=1;P0S|=SET_BIT0

// #define clr_P0S_P0SR.7                   SFRS=1;P0S&=CLR_BIT7
// #define clr_P0S_P0SR.6                   SFRS=1;P0S&=CLR_BIT6
// #define clr_P0S_P0SR.5                   SFRS=1;P0S&=CLR_BIT5
// #define clr_P0S_P0SR.4                   SFRS=1;P0S&=CLR_BIT4
// #define clr_P0S_P0SR.3                   SFRS=1;P0S&=CLR_BIT3
// #define clr_P0S_P0SR.2                   SFRS=1;P0S&=CLR_BIT2
// #define clr_P0S_P0SR.1                   SFRS=1;P0S&=CLR_BIT1
// #define clr_P0S_P0SR.0                   SFRS=1;P0S&=CLR_BIT0

/**** P0UP  9AH  PAGE 1 ****/
#define set_P0UP_7                       SFRS=1;P0UP|=SET_BIT7
#define set_P0UP_6                       SFRS=1;P0UP|=SET_BIT6
#define set_P0UP_5                       SFRS=1;P0UP|=SET_BIT5
#define set_P0UP_4                       SFRS=1;P0UP|=SET_BIT4
#define set_P0UP_3                       SFRS=1;P0UP|=SET_BIT3//@
#define set_P0UP_2                       SFRS=1;P0UP|=SET_BIT2//@
#define set_P0UP_1                       SFRS=1;P0UP|=SET_BIT1
#define set_P0UP_0                       SFRS=1;P0UP|=SET_BIT0

#define clr_P0UP_7                       SFRS=1;P0UP&=CLR_BIT7
#define clr_P0UP_6                       SFRS=1;P0UP&=CLR_BIT6
#define clr_P0UP_5                       SFRS=1;P0UP&=CLR_BIT5
#define clr_P0UP_4                       SFRS=1;P0UP&=CLR_BIT4
#define clr_P0UP_3                       SFRS=1;P0UP&=CLR_BIT3
#define clr_P0UP_2                       SFRS=1;P0UP&=CLR_BIT2
#define clr_P0UP_1                       SFRS=1;P0UP&=CLR_BIT1
#define clr_P0UP_0                       SFRS=1;P0UP&=CLR_BIT0

/**** P1S  9BH  PAGE 1 ****/
// #define set_P1S_P1SR.7                   SFRS=1;P1S|=SET_BIT7
// #define set_P1S_P1SR.6                   SFRS=1;P1S|=SET_BIT6
// #define set_P1S_P1SR.5                   SFRS=1;P1S|=SET_BIT5
// #define set_P1S_P1SR.4                   SFRS=1;P1S|=SET_BIT4
// #define set_P1S_P1SR.3                   SFRS=1;P1S|=SET_BIT4
// #define set_P1S_P1SR.2                   SFRS=1;P1S|=SET_BIT3
// #define set_P1S_P1SR.1                   SFRS=1;P1S|=SET_BIT1
// #define set_P1S_P1SR.0                   SFRS=1;P1S|=SET_BIT0

// #define clr_P1S_P1SR.7                   SFRS=1;P1S&=CLR_BIT7
// #define clr_P1S_P1SR.6                   SFRS=1;P1S&=CLR_BIT6
// #define clr_P1S_P1SR.5                   SFRS=1;P1S&=CLR_BIT5
// #define clr_P1S_P1SR.4                   SFRS=1;P1S&=CLR_BIT4
// #define clr_P1S_P1SR.3                   SFRS=1;P1S&=CLR_BIT3
// #define clr_P1S_P1SR.2                   SFRS=1;P1S&=CLR_BIT2
// #define clr_P1S_P1SR.1                   SFRS=1;P1S&=CLR_BIT1
// #define clr_P1S_P1SR.0                   SFRS=1;P1S&=CLR_BIT0

// /**** P1SR  9CH  PAGE 1 ****/
// #define set_P1SR_P2SR.7                  SFRS=1;P1SR|=SET_BIT7
// #define set_P1SR_P2SR.6                  SFRS=1;P1SR|=SET_BIT6
// #define set_P1SR_P2SR.5                  SFRS=1;P1SR|=SET_BIT5
// #define set_P1SR_P2SR.4                  SFRS=1;P1SR|=SET_BIT4
// #define set_P1SR_P2SR.3                  SFRS=1;P1SR|=SET_BIT4
// #define set_P1SR_P2SR.2                  SFRS=1;P1SR|=SET_BIT3
// #define set_P1SR_P2SR.1                  SFRS=1;P1SR|=SET_BIT1
// #define set_P1SR_P2SR.0                  SFRS=1;P1SR|=SET_BIT0

// #define clr_P1SR_P2SR.7                  SFRS=1;P1SR&=CLR_BIT7
// #define clr_P1SR_P2SR.6                  SFRS=1;P1SR&=CLR_BIT6
// #define clr_P1SR_P2SR.5                  SFRS=1;P1SR&=CLR_BIT5
// #define clr_P1SR_P2SR.4                  SFRS=1;P1SR&=CLR_BIT4
// #define clr_P1SR_P2SR.3                  SFRS=1;P1SR&=CLR_BIT3
// #define clr_P1SR_P2SR.2                  SFRS=1;P1SR&=CLR_BIT2
// #define clr_P1SR_P2SR.1                  SFRS=1;P1SR&=CLR_BIT1
// #define clr_P1SR_P2SR.0                  SFRS=1;P1SR&=CLR_BIT0

/**** P2S  9DH  PAGE 1 ****/
#define set_P2S_7                        SFRS=1;P2S|=SET_BIT7
#define set_P2S_6                        SFRS=1;P2S|=SET_BIT6
#define set_P2S_5                        SFRS=1;P2S|=SET_BIT5
#define set_P2S_4                        SFRS=1;P2S|=SET_BIT4
#define set_P2S_3                        SFRS=1;P2S|=SET_BIT3//@
#define set_P2S_2                        SFRS=1;P2S|=SET_BIT2//@
#define set_P2S_1                        SFRS=1;P2S|=SET_BIT1
#define set_P2S_0                        SFRS=1;P2S|=SET_BIT0

#define clr_P2S_7                        SFRS=1;P2S&=CLR_BIT7
#define clr_P2S_6                        SFRS=1;P2S&=CLR_BIT6
#define clr_P2S_5                        SFRS=1;P2S&=CLR_BIT5
#define clr_P2S_4                        SFRS=1;P2S&=CLR_BIT4
#define clr_P2S_3                        SFRS=1;P2S&=CLR_BIT3
#define clr_P2S_2                        SFRS=1;P2S&=CLR_BIT2
#define clr_P2S_1                        SFRS=1;P2S&=CLR_BIT1
#define clr_P2S_0                        SFRS=1;P2S&=CLR_BIT0

/**** P2SR  9EH  PAGE 1 ****/
#define set_P2SR_7                       SFRS=1;P2SR|=SET_BIT7
#define set_P2SR_6                       SFRS=1;P2SR|=SET_BIT6
#define set_P2SR_5                       SFRS=1;P2SR|=SET_BIT5
#define set_P2SR_4                       SFRS=1;P2SR|=SET_BIT4
#define set_P2SR_3                       SFRS=1;P2SR|=SET_BIT3//@
#define set_P2SR_2                       SFRS=1;P2SR|=SET_BIT2//@
#define set_P2SR_1                       SFRS=1;P2SR|=SET_BIT1
#define set_P2SR_0                       SFRS=1;P2SR|=SET_BIT0

#define clr_P2SR_7                       SFRS=1;P2SR&=CLR_BIT7
#define clr_P2SR_6                       SFRS=1;P2SR&=CLR_BIT6
#define clr_P2SR_5                       SFRS=1;P2SR&=CLR_BIT5
#define clr_P2SR_4                       SFRS=1;P2SR&=CLR_BIT4
#define clr_P2SR_3                       SFRS=1;P2SR&=CLR_BIT3
#define clr_P2SR_2                       SFRS=1;P2SR&=CLR_BIT2
#define clr_P2SR_1                       SFRS=1;P2SR&=CLR_BIT1
#define clr_P2SR_0                       SFRS=1;P2SR&=CLR_BIT0

/**** PIPS0  A1H  PAGE 1 ****/
/**** PIPS1  A2H  PAGE 1 ****/
/**** PIPS2  A3H  PAGE 1 ****/
/**** PIPS3  A4H  PAGE 1 ****/
/**** PIPS4  A5H  PAGE 1 ****/
/**** PIPS5  A6H  PAGE 1 ****/
/**** PIPS6  A7H  PAGE 1 ****/

/**** VRFCON  A9H  PAGE 1 ****/
#define set_VRFCON_VRFSEL_2              SFRS=1;VRFCON|=SET_BIT6
#define set_VRFCON_VRFSEL_1              SFRS=1;VRFCON|=SET_BIT5
#define set_VRFCON_VRFSEL_0              SFRS=1;VRFCON|=SET_BIT4
#define set_VRFCON_ENLOAD                SFRS=1;VRFCON|=SET_BIT1
#define set_VRFCON_ENVRF                 SFRS=1;VRFCON|=SET_BIT0

#define clr_VRFCON_VRFSEL_2              SFRS=1;VRFCON&=CLR_BIT6
#define clr_VRFCON_VRFSEL_1              SFRS=1;VRFCON&=CLR_BIT5
#define clr_VRFCON_VRFSEL_0              SFRS=1;VRFCON&=CLR_BIT4
#define clr_VRFCON_ENLOAD                SFRS=1;VRFCON&=CLR_BIT1
#define clr_VRFCON_ENVRF                 SFRS=1;VRFCON&=CLR_BIT0

/**** ACMPCR2  ABH  PAGE 1 ****/
#define set_ACMPCR2_AO1PEN               SFRS=1;ACMPCR2|=SET_BIT5
#define set_ACMPCR2_AO0PEN               SFRS=1;ACMPCR2|=SET_BIT4
#define set_ACMPCR2_CRVSSEL              SFRS=1;ACMPCR2|=SET_BIT1
#define set_ACMPCR2_CRVEN                SFRS=1;ACMPCR2|=SET_BIT0

#define clr_ACMPCR2_AO1PEN               SFRS=1;ACMPCR2&=CLR_BIT5
#define clr_ACMPCR2_AO0PEN               SFRS=1;ACMPCR2&=CLR_BIT4
#define clr_ACMPCR2_CRVSSEL              SFRS=1;ACMPCR2&=CLR_BIT1
#define clr_ACMPCR2_CRVEN                SFRS=1;ACMPCR2&=CLR_BIT0

/**** P3S  ACH  PAGE 1 ****/
#define set_P3S_7                        SFRS=1;P3S|=SET_BIT7
#define set_P3S_6                        SFRS=1;P3S|=SET_BIT6
#define set_P3S_5                        SFRS=1;P3S|=SET_BIT5
#define set_P3S_4                        SFRS=1;P3S|=SET_BIT4
#define set_P3S_3                        SFRS=1;P3S|=SET_BIT3//@
#define set_P3S_2                        SFRS=1;P3S|=SET_BIT2//@
#define set_P3S_1                        SFRS=1;P3S|=SET_BIT1
#define set_P3S_0                        SFRS=1;P3S|=SET_BIT0

#define clr_P3S_7                        SFRS=1;P3S&=CLR_BIT7
#define clr_P3S_6                        SFRS=1;P3S&=CLR_BIT6
#define clr_P3S_5                        SFRS=1;P3S&=CLR_BIT5
#define clr_P3S_4                        SFRS=1;P3S&=CLR_BIT4
#define clr_P3S_3                        SFRS=1;P3S&=CLR_BIT3
#define clr_P3S_2                        SFRS=1;P3S&=CLR_BIT2
#define clr_P3S_1                        SFRS=1;P3S&=CLR_BIT1
#define clr_P3S_0                        SFRS=1;P3S&=CLR_BIT0

/**** P3SR  ADH  PAGE 1 ****/
#define set_P3SR_7                       SFRS=1;P3SR|=SET_BIT7
#define set_P3SR_6                       SFRS=1;P3SR|=SET_BIT6
#define set_P3SR_5                       SFRS=1;P3SR|=SET_BIT5
#define set_P3SR_4                       SFRS=1;P3SR|=SET_BIT4
#define set_P3SR_3                       SFRS=1;P3SR|=SET_BIT3//@
#define set_P3SR_2                       SFRS=1;P3SR|=SET_BIT2//@
#define set_P3SR_1                       SFRS=1;P3SR|=SET_BIT1
#define set_P3SR_0                       SFRS=1;P3SR|=SET_BIT0

#define clr_P3SR_7                       SFRS=1;P3SR&=CLR_BIT7
#define clr_P3SR_6                       SFRS=1;P3SR&=CLR_BIT6
#define clr_P3SR_5                       SFRS=1;P3SR&=CLR_BIT5
#define clr_P3SR_4                       SFRS=1;P3SR&=CLR_BIT4
#define clr_P3SR_3                       SFRS=1;P3SR&=CLR_BIT3
#define clr_P3SR_2                       SFRS=1;P3SR&=CLR_BIT2
#define clr_P3SR_1                       SFRS=1;P3SR&=CLR_BIT1
#define clr_P3SR_0                       SFRS=1;P3SR&=CLR_BIT0

/**** P5SR  AEH  PAGE 1 ****/
#define set_P5SR_7                       SFRS=1;P5SR|=SET_BIT7
#define set_P5SR_6                       SFRS=1;P5SR|=SET_BIT6
#define set_P5SR_5                       SFRS=1;P5SR|=SET_BIT5
#define set_P5SR_4                       SFRS=1;P5SR|=SET_BIT4
#define set_P5SR_3                       SFRS=1;P5SR|=SET_BIT3//@
#define set_P5SR_2                       SFRS=1;P5SR|=SET_BIT2//@
#define set_P5SR_1                       SFRS=1;P5SR|=SET_BIT1
#define set_P5SR_0                       SFRS=1;P5SR|=SET_BIT0

#define clr_P5SR_7                       SFRS=1;P5SR&=CLR_BIT7
#define clr_P5SR_6                       SFRS=1;P5SR&=CLR_BIT6
#define clr_P5SR_5                       SFRS=1;P5SR&=CLR_BIT5
#define clr_P5SR_4                       SFRS=1;P5SR&=CLR_BIT4
#define clr_P5SR_3                       SFRS=1;P5SR&=CLR_BIT3
#define clr_P5SR_2                       SFRS=1;P5SR&=CLR_BIT2
#define clr_P5SR_1                       SFRS=1;P5SR&=CLR_BIT1
#define clr_P5SR_0                       SFRS=1;P5SR&=CLR_BIT0

/**** PIPS7  AFH  PAGE 1 ****/

/**** P0M1  B1H  PAGE 1 ****/
#define set_P0M1_7                       SFRS=1;P0M1|=SET_BIT7
#define set_P0M1_6                       SFRS=1;P0M1|=SET_BIT6
#define set_P0M1_5                       SFRS=1;P0M1|=SET_BIT5
#define set_P0M1_4                       SFRS=1;P0M1|=SET_BIT4
#define set_P0M1_3                       SFRS=1;P0M1|=SET_BIT3//@
#define set_P0M1_2                       SFRS=1;P0M1|=SET_BIT2//@
#define set_P0M1_1                       SFRS=1;P0M1|=SET_BIT1
#define set_P0M1_0                       SFRS=1;P0M1|=SET_BIT0

#define clr_P0M1_7                       SFRS=1;P0M1&=CLR_BIT7
#define clr_P0M1_6                       SFRS=1;P0M1&=CLR_BIT6
#define clr_P0M1_5                       SFRS=1;P0M1&=CLR_BIT5
#define clr_P0M1_4                       SFRS=1;P0M1&=CLR_BIT4
#define clr_P0M1_3                       SFRS=1;P0M1&=CLR_BIT3
#define clr_P0M1_2                       SFRS=1;P0M1&=CLR_BIT2
#define clr_P0M1_1                       SFRS=1;P0M1&=CLR_BIT1
#define clr_P0M1_0                       SFRS=1;P0M1&=CLR_BIT0

/**** P0M2  B2H  PAGE 1 ****/
#define set_P0M2_7                       SFRS=1;P0M2|=SET_BIT7
#define set_P0M2_6                       SFRS=1;P0M2|=SET_BIT6
#define set_P0M2_5                       SFRS=1;P0M2|=SET_BIT5
#define set_P0M2_4                       SFRS=1;P0M2|=SET_BIT4
#define set_P0M2_3                       SFRS=1;P0M2|=SET_BIT3//@
#define set_P0M2_2                       SFRS=1;P0M2|=SET_BIT2//@
#define set_P0M2_1                       SFRS=1;P0M2|=SET_BIT1
#define set_P0M2_0                       SFRS=1;P0M2|=SET_BIT0

#define clr_P0M2_7                       SFRS=1;P0M2&=CLR_BIT7
#define clr_P0M2_6                       SFRS=1;P0M2&=CLR_BIT6
#define clr_P0M2_5                       SFRS=1;P0M2&=CLR_BIT5
#define clr_P0M2_4                       SFRS=1;P0M2&=CLR_BIT4
#define clr_P0M2_3                       SFRS=1;P0M2&=CLR_BIT3
#define clr_P0M2_2                       SFRS=1;P0M2&=CLR_BIT2
#define clr_P0M2_1                       SFRS=1;P0M2&=CLR_BIT1
#define clr_P0M2_0                       SFRS=1;P0M2&=CLR_BIT0

/**** P1M1  B3H  PAGE 1 ****/
#define set_P1M1_7                       SFRS=1;P1M1|=SET_BIT7
#define set_P1M1_6                       SFRS=1;P1M1|=SET_BIT6
#define set_P1M1_5                       SFRS=1;P1M1|=SET_BIT5
#define set_P1M1_4                       SFRS=1;P1M1|=SET_BIT4
#define set_P1M1_3                       SFRS=1;P1M1|=SET_BIT3//@
#define set_P1M1_2                       SFRS=1;P1M1|=SET_BIT2//@
#define set_P1M1_1                       SFRS=1;P1M1|=SET_BIT1
#define set_P1M1_0                       SFRS=1;P1M1|=SET_BIT0

#define clr_P1M1_7                       SFRS=1;P1M1&=CLR_BIT7
#define clr_P1M1_6                       SFRS=1;P1M1&=CLR_BIT6
#define clr_P1M1_5                       SFRS=1;P1M1&=CLR_BIT5
#define clr_P1M1_4                       SFRS=1;P1M1&=CLR_BIT4
#define clr_P1M1_3                       SFRS=1;P1M1&=CLR_BIT3
#define clr_P1M1_2                       SFRS=1;P1M1&=CLR_BIT2
#define clr_P1M1_1                       SFRS=1;P1M1&=CLR_BIT1
#define clr_P1M1_0                       SFRS=1;P1M1&=CLR_BIT0

/**** P1M2  B4H  PAGE 1 ****/
#define set_P1M2_7                       SFRS=1;P1M2|=SET_BIT7
#define set_P1M2_6                       SFRS=1;P1M2|=SET_BIT6
#define set_P1M2_5                       SFRS=1;P1M2|=SET_BIT5
#define set_P1M2_4                       SFRS=1;P1M2|=SET_BIT4
#define set_P1M2_3                       SFRS=1;P1M2|=SET_BIT3//@
#define set_P1M2_2                       SFRS=1;P1M2|=SET_BIT2//@
#define set_P1M2_1                       SFRS=1;P1M2|=SET_BIT1
#define set_P1M2_0                       SFRS=1;P1M2|=SET_BIT0

#define clr_P1M2_7                       SFRS=1;P1M2&=CLR_BIT7
#define clr_P1M2_6                       SFRS=1;P1M2&=CLR_BIT6
#define clr_P1M2_5                       SFRS=1;P1M2&=CLR_BIT5
#define clr_P1M2_4                       SFRS=1;P1M2&=CLR_BIT4
#define clr_P1M2_3                       SFRS=1;P1M2&=CLR_BIT3
#define clr_P1M2_2                       SFRS=1;P1M2&=CLR_BIT2
#define clr_P1M2_1                       SFRS=1;P1M2&=CLR_BIT1
#define clr_P1M2_0                       SFRS=1;P1M2&=CLR_BIT0

/**** P2M1  B5H  PAGE 1 ****/
#define set_P2M1_7                       SFRS=1;P2M1|=SET_BIT7
#define set_P2M1_6                       SFRS=1;P2M1|=SET_BIT6
#define set_P2M1_5                       SFRS=1;P2M1|=SET_BIT5
#define set_P2M1_4                       SFRS=1;P2M1|=SET_BIT4
#define set_P2M1_3                       SFRS=1;P2M1|=SET_BIT3//@
#define set_P2M1_2                       SFRS=1;P2M1|=SET_BIT2//@
#define set_P2M1_1                       SFRS=1;P2M1|=SET_BIT1
#define set_P2M1_0                       SFRS=1;P2M1|=SET_BIT0

#define clr_P2M1_7                       SFRS=1;P2M1&=CLR_BIT7
#define clr_P2M1_6                       SFRS=1;P2M1&=CLR_BIT6
#define clr_P2M1_5                       SFRS=1;P2M1&=CLR_BIT5
#define clr_P2M1_4                       SFRS=1;P2M1&=CLR_BIT4
#define clr_P2M1_3                       SFRS=1;P2M1&=CLR_BIT3
#define clr_P2M1_2                       SFRS=1;P2M1&=CLR_BIT2
#define clr_P2M1_1                       SFRS=1;P2M1&=CLR_BIT1
#define clr_P2M1_0                       SFRS=1;P2M1&=CLR_BIT0

/**** P2M2  B6H  PAGE 1 ****/
#define set_P2M2_7                       SFRS=1;P2M2|=SET_BIT7
#define set_P2M2_6                       SFRS=1;P2M2|=SET_BIT6
#define set_P2M2_5                       SFRS=1;P2M2|=SET_BIT5
#define set_P2M2_4                       SFRS=1;P2M2|=SET_BIT4
#define set_P2M2_3                       SFRS=1;P2M2|=SET_BIT3//@
#define set_P2M2_2                       SFRS=1;P2M2|=SET_BIT2//#
#define set_P2M2_P5M2.1                  SFRS=1;P2M2|=SET_BIT1
#define set_P2M2_0                       SFRS=1;P2M2|=SET_BIT0

#define clr_P2M2_7                       SFRS=1;P2M2&=CLR_BIT7
#define clr_P2M2_6                       SFRS=1;P2M2&=CLR_BIT6
#define clr_P2M2_5                       SFRS=1;P2M2&=CLR_BIT5
#define clr_P2M2_4                       SFRS=1;P2M2&=CLR_BIT4
#define clr_P2M2_3                       SFRS=1;P2M2&=CLR_BIT3
#define clr_P2M2_2                       SFRS=1;P2M2&=CLR_BIT2
#define clr_P2M2_P5M2.1                  SFRS=1;P2M2&=CLR_BIT1
#define clr_P2M2_0                       SFRS=1;P2M2&=CLR_BIT0

/**** PWM0INTC  B7H  PAGE 1 ****/
#define set_PWM0INTC_INTTYP1             SFRS=1;PWM0INTC|=SET_BIT5
#define set_PWM0INTC_INTTYP0             SFRS=1;PWM0INTC|=SET_BIT4
#define set_PWM0INTC_INTSEL2             SFRS=1;PWM0INTC|=SET_BIT2//@
#define set_PWM0INTC_INTSEL1             SFRS=1;PWM0INTC|=SET_BIT1
#define set_PWM0INTC_INTSEL0             SFRS=1;PWM0INTC|=SET_BIT0

#define clr_PWM0INTC_INTTYP1             SFRS=1;PWM0INTC&=CLR_BIT5
#define clr_PWM0INTC_INTTYP0             SFRS=1;PWM0INTC&=CLR_BIT4
#define clr_PWM0INTC_INTSEL2             SFRS=1;PWM0INTC&=CLR_BIT2
#define clr_PWM0INTC_INTSEL1             SFRS=1;PWM0INTC&=CLR_BIT1
#define clr_PWM0INTC_INTSEL0             SFRS=1;PWM0INTC&=CLR_BIT0

/**** P4M1  B9H  PAGE 1 ****/
#define set_P4M1_7                       SFRS=1;P4M1|=SET_BIT7
#define set_P4M1_6                       SFRS=1;P4M1|=SET_BIT6
#define set_P4M1_5                       SFRS=1;P4M1|=SET_BIT5
#define set_P4M1_4                       SFRS=1;P4M1|=SET_BIT4
#define set_P4M1_3                       SFRS=1;P4M1|=SET_BIT3//@
#define set_P4M1_2                       SFRS=1;P4M1|=SET_BIT2//@
#define set_P4M1_1                       SFRS=1;P4M1|=SET_BIT1
#define set_P4M1_0                       SFRS=1;P4M1|=SET_BIT0

#define clr_P4M1_7                       SFRS=1;P4M1&=CLR_BIT7
#define clr_P4M1_6                       SFRS=1;P4M1&=CLR_BIT6
#define clr_P4M1_5                       SFRS=1;P4M1&=CLR_BIT5
#define clr_P4M1_4                       SFRS=1;P4M1&=CLR_BIT4
#define clr_P4M1_3                       SFRS=1;P4M1&=CLR_BIT3
#define clr_P4M1_2                       SFRS=1;P4M1&=CLR_BIT2
#define clr_P4M1_1                       SFRS=1;P4M1&=CLR_BIT1
#define clr_P4M1_0                       SFRS=1;P4M1&=CLR_BIT0

/**** P0DW  BAH  PAGE 1 ****/
#define set_P0DW_7                       SFRS=1;P0DW|=SET_BIT7
#define set_P0DW_6                       SFRS=1;P0DW|=SET_BIT6
#define set_P0DW_5                       SFRS=1;P0DW|=SET_BIT5
#define set_P0DW_4                       SFRS=1;P0DW|=SET_BIT4
#define set_P0DW_3                       SFRS=1;P0DW|=SET_BIT3//@
#define set_P0DW_2                       SFRS=1;P0DW|=SET_BIT2//@
#define set_P0DW_1                       SFRS=1;P0DW|=SET_BIT1
#define set_P0DW_0                       SFRS=1;P0DW|=SET_BIT0

#define clr_P0DW_7                       SFRS=1;P0DW&=CLR_BIT7
#define clr_P0DW_6                       SFRS=1;P0DW&=CLR_BIT6
#define clr_P0DW_5                       SFRS=1;P0DW&=CLR_BIT5
#define clr_P0DW_4                       SFRS=1;P0DW&=CLR_BIT4
#define clr_P0DW_3                       SFRS=1;P0DW&=CLR_BIT3
#define clr_P0DW_2                       SFRS=1;P0DW&=CLR_BIT2
#define clr_P0DW_1                       SFRS=1;P0DW&=CLR_BIT1
#define clr_P0DW_0                       SFRS=1;P0DW&=CLR_BIT0

/**** P4M2  BAH  PAGE 1 ****/
#define set_P4M2_7                       SFRS=1;P4M2|=SET_BIT7
#define set_P4M2_6                       SFRS=1;P4M2|=SET_BIT6
#define set_P4M2_5                       SFRS=1;P4M2|=SET_BIT5
#define set_P4M2_4                       SFRS=1;P4M2|=SET_BIT4
#define set_P4M2_3                       SFRS=1;P4M2|=SET_BIT3//@
#define set_P4M2_2                       SFRS=1;P4M2|=SET_BIT2//@
#define set_P4M2_1                       SFRS=1;P4M2|=SET_BIT1
#define set_P4M2_0                       SFRS=1;P4M2|=SET_BIT0

#define clr_P4M2_7                       SFRS=1;P4M2&=CLR_BIT7
#define clr_P4M2_6                       SFRS=1;P4M2&=CLR_BIT6
#define clr_P4M2_5                       SFRS=1;P4M2&=CLR_BIT5
#define clr_P4M2_4                       SFRS=1;P4M2&=CLR_BIT4
#define clr_P4M2_3                       SFRS=1;P4M2&=CLR_BIT3
#define clr_P4M2_2                       SFRS=1;P4M2&=CLR_BIT2
#define clr_P4M2_1                       SFRS=1;P4M2&=CLR_BIT1
#define clr_P4M2_0                       SFRS=1;P4M2&=CLR_BIT0

/**** P4S  BBH  PAGE 1 ****/
#define set_P4S_7                        SFRS=1;P4S|=SET_BIT7
#define set_P4S_P54S.6                   SFRS=1;P4S|=SET_BIT6
#define set_P4S_5                        SFRS=1;P4S|=SET_BIT5
#define set_P4S_4                        SFRS=1;P4S|=SET_BIT4
#define set_P4S_3                        SFRS=1;P4S|=SET_BIT3//@
#define set_P4S_2                        SFRS=1;P4S|=SET_BIT2//@
#define set_P4S_1                        SFRS=1;P4S|=SET_BIT1
#define set_P4S_0                        SFRS=1;P4S|=SET_BIT0

#define clr_P4S_7                        SFRS=1;P4S&=CLR_BIT7
#define clr_P4S_P54S.6                   SFRS=1;P4S&=CLR_BIT6
#define clr_P4S_5                        SFRS=1;P4S&=CLR_BIT5
#define clr_P4S_4                        SFRS=1;P4S&=CLR_BIT4
#define clr_P4S_3                        SFRS=1;P4S&=CLR_BIT3
#define clr_P4S_2                        SFRS=1;P4S&=CLR_BIT2
#define clr_P4S_1                        SFRS=1;P4S&=CLR_BIT1
#define clr_P4S_0                        SFRS=1;P4S&=CLR_BIT0

/**** PMW1INTC  BCH  PAGE 1 ****/
#define set_PMW1INTC_INTTYP1             SFRS=1;PMW1INTC|=SET_BIT5
#define set_PMW1INTC_INTTYP0             SFRS=1;PMW1INTC|=SET_BIT4
#define set_PMW1INTC_INTSEL2             SFRS=1;PMW1INTC|=SET_BIT2//@
#define set_PMW1INTC_INTSEL1             SFRS=1;PMW1INTC|=SET_BIT1
#define set_PMW1INTC_INTSEL0             SFRS=1;PMW1INTC|=SET_BIT0

#define clr_PMW1INTC_INTTYP1             SFRS=1;PMW1INTC&=CLR_BIT5
#define clr_PMW1INTC_INTTYP0             SFRS=1;PMW1INTC&=CLR_BIT4
#define clr_PMW1INTC_INTSEL2             SFRS=1;PMW1INTC&=CLR_BIT2
#define clr_PMW1INTC_INTSEL1             SFRS=1;PMW1INTC&=CLR_BIT1
#define clr_PMW1INTC_INTSEL0             SFRS=1;PMW1INTC&=CLR_BIT0

/**** P4SR  BCH  PAGE 1 ****/
#define set_P4SR_7                       SFRS=1;P4SR|=SET_BIT7
#define set_P4SR_6                       SFRS=1;P4SR|=SET_BIT6
#define set_P4SR_5                       SFRS=1;P4SR|=SET_BIT5
#define set_P4SR_4                       SFRS=1;P4SR|=SET_BIT4
#define set_P4SR_3                       SFRS=1;P4SR|=SET_BIT3//@
#define set_P4SR_2                       SFRS=1;P4SR|=SET_BIT2//@
#define set_P4SR_1                       SFRS=1;P4SR|=SET_BIT1
#define set_P4SR_0                       SFRS=1;P4SR|=SET_BIT0

#define clr_P4SR_7                       SFRS=1;P4SR&=CLR_BIT7
#define clr_P4SR_6                       SFRS=1;P4SR&=CLR_BIT6
#define clr_P4SR_5                       SFRS=1;P4SR&=CLR_BIT5
#define clr_P4SR_4                       SFRS=1;P4SR&=CLR_BIT4
#define clr_P4SR_3                       SFRS=1;P4SR&=CLR_BIT3
#define clr_P4SR_2                       SFRS=1;P4SR&=CLR_BIT2
#define clr_P4SR_1                       SFRS=1;P4SR&=CLR_BIT1
#define clr_P4SR_0                       SFRS=1;P4SR&=CLR_BIT0

/**** P5M1  BDH  PAGE 1 ****/
#define set_P5M1_7                       SFRS=1;P5M1|=SET_BIT7
#define set_P5M1_6                       SFRS=1;P5M1|=SET_BIT6
#define set_P5M1_5                       SFRS=1;P5M1|=SET_BIT5
#define set_P5M1_4                       SFRS=1;P5M1|=SET_BIT4
#define set_P5M1_3                       SFRS=1;P5M1|=SET_BIT3//@
#define set_P5M1_2                       SFRS=1;P5M1|=SET_BIT2//@
#define set_P5M1_1                       SFRS=1;P5M1|=SET_BIT1
#define set_P5M1_0                       SFRS=1;P5M1|=SET_BIT0

#define clr_P5M1_7                       SFRS=1;P5M1&=CLR_BIT7
#define clr_P5M1_6                       SFRS=1;P5M1&=CLR_BIT6
#define clr_P5M1_5                       SFRS=1;P5M1&=CLR_BIT5
#define clr_P5M1_4                       SFRS=1;P5M1&=CLR_BIT4
#define clr_P5M1_3                       SFRS=1;P5M1&=CLR_BIT3
#define clr_P5M1_2                       SFRS=1;P5M1&=CLR_BIT2
#define clr_P5M1_1                       SFRS=1;P5M1&=CLR_BIT1
#define clr_P5M1_0                       SFRS=1;P5M1&=CLR_BIT0

/**** P5M2  BEH  PAGE 1 ****/
#define set_P5M2_7                       SFRS=1;P5M2|=SET_BIT7
#define set_P5M2_6                       SFRS=1;P5M2|=SET_BIT6
#define set_P5M2_5                       SFRS=1;P5M2|=SET_BIT5
#define set_P5M2_4                       SFRS=1;P5M2|=SET_BIT4
#define set_P5M2_3                       SFRS=1;P5M2|=SET_BIT3//@
#define set_P5M2_2                       SFRS=1;P5M2|=SET_BIT2//@
#define set_P5M2_1                       SFRS=1;P5M2|=SET_BIT1
#define set_P5M2_0                       SFRS=1;P5M2|=SET_BIT0

#define clr_P5M2_7                       SFRS=1;P5M2&=CLR_BIT7
#define clr_P5M2_6                       SFRS=1;P5M2&=CLR_BIT6
#define clr_P5M2_5                       SFRS=1;P5M2&=CLR_BIT5
#define clr_P5M2_4                       SFRS=1;P5M2&=CLR_BIT4
#define clr_P5M2_3                       SFRS=1;P5M2&=CLR_BIT3
#define clr_P5M2_2                       SFRS=1;P5M2&=CLR_BIT2
#define clr_P5M2_1                       SFRS=1;P5M2&=CLR_BIT1
#define clr_P5M2_0                       SFRS=1;P5M2&=CLR_BIT0

/**** P5S  BFH  PAGE 1 ****/
#define set_P5S_7                        SFRS=1;P5S|=SET_BIT7
#define set_P5S_6                        SFRS=1;P5S|=SET_BIT6
#define set_P5S_5                        SFRS=1;P5S|=SET_BIT5
#define set_P5S_4                        SFRS=1;P5S|=SET_BIT4
#define set_P5S_3                        SFRS=1;P5S|=SET_BIT3//@
#define set_P5S_2                        SFRS=1;P5S|=SET_BIT2//@
#define set_P5S_1                        SFRS=1;P5S|=SET_BIT1
#define set_P5S_0                        SFRS=1;P5S|=SET_BIT0

#define clr_P5S_7                        SFRS=1;P5S&=CLR_BIT7
#define clr_P5S_6                        SFRS=1;P5S&=CLR_BIT6
#define clr_P5S_5                        SFRS=1;P5S&=CLR_BIT5
#define clr_P5S_4                        SFRS=1;P5S&=CLR_BIT4
#define clr_P5S_3                        SFRS=1;P5S&=CLR_BIT3
#define clr_P5S_2                        SFRS=1;P5S&=CLR_BIT2
#define clr_P5S_1                        SFRS=1;P5S&=CLR_BIT1
#define clr_P5S_0                        SFRS=1;P5S&=CLR_BIT0

/**** P3M1  C2H  PAGE 1 ****/
#define set_P3M1_7                       SFRS=1;P3M1|=SET_BIT7
#define set_P3M1_6                       SFRS=1;P3M1|=SET_BIT6
#define set_P3M1_5                       SFRS=1;P3M1|=SET_BIT5
#define set_P3M1_4                       SFRS=1;P3M1|=SET_BIT4
#define set_P3M1_3                       SFRS=1;P3M1|=SET_BIT3//@
#define set_P3M1_2                       SFRS=1;P3M1|=SET_BIT2//@
#define set_P3M1_1                       SFRS=1;P3M1|=SET_BIT1
#define set_P3M1_0                       SFRS=1;P3M1|=SET_BIT0

#define clr_P3M1_7                       SFRS=1;P3M1&=CLR_BIT7
#define clr_P3M1_6                       SFRS=1;P3M1&=CLR_BIT6
#define clr_P3M1_5                       SFRS=1;P3M1&=CLR_BIT5
#define clr_P3M1_4                       SFRS=1;P3M1&=CLR_BIT4
#define clr_P3M1_3                       SFRS=1;P3M1&=CLR_BIT3
#define clr_P3M1_2                       SFRS=1;P3M1&=CLR_BIT2
#define clr_P3M1_1                       SFRS=1;P3M1&=CLR_BIT1
#define clr_P3M1_0                       SFRS=1;P3M1&=CLR_BIT0

/**** P3M2  C3H  PAGE 1 ****/
#define set_P3M2_7                       SFRS=1;P3M2|=SET_BIT7
#define set_P3M2_6                       SFRS=1;P3M2|=SET_BIT6
#define set_P3M2_5                       SFRS=1;P3M2|=SET_BIT5
#define set_P3M2_4                       SFRS=1;P3M2|=SET_BIT4
#define set_P3M2_3                       SFRS=1;P3M2|=SET_BIT3//@
#define set_P3M2_2                       SFRS=1;P3M2|=SET_BIT2//@
#define set_P3M2_1                       SFRS=1;P3M2|=SET_BIT1
#define set_P3M2_0                       SFRS=1;P3M2|=SET_BIT0

#define clr_P3M2_7                       SFRS=1;P3M2&=CLR_BIT7
#define clr_P3M2_6                       SFRS=1;P3M2&=CLR_BIT6
#define clr_P3M2_5                       SFRS=1;P3M2&=CLR_BIT5
#define clr_P3M2_4                       SFRS=1;P3M2&=CLR_BIT4
#define clr_P3M2_3                       SFRS=1;P3M2&=CLR_BIT3
#define clr_P3M2_2                       SFRS=1;P3M2&=CLR_BIT2
#define clr_P3M2_1                       SFRS=1;P3M2&=CLR_BIT1
#define clr_P3M2_0                       SFRS=1;P3M2&=CLR_BIT0

/**** AUXR1  C9H  PAGE 1 ****/
#define set_AUXR1_UART2PX                SFRS=1;AUXR1|=SET_BIT2//@
#define set_AUXR1_UART1PX                SFRS=1;AUXR1|=SET_BIT1
#define set_AUXR1_UART0PX                SFRS=1;AUXR1|=SET_BIT0

#define clr_AUXR1_UART2PX                SFRS=1;AUXR1&=CLR_BIT2
#define clr_AUXR1_UART1PX                SFRS=1;AUXR1&=CLR_BIT1
#define clr_AUXR1_UART0PX                SFRS=1;AUXR1&=CLR_BIT0

/**** AINDIDS  CEH  PAGE 1 ****/
#define set_AINDIDS_AIN7DIDS             SFRS=1;AINDIDS|=SET_BIT7
#define set_AINDIDS_AIN6DIDS             SFRS=1;AINDIDS|=SET_BIT6
#define set_AINDIDS_AIN5DIDS             SFRS=1;AINDIDS|=SET_BIT5
#define set_AINDIDS_AIN4DIDS             SFRS=1;AINDIDS|=SET_BIT4
#define set_AINDIDS_AIN3DIDS             SFRS=1;AINDIDS|=SET_BIT3//@
#define set_AINDIDS_AIN2DIDS             SFRS=1;AINDIDS|=SET_BIT2//@
#define set_AINDIDS_AIN1DIDS             SFRS=1;AINDIDS|=SET_BIT1
#define set_AINDIDS_AIN0DIDS             SFRS=1;AINDIDS|=SET_BIT0

#define clr_AINDIDS_AIN7DIDS             SFRS=1;AINDIDS&=CLR_BIT7
#define clr_AINDIDS_AIN6DIDS             SFRS=1;AINDIDS&=CLR_BIT6
#define clr_AINDIDS_AIN5DIDS             SFRS=1;AINDIDS&=CLR_BIT5
#define clr_AINDIDS_AIN4DIDS             SFRS=1;AINDIDS&=CLR_BIT4
#define clr_AINDIDS_AIN3DIDS             SFRS=1;AINDIDS&=CLR_BIT3
#define clr_AINDIDS_AIN2DIDS             SFRS=1;AINDIDS&=CLR_BIT2
#define clr_AINDIDS_AIN1DIDS             SFRS=1;AINDIDS&=CLR_BIT1
#define clr_AINDIDS_AIN0DIDS             SFRS=1;AINDIDS&=CLR_BIT0

/**** BIASTEST  CFH  PAGE 1 TA protect register ****/
#define set_BIASTEST_CRVTEST             SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST|=SET_BIT6;EA=BIT_TMP
#define set_BIASTEST_LIRC_ITESTEN        SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST|=SET_BIT5;EA=BIT_TMP
#define set_BIASTEST_BI_BGRDYOEN         SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST|=SET_BIT4;EA=BIT_TMP
#define set_BIASTEST_BI_TESTSW1          SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST|=SET_BIT4;EA=BIT_TMP
#define set_BIASTEST_BI_TESTSW0          SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST|=SET_BIT3;EA=BIT_TMP
#define set_BIASTEST_BI_TESTEN           SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST|=SET_BIT1;EA=BIT_TMP
#define set_BIASTEST_BI_SWCTRL           SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST|=SET_BIT0;EA=BIT_TMP

#define clr_BIASTEST_CRVTEST             SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST&=CLR_BIT6;EA=BIT_TMP
#define clr_BIASTEST_LIRC_ITESTEN        SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST&=CLR_BIT5;EA=BIT_TMP
#define clr_BIASTEST_BI_BGRDYOEN         SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST&=CLR_BIT4;EA=BIT_TMP
#define clr_BIASTEST_BI_TESTSW1          SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST&=CLR_BIT3;EA=BIT_TMP
#define clr_BIASTEST_BI_TESTSW0          SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST&=CLR_BIT2;EA=BIT_TMP
#define clr_BIASTEST_BI_TESTEN           SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST&=CLR_BIT1;EA=BIT_TMP
#define clr_BIASTEST_BI_SWCTRL           SFRS=1;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;BIASTEST&=CLR_BIT0;EA=BIT_TMP

/**** PWM0NP  D6H  PAGE 1 ****/
#define set_PWM0NP_PNP5                  SFRS=1;PWM0NP|=SET_BIT5
#define set_PWM0NP_PNP4                  SFRS=1;PWM0NP|=SET_BIT4
#define set_PWM0NP_PNP3                  SFRS=1;PWM0NP|=SET_BIT3//@
#define set_PWM0NP_PNP2                  SFRS=1;PWM0NP|=SET_BIT2//@
#define set_PWM0NP_PNP1                  SFRS=1;PWM0NP|=SET_BIT1
#define set_PWM0NP_PNP0                  SFRS=1;PWM0NP|=SET_BIT0

#define clr_PWM0NP_PNP5                  SFRS=1;PWM0NP&=CLR_BIT5
#define clr_PWM0NP_PNP4                  SFRS=1;PWM0NP&=CLR_BIT4
#define clr_PWM0NP_PNP3                  SFRS=1;PWM0NP&=CLR_BIT3
#define clr_PWM0NP_PNP2                  SFRS=1;PWM0NP&=CLR_BIT2
#define clr_PWM0NP_PNP1                  SFRS=1;PWM0NP&=CLR_BIT1
#define clr_PWM0NP_PNP0                  SFRS=1;PWM0NP&=CLR_BIT0

/**** PWM0FBD  D7H  PAGE 1 ****/
#define set_PWM0FBD_FBF                  SFRS=1;PWM0FBD|=SET_BIT7
#define set_PWM0FBD_FBINLS               SFRS=1;PWM0FBD|=SET_BIT6
#define set_PWM0FBD_FBD5                 SFRS=1;PWM0FBD|=SET_BIT5
#define set_PWM0FBD_FBD4                 SFRS=1;PWM0FBD|=SET_BIT4
#define set_PWM0FBD_FBD3                 SFRS=1;PWM0FBD|=SET_BIT3//@
#define set_PWM0FBD_FBD2                 SFRS=1;PWM0FBD|=SET_BIT2//@
#define set_PWM0FBD_FBD1                 SFRS=1;PWM0FBD|=SET_BIT1
#define set_PWM0FBD_FBD0                 SFRS=1;PWM0FBD|=SET_BIT0

#define clr_PWM0FBD_FBF                  SFRS=1;PWM0FBD&=CLR_BIT7
#define clr_PWM0FBD_FBINLS               SFRS=1;PWM0FBD&=CLR_BIT6
#define clr_PWM0FBD_FBD5                 SFRS=1;PWM0FBD&=CLR_BIT5
#define clr_PWM0FBD_FBD4                 SFRS=1;PWM0FBD&=CLR_BIT4
#define clr_PWM0FBD_FBD3                 SFRS=1;PWM0FBD&=CLR_BIT3
#define clr_PWM0FBD_FBD2                 SFRS=1;PWM0FBD&=CLR_BIT2
#define clr_PWM0FBD_FBD1                 SFRS=1;PWM0FBD&=CLR_BIT1
#define clr_PWM0FBD_FBD0                 SFRS=1;PWM0FBD&=CLR_BIT0

/**** PWM0IOCON    DEH  PAGE1 ****/
/**** PWM0CON1  DFH  PAGE1 ****/
#define set_PWM0CON1_PWMMOD_1           SFRS=1;PWM0CON1|=SET_BIT7
#define set_PWM0CON1_PWMMOD_0           SFRS=1;PWM0CON1|=SET_BIT6
#define set_PWM0CON1_GP                 SFRS=1;PWM0CON1|=SET_BIT5
#define set_PWM0CON1_PWMTYP             SFRS=1;PWM0CON1|=SET_BIT4
#define set_PWM0CON1_FBINEN             SFRS=1;PWM0CON1|=SET_BIT3
#define set_PWM0CON1_PWMDIV2            SFRS=1;PWM0CON1|=SET_BIT2
#define set_PWM0CON1_PWMDIV1            SFRS=1;PWM0CON1|=SET_BIT1
#define set_PWM0CON1_PWMDIV0            SFRS=1;PWM0CON1|=SET_BIT0
                                                                 
#define clr_PWM0CON1_PWMMOD_1           SFRS=1;PWM0CON1&=CLR_BIT7
#define clr_PWM0CON1_PWMMOD_0           SFRS=1;PWM0CON1&=CLR_BIT6
#define clr_PWM0CON1_GP                 SFRS=1;PWM0CON1&=CLR_BIT5
#define clr_PWM0CON1_PWMTYP             SFRS=1;PWM0CON1&=CLR_BIT4
#define clr_PWM0CON1_FBINEN             SFRS=1;PWM0CON1&=CLR_BIT3
#define clr_PWM0CON1_PWMDIV2            SFRS=1;PWM0CON1&=CLR_BIT2
#define clr_PWM0CON1_PWMDIV1            SFRS=1;PWM0CON1&=CLR_BIT1
#define clr_PWM0CON1_PWMDIV0            SFRS=1;PWM0CON1&=CLR_BIT0

/**** CAPCON0  E1H  PAGE 1 ****/
#define set_CAPCON0_CAPEN2               SFRS=1;CAPCON0|=SET_BIT6
#define set_CAPCON0_CAPEN1               SFRS=1;CAPCON0|=SET_BIT5
#define set_CAPCON0_CAPEN0               SFRS=1;CAPCON0|=SET_BIT4
#define set_CAPCON0_CAPF2                SFRS=1;CAPCON0|=SET_BIT2
#define set_CAPCON0_CAPF1                SFRS=1;CAPCON0|=SET_BIT1
#define set_CAPCON0_CAPF0                SFRS=1;CAPCON0|=SET_BIT0

#define clr_CAPCON0_CAPEN2               SFRS=1;CAPCON0&=CLR_BIT6
#define clr_CAPCON0_CAPEN1               SFRS=1;CAPCON0&=CLR_BIT5
#define clr_CAPCON0_CAPEN0               SFRS=1;CAPCON0&=CLR_BIT4
#define clr_CAPCON0_CAPF2                SFRS=1;CAPCON0&=CLR_BIT2
#define clr_CAPCON0_CAPF1                SFRS=1;CAPCON0&=CLR_BIT1
#define clr_CAPCON0_CAPF0                SFRS=1;CAPCON0&=CLR_BIT0

/**** CAPCON1  E2H  PAGE 1 ****/
#define set_CAPCON1_CAP2LS1             SFRS=1;CAPCON1|=SET_BIT5
#define set_CAPCON1_CAP2LS0             SFRS=1;CAPCON1|=SET_BIT4
#define set_CAPCON1_CAP1LS1             SFRS=1;CAPCON1|=SET_BIT3
#define set_CAPCON1_CAP1LS0             SFRS=1;CAPCON1|=SET_BIT2
#define set_CAPCON1_CAP0LS1             SFRS=1;CAPCON1|=SET_BIT1
#define set_CAPCON1_CAP0LS0             SFRS=1;CAPCON1|=SET_BIT0
                                               
#define clr_CAPCON1_CAP2LS1             SFRS=1;CAPCON1&=CLR_BIT5
#define clr_CAPCON1_CAP2LS0             SFRS=1;CAPCON1&=CLR_BIT4
#define clr_CAPCON1_CAP1LS1             SFRS=1;CAPCON1&=CLR_BIT3
#define clr_CAPCON1_CAP1LS0             SFRS=1;CAPCON1&=CLR_BIT2
#define clr_CAPCON1_CAP0LS1             SFRS=1;CAPCON1&=CLR_BIT1
#define clr_CAPCON1_CAP0LS0             SFRS=1;CAPCON1&=CLR_BIT0

/**** CAPCON2  E3H  PAGE 1 ****/
#define set_CAPCON2_ENF2                 SFRS=1;CAPCON2|=SET_BIT6
#define set_CAPCON2_ENF1                 SFRS=1;CAPCON2|=SET_BIT5
#define set_CAPCON2_ENF0                 SFRS=1;CAPCON2|=SET_BIT4

#define clr_CAPCON2_ENF2                 SFRS=1;CAPCON2&=CLR_BIT6
#define clr_CAPCON2_ENF1                 SFRS=1;CAPCON2&=CLR_BIT5
#define clr_CAPCON2_ENF0                 SFRS=1;CAPCON2&=CLR_BIT4

/**** PICON  E9H  PAGE 1 ****/
#define set_PICON_PIT7                   SFRS=1;PICON|=SET_BIT7
#define set_PICON_PIT6                   SFRS=1;PICON|=SET_BIT6
#define set_PICON_PIT5                   SFRS=1;PICON|=SET_BIT5
#define set_PICON_PIT4                   SFRS=1;PICON|=SET_BIT4
#define set_PICON_PIT3                   SFRS=1;PICON|=SET_BIT3//@
#define set_PICON_PIT2                   SFRS=1;PICON|=SET_BIT2//@
#define set_PICON_PIT1                   SFRS=1;PICON|=SET_BIT1
#define set_PICON_PIT0                   SFRS=1;PICON|=SET_BIT0

#define clr_PICON_PIT7                   SFRS=1;PICON&=CLR_BIT7
#define clr_PICON_PIT6                   SFRS=1;PICON&=CLR_BIT6
#define clr_PICON_PIT5                   SFRS=1;PICON&=CLR_BIT5
#define clr_PICON_PIT4                   SFRS=1;PICON&=CLR_BIT4
#define clr_PICON_PIT3                   SFRS=1;PICON&=CLR_BIT3
#define clr_PICON_PIT2                   SFRS=1;PICON&=CLR_BIT2
#define clr_PICON_PIT1                   SFRS=1;PICON&=CLR_BIT1
#define clr_PICON_PIT0                   SFRS=1;PICON&=CLR_BIT0

/**** PINEN  EAH  PAGE 1 ****/
#define set_PINEN_PINEN7                 SFRS=1;PINEN|=SET_BIT7
#define set_PINEN_PINEN6                 SFRS=1;PINEN|=SET_BIT6
#define set_PINEN_PINEN5                 SFRS=1;PINEN|=SET_BIT5
#define set_PINEN_PINEN4                 SFRS=1;PINEN|=SET_BIT4
#define set_PINEN_PINEN3                 SFRS=1;PINEN|=SET_BIT3//@
#define set_PINEN_PINEN2                 SFRS=1;PINEN|=SET_BIT2//@
#define set_PINEN_PINEN1                 SFRS=1;PINEN|=SET_BIT1
#define set_PINEN_PINEN0                 SFRS=1;PINEN|=SET_BIT0

#define clr_PINEN_PINEN7                 SFRS=1;PINEN&=CLR_BIT7
#define clr_PINEN_PINEN6                 SFRS=1;PINEN&=CLR_BIT6
#define clr_PINEN_PINEN5                 SFRS=1;PINEN&=CLR_BIT5
#define clr_PINEN_PINEN4                 SFRS=1;PINEN&=CLR_BIT4
#define clr_PINEN_PINEN3                 SFRS=1;PINEN&=CLR_BIT3
#define clr_PINEN_PINEN2                 SFRS=1;PINEN&=CLR_BIT2
#define clr_PINEN_PINEN1                 SFRS=1;PINEN&=CLR_BIT1
#define clr_PINEN_PINEN0                 SFRS=1;PINEN&=CLR_BIT0

/**** PIPEN  EBH  PAGE 1 ****/
#define set_PIPEN_PIPEN7                 SFRS=1;PIPEN|=SET_BIT7
#define set_PIPEN_PIPEN6                 SFRS=1;PIPEN|=SET_BIT6
#define set_PIPEN_PIPEN5                 SFRS=1;PIPEN|=SET_BIT5
#define set_PIPEN_PIPEN4                 SFRS=1;PIPEN|=SET_BIT4
#define set_PIPEN_PIPEN3                 SFRS=1;PIPEN|=SET_BIT3//@
#define set_PIPEN_PIPEN2                 SFRS=1;PIPEN|=SET_BIT2//@
#define set_PIPEN_PIPEN1                 SFRS=1;PIPEN|=SET_BIT1
#define set_PIPEN_PIPEN0                 SFRS=1;PIPEN|=SET_BIT0

#define clr_PIPEN_PIPEN7                 SFRS=1;PIPEN&=CLR_BIT7
#define clr_PIPEN_PIPEN6                 SFRS=1;PIPEN&=CLR_BIT6
#define clr_PIPEN_PIPEN5                 SFRS=1;PIPEN&=CLR_BIT5
#define clr_PIPEN_PIPEN4                 SFRS=1;PIPEN&=CLR_BIT4
#define clr_PIPEN_PIPEN3                 SFRS=1;PIPEN&=CLR_BIT3
#define clr_PIPEN_PIPEN2                 SFRS=1;PIPEN&=CLR_BIT2
#define clr_PIPEN_PIPEN1                 SFRS=1;PIPEN&=CLR_BIT1
#define clr_PIPEN_PIPEN0                 SFRS=1;PIPEN&=CLR_BIT0

/**** SPI0CR1  F3H  PAGE 1 ****/
#define set_SPI0CR1_SPR3                 SFRS=1;SPI0CR1|=SET_BIT5
#define set_SPI0CR1_SPR2                 SFRS=1;SPI0CR1|=SET_BIT4
#define set_SPI0CR1_TXDMAEN              SFRS=1;SPI0CR1|=SET_BIT3//@
#define set_SPI0CR1_RXDMAEN              SFRS=1;SPI0CR1|=SET_BIT2//@
#define set_SPI0CR1_SPIS1                SFRS=1;SPI0CR1|=SET_BIT1
#define set_SPI0CR1_SPIS0                SFRS=1;SPI0CR1|=SET_BIT0

#define clr_SPI0CR1_SPR3                 SFRS=1;SPI0CR1&=CLR_BIT5
#define clr_SPI0CR1_SPR2                 SFRS=1;SPI0CR1&=CLR_BIT4
#define clr_SPI0CR1_TXDMAEN              SFRS=1;SPI0CR1&=CLR_BIT3
#define clr_SPI0CR1_RXDMAEN              SFRS=1;SPI0CR1&=CLR_BIT2
#define clr_SPI0CR1_SPIS1                SFRS=1;SPI0CR1&=CLR_BIT1
#define clr_SPI0CR1_SPIS0                SFRS=1;SPI0CR1&=CLR_BIT0

/**** PWM0DTEN  F9H  PAGE 1 ****/
#define set_PWM0DTEN_PWMDTCNT_8          SFRS=1;PWM0DTEN|=SET_BIT4
#define set_PWM0DTEN_PDT45EN             SFRS=1;PWM0DTEN|=SET_BIT2//@
#define set_PWM0DTEN_PDT23EN             SFRS=1;PWM0DTEN|=SET_BIT1
#define set_PWM0DTEN_PDT01EN             SFRS=1;PWM0DTEN|=SET_BIT0

#define clr_PWM0DTEN_PWMDTCNT_8          SFRS=1;PWM0DTEN&=CLR_BIT4
#define clr_PWM0DTEN_PDT45EN             SFRS=1;PWM0DTEN&=CLR_BIT2
#define clr_PWM0DTEN_PDT23EN             SFRS=1;PWM0DTEN&=CLR_BIT1
#define clr_PWM0DTEN_PDT01EN             SFRS=1;PWM0DTEN&=CLR_BIT0

/**** PWM0MEN  FBH  PAGE 1 ****/
#define set_PWM0MEN_PMEN5                SFRS=1;PWM0MEN|=SET_BIT5
#define set_PWM0MEN_PMEN4                SFRS=1;PWM0MEN|=SET_BIT4
#define set_PWM0MEN_PMEN3                SFRS=1;PWM0MEN|=SET_BIT3//@
#define set_PWM0MEN_PMEN2                SFRS=1;PWM0MEN|=SET_BIT2//@
#define set_PWM0MEN_PMEN1                SFRS=1;PWM0MEN|=SET_BIT1
#define set_PWM0MEN_PMEN0                SFRS=1;PWM0MEN|=SET_BIT0

#define clr_PWM0MEN_PMEN5                SFRS=1;PWM0MEN&=CLR_BIT5
#define clr_PWM0MEN_PMEN4                SFRS=1;PWM0MEN&=CLR_BIT4
#define clr_PWM0MEN_PMEN3                SFRS=1;PWM0MEN&=CLR_BIT3
#define clr_PWM0MEN_PMEN2                SFRS=1;PWM0MEN&=CLR_BIT2
#define clr_PWM0MEN_PMEN1                SFRS=1;PWM0MEN&=CLR_BIT1
#define clr_PWM0MEN_PMEN0                SFRS=1;PWM0MEN&=CLR_BIT0

/**** PWM0MD  FCH  PAGE 1 ****/
#define set_PWM0MD_PMD5                  SFRS=1;PWM0MD|=SET_BIT5
#define set_PWM0MD_PMD4                  SFRS=1;PWM0MD|=SET_BIT4
#define set_PWM0MD_PMD3                  SFRS=1;PWM0MD|=SET_BIT3//@
#define set_PWM0MD_PMD2                  SFRS=1;PWM0MD|=SET_BIT2//@
#define set_PWM0MD_PMD1                  SFRS=1;PWM0MD|=SET_BIT1
#define set_PWM0MD_PMD0                  SFRS=1;PWM0MD|=SET_BIT0

#define clr_PWM0MD_PMD5                  SFRS=1;PWM0MD&=CLR_BIT5
#define clr_PWM0MD_PMD4                  SFRS=1;PWM0MD&=CLR_BIT4
#define clr_PWM0MD_PMD3                  SFRS=1;PWM0MD&=CLR_BIT3
#define clr_PWM0MD_PMD2                  SFRS=1;PWM0MD&=CLR_BIT2
#define clr_PWM0MD_PMD1                  SFRS=1;PWM0MD&=CLR_BIT1
#define clr_PWM0MD_PMD0                  SFRS=1;PWM0MD&=CLR_BIT0

/********SFR PAGE 2*************/
/**** P6M1  84H  PAGE 2 ****/
#define set_P6M1_7                       SFRS=2;P6M1|=SET_BIT7
#define set_P6M1_6                       SFRS=2;P6M1|=SET_BIT6
#define set_P6M1_5                       SFRS=2;P6M1|=SET_BIT5
#define set_P6M1_4                       SFRS=2;P6M1|=SET_BIT4
#define set_P6M1_3                       SFRS=2;P6M1|=SET_BIT3//@
#define set_P6M1_2                       SFRS=2;P6M1|=SET_BIT2//@
#define set_P6M1_1                       SFRS=2;P6M1|=SET_BIT1
#define set_P6M1_0                       SFRS=2;P6M1|=SET_BIT0

#define clr_P6M1_7                       SFRS=2;P6M1&=CLR_BIT7
#define clr_P6M1_6                       SFRS=2;P6M1&=CLR_BIT6
#define clr_P6M1_5                       SFRS=2;P6M1&=CLR_BIT5
#define clr_P6M1_4                       SFRS=2;P6M1&=CLR_BIT4
#define clr_P6M1_3                       SFRS=2;P6M1&=CLR_BIT3
#define clr_P6M1_2                       SFRS=2;P6M1&=CLR_BIT2
#define clr_P6M1_1                       SFRS=2;P6M1&=CLR_BIT1
#define clr_P6M1_0                       SFRS=2;P6M1&=CLR_BIT0

/**** P6M2  85H  PAGE 2 ****/
#define set_P6M2_7                       SFRS=2;P6M2|=SET_BIT7
#define set_P6M2_6                       SFRS=2;P6M2|=SET_BIT6
#define set_P6M2_5                       SFRS=2;P6M2|=SET_BIT5
#define set_P6M2_4                       SFRS=2;P6M2|=SET_BIT4
#define set_P6M2_3                       SFRS=2;P6M2|=SET_BIT3//@
#define set_P6M2_2                       SFRS=2;P6M2|=SET_BIT2//@
#define set_P6M2_1                       SFRS=2;P6M2|=SET_BIT1
#define set_P6M2_0                       SFRS=2;P6M2|=SET_BIT0

#define clr_P6M2_7                       SFRS=2;P6M2&=CLR_BIT7
#define clr_P6M2_6                       SFRS=2;P6M2&=CLR_BIT6
#define clr_P6M2_5                       SFRS=2;P6M2&=CLR_BIT5
#define clr_P6M2_4                       SFRS=2;P6M2&=CLR_BIT4
#define clr_P6M2_3                       SFRS=2;P6M2&=CLR_BIT3
#define clr_P6M2_2                       SFRS=2;P6M2&=CLR_BIT2
#define clr_P6M2_1                       SFRS=2;P6M2&=CLR_BIT1
#define clr_P6M2_0                       SFRS=2;P6M2&=CLR_BIT0

/**** PWM1MD  8CH  PAGE 2 ****/
#define set_PWM1MD_PMD1                  SFRS=2;PWM1MD|=SET_BIT1
#define set_PWM1MD_PMD0                  SFRS=2;PWM1MD|=SET_BIT0

#define clr_PWM1MD_PMD1                  SFRS=2;PWM1MD&=CLR_BIT1
#define clr_PWM1MD_PMD0                  SFRS=2;PWM1MD&=CLR_BIT0

/**** PWM1MEN  8DH  PAGE 2 ****/
#define set_PWM1MEN_PMEN1                SFRS=2;PWM1MEN|=SET_BIT1
#define set_PWM1MEN_PMEN0                SFRS=2;PWM1MEN|=SET_BIT0

#define clr_PWM1MEN_PMEN1                SFRS=2;PWM1MEN&=CLR_BIT1
#define clr_PWM1MEN_PMEN0                SFRS=2;PWM1MEN&=CLR_BIT0

/**** P6SR  8EH  PAGE 2 ****/
#define set_P6SR_7                       SFRS=2;P6SR|=SET_BIT7
#define set_P6SR_6                       SFRS=2;P6SR|=SET_BIT6
#define set_P6SR_5                       SFRS=2;P6SR|=SET_BIT5
#define set_P6SR_4                       SFRS=2;P6SR|=SET_BIT4
#define set_P6SR_3                       SFRS=2;P6SR|=SET_BIT3//@
#define set_P6SR_2                       SFRS=2;P6SR|=SET_BIT2//@
#define set_P6SR_1                       SFRS=2;P6SR|=SET_BIT1
#define set_P6SR_0                       SFRS=2;P6SR|=SET_BIT0

#define clr_P6SR_7                       SFRS=2;P6SR&=CLR_BIT7
#define clr_P6SR_6                       SFRS=2;P6SR&=CLR_BIT6
#define clr_P6SR_5                       SFRS=2;P6SR&=CLR_BIT5
#define clr_P6SR_4                       SFRS=2;P6SR&=CLR_BIT4
#define clr_P6SR_3                       SFRS=2;P6SR&=CLR_BIT3
#define clr_P6SR_2                       SFRS=2;P6SR&=CLR_BIT2
#define clr_P6SR_1                       SFRS=2;P6SR&=CLR_BIT1
#define clr_P6SR_0                       SFRS=2;P6SR&=CLR_BIT0

/**** P6DW  8FH  PAGE 2 ****/
#define set_P6DW_7                       SFRS=2;P6DW|=SET_BIT7
#define set_P6DW_6                       SFRS=2;P6DW|=SET_BIT6
#define set_P6DW_5                       SFRS=2;P6DW|=SET_BIT5
#define set_P6DW_4                       SFRS=2;P6DW|=SET_BIT4
#define set_P6DW_3                       SFRS=2;P6DW|=SET_BIT3//@
#define set_P6DW_2                       SFRS=2;P6DW|=SET_BIT2//@
#define set_P6DW_1                       SFRS=2;P6DW|=SET_BIT1
#define set_P6DW_0                       SFRS=2;P6DW|=SET_BIT0

#define clr_P6DW_7                       SFRS=2;P6DW&=CLR_BIT7
#define clr_P6DW_6                       SFRS=2;P6DW&=CLR_BIT6
#define clr_P6DW_5                       SFRS=2;P6DW&=CLR_BIT5
#define clr_P6DW_4                       SFRS=2;P6DW&=CLR_BIT4
#define clr_P6DW_3                       SFRS=2;P6DW&=CLR_BIT3
#define clr_P6DW_2                       SFRS=2;P6DW&=CLR_BIT2
#define clr_P6DW_1                       SFRS=2;P6DW&=CLR_BIT1
#define clr_P6DW_0                       SFRS=2;P6DW&=CLR_BIT0

/**** P6MF10  92H  PAGE 2 ****/
/**** P6MF32  93H  PAGE 2 ****/
/**** P6MF54  94H  PAGE 2 ****/
/**** P6MF76  95H  PAGE 2 ****/
/**** P6S  96H  PAGE 2 ****/
#define set_P6S_7                        SFRS=2;P6S|=SET_BIT7
#define set_P6S_6                        SFRS=2;P6S|=SET_BIT6
#define set_P6S_5                        SFRS=2;P6S|=SET_BIT5
#define set_P6S_4                        SFRS=2;P6S|=SET_BIT4
#define set_P6S_3                        SFRS=2;P6S|=SET_BIT3//@
#define set_P6S_2                        SFRS=2;P6S|=SET_BIT2//@
#define set_P6S_1                        SFRS=2;P6S|=SET_BIT1
#define set_P6S_0                        SFRS=2;P6S|=SET_BIT0

#define clr_P6S_7                        SFRS=2;P6S&=CLR_BIT7
#define clr_P6S_6                        SFRS=2;P6S&=CLR_BIT6
#define clr_P6S_5                        SFRS=2;P6S&=CLR_BIT5
#define clr_P6S_4                        SFRS=2;P6S&=CLR_BIT4
#define clr_P6S_3                        SFRS=2;P6S&=CLR_BIT3
#define clr_P6S_2                        SFRS=2;P6S&=CLR_BIT2
#define clr_P6S_1                        SFRS=2;P6S&=CLR_BIT1
#define clr_P6S_0                        SFRS=2;P6S&=CLR_BIT0

/**** P6UP  97H  PAGE 2 ****/
#define set_P6UP_7                       SFRS=2;P6UP|=SET_BIT7
#define set_P6UP_6                       SFRS=2;P6UP|=SET_BIT6
#define set_P6UP_5                       SFRS=2;P6UP|=SET_BIT5
#define set_P6UP_4                       SFRS=2;P6UP|=SET_BIT4
#define set_P6UP_3                       SFRS=2;P6UP|=SET_BIT3//@
#define set_P6UP_2                       SFRS=2;P6UP|=SET_BIT2//@
#define set_P6UP_1                       SFRS=2;P6UP|=SET_BIT1
#define set_P6UP_0                       SFRS=2;P6UP|=SET_BIT0

#define clr_P6UP_7                       SFRS=2;P6UP&=CLR_BIT7
#define clr_P6UP_6                       SFRS=2;P6UP&=CLR_BIT6
#define clr_P6UP_5                       SFRS=2;P6UP&=CLR_BIT5
#define clr_P6UP_4                       SFRS=2;P6UP&=CLR_BIT4
#define clr_P6UP_3                       SFRS=2;P6UP&=CLR_BIT3
#define clr_P6UP_2                       SFRS=2;P6UP&=CLR_BIT2
#define clr_P6UP_1                       SFRS=2;P6UP&=CLR_BIT1
#define clr_P6UP_0                       SFRS=2;P6UP&=CLR_BIT0

/**** PWM1CON0  9CH  PAGE 2 ****/
#define set_PWM1CON0_PWM1RUN             SFRS=2;PWM1CON0|=SET_BIT7
#define set_PWM1CON0_LOAD                SFRS=2;PWM1CON0|=SET_BIT6
#define set_PWM1CON0_PWMF                SFRS=2;PWM1CON0|=SET_BIT5
#define set_PWM1CON0_CLRPWM              SFRS=2;PWM1CON0|=SET_BIT4

#define clr_PWM1CON0_PWM1RUN             SFRS=2;PWM1CON0&=CLR_BIT7
#define clr_PWM1CON0_LOAD                SFRS=2;PWM1CON0&=CLR_BIT6
#define clr_PWM1CON0_PWMF                SFRS=2;PWM1CON0&=CLR_BIT5
#define clr_PWM1CON0_CLRPWM              SFRS=2;PWM1CON0&=CLR_BIT4

/**** PWM1CON1  9DH  PAGE 2 ****/
#define set_PWM1CON1_PWMMOD_1            SFRS=2;PWM1CON1|=SET_BIT7
#define set_PWM1CON1_PWMMOD_0            SFRS=2;PWM1CON1|=SET_BIT6
#define set_PWM1CON1_GP                  SFRS=2;PWM1CON1|=SET_BIT5
#define set_PWM1CON1_PWMTYP              SFRS=2;PWM1CON1|=SET_BIT4
#define set_PWM1CON1_FBINEN              SFRS=2;PWM1CON1|=SET_BIT3
#define set_PWM1CON1_PWMDIV2             SFRS=2;PWM1CON1|=SET_BIT2
#define set_PWM1CON1_PWMDIV1             SFRS=2;PWM1CON1|=SET_BIT1
#define set_PWM1CON1_PWMDIV0             SFRS=2;PWM1CON1|=SET_BIT0
                                         
#define clr_PWM1CON1_PWMMOD_1            SFRS=2;PWM1CON1&=CLR_BIT7
#define clr_PWM1CON1_PWMMOD_0            SFRS=2;PWM1CON1&=CLR_BIT6
#define clr_PWM1CON1_GP                  SFRS=2;PWM1CON1&=CLR_BIT5
#define clr_PWM1CON1_PWMTYP              SFRS=2;PWM1CON1&=CLR_BIT4
#define clr_PWM1CON1_FBINEN              SFRS=2;PWM1CON1&=CLR_BIT3
#define clr_PWM1CON1_PWMDIV2             SFRS=2;PWM1CON1&=CLR_BIT2
#define clr_PWM1CON1_PWMDIV1             SFRS=2;PWM1CON1&=CLR_BIT1
#define clr_PWM1CON1_PWMDIV0             SFRS=2;PWM1CON1&=CLR_BIT0

/**** PWM1INTC  9EH  PAGE 2 ****/
#define set_PWM1INTC_INTTYP1             SFRS=2;PWM1INTC|=SET_BIT5
#define set_PWM1INTC_INTTYP0             SFRS=2;PWM1INTC|=SET_BIT4
#define set_PWM1INTC_INTSEL2             SFRS=2;PWM1INTC|=SET_BIT2//@
#define set_PWM1INTC_INTSEL1             SFRS=2;PWM1INTC|=SET_BIT1
#define set_PWM1INTC_INTSEL0             SFRS=2;PWM1INTC|=SET_BIT0

#define clr_PWM1INTC_INTTYP1             SFRS=2;PWM1INTC&=CLR_BIT5
#define clr_PWM1INTC_INTTYP0             SFRS=2;PWM1INTC&=CLR_BIT4
#define clr_PWM1INTC_INTSEL2             SFRS=2;PWM1INTC&=CLR_BIT2
#define clr_PWM1INTC_INTSEL1             SFRS=2;PWM1INTC&=CLR_BIT1
#define clr_PWM1INTC_INTSEL0             SFRS=2;PWM1INTC&=CLR_BIT0

/**** I2C0ADDR1  A1H  PAGE 2 ****/
#define set_I2C0ADDR1_GC                 SFRS=2;I2C0ADDR1|=SET_BIT0
#define clr_I2C0ADDR1_GC                 SFRS=2;I2C0ADDR1&=CLR_BIT0

/**** I2C0ADDR2  A2H  PAGE 2 ****/
#define set_I2C0ADDR2_GC                 SFRS=2;I2C0ADDR2|=SET_BIT0
#define clr_I2C0ADDR2_GC                 SFRS=2;I2C0ADDR2&=CLR_BIT0

/**** I2C0ADDR3  A3H  PAGE 2 ****/
#define set_I2C0ADDR3_GC                 SFRS=2;I2C0ADDR3|=SET_BIT0
#define clr_I2C0ADDR3_GC                 SFRS=2;I2C0ADDR3&=CLR_BIT6

/**** I2C1ADDR1  A4H  PAGE 2 ****/
#define set_I2C1ADDR1_GC                 SFRS=2;I2C1ADDR1|=SET_BIT0
#define clr_I2C1ADDR1_GC                 SFRS=2;I2C1ADDR1&=CLR_BIT0

/**** I2C1ADDR2  A5H  PAGE 2 TA protect register ****/
#define set_I2C1ADDR2_GC                 SFRS=2;I2C1ADDR2|=SET_BIT0
#define clr_I2C1ADDR2_GC                 SFRS=2;I2C1ADDR2&=CLR_BIT0

/**** I2C1ADDR3  A6H  PAGE 2 ****/
#define set_I2C1ADDR3_GC                 SFRS=2;I2C1ADDR3|=SET_BIT0
#define clr_I2C1ADDR3_GC                 SFRS=2;I2C1ADDR3&=CLR_BIT0

/**** P6  A7H  PAGE 2 ****/
#define set_P6_7                         SFRS=2;P6|=SET_BIT7
#define set_P6_6                         SFRS=2;P6|=SET_BIT6
#define set_P6_5                         SFRS=2;P6|=SET_BIT5
#define set_P6_4                         SFRS=2;P6|=SET_BIT4
#define set_P6_3                         SFRS=2;P6|=SET_BIT3//@
#define set_P6_2                         SFRS=2;P6|=SET_BIT2//@
#define set_P6_1                         SFRS=2;P6|=SET_BIT1
#define set_P6_0                         SFRS=2;P6|=SET_BIT0

#define clr_P6_7                         SFRS=2;P6&=CLR_BIT7
#define clr_P6_6                         SFRS=2;P6&=CLR_BIT6
#define clr_P6_5                         SFRS=2;P6&=CLR_BIT5
#define clr_P6_4                         SFRS=2;P6&=CLR_BIT4
#define clr_P6_3                         SFRS=2;P6&=CLR_BIT3
#define clr_P6_2                         SFRS=2;P6&=CLR_BIT2
#define clr_P6_1                         SFRS=2;P6&=CLR_BIT1
#define clr_P6_0                         SFRS=2;P6&=CLR_BIT0

#define set_P67                          SFRS=2;P6|=SET_BIT7
#define set_P66                          SFRS=2;P6|=SET_BIT6
#define set_P65                          SFRS=2;P6|=SET_BIT5
#define set_P64                          SFRS=2;P6|=SET_BIT4
#define set_P63                          SFRS=2;P6|=SET_BIT3//@
#define set_P62                          SFRS=2;P6|=SET_BIT2//@
#define set_P61                          SFRS=2;P6|=SET_BIT1
#define set_P60                          SFRS=2;P6|=SET_BIT0
                                     
#define clr_P67                          SFRS=2;P6&=CLR_BIT7
#define clr_P66                          SFRS=2;P6&=CLR_BIT6
#define clr_P65                          SFRS=2;P6&=CLR_BIT5
#define clr_P64                          SFRS=2;P6&=CLR_BIT4
#define clr_P63                          SFRS=2;P6&=CLR_BIT3
#define clr_P62                          SFRS=2;P6&=CLR_BIT2
#define clr_P61                          SFRS=2;P6&=CLR_BIT1
#define clr_P60                          SFRS=2;P6&=CLR_BIT0

/**** DMA3TSR  A9H  PAGE 2 ****/
#define set_DMA3TSR_ACT                  SFRS=2;DMA3TSR|=SET_BIT2//@
#define set_DMA3TSR_HDONE                SFRS=2;DMA3TSR|=SET_BIT1
#define set_DMA3TSR_FDONE                SFRS=2;DMA3TSR|=SET_BIT0

#define clr_DMA3TSR_ACT                  SFRS=2;DMA3TSR&=CLR_BIT2
#define clr_DMA3TSR_HDONE                SFRS=2;DMA3TSR&=CLR_BIT1
#define clr_DMA3TSR_FDONE                SFRS=2;DMA3TSR&=CLR_BIT0

/**** DMA3BAH  AAH  PAGE 2 ****/
/**** DMA2BAH  AAH  PAGE 2 ****/

/**** DMA3CR  ABH  PAGE 2 ****/
#define set_DMA3CR_PSSEL_3               SFRS=2;DMA3CR|=SET_BIT7//@
#define set_DMA3CR_PSSEL_2               SFRS=2;DMA3CR|=SET_BIT6//@
#define set_DMA3CR_PSSEL_1               SFRS=2;DMA3CR|=SET_BIT5//@
#define set_DMA3CR_PSSEL_0               SFRS=2;DMA3CR|=SET_BIT4//@
#define set_DMA3CR_HIE                   SFRS=2;DMA3CR|=SET_BIT3
#define set_DMA3CR_FIE                   SFRS=2;DMA3CR|=SET_BIT2
#define set_DMA3CR_RUN                   SFRS=2;DMA3CR|=SET_BIT1
#define set_DMA3CR_EN                    SFRS=2;DMA3CR|=SET_BIT0

#define clr_DMA3CR_PSSEL_3               SFRS=2;DMA3CR&=CLR_BIT7//@
#define clr_DMA3CR_PSSEL_2               SFRS=2;DMA3CR&=CLR_BIT6//@
#define clr_DMA3CR_PSSEL_1               SFRS=2;DMA3CR&=CLR_BIT5//@
#define clr_DMA3CR_PSSEL_0               SFRS=2;DMA3CR&=CLR_BIT4//@
#define clr_DMA3CR_HIE                   SFRS=2;DMA3CR&=CLR_BIT3
#define clr_DMA3CR_FIE                   SFRS=2;DMA3CR&=CLR_BIT2
#define clr_DMA3CR_RUN                   SFRS=2;DMA3CR&=CLR_BIT1
#define clr_DMA3CR_EN                    SFRS=2;DMA3CR&=CLR_BIT0

/**** DMA2TSR  B1H  PAGE 2 ****/
#define set_DMA2TSR_ACT                  SFRS=2;DMA2TSR|=SET_BIT2//@
#define set_DMA2TSR_HDONE                SFRS=2;DMA2TSR|=SET_BIT1
#define set_DMA2TSR_FDONE                SFRS=2;DMA2TSR|=SET_BIT0

#define clr_DMA2TSR_ACT                  SFRS=2;DMA2TSR&=CLR_BIT2
#define clr_DMA2TSR_HDONE                SFRS=2;DMA2TSR&=CLR_BIT1
#define clr_DMA2TSR_FDONE                SFRS=2;DMA2TSR&=CLR_BIT0

/**** DMA2CR  B3H  PAGE 2 ****/
#define set_DMA2CR_PSSEL_3               SFRS=2;DMA2CR|=SET_BIT7//@
#define set_DMA2CR_PSSEL_2               SFRS=2;DMA2CR|=SET_BIT6//@
#define set_DMA2CR_PSSEL_1               SFRS=2;DMA2CR|=SET_BIT5//@
#define set_DMA2CR_PSSEL_0               SFRS=2;DMA2CR|=SET_BIT4//@
#define set_DMA2CR_HIE                   SFRS=2;DMA2CR|=SET_BIT3
#define set_DMA2CR_FIE                   SFRS=2;DMA2CR|=SET_BIT2
#define set_DMA2CR_RUN                   SFRS=2;DMA2CR|=SET_BIT1
#define set_DMA2CR_EN                    SFRS=2;DMA2CR|=SET_BIT0

#define clr_DMA2CR_PSSEL_3               SFRS=2;DMA2CR&=CLR_BIT7//@
#define clr_DMA2CR_PSSEL_2               SFRS=2;DMA2CR&=CLR_BIT6//@
#define clr_DMA2CR_PSSEL_1               SFRS=2;DMA2CR&=CLR_BIT5//@
#define clr_DMA2CR_PSSEL_0               SFRS=2;DMA2CR&=CLR_BIT4//@
#define clr_DMA2CR_HIE                   SFRS=2;DMA2CR&=CLR_BIT3
#define clr_DMA2CR_FIE                   SFRS=2;DMA2CR&=CLR_BIT2
#define clr_DMA2CR_RUN                   SFRS=2;DMA2CR&=CLR_BIT1
#define clr_DMA2CR_EN                    SFRS=2;DMA2CR&=CLR_BIT0

/**** PWM2MD  BCH  PAGE 2 ****/
#define set_PWM2MD_PMD1                  SFRS=2;PWM2MD|=SET_BIT1
#define set_PWM2MD_PMD0                  SFRS=2;PWM2MD|=SET_BIT0

#define clr_PWM2MD_PMD1                  SFRS=2;PWM2MD&=CLR_BIT1
#define clr_PWM2MD_PMD0                  SFRS=2;PWM2MD&=CLR_BIT0

/**** PWM2MEN  BDH  PAGE 2 ****/
#define set_PWM2MEN_PMEN1                SFRS=2;PWM2MEN|=SET_BIT1
#define set_PWM2MEN_PMEN0                SFRS=2;PWM2MEN|=SET_BIT0

#define clr_PWM2MEN_PMEN1                SFRS=2;PWM2MEN&=CLR_BIT1
#define clr_PWM2MEN_PMEN0                SFRS=2;PWM2MEN&=CLR_BIT0

/**** PWM2CON0  C4H  PAGE 2 ****/
#define set_PWM2CON0_PWM2RUN             SFRS=2;PWM2CON0|=SET_BIT7
#define set_PWM2CON0_LOAD                SFRS=2;PWM2CON0|=SET_BIT6
#define set_PWM2CON0_PWMF                SFRS=2;PWM2CON0|=SET_BIT5
#define set_PWM2CON0_CLRPWM              SFRS=2;PWM2CON0|=SET_BIT4

#define clr_PWM2CON0_PWM2RUN             SFRS=2;PWM2CON0&=CLR_BIT7
#define clr_PWM2CON0_LOAD                SFRS=2;PWM2CON0&=CLR_BIT6
#define clr_PWM2CON0_PWMF                SFRS=2;PWM2CON0&=CLR_BIT5
#define clr_PWM2CON0_CLRPWM              SFRS=2;PWM2CON0&=CLR_BIT4

/**** PWM2CON1  C5H  PAGE 2 ****/
#define set_PWM2CON1_PWMMOD_1            SFRS=2;PWM2CON1|=SET_BIT7
#define set_PWM2CON1_PWMMOD_0            SFRS=2;PWM2CON1|=SET_BIT6
#define set_PWM2CON1_GP                  SFRS=2;PWM2CON1|=SET_BIT5
#define set_PWM2CON1_PWMTYP              SFRS=2;PWM2CON1|=SET_BIT4
#define set_PWM2CON1_FBINEN              SFRS=2;PWM2CON1|=SET_BIT3
#define set_PWM2CON1_PWMDIV_2            SFRS=2;PWM2CON1|=SET_BIT2
#define set_PWM2CON1_PWMDIV_1            SFRS=2;PWM2CON1|=SET_BIT1
#define set_PWM2CON1_PWMDIV_0            SFRS=2;PWM2CON1|=SET_BIT0
                                         
#define clr_PWM2CON1_PWMMOD_1            SFRS=2;PWM2CON1&=CLR_BIT7
#define clr_PWM2CON1_PWMMOD_0            SFRS=2;PWM2CON1&=CLR_BIT6
#define clr_PWM2CON1_GP                  SFRS=2;PWM2CON1&=CLR_BIT5
#define clr_PWM2CON1_PWMTYP              SFRS=2;PWM2CON1&=CLR_BIT4
#define clr_PWM2CON1_FBINEN              SFRS=2;PWM2CON1&=CLR_BIT3
#define clr_PWM2CON1_PWMDIV_2            SFRS=2;PWM2CON1&=CLR_BIT2
#define clr_PWM2CON1_PWMDIV_1            SFRS=2;PWM2CON1&=CLR_BIT1
#define clr_PWM2CON1_PWMDIV_0            SFRS=2;PWM2CON1&=CLR_BIT0

/**** PWM2INTC  C6H  PAGE 2 ****/
#define set_PWM2INTC_INTTYP_1            SFRS=2;PWM2INTC|=SET_BIT5
#define set_PWM2INTC_INTTYP_0            SFRS=2;PWM2INTC|=SET_BIT4
#define set_PWM2INTC_INTSEL_2            SFRS=2;PWM2INTC|=SET_BIT2//@
#define set_PWM2INTC_INTSEL_1            SFRS=2;PWM2INTC|=SET_BIT1
#define set_PWM2INTC_INTSEL_0            SFRS=2;PWM2INTC|=SET_BIT0
                                                                  
#define clr_PWM2INTC_INTTYP_1            SFRS=2;PWM2INTC&=CLR_BIT5
#define clr_PWM2INTC_INTTYP_0            SFRS=2;PWM2INTC&=CLR_BIT4
#define clr_PWM2INTC_INTSEL_2            SFRS=2;PWM2INTC&=CLR_BIT2
#define clr_PWM2INTC_INTSEL_1            SFRS=2;PWM2INTC&=CLR_BIT1
#define clr_PWM2INTC_INTSEL_0            SFRS=2;PWM2INTC&=CLR_BIT0

/**** PWM3MD  CCH  PAGE 2 ****/
#define set_PWM3MD_PMD_5                 SFRS=2;PWM3MD|=SET_BIT5
#define set_PWM3MD_PMD_4                 SFRS=2;PWM3MD|=SET_BIT4
#define set_PWM3MD_PMD_3                 SFRS=2;PWM3MD|=SET_BIT3//@
#define set_PWM3MD_PMD_2                 SFRS=2;PWM3MD|=SET_BIT2//@
#define set_PWM3MD_PMD_1                 SFRS=2;PWM3MD|=SET_BIT1
#define set_PWM3MD_PMD_0                 SFRS=2;PWM3MD|=SET_BIT0

#define clr_PWM3MD_PMD_5                 SFRS=2;PWM3MD&=CLR_BIT5
#define clr_PWM3MD_PMD_4                 SFRS=2;PWM3MD&=CLR_BIT4
#define clr_PWM3MD_PMD_3                 SFRS=2;PWM3MD&=CLR_BIT3
#define clr_PWM3MD_PMD_2                 SFRS=2;PWM3MD&=CLR_BIT2
#define clr_PWM3MD_PMD_1                 SFRS=2;PWM3MD&=CLR_BIT1
#define clr_PWM3MD_PMD_0                 SFRS=2;PWM3MD&=CLR_BIT0

/**** PWM3MEN  CDH  PAGE 2 ****/
#define set_PWM3MEN_PMEN_5               SFRS=2;PWM3MEN|=SET_BIT5
#define set_PWM3MEN_PMEN_4               SFRS=2;PWM3MEN|=SET_BIT4
#define set_PWM3MEN_PMEN_3               SFRS=2;PWM3MEN|=SET_BIT3//@
#define set_PWM3MEN_PMEN_2               SFRS=2;PWM3MEN|=SET_BIT2//@
#define set_PWM3MEN_PMEN_1               SFRS=2;PWM3MEN|=SET_BIT1
#define set_PWM3MEN_PMEN_0               SFRS=2;PWM3MEN|=SET_BIT0

#define clr_PWM3MEN_PMEN_5               SFRS=2;PWM3MEN&=CLR_BIT5
#define clr_PWM3MEN_PMEN_4               SFRS=2;PWM3MEN&=CLR_BIT4
#define clr_PWM3MEN_PMEN_3               SFRS=2;PWM3MEN&=CLR_BIT3
#define clr_PWM3MEN_PMEN_2               SFRS=2;PWM3MEN&=CLR_BIT2
#define clr_PWM3MEN_PMEN_1               SFRS=2;PWM3MEN&=CLR_BIT1
#define clr_PWM3MEN_PMEN_0               SFRS=2;PWM3MEN&=CLR_BIT0

/**** AINDIDS1  CEH  PAGE 2 ****/
#define set_AINDIDS_AIN15DIDS            SFRS=2;AINDIDS1|=SET_BIT5
#define set_AINDIDS_AIN14DIDS            SFRS=2;AINDIDS1|=SET_BIT4
#define set_AINDIDS_AIN13DIDS            SFRS=2;AINDIDS1|=SET_BIT3//@
#define set_AINDIDS_AIN12DIDS            SFRS=2;AINDIDS1|=SET_BIT3
#define set_AINDIDS_AIN11DIDS            SFRS=2;AINDIDS1|=SET_BIT1
#define set_AINDIDS_AIN10DIDS            SFRS=2;AINDIDS1|=SET_BIT0
                                        
#define clr_AINDIDS_AIN15DIDS            SFRS=2;AINDIDS1&=CLR_BIT5
#define clr_AINDIDS_AIN14DIDS            SFRS=2;AINDIDS1&=CLR_BIT4
#define clr_AINDIDS_AIN13DIDS            SFRS=2;AINDIDS1&=CLR_BIT3
#define clr_AINDIDS_AIN12DIDS            SFRS=2;AINDIDS1&=CLR_BIT2
#define clr_AINDIDS_AIN11DIDS            SFRS=2;AINDIDS1&=CLR_BIT1
#define clr_AINDIDS_AIN10DIDS            SFRS=2;AINDIDS1&=CLR_BIT0

/**** PWM3CON0  D4H  PAGE 2 ****/
#define set_PWM3CON0_PWM3RUN             SFRS=2;PWM3CON0|=SET_BIT7
#define set_PWM3CON0_LOAD                SFRS=2;PWM3CON0|=SET_BIT6
#define set_PWM3CON0_PWMF                SFRS=2;PWM3CON0|=SET_BIT5
#define set_PWM3CON0_CLRPWM              SFRS=2;PWM3CON0|=SET_BIT4

#define clr_PWM3CON0_PWM3RUN             SFRS=2;PWM3CON0&=CLR_BIT7
#define clr_PWM3CON0_LOAD                SFRS=2;PWM3CON0&=CLR_BIT6
#define clr_PWM3CON0_PWMF                SFRS=2;PWM3CON0&=CLR_BIT5
#define clr_PWM3CON0_CLRPWM              SFRS=2;PWM3CON0&=CLR_BIT4

/**** PWM3CON1  D5H  PAGE 2 ****/
#define set_PWM3CON1_PWMMOD_1            SFRS=2;PWM3CON1|=SET_BIT7
#define set_PWM3CON1_PWMMOD_0            SFRS=2;PWM3CON1|=SET_BIT6
#define set_PWM3CON1_GP                  SFRS=2;PWM3CON1|=SET_BIT5
#define set_PWM3CON1_PWMTYP              SFRS=2;PWM3CON1|=SET_BIT4
#define set_PWM3CON1_FBINEN              SFRS=2;PWM3CON1|=SET_BIT3
#define set_PWM3CON1_PWMDIV2             SFRS=2;PWM3CON1|=SET_BIT2
#define set_PWM3CON1_PWMDIV1             SFRS=2;PWM3CON1|=SET_BIT1
#define set_PWM3CON1_PWMDIV0             SFRS=2;PWM3CON1|=SET_BIT0
                                         
#define clr_PWM3CON1_PWMMOD_1            SFRS=2;PWM3CON1&=CLR_BIT7
#define clr_PWM3CON1_PWMMOD_0            SFRS=2;PWM3CON1&=CLR_BIT6
#define clr_PWM3CON1_GP                  SFRS=2;PWM3CON1&=CLR_BIT5
#define clr_PWM3CON1_PWMTYP              SFRS=2;PWM3CON1&=CLR_BIT4
#define clr_PWM3CON1_FBINEN              SFRS=2;PWM3CON1&=CLR_BIT3
#define clr_PWM3CON1_PWMDIV2             SFRS=2;PWM3CON1&=CLR_BIT2
#define clr_PWM3CON1_PWMDIV1             SFRS=2;PWM3CON1&=CLR_BIT1
#define clr_PWM3CON1_PWMDIV0             SFRS=2;PWM3CON1&=CLR_BIT0

/**** PWM3INTC  D6H  PAGE 2 ****/
#define set_PWM3INTC_INTTYP1             SFRS=2;PWM3INTC|=SET_BIT5
#define set_PWM3INTC_INTTYP0             SFRS=2;PWM3INTC|=SET_BIT4
#define set_PWM3INTC_INTSEL2             SFRS=2;PWM3INTC|=SET_BIT2//@
#define set_PWM3INTC_INTSEL1             SFRS=2;PWM3INTC|=SET_BIT1
#define set_PWM3INTC_INTSEL0             SFRS=2;PWM3INTC|=SET_BIT0

#define clr_PWM3INTC_INTTYP1             SFRS=2;PWM3INTC&=CLR_BIT5
#define clr_PWM3INTC_INTTYP0             SFRS=2;PWM3INTC&=CLR_BIT4
#define clr_PWM3INTC_INTSEL2             SFRS=2;PWM3INTC&=CLR_BIT2
#define clr_PWM3INTC_INTSEL1             SFRS=2;PWM3INTC&=CLR_BIT1
#define clr_PWM3INTC_INTSEL0             SFRS=2;PWM3INTC&=CLR_BIT0

/**** SC1ETURD1  DCH  PAGE 2 ****/
#define set_SC1ETURD1_SCDIV_2            SFRS=2;SC1ETURD1|=SET_BIT6
#define set_SC1ETURD1_SCDIV_1            SFRS=2;SC1ETURD1|=SET_BIT5
#define set_SC1ETURD1_SCDIV_0            SFRS=2;SC1ETURD1|=SET_BIT4
#define set_SC1ETURD1_ETURDIV_10         SFRS=2;SC1ETURD1|=SET_BIT3
#define set_SC1ETURD1_ETURDIV_11         SFRS=2;SC1ETURD1|=SET_BIT2
#define set_SC1ETURD1_ETURDIV_9          SFRS=2;SC1ETURD1|=SET_BIT1
#define set_SC1ETURD1_ETURDIV_8          SFRS=2;SC1ETURD1|=SET_BIT0
               
#define clr_SC1ETURD1_SCDIV_2            SFRS=2;SC1ETURD1&=CLR_BIT6
#define clr_SC1ETURD1_SCDIV_1            SFRS=2;SC1ETURD1&=CLR_BIT5
#define clr_SC1ETURD1_SCDIV_0            SFRS=2;SC1ETURD1&=CLR_BIT4
#define clr_SC1ETURD1_ETURDIV_10         SFRS=2;SC1ETURD1&=CLR_BIT3
#define clr_SC1ETURD1_ETURDIV_11         SFRS=2;SC1ETURD1&=CLR_BIT2
#define clr_SC1ETURD1_ETURDIV_9          SFRS=2;SC1ETURD1&=CLR_BIT1
#define clr_SC1ETURD1_ETURDIV_8          SFRS=2;SC1ETURD1&=CLR_BIT0

/**** SC1IE  DDH  PAGE 2 ****/
#define set_SC1IE_ACERRIEN1              SFRS=2;SC1IE|=SET_BIT4
#define set_SC1IE_BGTIEN1                SFRS=2;SC1IE|=SET_BIT3//@
#define set_SC1IE_TERRIEN1               SFRS=2;SC1IE|=SET_BIT2//@
#define set_SC1IE_TBEIEN1                SFRS=2;SC1IE|=SET_BIT1
#define set_SC1IE_RDAIEN1                SFRS=2;SC1IE|=SET_BIT0

#define clr_SC1IE_ACERRIEN1              SFRS=2;SC1IE&=CLR_BIT4
#define clr_SC1IE_BGTIEN1                SFRS=2;SC1IE&=CLR_BIT3
#define clr_SC1IE_TERRIEN1               SFRS=2;SC1IE&=CLR_BIT2
#define clr_SC1IE_TBEIEN1                SFRS=2;SC1IE&=CLR_BIT1
#define clr_SC1IE_RDAIEN1                SFRS=2;SC1IE&=CLR_BIT0

/**** SC1IS  DEH  PAGE 2 ****/
////#define set_SC1IS_LOOP                   SFRS=2;SC1IS|=SET_BIT7
////#define set_SC1IS_SIF                    SFRS=2;SC1IS|=SET_BIT6
#define set_SC1IS_ACERRIF                SFRS=2;SC1IS|=SET_BIT4
#define set_SC1IS_BGTIF                  SFRS=2;SC1IS|=SET_BIT3//@
#define set_SC1IS_TERRIF                 SFRS=2;SC1IS|=SET_BIT2//@
#define set_SC1IS_TBEIF                  SFRS=2;SC1IS|=SET_BIT1
#define set_SC1IS_RDAIF                  SFRS=2;SC1IS|=SET_BIT0

////#define clr_SC1IS_LOOP                   SFRS=2;SC1IS&=CLR_BIT7
////#define clr_SC1IS_SIF                    SFRS=2;SC1IS&=CLR_BIT6
#define clr_SC1IS_ACERRIF                SFRS=2;SC1IS&=CLR_BIT4
#define clr_SC1IS_BGTIF                  SFRS=2;SC1IS&=CLR_BIT3
#define clr_SC1IS_TERRIF                 SFRS=2;SC1IS&=CLR_BIT2
#define clr_SC1IS_TBEIF                  SFRS=2;SC1IS&=CLR_BIT1
#define clr_SC1IS_RDAIF                  SFRS=2;SC1IS&=CLR_BIT0

/**** SC1TSR  DFH  PAGE 2 ****/
#define set_SC1TSR_ACT1                  SFRS=2;SC1TSR|=SET_BIT7
#define set_SC1TSR_BEF1                  SFRS=2;SC1TSR|=SET_BIT6
#define set_SC1TSR_FEF1                  SFRS=2;SC1TSR|=SET_BIT5
#define set_SC1TSR_PEF1                  SFRS=2;SC1TSR|=SET_BIT4
#define set_SC1TSR_TXEMPTY1              SFRS=2;SC1TSR|=SET_BIT3//@
#define set_SC1TSR_TXOV1                 SFRS=2;SC1TSR|=SET_BIT2//@
#define set_SC1TSR_RXEMPTY1              SFRS=2;SC1TSR|=SET_BIT1
#define set_SC1TSR_RXOV1                 SFRS=2;SC1TSR|=SET_BIT0

#define clr_SC1TSR_ACT1                  SFRS=2;SC1TSR&=CLR_BIT7
#define clr_SC1TSR_BEF1                  SFRS=2;SC1TSR&=CLR_BIT6
#define clr_SC1TSR_FEF1                  SFRS=2;SC1TSR&=CLR_BIT5
#define clr_SC1TSR_PEF1                  SFRS=2;SC1TSR&=CLR_BIT4
#define clr_SC1TSR_TXEMPTY1              SFRS=2;SC1TSR&=CLR_BIT3
#define clr_SC1TSR_TXOV1                 SFRS=2;SC1TSR&=CLR_BIT2
#define clr_SC1TSR_RXEMPTY1              SFRS=2;SC1TSR&=CLR_BIT1
#define clr_SC1TSR_RXOV1                 SFRS=2;SC1TSR&=CLR_BIT0

/**** P5MF32  E1H  PAGE 2 ****/
/**** P5MF54  E2H  PAGE 2 ****/
/**** P5MF76  E3H  PAGE 2 ****/
/**** BRCTRIM  E4H  PAGE 2 ****/
/**** ADCCAL  E5H  PAGE 2 ****/

/**** SC1CR0  E6H  PAGE 2 ****/
#define set_SC1CR0_NSB                  SFRS=2;SC1CR0|=SET_BIT7
#define set_SC1CR0_T                    SFRS=2;SC1CR0|=SET_BIT6
#define set_SC1CR0_RXBGTEN              SFRS=2;SC1CR0|=SET_BIT5
#define set_SC1CR0_CONSEL               SFRS=2;SC1CR0|=SET_BIT4
#define set_SC1CR0_AUTOCEN              SFRS=2;SC1CR0|=SET_BIT3//@
#define set_SC1CR0_TXOFF                SFRS=2;SC1CR0|=SET_BIT2//@
#define set_SC1CR0_RXOFF                SFRS=2;SC1CR0|=SET_BIT1
#define set_SC1CR0_SCEN                 SFRS=2;SC1CR0|=SET_BIT0

#define clr_SC1CR0_NSB                  SFRS=2;SC1CR0&=CLR_BIT7
#define clr_SC1CR0_T                    SFRS=2;SC1CR0&=CLR_BIT6
#define clr_SC1CR0_RXBGTEN              SFRS=2;SC1CR0&=CLR_BIT5
#define clr_SC1CR0_CONSEL               SFRS=2;SC1CR0&=CLR_BIT4
#define clr_SC1CR0_AUTOCEN              SFRS=2;SC1CR0&=CLR_BIT3
#define clr_SC1CR0_TXOFF                SFRS=2;SC1CR0&=CLR_BIT2
#define clr_SC1CR0_RXOFF                SFRS=2;SC1CR0&=CLR_BIT1
#define clr_SC1CR0_SCEN                 SFRS=2;SC1CR0&=CLR_BIT0

/**** SC1CR1  E7H  PAGE 2 ****/
#define set_SC1CR1_OPE                  SFRS=2;SC1CR1|=SET_BIT7
#define set_SC1CR1_PBOFF                SFRS=2;SC1CR1|=SET_BIT6
#define set_SC1CR1_WLS                  SFRS=2;SC1CR1|=SET_BIT5
#define set_SC1CR1_TXDMAEN              SFRS=2;SC1CR1|=SET_BIT3//@
#define set_SC1CR1_RXDMAEN              SFRS=2;SC1CR1|=SET_BIT2//@
#define set_SC1CR1_CLKKEEP              SFRS=2;SC1CR1|=SET_BIT1
#define set_SC1CR1_UARTEN               SFRS=2;SC1CR1|=SET_BIT0

#define clr_SC1CR1_OPE                  SFRS=2;SC1CR1&=CLR_BIT7
#define clr_SC1CR1_PBOFF                SFRS=2;SC1CR1&=CLR_BIT6
#define clr_SC1CR1_WLS                  SFRS=2;SC1CR1&=CLR_BIT5
#define clr_SC1CR1_TXDMAEN              SFRS=2;SC1CR1&=CLR_BIT3
#define clr_SC1CR1_RXDMAEN              SFRS=2;SC1CR1&=CLR_BIT2
#define clr_SC1CR1_CLKKEEP              SFRS=2;SC1CR1&=CLR_BIT1
#define clr_SC1CR1_UARTEN               SFRS=2;SC1CR1&=CLR_BIT0

/**** P3MF54  E9H  PAGE 2 ****/
/**** P3MF76  EAH  PAGE 2 ****/
/**** P4MF10  EBH  PAGE 2 ****/
/**** P4MF32  ECH  PAGE 2 ****/
/**** P4MF54  EDH  PAGE 2 ****/
/**** P4MF76  EEH  PAGE 2 ****/
/**** P5MF10  EFH  PAGE 2 ****/
/**** P1MF76  F1H  PAGE 2 ****/
/**** P2MF10  F2H  PAGE 2 ****/
/**** P2MF32  F3H  PAGE 2 ****/
/**** P2MF54  F4H  PAGE 2 ****/
/**** P2MF76  F5H  PAGE 2 ****/
/**** P3MF10  F6H  PAGE 2 ****/
/**** P3MF32  F7H  PAGE 2 ****/
/**** P0MF10  F9H  PAGE 2 ****/
/**** P0MF32  FAH  PAGE 2 ****/
/**** P0MF54  FBH  PAGE 2 ****/
/**** P0MF76  FCH  PAGE 2 ****/
/**** P1MF10  FDH  PAGE 2 ****/
/**** P1MF32  FEH  PAGE 2 ****/
/**** P1MF54  FFH  PAGE 2 ****/

/********SFR PAGE 2*************/
/**** RTCRWEN  A2H  PAGE 3 ****/                                        
/**** RTCRWEN  A2H  PAGE 3 ****/
#define set_RTCRWEN_FADJTG               SFRS=3;RTCRWEN|=0x02
#define set_RTCRWEN_RWENF                SFRS=3;RTCRWEN|=0x01

#define clr_RTCRWEN_FADJTG               SFRS=3;RTCRWEN&=0xFD
#define clr_RTCRWEN_RWENF                SFRS=3;RTCRWEN&=0xFE

/**** RTCCLKSEL  A3H  PAGE 3 ****/
#define set_RTCCLKSEL_C32KS              SFRS=3;RTCCLKSEL|=0x01

#define clr_RTCCLKSEL_C32KS              SFRS=3;RTCCLKSEL&=0xFE

/**** RTCFREQADJ0  A4H  PAGE 3 ****/
#define set_RTCFREQADJ0_FRACTION         SFRS=3;RTCFREQADJ0|=0x20

#define clr_RTCFREQADJ0_FRACTION         SFRS=3;RTCFREQADJ0&=0xDF

/**** RTCFREQADJ1  A5H  PAGE 3 TA protect register ****/
#define set_RTCFREQADJ1_INTEGER          SFRS=3;RTCFREQADJ1|=0x40
#define set_RTCFREQADJ1_00010000b        SFRS=3;RTCFREQADJ1|=0x20

#define clr_RTCFREQADJ1_INTEGER          SFRS=3;RTCFREQADJ1&=0xBF
#define clr_RTCFREQADJ1_00010000b        SFRS=3;RTCFREQADJ1&=0xDF

/**** RTCINTEN  A6H  PAGE 3 ****/
#define set_RTCINTEN_TICKIEN             SFRS=3;RTCINTEN|=0x02
#define set_RTCINTEN_ALMIEN              SFRS=3;RTCINTEN|=0x01

#define clr_RTCINTEN_TICKIEN             SFRS=3;RTCINTEN&=0xFD
#define clr_RTCINTEN_ALMIEN              SFRS=3;RTCINTEN&=0xFE

/**** RTCINTSTS  A7H  PAGE 3 ****/
#define set_RTCINTSTS_TICKIF             SFRS=3;RTCINTSTS|=0x02
#define set_RTCINTSTS_ALMIF              SFRS=3;RTCINTSTS|=0x01

#define clr_RTCINTSTS_TICKIF             SFRS=3;RTCINTSTS&=0xFD
#define clr_RTCINTSTS_ALMIF              SFRS=3;RTCINTSTS&=0xFE

/**** RTCTIMESEC  A9H  PAGE 3 ****/
#define set_RTCTIMESEC_TENSEC_2          SFRS=3;RTCTIMESEC|=0x40
#define set_RTCTIMESEC_TENSEC_1          SFRS=3;RTCTIMESEC|=0x20
#define set_RTCTIMESEC_TENSEC_0          SFRS=3;RTCTIMESEC|=0x10
#define set_RTCTIMESEC_SEC_3             SFRS=3;RTCTIMESEC|=0x08
#define set_RTCTIMESEC_SEC_2             SFRS=3;RTCTIMESEC|=0x04
#define set_RTCTIMESEC_SEC_1             SFRS=3;RTCTIMESEC|=0x02
#define set_RTCTIMESEC_SEC_0             SFRS=3;RTCTIMESEC|=0x01

#define clr_RTCTIMESEC_TENSEC_2          SFRS=3;RTCTIMESEC&=0xBF
#define clr_RTCTIMESEC_TENSEC_1          SFRS=3;RTCTIMESEC&=0xDF
#define clr_RTCTIMESEC_TENSEC_0          SFRS=3;RTCTIMESEC&=0xEF
#define clr_RTCTIMESEC_SEC_3             SFRS=3;RTCTIMESEC&=0xF7
#define clr_RTCTIMESEC_SEC_2             SFRS=3;RTCTIMESEC&=0xFB
#define clr_RTCTIMESEC_SEC_1             SFRS=3;RTCTIMESEC&=0xFD
#define clr_RTCTIMESEC_SEC_0             SFRS=3;RTCTIMESEC&=0xFE

/**** RTCTIMEMIN  AAH  PAGE 3 ****/
#define set_RTCTIMEMIN_TENMIN_2          SFRS=3;RTCTIMEMIN|=0x40
#define set_RTCTIMEMIN_TENMIN_1          SFRS=3;RTCTIMEMIN|=0x20
#define set_RTCTIMEMIN_TENMIN_0          SFRS=3;RTCTIMEMIN|=0x10
#define set_RTCTIMEMIN_MIN_3             SFRS=3;RTCTIMEMIN|=0x08
#define set_RTCTIMEMIN_MIN_2             SFRS=3;RTCTIMEMIN|=0x04
#define set_RTCTIMEMIN_MIN_1             SFRS=3;RTCTIMEMIN|=0x02
#define set_RTCTIMEMIN_MIN_0             SFRS=3;RTCTIMEMIN|=0x01

#define clr_RTCTIMEMIN_TENMIN_2          SFRS=3;RTCTIMEMIN&=0xBF
#define clr_RTCTIMEMIN_TENMIN_1          SFRS=3;RTCTIMEMIN&=0xDF
#define clr_RTCTIMEMIN_TENMIN_0          SFRS=3;RTCTIMEMIN&=0xEF
#define clr_RTCTIMEMIN_MIN_3             SFRS=3;RTCTIMEMIN&=0xF7
#define clr_RTCTIMEMIN_MIN_2             SFRS=3;RTCTIMEMIN&=0xFB
#define clr_RTCTIMEMIN_MIN_1             SFRS=3;RTCTIMEMIN&=0xFD
#define clr_RTCTIMEMIN_MIN_0             SFRS=3;RTCTIMEMIN&=0xFE

/**** RTCTIMEHR  ABH  PAGE 3 ****/
#define set_RTCTIMEHR_TENHR_1            SFRS=3;RTCTIMEHR|=0x20
#define set_RTCTIMEHR_TENHR_0            SFRS=3;RTCTIMEHR|=0x10
#define set_RTCTIMEHR_HR_3               SFRS=3;RTCTIMEHR|=0x08
#define set_RTCTIMEHR_HR_2               SFRS=3;RTCTIMEHR|=0x04
#define set_RTCTIMEHR_HR_1               SFRS=3;RTCTIMEHR|=0x02
#define set_RTCTIMEHR_HR_0               SFRS=3;RTCTIMEHR|=0x01

#define clr_RTCTIMEHR_TENHR_1            SFRS=3;RTCTIMEHR&=0xDF
#define clr_RTCTIMEHR_TENHR_0            SFRS=3;RTCTIMEHR&=0xEF
#define clr_RTCTIMEHR_HR_3               SFRS=3;RTCTIMEHR&=0xF7
#define clr_RTCTIMEHR_HR_2               SFRS=3;RTCTIMEHR&=0xFB
#define clr_RTCTIMEHR_HR_1               SFRS=3;RTCTIMEHR&=0xFD
#define clr_RTCTIMEHR_HR_0               SFRS=3;RTCTIMEHR&=0xFE

/**** RTCTIMEHZ  ACH  PAGE 3 ****/
#define set_RTCTIMEHZ_HZCNT              SFRS=3;RTCTIMEHZ|=0x40

#define clr_RTCTIMEHZ_HZCNT              SFRS=3;RTCTIMEHZ&=0xBF

/**** RTCCALDAY  ADH  PAGE 3 ****/
#define set_RTCCALDAY_TENDAY             SFRS=3;RTCCALDAY|=0x20
#define set_RTCCALDAY_DAY                SFRS=3;RTCCALDAY|=0x08

#define clr_RTCCALDAY_TENDAY             SFRS=3;RTCCALDAY&=0xDF
#define clr_RTCCALDAY_DAY                SFRS=3;RTCCALDAY&=0xF7

/**** RTCCALMON  AEH  PAGE 3 ****/
#define set_RTCCALMON_TENMON_1           SFRS=3;RTCCALMON|=0x20
#define set_RTCCALMON_TENMON_0           SFRS=3;RTCCALMON|=0x10
#define set_RTCCALMON_MON_3              SFRS=3;RTCCALMON|=0x08
#define set_RTCCALMON_MON_2              SFRS=3;RTCCALMON|=0x04
#define set_RTCCALMON_MON_1              SFRS=3;RTCCALMON|=0x02
#define set_RTCCALMON_MON_0              SFRS=3;RTCCALMON|=0x01

#define clr_RTCCALMON_TENMON_1           SFRS=3;RTCCALMON&=0xDF
#define clr_RTCCALMON_TENMON_0           SFRS=3;RTCCALMON&=0xEF
#define clr_RTCCALMON_MON_3              SFRS=3;RTCCALMON&=0xF7
#define clr_RTCCALMON_MON_2              SFRS=3;RTCCALMON&=0xFB
#define clr_RTCCALMON_MON_1              SFRS=3;RTCCALMON&=0xFD
#define clr_RTCCALMON_MON_0              SFRS=3;RTCCALMON&=0xFE

/**** RTCCALYEAR  AFH  PAGE 3 ****/
#define set_RTCCALYEAR_TENYEAR           SFRS=3;RTCCALYEAR|=0x80
#define set_RTCCALYEAR_YEAR              SFRS=3;RTCCALYEAR|=0x40
#define set_RTCCALYEAR_00010101b         SFRS=3;RTCCALYEAR|=0x20

#define clr_RTCCALYEAR_TENYEAR           SFRS=3;RTCCALYEAR&=0x7F
#define clr_RTCCALYEAR_YEAR              SFRS=3;RTCCALYEAR&=0xBF
#define clr_RTCCALYEAR_00010101b         SFRS=3;RTCCALYEAR&=0xDF

/**** RTCTALMSEC  B1H  PAGE 3 ****/
#define set_RTCTALMSEC_TENSEC_2          SFRS=3;RTCTALMSEC|=0x40
#define set_RTCTALMSEC_TENSEC_1          SFRS=3;RTCTALMSEC|=0x20
#define set_RTCTALMSEC_TENSEC_0          SFRS=3;RTCTALMSEC|=0x10
#define set_RTCTALMSEC_SEC_3             SFRS=3;RTCTALMSEC|=0x08
#define set_RTCTALMSEC_SEC_2             SFRS=3;RTCTALMSEC|=0x04
#define set_RTCTALMSEC_SEC_1             SFRS=3;RTCTALMSEC|=0x02
#define set_RTCTALMSEC_SEC_0             SFRS=3;RTCTALMSEC|=0x01

#define clr_RTCTALMSEC_TENSEC_2          SFRS=3;RTCTALMSEC&=0xBF
#define clr_RTCTALMSEC_TENSEC_1          SFRS=3;RTCTALMSEC&=0xDF
#define clr_RTCTALMSEC_TENSEC_0          SFRS=3;RTCTALMSEC&=0xEF
#define clr_RTCTALMSEC_SEC_3             SFRS=3;RTCTALMSEC&=0xF7
#define clr_RTCTALMSEC_SEC_2             SFRS=3;RTCTALMSEC&=0xFB
#define clr_RTCTALMSEC_SEC_1             SFRS=3;RTCTALMSEC&=0xFD
#define clr_RTCTALMSEC_SEC_0             SFRS=3;RTCTALMSEC&=0xFE

/**** RTCTALMMIN  B2H  PAGE 3 ****/
#define set_RTCTALMMIN_TENMIN_2          SFRS=3;RTCTALMMIN|=0x40
#define set_RTCTALMMIN_TENMIN_1          SFRS=3;RTCTALMMIN|=0x20
#define set_RTCTALMMIN_TENMIN_0          SFRS=3;RTCTALMMIN|=0x10
#define set_RTCTALMMIN_MIN_3             SFRS=3;RTCTALMMIN|=0x08
#define set_RTCTALMMIN_MIN_2             SFRS=3;RTCTALMMIN|=0x04
#define set_RTCTALMMIN_MIN_1             SFRS=3;RTCTALMMIN|=0x02
#define set_RTCTALMMIN_MIN_0             SFRS=3;RTCTALMMIN|=0x01

#define clr_RTCTALMMIN_TENMIN_2          SFRS=3;RTCTALMMIN&=0xBF
#define clr_RTCTALMMIN_TENMIN_1          SFRS=3;RTCTALMMIN&=0xDF
#define clr_RTCTALMMIN_TENMIN_0          SFRS=3;RTCTALMMIN&=0xEF
#define clr_RTCTALMMIN_MIN_3             SFRS=3;RTCTALMMIN&=0xF7
#define clr_RTCTALMMIN_MIN_2             SFRS=3;RTCTALMMIN&=0xFB
#define clr_RTCTALMMIN_MIN_1             SFRS=3;RTCTALMMIN&=0xFD
#define clr_RTCTALMMIN_MIN_0             SFRS=3;RTCTALMMIN&=0xFE

/**** RTCTALMHR  B3H  PAGE 3 ****/
#define set_RTCTALMHR_TENHR_1            SFRS=3;RTCTALMHR|=0x20
#define set_RTCTALMHR_TENHR_0            SFRS=3;RTCTALMHR|=0x10
#define set_RTCTALMHR_HR_3               SFRS=3;RTCTALMHR|=0x08
#define set_RTCTALMHR_HR_2               SFRS=3;RTCTALMHR|=0x04
#define set_RTCTALMHR_HR_1               SFRS=3;RTCTALMHR|=0x02
#define set_RTCTALMHR_HR_0               SFRS=3;RTCTALMHR|=0x01

#define clr_RTCTALMHR_TENHR_1            SFRS=3;RTCTALMHR&=0xDF
#define clr_RTCTALMHR_TENHR_0            SFRS=3;RTCTALMHR&=0xEF
#define clr_RTCTALMHR_HR_3               SFRS=3;RTCTALMHR&=0xF7
#define clr_RTCTALMHR_HR_2               SFRS=3;RTCTALMHR&=0xFB
#define clr_RTCTALMHR_HR_1               SFRS=3;RTCTALMHR&=0xFD
#define clr_RTCTALMHR_HR_0               SFRS=3;RTCTALMHR&=0xFE

/**** RTCTALMHz  B4H  PAGE 3 ****/
#define set_RTCTALMHz_HZCNT              SFRS=3;RTCTALMHz|=0x40

#define clr_RTCTALMHz_HZCNT              SFRS=3;RTCTALMHz&=0xBF

/**** RTCCALMDAY  B5H  PAGE 3 ****/
#define set_RTCCALMDAY_TENDAY_1          SFRS=3;RTCCALMDAY|=0x20
#define set_RTCCALMDAY_TENDAY_0          SFRS=3;RTCCALMDAY|=0x10
#define set_RTCCALMDAY_DAY_3             SFRS=3;RTCCALMDAY|=0x08
#define set_RTCCALMDAY_DAY_2             SFRS=3;RTCCALMDAY|=0x04
#define set_RTCCALMDAY_DAY_1             SFRS=3;RTCCALMDAY|=0x02
#define set_RTCCALMDAY_DAY_0             SFRS=3;RTCCALMDAY|=0x01

#define clr_RTCCALMDAY_TENDAY_1          SFRS=3;RTCCALMDAY&=0xDF
#define clr_RTCCALMDAY_TENDAY_0          SFRS=3;RTCCALMDAY&=0xEF
#define clr_RTCCALMDAY_DAY_3             SFRS=3;RTCCALMDAY&=0xF7
#define clr_RTCCALMDAY_DAY_2             SFRS=3;RTCCALMDAY&=0xFB
#define clr_RTCCALMDAY_DAY_1             SFRS=3;RTCCALMDAY&=0xFD
#define clr_RTCCALMDAY_DAY_0             SFRS=3;RTCCALMDAY&=0xFE

/**** RTCCALMMON  B6H  PAGE 3 ****/
#define set_RTCCALMMON_TENMON            SFRS=3;RTCCALMMON|=0x10
#define set_RTCCALMMON_MON_3             SFRS=3;RTCCALMMON|=0x08
#define set_RTCCALMMON_MON_2             SFRS=3;RTCCALMMON|=0x04
#define set_RTCCALMMON_MON_1             SFRS=3;RTCCALMMON|=0x02
#define set_RTCCALMMON_MON_0             SFRS=3;RTCCALMMON|=0x01

#define clr_RTCCALMMON_TENMON            SFRS=3;RTCCALMMON&=0xEF
#define clr_RTCCALMMON_MON_3             SFRS=3;RTCCALMMON&=0xF7
#define clr_RTCCALMMON_MON_2             SFRS=3;RTCCALMMON&=0xFB
#define clr_RTCCALMMON_MON_1             SFRS=3;RTCCALMMON&=0xFD
#define clr_RTCCALMMON_MON_0             SFRS=3;RTCCALMMON&=0xFE

/**** RTCCALMYEAR  BBH  PAGE 3 ****/
#define set_RTCCALMYEAR_TENYEAR_3        SFRS=3;RTCCALMYEAR|=0x80
#define set_RTCCALMYEAR_TENYEAR_2        SFRS=3;RTCCALMYEAR|=0x40
#define set_RTCCALMYEAR_TENYEAR_1        SFRS=3;RTCCALMYEAR|=0x20
#define set_RTCCALMYEAR_TENYEAR_0        SFRS=3;RTCCALMYEAR|=0x10
#define set_RTCCALMYEAR_YEAR_3           SFRS=3;RTCCALMYEAR|=0x08
#define set_RTCCALMYEAR_YEAR_2           SFRS=3;RTCCALMYEAR|=0x04
#define set_RTCCALMYEAR_YEAR_1           SFRS=3;RTCCALMYEAR|=0x02
#define set_RTCCALMYEAR_YEAR_0           SFRS=3;RTCCALMYEAR|=0x01

#define clr_RTCCALMYEAR_TENYEAR_3        SFRS=3;RTCCALMYEAR&=0x7F
#define clr_RTCCALMYEAR_TENYEAR_2        SFRS=3;RTCCALMYEAR&=0xBF
#define clr_RTCCALMYEAR_TENYEAR_1        SFRS=3;RTCCALMYEAR&=0xDF
#define clr_RTCCALMYEAR_TENYEAR_0        SFRS=3;RTCCALMYEAR&=0xEF
#define clr_RTCCALMYEAR_YEAR_3           SFRS=3;RTCCALMYEAR&=0xF7
#define clr_RTCCALMYEAR_YEAR_2           SFRS=3;RTCCALMYEAR&=0xFB
#define clr_RTCCALMYEAR_YEAR_1           SFRS=3;RTCCALMYEAR&=0xFD
#define clr_RTCCALMYEAR_YEAR_0           SFRS=3;RTCCALMYEAR&=0xFE

/**** RTCCLKFMT  B9H  PAGE 3 ****/
#define set_RTCCLKFMT_HZCNTEN            SFRS=3;RTCCLKFMT|=0x02
#define set_RTCCLKFMT_24HEN              SFRS=3;RTCCLKFMT|=0x01

#define clr_RTCCLKFMT_HZCNTEN            SFRS=3;RTCCLKFMT&=0xFD
#define clr_RTCCLKFMT_24HEN              SFRS=3;RTCCLKFMT&=0xFE

/**** RTCCLKTEST  BAH  PAGE 3 TA protect register ****/
#define set_RTCCLKTEST_X64EN             SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;RTCCLKTEST|=0x01;EA=BIT_TMP

#define clr_RTCCLKTEST_X64EN             SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;RTCCLKTEST&=0xFE;EA=BIT_TMP

/**** RTCWEEKDAY  BBH  PAGE 3 ****/
#define set_RTCWEEKDAY_WEEKDAY_2         SFRS=3;RTCWEEKDAY|=0x04
#define set_RTCWEEKDAY_WEEKDAY_1         SFRS=3;RTCWEEKDAY|=0x02
#define set_RTCWEEKDAY_WEEKDAY_0         SFRS=3;RTCWEEKDAY|=0x01

#define clr_RTCWEEKDAY_WEEKDAY_2         SFRS=3;RTCWEEKDAY&=0xFB
#define clr_RTCWEEKDAY_WEEKDAY_1         SFRS=3;RTCWEEKDAY&=0xFD
#define clr_RTCWEEKDAY_WEEKDAY_0         SFRS=3;RTCWEEKDAY&=0xFE

/**** RTCLEAPYEAR  BCH  PAGE 3 ****/
#define set_RTCLEAPYEAR_LEAPYEAR         SFRS=3;RTCLEAPYEAR|=0x01

#define clr_RTCLEAPYEAR_LEAPYEAR         SFRS=3;RTCLEAPYEAR&=0xFE

/**** RTCTICK  BDH  PAGE 3 ****/
#define set_RTCTICK_TICK_2               SFRS=3;RTCTICK|=0x04
#define set_RTCTICK_TICK_1               SFRS=3;RTCTICK|=0x02
#define set_RTCTICK_TICK_0               SFRS=3;RTCTICK|=0x01

#define clr_RTCTICK_TICK_2               SFRS=3;RTCTICK&=0xFB
#define clr_RTCTICK_TICK_1               SFRS=3;RTCTICK&=0xFD
#define clr_RTCTICK_TICK_0               SFRS=3;RTCTICK&=0xFE

/**** RTCTAMSK  BEH  PAGE 3 ****/
#define set_RTCTAMSK_MTENHR              SFRS=3;RTCTAMSK|=0x20
#define set_RTCTAMSK_MHR                 SFRS=3;RTCTAMSK|=0x10
#define set_RTCTAMSK_MTENMIN             SFRS=3;RTCTAMSK|=0x08
#define set_RTCTAMSK_MMIN                SFRS=3;RTCTAMSK|=0x04
#define set_RTCTAMSK_MTENSEC             SFRS=3;RTCTAMSK|=0x02
#define set_RTCTAMSK_MSEC                SFRS=3;RTCTAMSK|=0x01

#define clr_RTCTAMSK_MTENHR              SFRS=3;RTCTAMSK&=0xDF
#define clr_RTCTAMSK_MHR                 SFRS=3;RTCTAMSK&=0xEF
#define clr_RTCTAMSK_MTENMIN             SFRS=3;RTCTAMSK&=0xF7
#define clr_RTCTAMSK_MMIN                SFRS=3;RTCTAMSK&=0xFB
#define clr_RTCTAMSK_MTENSEC             SFRS=3;RTCTAMSK&=0xFD
#define clr_RTCTAMSK_MSEC                SFRS=3;RTCTAMSK&=0xFE

/**** RTCCAMSK  BFH  PAGE 3 ****/
#define set_RTCCAMSK_MTENYEAR            SFRS=3;RTCCAMSK|=0x20
#define set_RTCCAMSK_MYEAR               SFRS=3;RTCCAMSK|=0x10
#define set_RTCCAMSK_MTENMON             SFRS=3;RTCCAMSK|=0x08
#define set_RTCCAMSK_MMON                SFRS=3;RTCCAMSK|=0x04
#define set_RTCCAMSK_MTENDAY             SFRS=3;RTCCAMSK|=0x02
#define set_RTCCAMSK_MDAY                SFRS=3;RTCCAMSK|=0x01

#define clr_RTCCAMSK_MTENYEAR            SFRS=3;RTCCAMSK&=0xDF
#define clr_RTCCAMSK_MYEAR               SFRS=3;RTCCAMSK&=0xEF
#define clr_RTCCAMSK_MTENMON             SFRS=3;RTCCAMSK&=0xF7
#define clr_RTCCAMSK_MMON                SFRS=3;RTCCAMSK&=0xFB
#define clr_RTCCAMSK_MTENDAY             SFRS=3;RTCCAMSK&=0xFD
#define clr_RTCCAMSK_MDAY                SFRS=3;RTCCAMSK&=0xFE

/**** LCDPCNTS1  E9H  PAGE 3 TA protect register ****/
#define set_LCDPCNTS1_LCDPCNTS_9         SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDPCNTS1|=0x02;EA=BIT_TMP
#define set_LCDPCNTS1_LCDPCNTS_8         SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDPCNTS1|=0x01;EA=BIT_TMP

#define clr_LCDPCNTS1_LCDPCNTS_9         SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDPCNTS1&=0xFD;EA=BIT_TMP
#define clr_LCDPCNTS1_LCDPCNTS_8         SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDPCNTS1&=0xFE;EA=BIT_TMP

/**** LCDPCNTV1  EAH  PAGE 3 TA protect register ****/
#define set_LCDPCNTV1_LCDPCNTV_9         SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDPCNTV1|=0x02;EA=BIT_TMP
#define set_LCDPCNTV1_LCDPCNTV_8         SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDPCNTV1|=0x01;EA=BIT_TMP

#define clr_LCDPCNTV1_LCDPCNTV_9         SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDPCNTV1&=0xFD;EA=BIT_TMP
#define clr_LCDPCNTV1_LCDPCNTV_8         SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDPCNTV1&=0xFE;EA=BIT_TMP

/**** LCDCPUMP  F1H  PAGE 3 ****/
#define set_LCDCPUMP_CP_VSET             SFRS=3;LCDCPUMP|=0x20

#define clr_LCDCPUMP_CP_VSET             SFRS=3;LCDCPUMP&=0xDF

/**** LCDADJUST  F2H  PAGE 3 TA protect register ****/
#define set_LCDADJUST_BUF_V3_iset        SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST|=0x80;EA=BIT_TMP
#define set_LCDADJUST_BUF_V2_iset        SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST|=0x40;EA=BIT_TMP
#define set_LCDADJUST_BUF_V1_iset        SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST|=0x20;EA=BIT_TMP
#define set_LCDADJUST_PUMP_HYS           SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST|=0x10;EA=BIT_TMP
#define set_LCDADJUST_SYN_SAV            SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST|=0x08;EA=BIT_TMP
#define set_LCDADJUST_L_ICMP             SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST|=0x04;EA=BIT_TMP
#define set_LCDADJUST_CP_ILOAD           SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST|=0x02;EA=BIT_TMP
#define set_LCDADJUST_IBOOST             SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST|=0x01;EA=BIT_TMP

#define clr_LCDADJUST_BUF_V3_iset        SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST&=0x7F;EA=BIT_TMP
#define clr_LCDADJUST_BUF_V2_iset        SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST&=0xBF;EA=BIT_TMP
#define clr_LCDADJUST_BUF_V1_iset        SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST&=0xDF;EA=BIT_TMP
#define clr_LCDADJUST_PUMP_HYS           SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST&=0xEF;EA=BIT_TMP
#define clr_LCDADJUST_SYN_SAV            SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST&=0xF7;EA=BIT_TMP
#define clr_LCDADJUST_L_ICMP             SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST&=0xFB;EA=BIT_TMP
#define clr_LCDADJUST_CP_ILOAD           SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST&=0xFD;EA=BIT_TMP
#define clr_LCDADJUST_IBOOST             SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDADJUST&=0xFE;EA=BIT_TMP

/**** LCDTest0  F3H  PAGE 3 TA protect register ****/
#define set_LCDTest0_V41_trim            SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDTest0|=0x80;EA=BIT_TMP
#define set_LCDTest0_V31_trim            SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDTest0|=0x20;EA=BIT_TMP
#define set_LCDTest0_LCD_T_DATA          SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDTest0|=0x08;EA=BIT_TMP
#define set_LCDTest0_BIN_TEST            SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDTest0|=0x01;EA=BIT_TMP

#define clr_LCDTest0_V41_trim            SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDTest0&=0x7F;EA=BIT_TMP
#define clr_LCDTest0_V31_trim            SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDTest0&=0xDF;EA=BIT_TMP
#define clr_LCDTest0_LCD_T_DATA          SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDTest0&=0xF7;EA=BIT_TMP
#define clr_LCDTest0_BIN_TEST            SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDTest0&=0xFE;EA=BIT_TMP

/**** LCDTest1  F4H  PAGE 3 TA protect register ****/
#define set_LCDCON1_LCDIS                SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDCON1|=0x08;EA=BIT_TMP
#define set_LCDCON1_LCDIE                SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDCON1|=0x04;EA=BIT_TMP
#define set_LCDCON1_RE_MODE              SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDCON1|=0x02;EA=BIT_TMP

#define clr_LCDCON1_LCDIS                SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDCON1&=0xF7;EA=BIT_TMP
#define clr_LCDCON1_LCDIE                SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDCON1&=0xFB;EA=BIT_TMP
#define clr_LCDCON1_RE_MODE              SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDCON1&=0xFD;EA=BIT_TMP

/**** LCDIS  F7H  PAGE 3 TA protect register ****/
#define set_LCDIS_LCDPO_INT              SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDIS|=0x02;EA=BIT_TMP
#define set_LCDIS_LCD_INT                SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDIS|=0x01;EA=BIT_TMP

#define clr_LCDIS_LCDPO_INT              SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDIS&=0xFD;EA=BIT_TMP
#define clr_LCDIS_LCD_INT                SFRS=3;BIT_TMP=EA;EA=0;TA=0xAA;TA=0x55;LCDIS&=0xFE;EA=BIT_TMP

/**** LCDCON0  F9H  PAGE 3 ****/
#define set_LCDCON0_LCDEN                SFRS=3;LCDCON0|=0x80
#define set_LCDCON0_TYPE                 SFRS=3;LCDCON0|=0x40
#define set_LCDCON0_BIAS_1               SFRS=3;LCDCON0|=0x20
#define set_LCDCON0_BIAS_0               SFRS=3;LCDCON0|=0x10
#define set_LCDCON0_DUTY_1               SFRS=3;LCDCON0|=0x08
#define set_LCDCON0_DUTY_0               SFRS=3;LCDCON0|=0x04
#define set_LCDCON0_LCD_IE               SFRS=3;LCDCON0|=0x01

#define clr_LCDCON0_LCDEN                SFRS=3;LCDCON0&=0x7F
#define clr_LCDCON0_TYPE                 SFRS=3;LCDCON0&=0xBF
#define clr_LCDCON0_BIAS_1               SFRS=3;LCDCON0&=0xDF
#define clr_LCDCON0_BIAS_0               SFRS=3;LCDCON0&=0xEF
#define clr_LCDCON0_DUTY_1               SFRS=3;LCDCON0&=0xF7
#define clr_LCDCON0_DUTY_0               SFRS=3;LCDCON0&=0xFB
#define clr_LCDCON0_LCD_IE               SFRS=3;LCDCON0&=0xFE

/**** LCDCLK  FAH  PAGE 3 ****/
#define set_LCDCLK_LCDCKS                SFRS=3;LCDCLK|=0x10
#define set_LCDCLK_DISP                  SFRS=3;LCDCLK|=0x08
#define set_LCDCLK_LCDDIV_2              SFRS=3;LCDCLK|=0x04
#define set_LCDCLK_LCDDIV_1              SFRS=3;LCDCLK|=0x02
#define set_LCDCLK_LCDDIV_0              SFRS=3;LCDCLK|=0x01

#define clr_LCDCLK_LCDCKS                SFRS=3;LCDCLK&=0xEF
#define clr_LCDCLK_DISP                  SFRS=3;LCDCLK&=0xF7
#define clr_LCDCLK_LCDDIV_2              SFRS=3;LCDCLK&=0xFB
#define clr_LCDCLK_LCDDIV_1              SFRS=3;LCDCLK&=0xFD
#define clr_LCDCLK_LCDDIV_0              SFRS=3;LCDCLK&=0xFE

/**** LCDPTR  FBH  PAGE 3 ****/
#define set_LCDPTR_LCDPTR_4              SFRS=3;LCDPTR|=0x10
#define set_LCDPTR_LCDPTR_3              SFRS=3;LCDPTR|=0x08
#define set_LCDPTR_LCDPTR_2              SFRS=3;LCDPTR|=0x04
#define set_LCDPTR_LCDPTR_1              SFRS=3;LCDPTR|=0x02
#define set_LCDPTR_LCDPTR_0              SFRS=3;LCDPTR|=0x01

#define clr_LCDPTR_LCDPTR_4              SFRS=3;LCDPTR&=0xEF
#define clr_LCDPTR_LCDPTR_3              SFRS=3;LCDPTR&=0xF7
#define clr_LCDPTR_LCDPTR_2              SFRS=3;LCDPTR&=0xFB
#define clr_LCDPTR_LCDPTR_1              SFRS=3;LCDPTR&=0xFD
#define clr_LCDPTR_LCDPTR_0              SFRS=3;LCDPTR&=0xFE

/**** LCDPWR  FDH  PAGE 3 ****/
#define set_LCDPWR_PWR_SAVE_1            SFRS=3;LCDPWR|=0x02
#define set_LCDPWR_PWR_SAVE_0            SFRS=3;LCDPWR|=0x01

#define clr_LCDPWR_PWR_SAVE_1            SFRS=3;LCDPWR&=0xFD
#define clr_LCDPWR_PWR_SAVE_0            SFRS=3;LCDPWR&=0xFE

/**** LCDBL  FEH  PAGE 3 ****/
#define set_LCDBL_DT_2                   SFRS=3;LCDBL|=0x40
#define set_LCDBL_DT_1                   SFRS=3;LCDBL|=0x20
#define set_LCDBL_DT_0                   SFRS=3;LCDBL|=0x10
#define set_LCDBL_BLINK                  SFRS=3;LCDBL|=0x08
#define set_LCDBL_BLF_2                  SFRS=3;LCDBL|=0x04
#define set_LCDBL_BLF_1                  SFRS=3;LCDBL|=0x02
#define set_LCDBL_BLF_0                  SFRS=3;LCDBL|=0x01

#define clr_LCDBL_DT_2                   SFRS=3;LCDBL&=0xBF
#define clr_LCDBL_DT_1                   SFRS=3;LCDBL&=0xDF
#define clr_LCDBL_DT_0                   SFRS=3;LCDBL&=0xEF
#define clr_LCDBL_BLINK                  SFRS=3;LCDBL&=0xF7
#define clr_LCDBL_BLF_2                  SFRS=3;LCDBL&=0xFB
#define clr_LCDBL_BLF_1                  SFRS=3;LCDBL&=0xFD
#define clr_LCDBL_BLF_0                  SFRS=3;LCDBL&=0xFE

/**** LCDMODE  FFH  PAGE 3 ****/
#define set_LCDMODE_R_MODE               SFRS=3;LCDMODE|=0x80
#define set_LCDMODE_SELBUF               SFRS=3;LCDMODE|=0x40
#define set_LCDMODE_VLCD_MODE_1          SFRS=3;LCDMODE|=0x02
#define set_LCDMODE_VLCD_MODE_0          SFRS=3;LCDMODE|=0x01

#define clr_LCDMODE_R_MODE               SFRS=3;LCDMODE&=0x7F
#define clr_LCDMODE_SELBUF               SFRS=3;LCDMODE&=0xBF
#define clr_LCDMODE_VLCD_MODE_1          SFRS=3;LCDMODE&=0xFD
#define clr_LCDMODE_VLCD_MODE_0          SFRS=3;LCDMODE&=0xFE
