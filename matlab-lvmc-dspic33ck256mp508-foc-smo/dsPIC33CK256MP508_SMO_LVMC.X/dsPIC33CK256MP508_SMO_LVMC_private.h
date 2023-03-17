/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.50.30 (21-Nov-2022)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: dsPIC33CK256MP508_SMO_LVMC_private.h
 *
 * Code generated for Simulink model 'dsPIC33CK256MP508_SMO_LVMC'.
 *
 * Model version                  : 7.14
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Mar 16 10:58:36 2023
 */

#ifndef RTW_HEADER_dsPIC33CK256MP508_SMO_LVMC_private_h_
#define RTW_HEADER_dsPIC33CK256MP508_SMO_LVMC_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "dsPIC33CK256MP508_SMO_LVMC.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Declare UART1 Tx Circular Buffer Structure */
extern MCHP_UART1_TxStr MCHP_UART1_Tx;
extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_hiSR(int32_T a, int32_T b, uint32_T aShift);
extern int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift);
extern void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern uint32_T mul_u32_hiSR(uint32_T a, uint32_T b, uint32_T aShift);
extern int16_T div_s16_floor(int16_T numerator, int16_T denominator);
extern void dsPIC33CK256MP508_SMO_LVMC_SpeedControl_Init(void);
extern void dsPIC33CK256MP508_SMO_LVMC_SpeedControl(void);

#endif                    /* RTW_HEADER_dsPIC33CK256MP508_SMO_LVMC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
