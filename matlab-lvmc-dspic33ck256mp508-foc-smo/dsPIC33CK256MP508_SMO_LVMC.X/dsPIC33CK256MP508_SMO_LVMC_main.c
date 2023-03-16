/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.50.30 (21-Nov-2022)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: dsPIC33CK256MP508_SMO_LVMC_main.c
 *
 * Code generated for Simulink model 'dsPIC33CK256MP508_SMO_LVMC'.
 *
 * Model version                  : 7.14
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Mar 16 10:58:36 2023
 */

/* Set Fuses Options */

#pragma config FNOSC = FRC
#pragma config OSCIOFNC = ON, FCKSM = CSECMD, PLLKEN = ON
#pragma config RWDTPS = PS1048576, SWDTPS = PS1048576, FWDTEN = ON_SW
#pragma config ICS = PGD3, JTAGEN = OFF

#define MCHP_isMainFile
#include "dsPIC33CK256MP508_SMO_LVMC.h"
#include "dsPIC33CK256MP508_SMO_LVMC_private.h"

/* Microchip Global Variables */
int main()
{
  /* Initialize model */

  /* Start Clock Switching */
  if ((OSCCONbits.COSC & 1) && !(OSCCONbits.COSC & 4))/* check not already in PLL mode (0?1) */
  {
    __builtin_write_OSCCONH(2);        /* Clock Switch to non PLL mode */
    __builtin_write_OSCCONL(0x01);     /* Start clock switching */
    __asm__ volatile("nop\n"
                     "nop");
    while (OSCCONbits.COSC != 2) ;
  }

  PLLFBD = 100;                        /* Oscillator PLL : PLLDIV */
  CLKDIV = 0x01;                /* Oscillator PLL : FRCDIV ; PLLPOST ; PLLPRE */
  PLLDIV = 0x21;                   /* Oscillator PLL : POST1DIV and POST2DIV  */
  __builtin_write_OSCCONH(1);        /* Clock Switch to desired configuration */
  __builtin_write_OSCCONL(0x01);       /* Start clock switching */

  /* Configure Pins as Analog or Digital */
  ANSELD = 0x0C00;

  /* Configure Remappables Pins */
  RPOR22 = 0x0100;

  /* Configure Digitals I/O directions */
  TRISD = 0xFEFF;
  TRISE = 0xFF3F;

  /* Finish clock switching procedure */
  while (OSCCONbits.COSC != 1) ;       /* Wait for Oscillator Stabilisation */
  while (OSCCONbits.LOCK != 1) ;       /* Wait for PLL Stabilisation */

  /* Initialize model */
  dsPIC33CK256MP508_SMO_LVMC_initialize();

  /* Configure Timers */

  /* Enable Time-step */
  /* Turning ON the PWM Generator 1;
     Thus starting all the PWM modules in unison */
  PG1CONLbits.ON = 1;

  /* Main Loop */
  for (;;) ;

  /* Terminate model */
  dsPIC33CK256MP508_SMO_LVMC_terminate();
}                                      /* end of main() */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
