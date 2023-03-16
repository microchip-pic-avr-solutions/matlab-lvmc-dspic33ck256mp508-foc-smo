/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.50.30 (21-Nov-2022)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: dsPIC33CK256MP508_SMO_LVMC.c
 *
 * Code generated for Simulink model 'dsPIC33CK256MP508_SMO_LVMC'.
 *
 * Model version                  : 7.14
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Mar 16 10:58:36 2023
 */

#include "dsPIC33CK256MP508_SMO_LVMC.h"
#include "rtwtypes.h"
#include "dsPIC33CK256MP508_SMO_LVMC_private.h"
#include "MCHP_MACRO_AddSubSat.h"
#include "MCHP_MACRO_Saturate.h"
#include "MCHP_MACRO_Atan2.h"
#include "MCHP_MACRO_SQRT.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S148>/Chart' */
#define dsPIC33CK256MP508_SMO_LVMC_IN_Align ((uint8_T)1U)
#define dsPIC33CK256MP508_SMO_LVMC_IN_ClosedLoop ((uint8_T)2U)
#define dsPIC33CK256MP508_SMO_LVMC_IN_ClosedLoopFilter ((uint8_T)3U)
#define dsPIC33CK256MP508_SMO_LVMC_IN_Init ((uint8_T)4U)
#define dsPIC33CK256MP508_SMO_LVMC_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define dsPIC33CK256MP508_SMO_LVMC_IN_OpenLoop ((uint8_T)5U)

/* Block signals (default storage) */
B_dsPIC33CK256MP508_SMO_LVMC_T dsPIC33CK256MP508_SMO_LVMC_B;

/* Block states (default storage) */
DW_dsPIC33CK256MP508_SMO_LVMC_T dsPIC33CK256MP508_SMO_LVMC_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_dsPIC33CK256MP508_SMO_LVMC_T dsPIC33CK256MP508_SMO_LVMC_PrevZCX;

/* Real-time model */
static RT_MODEL_dsPIC33CK256MP508_SMO_LVMC_T dsPIC33CK256MP508_SMO_LVMC_M_;
RT_MODEL_dsPIC33CK256MP508_SMO_LVMC_T *const dsPIC33CK256MP508_SMO_LVMC_M =
  &dsPIC33CK256MP508_SMO_LVMC_M_;
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0L ? ~(uint32_T)in0 + 1UL : (uint32_T)in0;
  absIn1 = in1 < 0L ? ~(uint32_T)in1 + 1UL : (uint32_T)in1;
  in0Hi = absIn0 >> 16UL;
  in0Lo = absIn0 & 65535UL;
  in1Hi = absIn1 >> 16UL;
  absIn0 = absIn1 & 65535UL;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0UL;
  in0Lo = (productLoHi << 16UL) + absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1UL;
  }

  absIn0 = in0Lo;
  in0Lo += productHiLo << 16UL;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16UL) + (productHiLo >> 16UL)) + in0Hi * in1Hi) +
    absIn1;
  if ((in0 != 0L) && ((in1 != 0L) && ((in0 > 0L) != (in1 > 0L)))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0UL) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_hiSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  return (int32_T)u32_chi >> aShift;
}

int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << (32UL - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T in1Lo;
  uint32_T outBitsLo;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16UL;
  in0Lo = in0 & 65535UL;
  in1Hi = in1 >> 16UL;
  in1Lo = in1 & 65535UL;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0UL;
  outBitsLo = (productLoHi << 16UL) + in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1UL;
  }

  in0Lo = outBitsLo;
  outBitsLo += productHiLo << 16UL;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16UL) + (productHiLo >> 16UL)) + in0Hi *
                   in1Hi) + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_hiSR(uint32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  return u32_chi >> aShift;
}

int16_T div_s16_floor(int16_T numerator, int16_T denominator)
{
  int16_T quotient;
  uint16_T absDenominator;
  uint16_T absNumerator;
  uint16_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int16_T : MIN_int16_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint16_T)numerator + 1U : (uint16_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint16_T)denominator + 1U : (uint16_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int16_T)tempAbsQuotient : (int16_T)
      tempAbsQuotient;
  }

  return quotient;
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void dsPIC33CK256MP508_SMO_LVMC_SpeedControl_Init(void)
{
  /* InitializeConditions for RateLimiter: '<S4>/Rate Limiter2' */
  dsPIC33CK256MP508_SMO_LVMC_DW.PrevY = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S216>/Integrator' incorporates:
   *  Constant: '<S177>/Ki2'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE_f = 0;
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_PrevResetState_o = 0;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void dsPIC33CK256MP508_SMO_LVMC_SpeedControl(void)
{
  /* local block i/o variables */
  boolean_T rtb_ButtonS2;
  int32_T tmp;
  int16_T rtb_IProdOut;
  int16_T rtb_RateLimiter2;
  int16_T rtb_Sum;
  int16_T rtb_Sum_j;
  int8_T rtb_IProdOut_0;
  int8_T rtb_Switch1;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_RelationalOperator;

  /* RateLimiter: '<S4>/Rate Limiter2' incorporates:
   *  RateTransition: '<Root>/Rate Transition6'
   */
  tmp = (int32_T)dsPIC33CK256MP508_SMO_LVMC_B.RateTransition6 -
    dsPIC33CK256MP508_SMO_LVMC_DW.PrevY;
  if (tmp > 12L) {
    rtb_RateLimiter2 = (int16_T)(dsPIC33CK256MP508_SMO_LVMC_DW.PrevY + 12L);
  } else if (tmp < -5L) {
    rtb_RateLimiter2 = (int16_T)(dsPIC33CK256MP508_SMO_LVMC_DW.PrevY + -5L);
  } else {
    rtb_RateLimiter2 = dsPIC33CK256MP508_SMO_LVMC_B.RateTransition6;
  }

  dsPIC33CK256MP508_SMO_LVMC_DW.PrevY = rtb_RateLimiter2;

  /* End of RateLimiter: '<S4>/Rate Limiter2' */

  /* Switch: '<S178>/Switch' incorporates:
   *  Constant: '<S178>/Constant'
   *  DataStoreRead: '<S178>/Data Store Read1'
   *  DataStoreWrite: '<S4>/Data Store Write'
   */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.EnableFOC) {
    /* Saturate: '<S4>/Saturation' incorporates:
     *  DataStoreWrite: '<S4>/Data Store Write'
     *  RateLimiter: '<S4>/Rate Limiter2'
     *  Switch: '<S178>/Switch'
     */
    if (rtb_RateLimiter2 > 20367) {
      dsPIC33CK256MP508_SMO_LVMC_DW.SpeedRef = 20367;
    } else if (rtb_RateLimiter2 < 2829) {
      dsPIC33CK256MP508_SMO_LVMC_DW.SpeedRef = 2829;
    } else {
      dsPIC33CK256MP508_SMO_LVMC_DW.SpeedRef = rtb_RateLimiter2;
    }

    /* End of Saturate: '<S4>/Saturation' */
  } else {
    dsPIC33CK256MP508_SMO_LVMC_DW.SpeedRef = 0;
  }

  /* End of Switch: '<S178>/Switch' */

  /* Constant: '<S4>/Id_ref' */
  dsPIC33CK256MP508_SMO_LVMC_B.Id_ref = 0;

  /* Sum: '<S235>/Add1' incorporates:
   *  DataStoreWrite: '<S4>/Data Store Write'
   *  Product: '<S235>/Product'
   *  Product: '<S235>/Product1'
   *  Switch: '<S178>/Switch'
   *  UnitDelay: '<S235>/Unit Delay'
   */
  rtb_RateLimiter2 = (int16_T)((dsPIC33CK256MP508_SMO_LVMC_DW.SpeedRef * 123L) >>
    12) + (int16_T)((3973L * dsPIC33CK256MP508_SMO_LVMC_DW.UnitDelay_DSTATE) >>
                    12);

  /* Sum: '<S177>/Sum' incorporates:
   *  RateTransition: '<Root>/Rate Transition7'
   *  Sum: '<S235>/Add1'
   */
  rtb_Sum_j = rtb_RateLimiter2 - dsPIC33CK256MP508_SMO_LVMC_B.RateTransition7;

  /* Logic: '<S177>/Logical Operator' incorporates:
   *  DataStoreRead: '<S177>/Data Store Read1'
   *  DataStoreRead: '<S177>/Data Store Read2'
   *  Logic: '<S177>/AND'
   */
  rtb_LogicalOperator = ((!dsPIC33CK256MP508_SMO_LVMC_DW.EnableClosedLoop) ||
    (!dsPIC33CK256MP508_SMO_LVMC_DW.Enable));

  /* DiscreteIntegrator: '<S216>/Integrator' incorporates:
   *  Constant: '<S177>/Ki2'
   */
  if (rtb_LogicalOperator ||
      (dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_PrevResetState_o != 0)) {
    dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE_f = 0;
  }

  /* Sum: '<S225>/Sum' incorporates:
   *  DiscreteIntegrator: '<S216>/Integrator'
   *  Product: '<S221>/PProd Out'
   *  Sum: '<S177>/Sum'
   */
  rtb_Sum = (int16_T)((rtb_Sum_j * 1923L) >> 12) +
    dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE_f;

  /* DeadZone: '<S209>/DeadZone' incorporates:
   *  Product: '<S213>/IProd Out'
   *  Sum: '<S225>/Sum'
   */
  if (rtb_Sum > 16384) {
    rtb_IProdOut = rtb_Sum - 16384;
  } else if (rtb_Sum >= -16384) {
    rtb_IProdOut = 0;
  } else {
    rtb_IProdOut = rtb_Sum - -16384;
  }

  /* End of DeadZone: '<S209>/DeadZone' */

  /* RelationalOperator: '<S207>/Relational Operator' incorporates:
   *  Product: '<S213>/IProd Out'
   */
  rtb_RelationalOperator = (rtb_IProdOut != 0);

  /* Switch: '<S207>/Switch1' incorporates:
   *  Constant: '<S207>/Constant'
   *  Constant: '<S207>/Constant2'
   *  Product: '<S213>/IProd Out'
   *  RelationalOperator: '<S207>/fix for DT propagation issue'
   */
  if (rtb_IProdOut > 0) {
    rtb_Switch1 = 1;
  } else {
    rtb_Switch1 = -1;
  }

  /* End of Switch: '<S207>/Switch1' */

  /* Product: '<S213>/IProd Out' incorporates:
   *  Constant: '<S177>/Ki1'
   *  Sum: '<S177>/Sum'
   */
  rtb_IProdOut = (int16_T)((rtb_Sum_j * 221L) >> 14);

  /* Switch: '<S4>/Switch' incorporates:
   *  DataStoreRead: '<S4>/Data Store Read'
   */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.EnableClosedLoop) {
    /* Saturate: '<S223>/Saturation' incorporates:
     *  Sum: '<S225>/Sum'
     */
    if (rtb_Sum > 16384) {
      /* Switch: '<S4>/Switch' */
      dsPIC33CK256MP508_SMO_LVMC_B.Switch = 16384;
    } else if (rtb_Sum < -16384) {
      /* Switch: '<S4>/Switch' */
      dsPIC33CK256MP508_SMO_LVMC_B.Switch = -16384;
    } else {
      /* Switch: '<S4>/Switch' */
      dsPIC33CK256MP508_SMO_LVMC_B.Switch = rtb_Sum;
    }

    /* End of Saturate: '<S223>/Saturation' */
  } else {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Iq_ref1'
     */
    dsPIC33CK256MP508_SMO_LVMC_B.Switch = 562;
  }

  /* End of Switch: '<S4>/Switch' */

  /* S-Function (MCHP_Digital_Input): '<S179>/Button S2' */
  /* MCHP_Digital_Input Block: <S179>/Button S2/Output */
  rtb_ButtonS2 = PORTEbits.RE11;       /* Read pin E11 */

  /* Outputs for Triggered SubSystem: '<S179>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S180>/Trigger'
   */
  if ((!rtb_ButtonS2) &&
      (dsPIC33CK256MP508_SMO_LVMC_PrevZCX.TriggeredSubsystem_Trig_ZCE !=
       ZERO_ZCSIG)) {
    /* Logic: '<S180>/NOT' incorporates:
     *  DataStoreWrite: '<S180>/Data Store Write'
     *  Delay: '<S180>/Delay'
     */
    dsPIC33CK256MP508_SMO_LVMC_DW.Enable =
      !dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_a;

    /* Update for Delay: '<S180>/Delay' incorporates:
     *  DataStoreWrite: '<S180>/Data Store Write'
     */
    dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_a =
      dsPIC33CK256MP508_SMO_LVMC_DW.Enable;
  }

  dsPIC33CK256MP508_SMO_LVMC_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_ButtonS2;

  /* End of Outputs for SubSystem: '<S179>/Triggered Subsystem' */

  /* Update for UnitDelay: '<S235>/Unit Delay' incorporates:
   *  Sum: '<S235>/Add1'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.UnitDelay_DSTATE = rtb_RateLimiter2;

  /* Switch: '<S207>/Switch2' incorporates:
   *  Constant: '<S207>/Constant3'
   *  Constant: '<S207>/Constant4'
   *  Product: '<S213>/IProd Out'
   *  RelationalOperator: '<S207>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0) {
    rtb_IProdOut_0 = 1;
  } else {
    rtb_IProdOut_0 = -1;
  }

  /* End of Switch: '<S207>/Switch2' */

  /* Switch: '<S207>/Switch' incorporates:
   *  Constant: '<S207>/Constant1'
   *  Logic: '<S207>/AND3'
   *  RelationalOperator: '<S207>/Equal1'
   */
  if (rtb_RelationalOperator && (rtb_Switch1 == rtb_IProdOut_0)) {
    rtb_IProdOut = 0;
  }

  /* End of Switch: '<S207>/Switch' */

  /* Update for DiscreteIntegrator: '<S216>/Integrator' */
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE_f += rtb_IProdOut;
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_PrevResetState_o = (int8_T)
    rtb_LogicalOperator;
}

/* Model step function for TID0 */
void dsPIC33CK256MP508_SMO_LVMC_step0(void) /* Sample time: [5.0E-5s, 0.0s] */
{
  int32_T tmp;
  int16_T rtb_RateTransition5[2];
  int16_T DiscreteTimeIntegrator;
  int16_T DiscreteTimeIntegrator2_idx_0;
  int16_T DiscreteTimeIntegrator2_idx_1;
  int16_T DiscreteTimeIntegrator4;
  int16_T DiscreteTimeIntegrator_idx_0;
  int16_T rtb_DeadZone;
  int16_T rtb_Gain5;
  int16_T rtb_Gain7_e_idx_0;
  int16_T rtb_Gain7_e_idx_1;
  int16_T rtb_Gain_d;
  int16_T rtb_IProdOut;
  int16_T rtb_Integrator_i;
  int16_T rtb_Saturation_g;
  int16_T rtb_Sum;
  int16_T rtb_Sum4_f;
  int16_T rtb_Sum4_j_idx_0;
  int16_T rtb_Sum4_j_idx_1;
  int16_T rtb_Switch1;
  int16_T rtb_Switch1_j_idx_0;
  int16_T rtb_ToPerUnit_idx_0;
  int16_T rtb_ToPerUnit_idx_1;
  int16_T rtb_sum_beta;
  uint16_T rtb_DataTypeConversion;
  uint16_T rtb_DeadtimeCompensation_idx_1;
  uint16_T rtb_DeadtimeCompensation_idx_2;
  int8_T rtb_DeadZone_0;
  int8_T rtb_IProdOut_i;
  boolean_T EnCurOffset;
  boolean_T rtb_LogicalOperator_o_tmp;

  /* Outputs for Enabled SubSystem: '<S140>/Up Counter' incorporates:
   *  EnablePort: '<S142>/Enable'
   */
  /* Logic: '<S140>/NOT' incorporates:
   *  Delay: '<S140>/Delay'
   */
  if (!dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_n) {
    if (!dsPIC33CK256MP508_SMO_LVMC_DW.UpCounter_MODE) {
      /* InitializeConditions for Delay: '<S142>/Delay' */
      dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE = 0UL;
      dsPIC33CK256MP508_SMO_LVMC_DW.UpCounter_MODE = true;
    }

    /* Sum: '<S142>/Add1' incorporates:
     *  Constant: '<S142>/Constant'
     *  Delay: '<S142>/Delay'
     */
    dsPIC33CK256MP508_SMO_LVMC_B.Add1 = MCHP_addSat_CAO_u32_u32_u32(1UL,
      dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE);

    /* Update for Delay: '<S142>/Delay' */
    dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE =
      dsPIC33CK256MP508_SMO_LVMC_B.Add1;
  } else {
    dsPIC33CK256MP508_SMO_LVMC_DW.UpCounter_MODE = false;
  }

  /* End of Logic: '<S140>/NOT' */
  /* End of Outputs for SubSystem: '<S140>/Up Counter' */

  /* Gain: '<S141>/Gain' */
  rtb_Gain_d = (int16_T)mul_u32_hiSR(3518437209UL,
    dsPIC33CK256MP508_SMO_LVMC_B.Add1, 2UL);

  /* RelationalOperator: '<S144>/Compare' incorporates:
   *  DataStoreWrite: '<S141>/Data Store Write'
   *  Gain: '<S141>/Gain'
   */
  EnCurOffset = (rtb_Gain_d < 4096);

  /* RelationalOperator: '<S143>/Compare' incorporates:
   *  DataStoreWrite: '<S141>/Data Store Write1'
   *  Gain: '<S141>/Gain'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.EnableFOC = (rtb_Gain_d >= 8192);

  /* RateTransition: '<Root>/Rate Transition5' */
  rtb_Sum4_f = dsPIC33CK256MP508_SMO_LVMC_DW.RateTransition5_ActiveBufIdx << 1;
  rtb_RateTransition5[0] =
    dsPIC33CK256MP508_SMO_LVMC_DW.RateTransition5_Buffer[rtb_Sum4_f];
  rtb_RateTransition5[1] =
    dsPIC33CK256MP508_SMO_LVMC_DW.RateTransition5_Buffer[rtb_Sum4_f + 1];

  /* S-Function (MCHP_ADC_HighSpeed_SAR_dsPIC): '<S7>/ADC dsPIC High Speed SAR' */
  dsPIC33CK256MP508_SMO_LVMC_B.ADCdsPICHighSpeedSAR_o1 = (signed int) ADCBUF0;/* Read ADC converted value */
  dsPIC33CK256MP508_SMO_LVMC_B.ADCdsPICHighSpeedSAR_o2 = (signed int) ADCBUF1;/* Read ADC converted value */
  dsPIC33CK256MP508_SMO_LVMC_B.U2CH2 = (unsigned int) ADCBUF11;/* Read ADC converted value */

  /* Outputs for Enabled SubSystem: '<S7>/Offset1' incorporates:
   *  EnablePort: '<S139>/Enable'
   */
  /* DataStoreRead: '<S7>/Data Store Read' */
  if (EnCurOffset) {
    /* SignalConversion generated from: '<S139>/Iab' */
    dsPIC33CK256MP508_SMO_LVMC_B.Iab[0] =
      dsPIC33CK256MP508_SMO_LVMC_B.ADCdsPICHighSpeedSAR_o1;
    dsPIC33CK256MP508_SMO_LVMC_B.Iab[1] =
      dsPIC33CK256MP508_SMO_LVMC_B.ADCdsPICHighSpeedSAR_o2;
  }

  /* End of DataStoreRead: '<S7>/Data Store Read' */
  /* End of Outputs for SubSystem: '<S7>/Offset1' */

  /* Gain: '<S7>/To Per-Unit' incorporates:
   *  SignalConversion generated from: '<S7>/Add2'
   *  Sum: '<S7>/Add2'
   */
  tmp = (dsPIC33CK256MP508_SMO_LVMC_B.ADCdsPICHighSpeedSAR_o1 -
         dsPIC33CK256MP508_SMO_LVMC_B.Iab[0]) * -23995L;
  tmp = (((tmp < 0L ? MAX_uint16_T : 0U) + tmp) >> 16) * 2795L;
  rtb_ToPerUnit_idx_0 = (int16_T)(((tmp < 0L ? 2047 : 0) + tmp) >> 11);
  tmp = (dsPIC33CK256MP508_SMO_LVMC_B.ADCdsPICHighSpeedSAR_o2 -
         dsPIC33CK256MP508_SMO_LVMC_B.Iab[1]) * -23995L;
  tmp = (((tmp < 0L ? MAX_uint16_T : 0U) + tmp) >> 16) * 2795L;
  rtb_ToPerUnit_idx_1 = (int16_T)(((tmp < 0L ? 2047 : 0) + tmp) >> 11);

  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* AlgorithmDescriptorDelegate generated from: '<S11>/a16' incorporates:
   *  Gain: '<S11>/one_by_sqrt3'
   *  Sum: '<S11>/a_plus_2b'
   */
  rtb_ToPerUnit_idx_1 = (int16_T)((((rtb_ToPerUnit_idx_0 + rtb_ToPerUnit_idx_1)
    + rtb_ToPerUnit_idx_1) * 18919L) >> 15);

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */

  /* Gain: '<S155>/Gain' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Gain: '<S155>/Inverting OpAmp5'
   */
  rtb_Integrator_i = (int16_T)((((181L * dsPIC33CK256MP508_SMO_LVMC_DW.SpeedRef)
    >> 8) * 17157L) >> 14);

  /* Abs: '<S149>/Abs' incorporates:
   *  DiscreteIntegrator: '<S58>/Integrator'
   */
  if (rtb_Integrator_i < 0) {
    rtb_Integrator_i = -rtb_Integrator_i;
  }

  /* End of Abs: '<S149>/Abs' */

  /* Delay: '<S149>/Delay2' incorporates:
   *  Sum: '<S149>/Sum4'
   */
  rtb_Sum4_j_idx_0 = dsPIC33CK256MP508_SMO_LVMC_DW.Delay2_DSTATE[0];
  rtb_Sum4_j_idx_1 = dsPIC33CK256MP508_SMO_LVMC_DW.Delay2_DSTATE[1];

  /* Sum: '<S149>/Sum' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S149>/Gain7'
   *  Gain: '<S155>/Inverting OpAmp1'
   *  Gain: '<S155>/Inverting OpAmp2'
   *  Sum: '<S149>/Sum4'
   */
  rtb_Gain7_e_idx_0 = rtb_Sum4_j_idx_0 - (int16_T)((11187L *
    dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_h[0]) >> 12);
  rtb_Gain7_e_idx_1 = rtb_Sum4_j_idx_1 - (int16_T)((11187L *
    dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_h[1]) >> 12);

  /* Abs: '<S156>/Abs1' incorporates:
   *  Gain: '<S149>/Gain7'
   */
  if (rtb_Gain7_e_idx_0 < 0) {
    DiscreteTimeIntegrator2_idx_0 = -rtb_Gain7_e_idx_0;
  } else {
    DiscreteTimeIntegrator2_idx_0 = rtb_Gain7_e_idx_0;
  }

  /* Switch: '<S156>/Switch1' incorporates:
   *  Abs: '<S156>/Abs1'
   *  Gain: '<S149>/Gain7'
   *  Gain: '<S156>/Gain4'
   *  Gain: '<S156>/Gain7'
   *  RelationalOperator: '<S159>/Compare'
   */
  if (DiscreteTimeIntegrator2_idx_0 >= 2110) {
    /* Signum: '<S156>/Sign1' incorporates:
     *  Abs: '<S156>/Abs1'
     *  Gain: '<S149>/Gain7'
     */
    if (rtb_Gain7_e_idx_0 < 0) {
      rtb_Gain7_e_idx_0 = -1;
    } else {
      rtb_Gain7_e_idx_0 = (rtb_Gain7_e_idx_0 > 0);
    }

    rtb_Switch1 = (31867 * rtb_Gain7_e_idx_0) >> 4;
  } else {
    rtb_Switch1 = (int16_T)((15465L * rtb_Gain7_e_idx_0) >> 14);
  }

  /* DiscreteIntegrator: '<S154>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S154>/Delay'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Product: '<S154>/Product'
   *  Sum: '<S154>/Sum2'
   */
  DiscreteTimeIntegrator = (int16_T)mul_s32_hiSR(439804651L, ((int32_T)
    (rtb_Switch1 - dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_i[0]) *
    rtb_Integrator_i) >> 3, 11UL) +
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* DiscreteIntegrator: '<S154>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S154>/Delay3'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Product: '<S154>/Product2'
   *  Sum: '<S154>/Sum3'
   */
  DiscreteTimeIntegrator2_idx_0 = (int16_T)mul_s32_hiSR(439804651L, ((int32_T)
    (DiscreteTimeIntegrator - dsPIC33CK256MP508_SMO_LVMC_DW.Delay3_DSTATE[0]) *
    rtb_Integrator_i) >> 3, 11UL) +
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator2_DSTATE[0];

  /* Switch: '<S156>/Switch1' */
  rtb_Switch1_j_idx_0 = rtb_Switch1;

  /* DiscreteIntegrator: '<S154>/Discrete-Time Integrator' */
  DiscreteTimeIntegrator_idx_0 = DiscreteTimeIntegrator;

  /* Abs: '<S156>/Abs1' incorporates:
   *  Gain: '<S149>/Gain7'
   */
  if (rtb_Gain7_e_idx_1 < 0) {
    rtb_Switch1 = -rtb_Gain7_e_idx_1;
  } else {
    rtb_Switch1 = rtb_Gain7_e_idx_1;
  }

  /* Switch: '<S156>/Switch1' incorporates:
   *  Abs: '<S156>/Abs1'
   *  Gain: '<S149>/Gain7'
   *  Gain: '<S156>/Gain4'
   *  Gain: '<S156>/Gain7'
   *  RelationalOperator: '<S159>/Compare'
   */
  if (rtb_Switch1 >= 2110) {
    /* Signum: '<S156>/Sign1' incorporates:
     *  Abs: '<S156>/Abs1'
     *  Gain: '<S149>/Gain7'
     */
    if (rtb_Gain7_e_idx_1 < 0) {
      rtb_Gain7_e_idx_1 = -1;
    } else {
      rtb_Gain7_e_idx_1 = (rtb_Gain7_e_idx_1 > 0);
    }

    rtb_Switch1 = (31867 * rtb_Gain7_e_idx_1) >> 4;
  } else {
    rtb_Switch1 = (int16_T)((15465L * rtb_Gain7_e_idx_1) >> 14);
  }

  /* DiscreteIntegrator: '<S154>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S154>/Delay'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Product: '<S154>/Product'
   *  Sum: '<S154>/Sum2'
   */
  DiscreteTimeIntegrator = (int16_T)mul_s32_hiSR(439804651L, ((int32_T)
    (rtb_Switch1 - dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_i[1]) *
    rtb_Integrator_i) >> 3, 11UL) +
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* DiscreteIntegrator: '<S154>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S154>/Delay3'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Product: '<S154>/Product2'
   *  Sum: '<S154>/Sum3'
   */
  DiscreteTimeIntegrator2_idx_1 = (int16_T)mul_s32_hiSR(439804651L, ((int32_T)
    (DiscreteTimeIntegrator - dsPIC33CK256MP508_SMO_LVMC_DW.Delay3_DSTATE[1]) *
    rtb_Integrator_i) >> 3, 11UL) +
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator2_DSTATE[1];

  /* Gain: '<S158>/Gain3' incorporates:
   *  Sum: '<S13>/sum_beta'
   */
  rtb_sum_beta = -DiscreteTimeIntegrator2_idx_0;

  /* Gain: '<S158>/Gain5' incorporates:
   *  Bias: '<S158>/Bias3'
   *  DataTypeConversion: '<S158>/Cast2'
   *  Sum: '<S13>/sum_beta'
   *  Trigonometry: '<S158>/Trigonometric Function1'
   */
  rtb_Gain5 = (int16_T)(((MCHP_MACRO_Atan2(rtb_sum_beta,
    DiscreteTimeIntegrator2_idx_1, 32768U, MAX_uint16_T) + 12975U) * 3217UL) >>
                        13);

  /* Sum: '<S157>/Sum2' incorporates:
   *  Gain: '<S158>/Gain5'
   *  UnitDelay: '<S157>/Unit Delay3'
   */
  DiscreteTimeIntegrator4 = rtb_Gain5 -
    dsPIC33CK256MP508_SMO_LVMC_DW.UnitDelay3_DSTATE;

  /* Bias: '<S160>/Bias' incorporates:
   *  Math: '<S160>/Math Function1'
   */
  DiscreteTimeIntegrator4 = (DiscreteTimeIntegrator4 - div_s16_floor
    (DiscreteTimeIntegrator4, 25736) * 25736) + 12868;

  /* DiscreteIntegrator: '<S157>/Discrete-Time Integrator4' incorporates:
   *  Bias: '<S160>/Bias1'
   *  Delay: '<S157>/Delay1'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Gain: '<S157>/Gain1'
   *  Gain: '<S157>/Gain2'
   *  Math: '<S160>/Math Function'
   *  Product: '<S157>/Product1'
   *  Sum: '<S157>/Sum4'
   */
  DiscreteTimeIntegrator4 = (int16_T)mul_s32_hiSR(439804651L, (((int16_T)
    ((((DiscreteTimeIntegrator4 - div_s16_floor(DiscreteTimeIntegrator4, 25736) *
        25736) + -12868) * 625L) >> 4) -
    dsPIC33CK256MP508_SMO_LVMC_DW.Delay1_DSTATE) * ((19661L * rtb_Integrator_i) >>
    16)) << 2, 16UL) +
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator4_DSTATE;

  /* Gain: '<S149>/Gain8' incorporates:
   *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator4'
   */
  dsPIC33CK256MP508_SMO_LVMC_B.Gain8 = (int16_T)((22129L *
    DiscreteTimeIntegrator4) >> 14);

  /* Chart: '<S148>/Chart' incorporates:
   *  DataStoreRead: '<S148>/Data Store Read5'
   *  Gain: '<S149>/Gain8'
   */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.temporalCounter_i1 < MAX_uint16_T) {
    dsPIC33CK256MP508_SMO_LVMC_DW.temporalCounter_i1++;
  }

  /* Gateway: Current Control/Position and Speed Estimation/OpentoClosed/Chart */
  /* During: Current Control/Position and Speed Estimation/OpentoClosed/Chart */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.is_active_c3_dsPIC33CK256MP508_SMO_LVMC ==
      0U) {
    /* Entry: Current Control/Position and Speed Estimation/OpentoClosed/Chart */
    dsPIC33CK256MP508_SMO_LVMC_DW.is_active_c3_dsPIC33CK256MP508_SMO_LVMC = 1U;

    /* Entry Internal: Current Control/Position and Speed Estimation/OpentoClosed/Chart */
    /* Transition: '<S153>:2' */
    dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
      dsPIC33CK256MP508_SMO_LVMC_IN_Init;

    /* Entry 'Init': '<S153>:1' */
  } else {
    switch (dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC) {
     case dsPIC33CK256MP508_SMO_LVMC_IN_Align:
      /* During 'Align': '<S153>:16' */
      if (!dsPIC33CK256MP508_SMO_LVMC_DW.Enable) {
        /* Transition: '<S153>:7' */
        dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
          dsPIC33CK256MP508_SMO_LVMC_IN_Init;

        /* Entry 'Init': '<S153>:1' */
      } else if (dsPIC33CK256MP508_SMO_LVMC_DW.temporalCounter_i1 >= 10000U) {
        /* Transition: '<S153>:17' */
        dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
          dsPIC33CK256MP508_SMO_LVMC_IN_OpenLoop;
        dsPIC33CK256MP508_SMO_LVMC_DW.temporalCounter_i1 = 0U;

        /* Entry 'OpenLoop': '<S153>:3' */
      } else {
        dsPIC33CK256MP508_SMO_LVMC_B.Mode = 0U;
      }
      break;

     case dsPIC33CK256MP508_SMO_LVMC_IN_ClosedLoop:
      /* During 'ClosedLoop': '<S153>:4' */
      if (!dsPIC33CK256MP508_SMO_LVMC_DW.Enable) {
        /* Transition: '<S153>:8' */
        dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
          dsPIC33CK256MP508_SMO_LVMC_IN_Init;

        /* Entry 'Init': '<S153>:1' */
      } else if (dsPIC33CK256MP508_SMO_LVMC_DW.temporalCounter_i1 >= 2000U) {
        /* Transition: '<S153>:22' */
        dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
          dsPIC33CK256MP508_SMO_LVMC_IN_ClosedLoopFilter;

        /* Entry 'ClosedLoopFilter': '<S153>:21' */
      } else {
        dsPIC33CK256MP508_SMO_LVMC_B.Mode = 2U;
      }
      break;

     case dsPIC33CK256MP508_SMO_LVMC_IN_ClosedLoopFilter:
      /* During 'ClosedLoopFilter': '<S153>:21' */
      if (!dsPIC33CK256MP508_SMO_LVMC_DW.Enable) {
        /* Transition: '<S153>:23' */
        dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
          dsPIC33CK256MP508_SMO_LVMC_IN_Init;

        /* Entry 'Init': '<S153>:1' */
      } else {
        dsPIC33CK256MP508_SMO_LVMC_B.Mode = 2U;
      }
      break;

     case dsPIC33CK256MP508_SMO_LVMC_IN_Init:
      /* During 'Init': '<S153>:1' */
      if (dsPIC33CK256MP508_SMO_LVMC_DW.Enable) {
        /* Transition: '<S153>:6' */
        dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
          dsPIC33CK256MP508_SMO_LVMC_IN_Align;
        dsPIC33CK256MP508_SMO_LVMC_DW.temporalCounter_i1 = 0U;

        /* Entry 'Align': '<S153>:16' */
      } else {
        dsPIC33CK256MP508_SMO_LVMC_B.Mode = 0U;
      }
      break;

     default:
      /* During 'OpenLoop': '<S153>:3' */
      if ((dsPIC33CK256MP508_SMO_LVMC_DW.temporalCounter_i1 >= 40000U) &&
          (dsPIC33CK256MP508_SMO_LVMC_B.Gain8 > 2829)) {
        /* Transition: '<S153>:9' */
        dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
          dsPIC33CK256MP508_SMO_LVMC_IN_ClosedLoop;
        dsPIC33CK256MP508_SMO_LVMC_DW.temporalCounter_i1 = 0U;

        /* Entry 'ClosedLoop': '<S153>:4' */
      } else if (!dsPIC33CK256MP508_SMO_LVMC_DW.Enable) {
        /* Transition: '<S153>:20' */
        dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
          dsPIC33CK256MP508_SMO_LVMC_IN_Init;

        /* Entry 'Init': '<S153>:1' */
      } else {
        dsPIC33CK256MP508_SMO_LVMC_B.Mode = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S148>/Chart' */

  /* DataTypeConversion: '<S148>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<S148>/Data Store Write2'
   *  Switch: '<S148>/Switch2'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.EnableClosedLoop =
    (dsPIC33CK256MP508_SMO_LVMC_B.Mode > 1U);

  /* Outputs for Resettable SubSystem: '<S9>/Openloop Pos_PU' incorporates:
   *  ResetPort: '<S147>/Reset'
   */
  /* DataStoreRead: '<S9>/Data Store Read2' */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.Enable &&
      (dsPIC33CK256MP508_SMO_LVMC_PrevZCX.OpenloopPos_PU_Reset_ZCE != POS_ZCSIG))
  {
    /* InitializeConditions for DiscreteIntegrator: '<S147>/Discrete-Time Integrator' */
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE = 0L;

    /* InitializeConditions for UnitDelay: '<S151>/Uni Delay' */
    dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay_DSTATE = 0;

    /* InitializeConditions for UnitDelay: '<S151>/Uni Delay1' */
    dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay1_DSTATE = true;

    /* InitializeConditions for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' */
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_IC_LOADING = 1U;
  }

  dsPIC33CK256MP508_SMO_LVMC_PrevZCX.OpenloopPos_PU_Reset_ZCE =
    dsPIC33CK256MP508_SMO_LVMC_DW.Enable;

  /* End of DataStoreRead: '<S9>/Data Store Read2' */

  /* Gain: '<S147>/Gain' incorporates:
   *  DiscreteIntegrator: '<S147>/Discrete-Time Integrator'
   *  Product: '<S106>/IProd Out'
   */
  rtb_IProdOut = (int16_T)mul_s32_loSR(12653L,
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE, 26UL);

  /* Gain: '<S152>/scale' incorporates:
   *  DeadZone: '<S102>/DeadZone'
   *  Product: '<S106>/IProd Out'
   */
  rtb_Integrator_i = rtb_IProdOut;

  /* Abs: '<S150>/Abs' incorporates:
   *  Gain: '<S152>/scale'
   *  Product: '<S106>/IProd Out'
   */
  if (rtb_IProdOut < 0) {
    rtb_Integrator_i = -rtb_IProdOut;
  }

  /* End of Abs: '<S150>/Abs' */

  /* DiscreteIntegrator: '<S150>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S151>/PhaseOffset'
   *  Switch: '<S151>/Switch'
   */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_IC_LOADING != 0) {
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 0;
    if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l >= 16384)
    {
      dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 16384;
    } else if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l <=
               0) {
      dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 0;
    }
  }

  /* Abs: '<S151>/Abs' incorporates:
   *  UnitDelay: '<S151>/Uni Delay'
   */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay_DSTATE < 0) {
    rtb_Sum4_f = -dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay_DSTATE;
  } else {
    rtb_Sum4_f = dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay_DSTATE;
  }

  /* End of Abs: '<S151>/Abs' */

  /* DiscreteIntegrator: '<S150>/Discrete-Time Integrator' incorporates:
   *  Abs: '<S150>/Abs'
   *  Constant: '<S150>/Frequency1'
   *  Constant: '<S151>/PhaseOffset'
   *  Gain: '<S151>/gain'
   *  Logic: '<S151>/Logical Operator'
   *  RelationalOperator: '<S151>/Relatioal Operator'
   *  Sum: '<S151>/Add2'
   *  Switch: '<S151>/Switch'
   *  UnitDelay: '<S151>/Uni Delay1'
   */
  if ((rtb_Sum4_f > 16384 - (int16_T)((3L * rtb_Integrator_i) >> 1)) ||
      dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay1_DSTATE) {
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 0;
    if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l >= 16384)
    {
      dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 16384;
    } else if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l <=
               0) {
      dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 0;
    }
  }

  if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l >= 16384) {
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 16384;
  } else if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l <= 0)
  {
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 0;
  }

  /* Switch: '<S150>/Direction' incorporates:
   *  Constant: '<S150>/ '
   *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator'
   *  Product: '<S106>/IProd Out'
   *  Sum: '<S150>/Sum2'
   */
  if (rtb_IProdOut > 0) {
    rtb_IProdOut = dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l;
  } else {
    rtb_IProdOut = 16384 -
      dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l;
  }

  /* End of Switch: '<S150>/Direction' */

  /* Update for DiscreteIntegrator: '<S147>/Discrete-Time Integrator' incorporates:
   *  DataTypeConversion: '<S147>/Data Type Conversion'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE += 5L;
  if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE >= 181039L) {
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE = 181039L;
  } else if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE <= 0L)
  {
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE = 0L;
  }

  /* End of Update for DiscreteIntegrator: '<S147>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S151>/Uni Delay' incorporates:
   *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay_DSTATE =
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l;

  /* Update for UnitDelay: '<S151>/Uni Delay1' */
  dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay1_DSTATE = false;

  /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' incorporates:
   *  Abs: '<S150>/Abs'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_IC_LOADING = 0U;
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l +=
    rtb_Integrator_i;
  if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l >= 16384) {
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 16384;
  } else if (dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l <= 0)
  {
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_l = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' */
  /* End of Outputs for SubSystem: '<S9>/Openloop Pos_PU' */

  /* Switch: '<S9>/Switch' incorporates:
   *  DataStoreWrite: '<S148>/Data Store Write2'
   *  Gain: '<S149>/Gain9'
   *  Gain: '<S150>/scale'
   *  Gain: '<S158>/Gain5'
   *  Product: '<S106>/IProd Out'
   *  Sum: '<S13>/sum_beta'
   */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.EnableClosedLoop) {
    rtb_sum_beta = (int16_T)((20861L * rtb_Gain5) >> 15);
  } else {
    /* Outputs for Resettable SubSystem: '<S9>/Openloop Pos_PU' incorporates:
     *  ResetPort: '<S147>/Reset'
     */
    rtb_sum_beta = rtb_IProdOut;

    /* End of Outputs for SubSystem: '<S9>/Openloop Pos_PU' */
  }

  /* End of Switch: '<S9>/Switch' */

  /* Outputs for IfAction SubSystem: '<S129>/If Action Subsystem' incorporates:
   *  ActionPort: '<S131>/Action Port'
   */
  /* If: '<S129>/If' incorporates:
   *  DataTypeConversion: '<S131>/Convert_back'
   *  DataTypeConversion: '<S131>/Convert_uint16'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Gain: '<S129>/convert_pu'
   *  Gain: '<S15>/indexing'
   *  Sum: '<S131>/Sum'
   *  Sum: '<S13>/sum_beta'
   */
  rtb_Integrator_i = (int16_T)(((rtb_sum_beta - ((rtb_sum_beta >> 14) << 14)) *
    25L) >> 4);

  /* End of Outputs for SubSystem: '<S129>/If Action Subsystem' */

  /* DataTypeConversion: '<S15>/Get_Integer' incorporates:
   *  DiscreteIntegrator: '<S58>/Integrator'
   */
  rtb_DataTypeConversion = (uint16_T)(rtb_Integrator_i >> 5);

  /* DataTypeConversion: '<S15>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Sum: '<S15>/Sum2'
   */
  rtb_Integrator_i = (rtb_Integrator_i - ((int16_T)rtb_DataTypeConversion << 5))
    << 9;

  /* Selector: '<S15>/Lookup' incorporates:
   *  Constant: '<S15>/sine_table_values'
   *  Sum: '<S128>/Sum3'
   *  Sum: '<S15>/Sum'
   */
  rtb_IProdOut = dsPIC33CK256MP508_SMO_LVMC_ConstP.sine_table_values_Value
    [(int16_T)rtb_DataTypeConversion];

  /* Sum: '<S128>/Sum4' incorporates:
   *  Constant: '<S15>/offset'
   *  Constant: '<S15>/sine_table_values'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Product: '<S128>/Product'
   *  Selector: '<S15>/Lookup'
   *  Sum: '<S128>/Sum3'
   *  Sum: '<S15>/Sum'
   */
  rtb_Sum4_f = (int16_T)(((int32_T)
    (dsPIC33CK256MP508_SMO_LVMC_ConstP.sine_table_values_Value[(int16_T)
     (rtb_DataTypeConversion + 1UL)] - rtb_IProdOut) * rtb_Integrator_i) >> 14)
    + rtb_IProdOut;

  /* Selector: '<S15>/Lookup' incorporates:
   *  Constant: '<S15>/offset'
   *  Constant: '<S15>/sine_table_values'
   *  Sum: '<S128>/Sum5'
   *  Sum: '<S15>/Sum'
   */
  rtb_IProdOut = dsPIC33CK256MP508_SMO_LVMC_ConstP.sine_table_values_Value
    [(int16_T)(rtb_DataTypeConversion + 200UL)];

  /* Sum: '<S128>/Sum6' incorporates:
   *  Constant: '<S15>/offset'
   *  Constant: '<S15>/sine_table_values'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Product: '<S128>/Product1'
   *  Selector: '<S15>/Lookup'
   *  Sum: '<S128>/Sum5'
   *  Sum: '<S15>/Sum'
   */
  rtb_Gain7_e_idx_1 = (int16_T)(((int32_T)
    (dsPIC33CK256MP508_SMO_LVMC_ConstP.sine_table_values_Value[(int16_T)
     (rtb_DataTypeConversion + 201UL)] - rtb_IProdOut) * rtb_Integrator_i) >> 14)
    + rtb_IProdOut;

  /* Outputs for Atomic SubSystem: '<S5>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Sum: '<S18>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
   *  Product: '<S14>/acos'
   *  Product: '<S14>/bsin'
   *  Sum: '<S128>/Sum4'
   *  Sum: '<S128>/Sum6'
   *  Sum: '<S14>/sum_Ds'
   */
  rtb_Sum = (rtb_RateTransition5[0] - (int16_T)(((int32_T)rtb_ToPerUnit_idx_0 *
    rtb_Gain7_e_idx_1) >> 14)) - (int16_T)(((int32_T)rtb_ToPerUnit_idx_1 *
    rtb_Sum4_f) >> 14);

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S5>/Park Transform' */

  /* Logic: '<S18>/Logical Operator' incorporates:
   *  DataStoreRead: '<S18>/Data Store Read'
   *  DataStoreRead: '<S18>/Data Store Read1'
   *  Logic: '<S18>/AND'
   *  Logic: '<S19>/AND'
   *  Logic: '<S19>/Logical Operator'
   */
  rtb_LogicalOperator_o_tmp = ((!dsPIC33CK256MP508_SMO_LVMC_DW.EnableFOC) ||
    (!dsPIC33CK256MP508_SMO_LVMC_DW.Enable));

  /* DiscreteIntegrator: '<S58>/Integrator' incorporates:
   *  Constant: '<S18>/Ki1'
   *  Logic: '<S18>/AND'
   *  Logic: '<S18>/Logical Operator'
   */
  if (rtb_LogicalOperator_o_tmp ||
      (dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_PrevResetState != 0)) {
    dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE = 0;
  }

  /* Sum: '<S67>/Sum' incorporates:
   *  DeadZone: '<S51>/DeadZone'
   *  DiscreteIntegrator: '<S58>/Integrator'
   *  Product: '<S63>/PProd Out'
   *  Sum: '<S18>/Sum'
   */
  rtb_DeadZone = (int16_T)((rtb_Sum * 2317L) >> 10) +
    dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE;

  /* Saturate: '<S65>/Saturation' incorporates:
   *  DeadZone: '<S51>/DeadZone'
   */
  if (rtb_DeadZone > 16384) {
    rtb_Gain7_e_idx_0 = 16384;
  } else if (rtb_DeadZone < -16384) {
    rtb_Gain7_e_idx_0 = -16384;
  } else {
    rtb_Gain7_e_idx_0 = rtb_DeadZone;
  }

  /* End of Saturate: '<S65>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S5>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Sum: '<S19>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
   *  Product: '<S14>/asin'
   *  Product: '<S14>/bcos'
   *  Sum: '<S128>/Sum4'
   *  Sum: '<S128>/Sum6'
   *  Sum: '<S14>/sum_Qs'
   */
  rtb_sum_beta = (rtb_RateTransition5[1] - (int16_T)(((int32_T)
    rtb_ToPerUnit_idx_1 * rtb_Gain7_e_idx_1) >> 14)) + (int16_T)(((int32_T)
    rtb_ToPerUnit_idx_0 * rtb_Sum4_f) >> 14);

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S5>/Park Transform' */

  /* DiscreteIntegrator: '<S109>/Integrator' incorporates:
   *  Constant: '<S19>/Kp1'
   */
  if (rtb_LogicalOperator_o_tmp ||
      (dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_PrevResetState_a != 0)) {
    dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE_d = 0;
  }

  /* Sum: '<S118>/Sum' incorporates:
   *  DeadZone: '<S102>/DeadZone'
   *  DiscreteIntegrator: '<S109>/Integrator'
   *  Product: '<S114>/PProd Out'
   *  Sum: '<S19>/Sum'
   */
  rtb_Integrator_i = (int16_T)((rtb_sum_beta * 2317L) >> 10) +
    dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE_d;

  /* Saturate: '<S116>/Saturation' incorporates:
   *  DeadZone: '<S102>/DeadZone'
   */
  if (rtb_Integrator_i > 16384) {
    rtb_Saturation_g = 16384;
  } else if (rtb_Integrator_i < -16384) {
    rtb_Saturation_g = -16384;
  } else {
    rtb_Saturation_g = rtb_Integrator_i;
  }

  /* End of Saturate: '<S116>/Saturation' */

  /* Sum: '<S23>/Sum2' incorporates:
   *  Product: '<S106>/IProd Out'
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   *  Saturate: '<S116>/Saturation'
   *  Saturate: '<S65>/Saturation'
   */
  rtb_IProdOut = (int16_T)(((int32_T)rtb_Gain7_e_idx_0 * rtb_Gain7_e_idx_0) >>
    14) + (int16_T)(((int32_T)rtb_Saturation_g * rtb_Saturation_g) >> 14);

  /* Sqrt: '<S23>/Sqrt' incorporates:
   *  Product: '<S106>/IProd Out'
   */
  rtb_IProdOut = MCHP_MACRO_sqrt_Qxx(rtb_IProdOut, 1);

  /* If: '<S17>/If1' incorporates:
   *  RelationalOperator: '<S20>/Compare'
   *  Sqrt: '<S23>/Sqrt'
   */
  if (rtb_IProdOut >= 15565) {
    /* Outputs for IfAction SubSystem: '<S17>/Limiter' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    /* Gain: '<S22>/Gain' incorporates:
     *  Math: '<S22>/Math Function2'
     *
     * About '<S22>/Math Function2':
     *  Operator: reciprocal
     */
    rtb_IProdOut = (int16_T)(((int16_T)(268435456L / rtb_IProdOut) * 15565L) >>
      14);

    /* Product: '<S22>/Product2' incorporates:
     *  Gain: '<S22>/Gain'
     *  Merge: '<S17>/Merge'
     */
    rtb_RateTransition5[0] = (int16_T)(((int32_T)rtb_IProdOut *
      rtb_Gain7_e_idx_0) >> 14);
    rtb_RateTransition5[1] = (int16_T)(((int32_T)rtb_IProdOut * rtb_Saturation_g)
      >> 14);

    /* End of Outputs for SubSystem: '<S17>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* SignalConversion generated from: '<S21>/In1' incorporates:
     *  Merge: '<S17>/Merge'
     */
    rtb_RateTransition5[0] = rtb_Gain7_e_idx_0;
    rtb_RateTransition5[1] = rtb_Saturation_g;

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
  }

  /* End of If: '<S17>/If1' */

  /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
  /* Switch: '<S126>/Switch' incorporates:
   *  Gain: '<S149>/Gain7'
   *  Product: '<S13>/dcos'
   *  Product: '<S13>/dsin'
   *  Product: '<S13>/qcos'
   *  Product: '<S13>/qsin'
   *  Sum: '<S128>/Sum4'
   *  Sum: '<S128>/Sum6'
   *  Sum: '<S13>/sum_alpha'
   *  Sum: '<S13>/sum_beta'
   */
  rtb_Gain7_e_idx_0 = (int16_T)(((int32_T)rtb_RateTransition5[0] *
    rtb_Gain7_e_idx_1) >> 14) - (int16_T)(((int32_T)rtb_RateTransition5[1] *
    rtb_Sum4_f) >> 14);
  rtb_Gain7_e_idx_1 = (int16_T)(((int32_T)rtb_RateTransition5[1] *
    rtb_Gain7_e_idx_1) >> 14) + (int16_T)(((int32_T)rtb_RateTransition5[0] *
    rtb_Sum4_f) >> 14);

  /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */

  /* Switch: '<S8>/Enable motor control' incorporates:
   *  Constant: '<S8>/Constant2'
   *  DataStoreRead: '<S8>/Enable'
   */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.Enable) {
    /* Switch: '<S8>/Switch for Current offset calibration' incorporates:
     *  Constant: '<S8>/Constant2'
     *  DataStoreWrite: '<S141>/Data Store Write'
     *  Gain: '<S141>/Gain'
     *  Logic: '<S141>/AND'
     *  RelationalOperator: '<S145>/Compare'
     *  RelationalOperator: '<S146>/Compare'
     *  Switch: '<S8>/Switch for rotor alignment'
     */
    if (EnCurOffset) {
      rtb_DataTypeConversion = 0U;
      rtb_DeadtimeCompensation_idx_1 = 0U;
      rtb_DeadtimeCompensation_idx_2 = 0U;
    } else if ((rtb_Gain_d > 4096) && (rtb_Gain_d < 8192)) {
      /* Switch: '<S8>/Switch for rotor alignment' incorporates:
       *  Constant: '<S8>/Constant3'
       *  Constant: '<S8>/Constant4'
       */
      rtb_DataTypeConversion = 2128U;
      rtb_DeadtimeCompensation_idx_1 = 1371U;
      rtb_DeadtimeCompensation_idx_2 = 1371U;
    } else {
      /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
      /* Gain: '<S138>/sqrt3_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
       *  MinMax: '<S136>/Max'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_IProdOut = (int16_T)((14189L * rtb_Gain7_e_idx_1) >> 14);

      /* Gain: '<S138>/one_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
       *  Gain: '<S136>/one_by_two'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Gain_d = rtb_Gain7_e_idx_0 >> 1;

      /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */

      /* Sum: '<S138>/add_c' incorporates:
       *  Gain: '<S136>/one_by_two'
       *  MinMax: '<S136>/Max'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Sum4_f = -rtb_Gain_d - rtb_IProdOut;

      /* Sum: '<S138>/add_b' incorporates:
       *  Gain: '<S136>/one_by_two'
       *  MinMax: '<S136>/Max'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_IProdOut -= rtb_Gain_d;

      /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
      /* MinMax: '<S136>/Min' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
       *  Sum: '<S138>/add_b'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      if (rtb_Gain7_e_idx_0 <= rtb_IProdOut) {
        rtb_Gain_d = rtb_Gain7_e_idx_0;
      } else {
        rtb_Gain_d = rtb_IProdOut;
      }

      /* MinMax: '<S136>/Max' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
       *  Sum: '<S138>/add_b'
       *  Sum: '<S138>/add_c'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      if (rtb_Gain7_e_idx_0 >= rtb_IProdOut) {
        rtb_Saturation_g = rtb_Gain7_e_idx_0;
      } else {
        rtb_Saturation_g = rtb_IProdOut;
      }

      /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */
      if (rtb_Saturation_g < rtb_Sum4_f) {
        rtb_Saturation_g = rtb_Sum4_f;
      }

      /* End of MinMax: '<S136>/Max' */

      /* MinMax: '<S136>/Min' incorporates:
       *  Sum: '<S138>/add_c'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      if (rtb_Gain_d > rtb_Sum4_f) {
        rtb_Gain_d = rtb_Sum4_f;
      }

      /* Gain: '<S136>/one_by_two' incorporates:
       *  Sum: '<S136>/Add'
       *  Switch: '<S8>/Switch for rotor alignment'
       */
      rtb_Gain_d = (int16_T)(-(int32_T)(rtb_Saturation_g + rtb_Gain_d) >> 1);

      /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
      /* Switch: '<S8>/Switch for rotor alignment' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
       *  Constant: '<S8>/Constant'
       *  Gain: '<S135>/Gain'
       *  Gain: '<S136>/one_by_two'
       *  Gain: '<S8>/One_by_Two'
       *  Gain: '<S8>/Scale_to_PWM_Counter_PRD'
       *  Sum: '<S135>/Add1'
       *  Sum: '<S135>/Add2'
       *  Sum: '<S135>/Add3'
       *  Sum: '<S138>/add_b'
       *  Sum: '<S138>/add_c'
       *  Sum: '<S8>/Sum'
       */
      rtb_DataTypeConversion = (uint16_T)(((((int16_T)(((rtb_Gain7_e_idx_0 +
        rtb_Gain_d) * 18919L) >> 14) >> 1) + 8192) * 5001L) >> 14);

      /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */
      rtb_DeadtimeCompensation_idx_1 = (uint16_T)(((((int16_T)(((rtb_IProdOut +
        rtb_Gain_d) * 18919L) >> 14) >> 1) + 8192) * 5001L) >> 14);
      rtb_DeadtimeCompensation_idx_2 = (uint16_T)(((((int16_T)(((rtb_Gain_d +
        rtb_Sum4_f) * 18919L) >> 14) >> 1) + 8192) * 5001L) >> 14);
    }

    /* End of Switch: '<S8>/Switch for Current offset calibration' */
  } else {
    rtb_DataTypeConversion = 0U;
    rtb_DeadtimeCompensation_idx_1 = 0U;
    rtb_DeadtimeCompensation_idx_2 = 0U;
  }

  /* End of Switch: '<S8>/Enable motor control' */

  /* DiscreteIntegrator: '<S149>/Discrete-Time Integrator3' incorporates:
   *  Delay: '<S1>/Delay'
   *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator'
   *  Gain: '<S149>/Gain4'
   *  Gain: '<S149>/Gain7'
   *  Gain: '<S155>/Inverting OpAmp3'
   *  Gain: '<S155>/Inverting OpAmp4'
   *  Sum: '<S149>/Sum4'
   *  Switch: '<S156>/Switch1'
   */
  rtb_RateTransition5[0] = (int16_T)mul_s32_hiSR(439804651L, ((((((int16_T)
    ((14189L * dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_h[2]) >> 13) >> 1) -
    ((int16_T)((9339L * rtb_Sum4_j_idx_0) >> 15) >> 1)) - (rtb_Switch1_j_idx_0 <<
    2)) - (DiscreteTimeIntegrator_idx_0 << 2)) * 11111L) >> 1, 11UL) +
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator3_DSTATE[0];
  rtb_RateTransition5[1] = (int16_T)mul_s32_hiSR(439804651L, ((((((int16_T)
    ((14189L * dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_h[3]) >> 13) >> 1) -
    ((int16_T)((9339L * rtb_Sum4_j_idx_1) >> 15) >> 1)) - (rtb_Switch1 << 2)) -
    (DiscreteTimeIntegrator << 2)) * 11111L) >> 1, 11UL) +
    dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator3_DSTATE[1];

  /* Saturate: '<S6>/Saturation low side turn  on' incorporates:
   *  Bias: '<S6>/Dead time Compensation'
   */
  if (rtb_DataTypeConversion + 100U > 5000U) {
    /* Saturate: '<S6>/Saturation low side turn  on' */
    dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[0] = 5000U;
  } else if (rtb_DataTypeConversion + 100U < 200U) {
    /* Saturate: '<S6>/Saturation low side turn  on' */
    dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[0] = 200U;
  } else {
    /* Saturate: '<S6>/Saturation low side turn  on' */
    dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[0] =
      rtb_DataTypeConversion + 100U;
  }

  if (rtb_DeadtimeCompensation_idx_1 + 100U > 5000U) {
    /* Saturate: '<S6>/Saturation low side turn  on' */
    dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[1] = 5000U;
  } else if (rtb_DeadtimeCompensation_idx_1 + 100U < 200U) {
    /* Saturate: '<S6>/Saturation low side turn  on' */
    dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[1] = 200U;
  } else {
    /* Saturate: '<S6>/Saturation low side turn  on' */
    dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[1] =
      rtb_DeadtimeCompensation_idx_1 + 100U;
  }

  if (rtb_DeadtimeCompensation_idx_2 + 100U > 5000U) {
    /* Saturate: '<S6>/Saturation low side turn  on' */
    dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[2] = 5000U;
  } else if (rtb_DeadtimeCompensation_idx_2 + 100U < 200U) {
    /* Saturate: '<S6>/Saturation low side turn  on' */
    dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[2] = 200U;
  } else {
    /* Saturate: '<S6>/Saturation low side turn  on' */
    dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[2] =
      rtb_DeadtimeCompensation_idx_2 + 100U;
  }

  /* End of Saturate: '<S6>/Saturation low side turn  on' */

  /* S-Function (MCHP_PWM_HS_FEP): '<S6>/PWM_HS_FEP' */
  /* Update PWM Duty Cycle */
  PG4DC = dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[2];/* Update PWM4 Duty Cycle */
  PG2DC = dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[1];/* Update PWM2 Duty Cycle */
  PG1DC = dsPIC33CK256MP508_SMO_LVMC_B.Saturationlowsideturnon[0];/* Update PWM1 Duty Cycle */
  PG1STATbits.UPDREQ = 1;              /* synchronized UPDATE */

  /* DeadZone: '<S51>/DeadZone' */
  if (rtb_DeadZone > 16384) {
    rtb_DeadZone -= 16384;
  } else if (rtb_DeadZone >= -16384) {
    rtb_DeadZone = 0;
  } else {
    rtb_DeadZone -= -16384;
  }

  /* End of DeadZone: '<S51>/DeadZone' */

  /* Product: '<S55>/IProd Out' incorporates:
   *  Constant: '<S18>/Ki'
   *  Product: '<S106>/IProd Out'
   *  Sum: '<S18>/Sum'
   */
  rtb_IProdOut = (int16_T)((rtb_Sum * 1869L) >> 14);

  /* Switch: '<S49>/Switch1' incorporates:
   *  Constant: '<S49>/Constant'
   *  Constant: '<S49>/Constant2'
   *  DeadZone: '<S51>/DeadZone'
   *  RelationalOperator: '<S49>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0) {
    rtb_DeadZone_0 = 1;
  } else {
    rtb_DeadZone_0 = -1;
  }

  /* End of Switch: '<S49>/Switch1' */

  /* Switch: '<S49>/Switch2' incorporates:
   *  Constant: '<S49>/Constant3'
   *  Constant: '<S49>/Constant4'
   *  Product: '<S106>/IProd Out'
   *  RelationalOperator: '<S49>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0) {
    rtb_IProdOut_i = 1;
  } else {
    rtb_IProdOut_i = -1;
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Constant1'
   *  DeadZone: '<S51>/DeadZone'
   *  Logic: '<S49>/AND3'
   *  Product: '<S106>/IProd Out'
   *  RelationalOperator: '<S49>/Equal1'
   *  RelationalOperator: '<S49>/Relational Operator'
   */
  if ((rtb_DeadZone != 0) && (rtb_DeadZone_0 == rtb_IProdOut_i)) {
    rtb_Gain_d = 0;
  } else {
    rtb_Gain_d = rtb_IProdOut;
  }

  /* End of Switch: '<S49>/Switch' */

  /* DeadZone: '<S102>/DeadZone' */
  if (rtb_Integrator_i > 16384) {
    rtb_Integrator_i -= 16384;
  } else if (rtb_Integrator_i >= -16384) {
    rtb_Integrator_i = 0;
  } else {
    rtb_Integrator_i -= -16384;
  }

  /* End of DeadZone: '<S102>/DeadZone' */

  /* Product: '<S106>/IProd Out' incorporates:
   *  Constant: '<S19>/Ki'
   *  Sum: '<S19>/Sum'
   */
  rtb_IProdOut = (int16_T)((rtb_sum_beta * 1869L) >> 14);

  /* DataStoreRead: '<S1>/Data Store Read' */
  dsPIC33CK256MP508_SMO_LVMC_B.Speed_Ref =
    dsPIC33CK256MP508_SMO_LVMC_DW.SpeedRef;

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  S-Function (MCHP_ADC_HighSpeed_SAR_dsPIC): '<S7>/ADC dsPIC High Speed SAR'
   */
  dsPIC33CK256MP508_SMO_LVMC_B.DataTypeConversion = (int16_T)
    (dsPIC33CK256MP508_SMO_LVMC_B.U2CH2 >> 2);

  /* Update for Delay: '<S140>/Delay' incorporates:
   *  DataStoreWrite: '<S141>/Data Store Write1'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_n =
    dsPIC33CK256MP508_SMO_LVMC_DW.EnableFOC;

  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Update for Delay: '<S1>/Delay' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
   *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
   *  SignalConversion generated from: '<S1>/Delay'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_h[0] = rtb_ToPerUnit_idx_0;

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_h[1] = rtb_ToPerUnit_idx_1;

  /* Outputs for Atomic SubSystem: '<S5>/Inverse Park Transform' */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_h[2] = rtb_Gain7_e_idx_0;
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_h[3] = rtb_Gain7_e_idx_1;

  /* End of Outputs for SubSystem: '<S5>/Inverse Park Transform' */

  /* Update for UnitDelay: '<S157>/Unit Delay3' incorporates:
   *  Gain: '<S158>/Gain5'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.UnitDelay3_DSTATE = rtb_Gain5;

  /* Update for Delay: '<S157>/Delay1' incorporates:
   *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator4'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay1_DSTATE = DiscreteTimeIntegrator4;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator4' */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator4_DSTATE =
    DiscreteTimeIntegrator4;

  /* Update for DiscreteIntegrator: '<S58>/Integrator' incorporates:
   *  Logic: '<S18>/AND'
   *  Logic: '<S18>/Logical Operator'
   *  Switch: '<S49>/Switch'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE += rtb_Gain_d;
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_PrevResetState = (int8_T)
    rtb_LogicalOperator_o_tmp;

  /* Switch: '<S100>/Switch1' incorporates:
   *  Constant: '<S100>/Constant'
   *  Constant: '<S100>/Constant2'
   *  DeadZone: '<S102>/DeadZone'
   *  RelationalOperator: '<S100>/fix for DT propagation issue'
   */
  if (rtb_Integrator_i > 0) {
    rtb_DeadZone_0 = 1;
  } else {
    rtb_DeadZone_0 = -1;
  }

  /* End of Switch: '<S100>/Switch1' */

  /* Switch: '<S100>/Switch2' incorporates:
   *  Constant: '<S100>/Constant3'
   *  Constant: '<S100>/Constant4'
   *  Product: '<S106>/IProd Out'
   *  RelationalOperator: '<S100>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0) {
    rtb_IProdOut_i = 1;
  } else {
    rtb_IProdOut_i = -1;
  }

  /* End of Switch: '<S100>/Switch2' */

  /* Switch: '<S100>/Switch' incorporates:
   *  Constant: '<S100>/Constant1'
   *  DeadZone: '<S102>/DeadZone'
   *  Logic: '<S100>/AND3'
   *  RelationalOperator: '<S100>/Equal1'
   *  RelationalOperator: '<S100>/Relational Operator'
   */
  if ((rtb_Integrator_i != 0) && (rtb_DeadZone_0 == rtb_IProdOut_i)) {
    rtb_IProdOut = 0;
  }

  /* End of Switch: '<S100>/Switch' */

  /* Update for DiscreteIntegrator: '<S109>/Integrator' incorporates:
   *  Logic: '<S18>/AND'
   *  Logic: '<S18>/Logical Operator'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE_d += rtb_IProdOut;
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_PrevResetState_a = (int8_T)
    rtb_LogicalOperator_o_tmp;

  /* Update for Delay: '<S149>/Delay2' incorporates:
   *  DiscreteIntegrator: '<S149>/Discrete-Time Integrator3'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay2_DSTATE[0] = rtb_RateTransition5[0];

  /* Update for Delay: '<S154>/Delay' incorporates:
   *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_i[0] = DiscreteTimeIntegrator_idx_0;

  /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S154>/Delay'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_e[0] =
    DiscreteTimeIntegrator_idx_0;

  /* Update for Delay: '<S154>/Delay3' incorporates:
   *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator2'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay3_DSTATE[0] = DiscreteTimeIntegrator2_idx_0;

  /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S154>/Delay3'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator2_DSTATE[0] =
    DiscreteTimeIntegrator2_idx_0;

  /* Update for DiscreteIntegrator: '<S149>/Discrete-Time Integrator3' incorporates:
   *  Delay: '<S149>/Delay2'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator3_DSTATE[0] =
    rtb_RateTransition5[0];

  /* Update for Delay: '<S149>/Delay2' incorporates:
   *  DiscreteIntegrator: '<S149>/Discrete-Time Integrator3'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay2_DSTATE[1] = rtb_RateTransition5[1];

  /* Update for Delay: '<S154>/Delay' */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE_i[1] = DiscreteTimeIntegrator;

  /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator' */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE_e[1] =
    DiscreteTimeIntegrator;

  /* Update for Delay: '<S154>/Delay3' incorporates:
   *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator2'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay3_DSTATE[1] = DiscreteTimeIntegrator2_idx_1;

  /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S154>/Delay3'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator2_DSTATE[1] =
    DiscreteTimeIntegrator2_idx_1;

  /* Update for DiscreteIntegrator: '<S149>/Discrete-Time Integrator3' incorporates:
   *  Delay: '<S149>/Delay2'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator3_DSTATE[1] =
    rtb_RateTransition5[1];
}

/* Model step function for TID1 */
void dsPIC33CK256MP508_SMO_LVMC_step1(void) /* Sample time: [0.0015s, 0.0s] */
{
  /* RateTransition: '<Root>/Rate Transition6' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  dsPIC33CK256MP508_SMO_LVMC_B.RateTransition6 =
    dsPIC33CK256MP508_SMO_LVMC_B.DataTypeConversion;

  /* RateTransition: '<Root>/Rate Transition7' incorporates:
   *  Gain: '<S149>/Gain8'
   */
  dsPIC33CK256MP508_SMO_LVMC_B.RateTransition7 =
    dsPIC33CK256MP508_SMO_LVMC_B.Gain8;

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  dsPIC33CK256MP508_SMO_LVMC_SpeedControl();

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* RateTransition: '<Root>/Rate Transition5' */
  dsPIC33CK256MP508_SMO_LVMC_DW.RateTransition5_Buffer
    [(dsPIC33CK256MP508_SMO_LVMC_DW.RateTransition5_ActiveBufIdx == 0) << 1] =
    dsPIC33CK256MP508_SMO_LVMC_B.Id_ref;
  dsPIC33CK256MP508_SMO_LVMC_DW.RateTransition5_Buffer[1 +
    ((dsPIC33CK256MP508_SMO_LVMC_DW.RateTransition5_ActiveBufIdx == 0) << 1)] =
    dsPIC33CK256MP508_SMO_LVMC_B.Switch;
  dsPIC33CK256MP508_SMO_LVMC_DW.RateTransition5_ActiveBufIdx = (int8_T)
    (dsPIC33CK256MP508_SMO_LVMC_DW.RateTransition5_ActiveBufIdx == 0);
}

/* Model step function for TID2 */
void dsPIC33CK256MP508_SMO_LVMC_step2(void) /* Sample time: [0.005s, 0.0s] */
{
  int16_T rtb_IndexVector;

  /* MultiPortSwitch: '<S10>/Index Vector' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read'
   *  Gain: '<S149>/Gain8'
   *  UnitDelay: '<S161>/Output'
   */
  if (dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE == 0) {
    rtb_IndexVector = dsPIC33CK256MP508_SMO_LVMC_B.Gain8;
  } else {
    rtb_IndexVector = dsPIC33CK256MP508_SMO_LVMC_B.Speed_Ref;
  }

  /* End of MultiPortSwitch: '<S10>/Index Vector' */

  /* SignalConversion generated from: '<S166>/UART Tx' incorporates:
   *  ArithShift: '<S165>/Shift Arithmetic2'
   *  Constant: '<S166>/End'
   *  Constant: '<S166>/Start'
   *  DataTypeConversion: '<S165>/Data Type Conversion1'
   *  DataTypeConversion: '<S165>/Data Type Conversion2'
   *  DataTypeConversion: '<S165>/Data Type Conversion3'
   *  MultiPortSwitch: '<S10>/Index Vector'
   *  S-Function (sfix_bitop): '<S165>/Bitwise Operator2'
   *  UnitDelay: '<S161>/Output'
   */
  dsPIC33CK256MP508_SMO_LVMC_B.TmpSignalConversionAtUARTTxInport1[0] = 83U;
  dsPIC33CK256MP508_SMO_LVMC_B.TmpSignalConversionAtUARTTxInport1[1] =
    dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE;
  dsPIC33CK256MP508_SMO_LVMC_B.TmpSignalConversionAtUARTTxInport1[2] = (uint8_T)
    (rtb_IndexVector & 255U);
  dsPIC33CK256MP508_SMO_LVMC_B.TmpSignalConversionAtUARTTxInport1[3] = (uint8_T)
    ((uint16_T)rtb_IndexVector >> 8);
  dsPIC33CK256MP508_SMO_LVMC_B.TmpSignalConversionAtUARTTxInport1[4] = 69U;

  /* S-Function (MCHP_UART_Tx): '<S166>/UART Tx' */
  /* MCHP_UART_Tx Block: <S166>/UART Tx/Outputs */
  {
    uint_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);/* head - tail - 1 */
    Tmp = Tmp & (Tx_BUFF_SIZE_UART1 - 1);
    /* Modulo Buffer Size (Buffer Size is 2^n). Tmp is the buffer free space */

    {
      uint_T i1 = 0;
      uint_T LocalTail = MCHP_UART1_Tx.tail;
      /* Tail is a volatile variable. Use local variable to speed-up execution */
      const uint8_T *u0 =
        &dsPIC33CK256MP508_SMO_LVMC_B.TmpSignalConversionAtUARTTxInport1[0] ;
      if (Tmp >= 5)         /* Does buffer can contains all char to be sent ? */
      {
        Tmp = 5 ;          /* If so, set tmp to the number of char to be sent */
      }
          /* Otherwise, send only the number of char which can be contained within the buffer (Tmp) */

      while (i1 < Tmp) {
        MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
        LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_UART1 - 1);
        i1= i1 + 1;
      }

      MCHP_UART1_Tx.tail = LocalTail;  /* Push back volatile variable */
    }

    {
      uint_T LocalHead;
      int cpu_ipl_switchVar;
      cpu_ipl_switchVar = 5 << 5;      /* new IPL (SR bits 5,6,7) */
      cpu_ipl_switchVar ^= SR;         /* bit to reverse */
      cpu_ipl_switchVar &= 0xE0;       /* mask to not change other SR bits */
      SR ^= cpu_ipl_switchVar;
              /* mimic Tx interrupt, disable Tx & thread switching interrupts */
      LocalHead = MCHP_UART1_Tx.head;
      /* Head is a volatile variable. Use local variable to speed-up execution */
      _U1TXIF = 0;                     /* Clear Interrupt Flag */
      while ((0U == U1STAHbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
      {
        U1TXREG = MCHP_UART1_Tx.buffer[LocalHead++];
        LocalHead &= (Tx_BUFF_SIZE_UART1-1);
      }

      MCHP_UART1_Tx.head = LocalHead;  /* Push back volatile variable */
      SR ^= cpu_ipl_switchVar;      /* stop mimic UART TX interrupt IPL level */
    }
  }

  /* Switch: '<S164>/FixPt Switch' incorporates:
   *  Constant: '<S163>/FixPt Constant'
   *  Sum: '<S163>/FixPt Sum1'
   *  UnitDelay: '<S161>/Output'
   */
  if ((uint8_T)(dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE + 1U) > 3) {
    /* Update for UnitDelay: '<S161>/Output' incorporates:
     *  Constant: '<S164>/Constant'
     */
    dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S161>/Output' */
    dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S164>/FixPt Switch' */
}

/* Model step function for TID3 */
void dsPIC33CK256MP508_SMO_LVMC_step3(void) /* Sample time: [0.1s, 0.0s] */
{
  boolean_T rtb_DataTypeConversion1_a;

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S169>/Output'
   */
  rtb_DataTypeConversion1_a = (dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE_p !=
    0);

  /* S-Function (MCHP_Digital_Output_Write): '<S171>/Digital Output Write' */
  LATEbits.LATE7 = rtb_DataTypeConversion1_a;

  /* Update for UnitDelay: '<S169>/Output' incorporates:
   *  Constant: '<S174>/FixPt Constant'
   *  Sum: '<S174>/FixPt Sum1'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE_p = (uint8_T)((uint8_T)
    (dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE_p + 1U) & 1);
}

/* Model step function for TID4 */
void dsPIC33CK256MP508_SMO_LVMC_step4(void) /* Sample time: [0.5s, 0.0s] */
{
  boolean_T rtb_DataTypeConversion;

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S168>/Output'
   */
  rtb_DataTypeConversion = (dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE_l != 0);

  /* S-Function (MCHP_Digital_Output_Write): '<S170>/Digital Output Write' */
  LATEbits.LATE6 = rtb_DataTypeConversion;

  /* Update for UnitDelay: '<S168>/Output' incorporates:
   *  Constant: '<S172>/FixPt Constant'
   *  Sum: '<S172>/FixPt Sum1'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE_l = (uint8_T)((uint8_T)
    (dsPIC33CK256MP508_SMO_LVMC_DW.Output_DSTATE_l + 1U) & 1);
}

/* Model initialize function */
void dsPIC33CK256MP508_SMO_LVMC_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (dsPIC33CK256MP508_SMO_LVMC_M)->Timing.TaskCounters.cLimit[0] = 1;
  (dsPIC33CK256MP508_SMO_LVMC_M)->Timing.TaskCounters.cLimit[1] = 30;
  (dsPIC33CK256MP508_SMO_LVMC_M)->Timing.TaskCounters.cLimit[2] = 100;
  (dsPIC33CK256MP508_SMO_LVMC_M)->Timing.TaskCounters.cLimit[3] = 2000;
  (dsPIC33CK256MP508_SMO_LVMC_M)->Timing.TaskCounters.cLimit[4] = 10000;

  /* initialize error status */
  rtmSetErrorStatus(dsPIC33CK256MP508_SMO_LVMC_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &dsPIC33CK256MP508_SMO_LVMC_B), 0,
                sizeof(B_dsPIC33CK256MP508_SMO_LVMC_T));

  /* states (dwork) */
  (void) memset((void *)&dsPIC33CK256MP508_SMO_LVMC_DW, 0,
                sizeof(DW_dsPIC33CK256MP508_SMO_LVMC_T));

  /* Start for S-Function (MCHP_ADC_HighSpeed_SAR_dsPIC): '<S7>/ADC dsPIC High Speed SAR' */

  /* ADC common settings */
  ADCON1Hbits.FORM = 1;                /* Fractional format */
  ADCON5Hbits.WARMTIME = 10;  /* Warm-up time, minimum is 10us (DS700005213F) */
  ADCON3Hbits.CLKSEL = 1;              /* Select input clock source */
  ADCON3Hbits.CLKDIV = 1;              /* clock pre scaler */
  ADCON3Lbits.REFSEL = 0;         /* Select AVdd and AVss as reference source */

  /* Configuration for ADC Core */
  ADCON4Hbits.C0CHS = 0;               /* Dedicated core - Input pins */
  ADCON4Hbits.C1CHS = 0;               /* Dedicated core - Input pins */
  ADCORE0L = 101;
  /* ADC Sample Time for dedicated ADC (SAMC field) (if SAMCEN not set-default => trig end sampling ) */
  ADCORE1L = 101;
  /* ADC Sample Time for dedicated ADC (SAMC field) (if SAMCEN not set-default => trig end sampling ) */
  ADCON2Hbits.SHRSAMC = 102;           /* ADC Sample Time for shared ADC7 */
  ADCON4Lbits.SAMC0EN = 1;
                  /* Trig start (or continue) sampling for a time set in SAMC */
  ADCON4Lbits.SAMC1EN = 1;
                  /* Trig start (or continue) sampling for a time set in SAMC */
  ADMOD0Lbits.SIGN0 = 1;             /* Signed (1) / Unsigned (0) data format */
  ADMOD0Lbits.SIGN1 = 1;             /* Signed (1) / Unsigned (0) data format */
  ADTRIG0Lbits.TRGSRC0 = 4;            /* CH0 Trigger source */
  ADTRIG0Lbits.TRGSRC1 = 4;            /* CH1 Trigger source */
  ADTRIG2Hbits.TRGSRC11 = 4;           /* CH11 Trigger source */
  ADLVLTRGLbits.LVLEN0 = 0;            /* Input trig is edge sensitive */
  ADLVLTRGLbits.LVLEN1 = 0;            /* Input trig is edge sensitive */
  ADLVLTRGLbits.LVLEN11 = 0;           /* Input trig is edge sensitive */
  ADCORE0Hbits.ADCS = 1;               /* ADC Clock Frequency for core 0 */
  ADCORE1Hbits.ADCS = 1;               /* ADC Clock Frequency for core 1 */
  ADCON2Lbits.SHRADCS = 1;             /* ADC Clock Frequency for shared ADC7 */
  ADCORE0Hbits.RES = 3;                /* ADC Resolution for core 0 */
  ADCORE1Hbits.RES = 3;                /* ADC Resolution for core 1 */
  ADCON1Hbits.SHRRES = 3;              /* ADC Resolution for shared ADC7 */
  ADIELbits.IE11 = 1;                  /* enable interrupt for ADC channel 11 */
  _ADCAN11IP = 2;                      /* Set Interrupt priority for tasking */
  _ADCAN11IF = 0;                      /* Reset pending interrupt */
  _ADCAN11IE = 1;      /* Enable Interrupt which trig the base rate time step */

  /* Turn on ADC module common to all ADC core */
  ADCON1Lbits.ADON = 1;

  /* Switch on dedicated ADC core 0 */
  ADCON5Lbits.C0PWR = 1;         /* Turn on Analog power for dedicated core 0 */
  while (ADCON5Lbits.C0RDY == 0) ;     /* Wait for core 0 ready */
  ADCON3Hbits.C0EN = 1;  /* Turn on Digital power enabling triggers to core 0 */

  /* Switch on dedicated ADC core 1 */
  ADCON5Lbits.C1PWR = 1;         /* Turn on Analog power for dedicated core 1 */
  while (ADCON5Lbits.C1RDY == 0) ;     /* Wait for core 1 ready */
  ADCON3Hbits.C1EN = 1;  /* Turn on Digital power enabling triggers to core 1 */

  /* Switch on shared ADC core */
  ADCON5Lbits.SHRPWR = 1;             /* Turn on Analog power for shared core */
  while (ADCON5Lbits.SHRRDY == 0) ;    /* Wait for shared core ready */
  ADCON3Hbits.SHREN = 1; /* Turn on Digital power enabling triggers to shared */

  /* Start for S-Function (MCHP_PWM_HS_FEP): '<S6>/PWM_HS_FEP' */

  /* Set initial Dead Time */
  PG1DTH = 200U;                       /* 1.0E-6s */
  PG2DTH = 200U;                       /* 1.0E-6s */
  PG4DTH = 200U;                       /* 1.0E-6s */
  PG1DTL = 200U;                       /* 1.0E-6s */
  PG2DTL = 200U;                       /* 1.0E-6s */
  PG4DTL = 200U;                       /* 1.0E-6s */

  /* Set initial PWM Period */
  PG4PER = 4999U;                      /* 5.0E-5s */
  PG2PER = 4999U;                      /* 5.0E-5s */
  PG1PER = 4999U;                      /* 5.0E-5s */

  /* Set initial PWM Duty Cycles */
  PG4DC = 200U;                        /* 2.0E-6s */
  PG2DC = 200U;                        /* 2.0E-6s */
  PG1DC = 200U;                        /* 2.0E-6s */

  /* Set Trigger (for ADC) initial values */
  PG1TRIGA = 0U;                       /* Trigger A (0.0s) for PWM 1 */

  /* Set PWM settings for each channels */
  {
    /* non volatile temp variable to precompute settings */
    PG1CONHBITS R_PG1CONH = { 0 };

    PG2CONHBITS R_PG2CONH = { 0 };

    PG4CONHBITS R_PG4CONH = { 0 };

    PG1CONLBITS R_PG1CONL = { 0 };

    PG2CONLBITS R_PG2CONL = { 0 };

    PG4CONLBITS R_PG4CONL = { 0 };

    PG1IOCONHBITS R_PG1IOCONH = { 0 };

    PG2IOCONHBITS R_PG2IOCONH = { 0 };

    PG4IOCONHBITS R_PG4IOCONH = { 0 };

    PG1EVTLBITS R_PG1EVTL = { 0 };

    /* PGxCONH */
    R_PG1CONH.SOCS = 0;                /* Start of Cycle is Local EOC */
    R_PG1CONH.MSTEN = 1;       /* Broadcast set of UPDREQ & EOC to other PWMs */
    R_PG1CONH.UPDMOD = 0;          /* PWM Update (00 next cycle, 01 Immedite) */
    PG1CONHbits = R_PG1CONH;           /* -- WRITE CONFIG -- */
    R_PG2CONH.SOCS = 1;  /* Start of Cycle sync with 1-4 => PG1 PG4 - PG5 PG8 */
    R_PG2CONH.UPDMOD = 2;     /* PWM Slave Update (2 next cycle, 3 immediate) */
    PG2CONHbits = R_PG2CONH;           /* -- WRITE CONFIG -- */
    R_PG4CONH.SOCS = 1;  /* Start of Cycle sync with 1-4 => PG1 PG4 - PG5 PG8 */
    R_PG4CONH.UPDMOD = 2;     /* PWM Slave Update (2 next cycle, 3 immediate) */
    PG4CONHbits = R_PG4CONH;           /* -- WRITE CONFIG -- */

    /* PGxCONL */
    R_PG1CONL.MODSEL = 4 ;             /* PWM mode */
    R_PG1CONL.CLKSEL = 1;              /* Clock Selection */
    R_PG1CONL.ON = 0;                  /* PWM Generator is disabled */
    PG1CONLbits = R_PG1CONL;           /* -- WRITE CONFIG -- */
    R_PG2CONL.MODSEL = 4 ;             /* PWM mode */
    R_PG2CONL.CLKSEL = 1;              /* Clock Selection */
    R_PG2CONL.ON = 1;                  /* PWM Generator is enabled */
    PG2CONLbits = R_PG2CONL;           /* -- WRITE CONFIG -- */
    R_PG4CONL.MODSEL = 4 ;             /* PWM mode */
    R_PG4CONL.CLKSEL = 1;              /* Clock Selection */
    R_PG4CONL.ON = 1;                  /* PWM Generator is enabled */
    PG4CONLbits = R_PG4CONL;           /* -- WRITE CONFIG -- */

    /* PGxIOCONH */
    R_PG1IOCONH.PENL = 1;              /* Enable PWMxL */
    R_PG1IOCONH.PENH = 1;              /* Enable PWMxH */
    PG1IOCONHbits = R_PG1IOCONH;       /* -- WRITE CONFIG -- */
    R_PG2IOCONH.PENL = 1;              /* Enable PWMxL */
    R_PG2IOCONH.PENH = 1;              /* Enable PWMxH */
    PG2IOCONHbits = R_PG2IOCONH;       /* -- WRITE CONFIG -- */
    R_PG4IOCONH.PENL = 1;              /* Enable PWMxL */
    R_PG4IOCONH.PENH = 1;              /* Enable PWMxH */
    PG4IOCONHbits = R_PG4IOCONH;       /* -- WRITE CONFIG -- */

    /* PGxEVTL */
    R_PG1EVTL.ADTR1EN1 = 1;         /* PWM1 TRIG A is trig src for ADC Trig 1 */
    PG1EVTLbits = R_PG1EVTL;           /* -- WRITE CONFIG -- */
  }

  {                                   /* Shared Settings for all PWM channels */
  }

  /* Start for S-Function (MCHP_OP_AMP): '<S2>/Op-Amp' */
  {                                    /* Configure Op-Amp */
    AMPCON1HBITS R_AMPCON1H = { 0 };

    AMPCON1LBITS R_AMPCON1L = { 0 };

    R_AMPCON1H.NCHDIS1 = 1;            /* Reduce Op-Amp 1 non linearity */
    R_AMPCON1H.NCHDIS2 = 1;            /* Reduce Op-Amp 2 non linearity */
    AMPCON1Hbits = R_AMPCON1H;
    R_AMPCON1L.AMPEN1 = 1;             /* Enable Op-Amp 1 */
    R_AMPCON1L.AMPEN2 = 1;             /* Enable Op-Amp 2 */
    R_AMPCON1L.AMPON = 1;              /* Enable Op-Amp Module */
    AMPCON1Lbits = R_AMPCON1L;
  }

  /* Start for S-Function (MCHP_Master): '<S2>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <S2>/Microchip Master */

  /* Start for S-Function (MCHP_UART_Config): '<S2>/UART Configuration' */

  /* MCHP_UART_Config Block for UART 1: <S2>/UART Configuration/Initialize */
  U1BRG = 0xD9;                        /* Baud rate: 921600 (+0.01%) */
  U1BRGH = 0x00;                       /* Baud rate MSB */
  U1MODE = 0x8020;
  U1MODEH = 0x8C00;
  U1STA = 0x00;
  U1STAH = 0x0700;

  /* Configure UART1 using Tx Interruption */
  _U1TXIP = 5;                         /*  Tx Interrupt priority set to 5 */
  _U1TXIF = 0;                         /*  */
  _U1TXIE = 1;                         /* Enable Interrupt */
  dsPIC33CK256MP508_SMO_LVMC_PrevZCX.OpenloopPos_PU_Reset_ZCE = POS_ZCSIG;
  dsPIC33CK256MP508_SMO_LVMC_PrevZCX.TriggeredSubsystem_Trig_ZCE = ZERO_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S58>/Integrator' incorporates:
   *  Constant: '<S18>/Ki1'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE = 0;
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator' incorporates:
   *  Constant: '<S19>/Kp1'
   */
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_DSTATE_d = 0;
  dsPIC33CK256MP508_SMO_LVMC_DW.Integrator_PrevResetState_a = 0;

  /* SystemInitialize for Enabled SubSystem: '<S140>/Up Counter' */
  /* InitializeConditions for Delay: '<S142>/Delay' */
  dsPIC33CK256MP508_SMO_LVMC_DW.Delay_DSTATE = 0UL;

  /* End of SystemInitialize for SubSystem: '<S140>/Up Counter' */

  /* SystemInitialize for Chart: '<S148>/Chart' */
  dsPIC33CK256MP508_SMO_LVMC_DW.temporalCounter_i1 = 0U;
  dsPIC33CK256MP508_SMO_LVMC_DW.is_active_c3_dsPIC33CK256MP508_SMO_LVMC = 0U;
  dsPIC33CK256MP508_SMO_LVMC_DW.is_c3_dsPIC33CK256MP508_SMO_LVMC =
    dsPIC33CK256MP508_SMO_LVMC_IN_NO_ACTIVE_CHILD;
  dsPIC33CK256MP508_SMO_LVMC_B.Mode = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S9>/Openloop Pos_PU' */
  /* InitializeConditions for DiscreteIntegrator: '<S147>/Discrete-Time Integrator' */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_DSTATE = 0L;

  /* InitializeConditions for UnitDelay: '<S151>/Uni Delay' */
  dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S151>/Uni Delay1' */
  dsPIC33CK256MP508_SMO_LVMC_DW.UniDelay1_DSTATE = true;

  /* InitializeConditions for DiscreteIntegrator: '<S150>/Discrete-Time Integrator' */
  dsPIC33CK256MP508_SMO_LVMC_DW.DiscreteTimeIntegrator_IC_LOADING = 1U;

  /* End of SystemInitialize for SubSystem: '<S9>/Openloop Pos_PU' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
  dsPIC33CK256MP508_SMO_LVMC_SpeedControl_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */
}

/* Model terminate function */
void dsPIC33CK256MP508_SMO_LVMC_terminate(void)
{
  /* Terminate for S-Function (MCHP_PWM_HS_FEP): '<S6>/PWM_HS_FEP' */

  /* Set initial Dead Time */
  PG1DTH = 200U;                       /* 1.0E-6s */
  PG2DTH = 200U;                       /* 1.0E-6s */
  PG4DTH = 200U;                       /* 1.0E-6s */
  PG1DTL = 200U;                       /* 1.0E-6s */
  PG2DTL = 200U;                       /* 1.0E-6s */
  PG4DTL = 200U;                       /* 1.0E-6s */

  /* Set initial PWM Period */
  PG4PER = 4999U;                      /* 5.0E-5s */
  PG2PER = 4999U;                      /* 5.0E-5s */
  PG1PER = 4999U;                      /* 5.0E-5s */

  /* Set initial PWM Duty Cycles */
  PG4DC = 200U;                        /* 2.0E-6s */
  PG2DC = 200U;                        /* 2.0E-6s */
  PG1DC = 200U;                        /* 2.0E-6s */

  /* Terminate for S-Function (MCHP_UART_Config): '<S2>/UART Configuration' */
  while (0U == U1STAbits.TRMT) ;       /* Wait until all byte are sent */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
