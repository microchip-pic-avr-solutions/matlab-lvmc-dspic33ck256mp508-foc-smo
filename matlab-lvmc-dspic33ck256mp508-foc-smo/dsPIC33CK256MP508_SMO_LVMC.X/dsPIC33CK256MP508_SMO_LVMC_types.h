/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.50.30 (21-Nov-2022)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: dsPIC33CK256MP508_SMO_LVMC_types.h
 *
 * Code generated for Simulink model 'dsPIC33CK256MP508_SMO_LVMC'.
 *
 * Model version                  : 7.14
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Mar 16 10:58:36 2023
 */

#ifndef RTW_HEADER_dsPIC33CK256MP508_SMO_LVMC_types_h_
#define RTW_HEADER_dsPIC33CK256MP508_SMO_LVMC_types_h_
#include "rtwtypes.h"

/* Model Code Variants */

/* Declare UART1 Tx Circular Buffer Structure */
#define Tx_BUFF_SIZE_UART1             (64)

typedef struct MCHP_UART1_TxStr{
  volatile uint8_T buffer[Tx_BUFF_SIZE_UART1];/* Size Rx_BUFF_SIZE_UART1 is 64 */
  volatile uint_T tail;
  /* tail is the index for the next value to be read from the Circular buffer */
  volatile uint_T head;
  /* head is the index for the next value to be written into the Circular buffer */
} MCHP_UART1_TxStr;

/* Forward declaration for rtModel */
typedef struct tag_RTM_dsPIC33CK256MP508_SMO_LVMC_T
  RT_MODEL_dsPIC33CK256MP508_SMO_LVMC_T;

#endif                      /* RTW_HEADER_dsPIC33CK256MP508_SMO_LVMC_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
