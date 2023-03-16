/*
 * -------------------------------------------------------------------
 * MPLAB Device Blocks for Simulink v3.50.30 (21-Nov-2022)
 *
 *   Product Page:  https://www.mathworks.com/matlabcentral/fileexchange/71892
 *           Forum: https://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: dsPIC33CK256MP508_SMO_LVMC.h
 *
 * Code generated for Simulink model 'dsPIC33CK256MP508_SMO_LVMC'.
 *
 * Model version                  : 7.14
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Mar 16 10:58:36 2023
 */

#ifndef RTW_HEADER_dsPIC33CK256MP508_SMO_LVMC_h_
#define RTW_HEADER_dsPIC33CK256MP508_SMO_LVMC_h_
#ifndef dsPIC33CK256MP508_SMO_LVMC_COMMON_INCLUDES_
#define dsPIC33CK256MP508_SMO_LVMC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                         /* dsPIC33CK256MP508_SMO_LVMC_COMMON_INCLUDES_ */

#define FCY                            (100000000UL)             /* Instruction Frequency FCY set at  100.0 MHz */

/* Include for pic 33C */
#include <xc.h>
#include <libpic30.h>
/* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include "dsPIC33CK256MP508_SMO_LVMC_types.h"
#include <stddef.h>
#include <string.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T Add1;                       /* '<S142>/Add1' */
  uint16_T U2CH2;                      /* '<S7>/ADC dsPIC High Speed SAR' */
  uint16_T Saturationlowsideturnon[3]; /* '<S6>/Saturation low side turn  on' */
  uint16_T Mode;                       /* '<S148>/Chart' */
  int16_T Gain8;                       /* '<S149>/Gain8' */
  int16_T Speed_Ref;                   /* '<S1>/Data Store Read' */
  int16_T DataTypeConversion;          /* '<S7>/Data Type Conversion' */
  int16_T RateTransition6;             /* '<Root>/Rate Transition6' */
  int16_T RateTransition7;             /* '<Root>/Rate Transition7' */
  int16_T Id_ref;                      /* '<S4>/Id_ref' */
  int16_T Switch;                      /* '<S4>/Switch' */
  int16_T ADCdsPICHighSpeedSAR_o1;     /* '<S7>/ADC dsPIC High Speed SAR' */
  int16_T ADCdsPICHighSpeedSAR_o2;     /* '<S7>/ADC dsPIC High Speed SAR' */
  int16_T Iab[2];                      /* '<S139>/Iab' */
  uint8_T TmpSignalConversionAtUARTTxInport1[5];
} B_dsPIC33CK256MP508_SMO_LVMC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T Delay_DSTATE;               /* '<S142>/Delay' */
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<S147>/Discrete-Time Integrator' */
  int16_T Delay_DSTATE_h[4];           /* '<S1>/Delay' */
  int16_T Integrator_DSTATE;           /* '<S58>/Integrator' */
  int16_T Integrator_DSTATE_d;         /* '<S109>/Integrator' */
  int16_T UnitDelay_DSTATE;            /* '<S235>/Unit Delay' */
  int16_T Integrator_DSTATE_f;         /* '<S216>/Integrator' */
  int16_T UniDelay_DSTATE;             /* '<S151>/Uni Delay' */
  int16_T DiscreteTimeIntegrator_DSTATE_l;/* '<S150>/Discrete-Time Integrator' */
  int16_T UnitDelay3_DSTATE;           /* '<S157>/Unit Delay3' */
  int16_T Delay_DSTATE_i[2];           /* '<S154>/Delay' */
  int16_T DiscreteTimeIntegrator_DSTATE_e[2];/* '<S154>/Discrete-Time Integrator' */
  int16_T Delay3_DSTATE[2];            /* '<S154>/Delay3' */
  int16_T DiscreteTimeIntegrator2_DSTATE[2];/* '<S154>/Discrete-Time Integrator2' */
  int16_T Delay2_DSTATE[2];            /* '<S149>/Delay2' */
  int16_T DiscreteTimeIntegrator3_DSTATE[2];/* '<S149>/Discrete-Time Integrator3' */
  int16_T Delay1_DSTATE;               /* '<S157>/Delay1' */
  int16_T DiscreteTimeIntegrator4_DSTATE;/* '<S157>/Discrete-Time Integrator4' */
  uint16_T temporalCounter_i1;         /* '<S148>/Chart' */
  volatile int16_T RateTransition5_Buffer[4];/* '<Root>/Rate Transition5' */
  int16_T SpeedRef;                    /* '<Root>/Data Store Memory4' */
  int16_T PrevY;                       /* '<S4>/Rate Limiter2' */
  uint8_T Output_DSTATE;               /* '<S161>/Output' */
  boolean_T Delay_DSTATE_n;            /* '<S140>/Delay' */
  boolean_T Delay_DSTATE_a;            /* '<S180>/Delay' */
  boolean_T UniDelay1_DSTATE;          /* '<S151>/Uni Delay1' */
  uint8_T Output_DSTATE_p;             /* '<S169>/Output' */
  uint8_T Output_DSTATE_l;             /* '<S168>/Output' */
  volatile int8_T RateTransition5_ActiveBufIdx;/* '<Root>/Rate Transition5' */
  int8_T Integrator_PrevResetState;    /* '<S58>/Integrator' */
  int8_T Integrator_PrevResetState_a;  /* '<S109>/Integrator' */
  int8_T Integrator_PrevResetState_o;  /* '<S216>/Integrator' */
  uint8_T is_active_c3_dsPIC33CK256MP508_SMO_LVMC;/* '<S148>/Chart' */
  uint8_T is_c3_dsPIC33CK256MP508_SMO_LVMC;/* '<S148>/Chart' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S150>/Discrete-Time Integrator' */
  boolean_T EnableFOC;                 /* '<Root>/Data Store Memory29' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory3' */
  boolean_T EnableClosedLoop;          /* '<Root>/Data Store Memory6' */
  boolean_T UpCounter_MODE;            /* '<S140>/Up Counter' */
} DW_dsPIC33CK256MP508_SMO_LVMC_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S179>/Triggered Subsystem' */
  ZCSigState OpenloopPos_PU_Reset_ZCE; /* '<S9>/Openloop Pos_PU' */
} PrevZCX_dsPIC33CK256MP508_SMO_LVMC_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S15>/sine_table_values'
   */
  int16_T sine_table_values_Value[1002];
} ConstP_dsPIC33CK256MP508_SMO_LVMC_T;

/* Real-time Model Data Structure */
struct tag_RTM_dsPIC33CK256MP508_SMO_LVMC_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[5];
      uint16_T cLimit[5];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_dsPIC33CK256MP508_SMO_LVMC_T dsPIC33CK256MP508_SMO_LVMC_B;

/* Block states (default storage) */
extern DW_dsPIC33CK256MP508_SMO_LVMC_T dsPIC33CK256MP508_SMO_LVMC_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_dsPIC33CK256MP508_SMO_LVMC_T dsPIC33CK256MP508_SMO_LVMC_PrevZCX;

/* Constant parameters (default storage) */
extern const ConstP_dsPIC33CK256MP508_SMO_LVMC_T
  dsPIC33CK256MP508_SMO_LVMC_ConstP;

/* Model entry point functions */
extern void dsPIC33CK256MP508_SMO_LVMC_initialize(void);
extern void dsPIC33CK256MP508_SMO_LVMC_step0(void);
extern void dsPIC33CK256MP508_SMO_LVMC_step1(void);
extern void dsPIC33CK256MP508_SMO_LVMC_step2(void);
extern void dsPIC33CK256MP508_SMO_LVMC_step3(void);
extern void dsPIC33CK256MP508_SMO_LVMC_step4(void);
extern void dsPIC33CK256MP508_SMO_LVMC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_dsPIC33CK256MP508_SMO_LVMC_T *const dsPIC33CK256MP508_SMO_LVMC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'dsPIC33CK256MP508_SMO_LVMC'
 * '<S1>'   : 'dsPIC33CK256MP508_SMO_LVMC/Current Control'
 * '<S2>'   : 'dsPIC33CK256MP508_SMO_LVMC/Hardware Init'
 * '<S3>'   : 'dsPIC33CK256MP508_SMO_LVMC/Heartbeat LED'
 * '<S4>'   : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control'
 * '<S5>'   : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control'
 * '<S6>'   : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/MOTOR Cmd'
 * '<S7>'   : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/MOTOR - Board Sensor'
 * '<S8>'   : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Output Scaling'
 * '<S9>'   : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation'
 * '<S10>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Serial Tx'
 * '<S11>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Clarke Transform'
 * '<S12>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers'
 * '<S13>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Inverse Park Transform'
 * '<S14>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Park Transform'
 * '<S15>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Sine-Cosine Lookup'
 * '<S16>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Space Vector Generator'
 * '<S17>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter'
 * '<S18>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id'
 * '<S19>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq'
 * '<S20>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/Compare To Constant'
 * '<S21>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/If Action Subsystem1'
 * '<S22>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/Limiter'
 * '<S23>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/DQ Limiter/calc Vmax_unsat'
 * '<S24>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S25>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S26>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S27>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S28>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S29>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S30>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S31>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S32>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S33>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S34>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S35>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S36>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S37>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S38>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S39>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S40>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S41>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S42>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S43>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S44>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S45>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S46>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S47>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S48>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S49>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S50>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S51>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S52>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S53>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S54>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S55>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S56>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S57>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S58>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S59>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S60>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S61>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S62>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S63>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S64>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S65>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S66>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S67>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S68>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S69>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S70>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S71>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/Passthrough'
 * '<S72>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S73>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S74>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S75>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S76>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S77>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S78>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S79>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S80>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S81>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S82>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S83>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S84>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S85>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S86>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S87>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S88>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S89>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S90>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S91>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S92>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S93>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S94>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S95>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S96>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S97>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S98>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S99>'  : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S100>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S101>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S102>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S103>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S104>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S105>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S106>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S107>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S108>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S109>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S110>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S111>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S112>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S113>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S114>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S115>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S116>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S117>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S118>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S119>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S120>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S121>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S122>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/Passthrough'
 * '<S123>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S124>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S125>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S126>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Inverse Park Transform/Switch_Axis'
 * '<S127>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Park Transform/Switch_Axis'
 * '<S128>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Sine-Cosine Lookup/Interpolation'
 * '<S129>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp'
 * '<S130>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S131>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S132>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S133>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Space Vector Generator/Modulation method'
 * '<S134>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input'
 * '<S135>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S136>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S137>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S138>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Closed Loop Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S139>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/MOTOR - Board Sensor/Offset1'
 * '<S140>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Output Scaling/Mode Selector'
 * '<S141>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Output Scaling/Mode Selector/Subsystem1'
 * '<S142>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Output Scaling/Mode Selector/Up Counter'
 * '<S143>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Output Scaling/Mode Selector/Subsystem1/Compare To Constant'
 * '<S144>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Output Scaling/Mode Selector/Subsystem1/Compare To Constant1'
 * '<S145>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Output Scaling/Mode Selector/Subsystem1/Compare To Constant2'
 * '<S146>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Output Scaling/Mode Selector/Subsystem1/Compare To Constant3'
 * '<S147>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Openloop Pos_PU'
 * '<S148>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/OpentoClosed'
 * '<S149>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Sliding Mode Observer'
 * '<S150>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Openloop Pos_PU/Position Generator'
 * '<S151>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Openloop Pos_PU/Position Generator/Reset_Logic'
 * '<S152>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Openloop Pos_PU/Position Generator/Theta_Increment_Source'
 * '<S153>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/OpentoClosed/Chart'
 * '<S154>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Sliding Mode Observer/Adaptive Filter2'
 * '<S155>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Sliding Mode Observer/Scaling'
 * '<S156>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Sliding Mode Observer/Subsystem3'
 * '<S157>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Sliding Mode Observer/Subsystem4'
 * '<S158>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Sliding Mode Observer/atan1'
 * '<S159>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Sliding Mode Observer/Subsystem3/Compare To Constant1'
 * '<S160>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Position and Speed Estimation/Sliding Mode Observer/Subsystem4/Wrap_to_pi2'
 * '<S161>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Serial Tx/Counter Limited'
 * '<S162>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Serial Tx/UART_TX'
 * '<S163>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Serial Tx/Counter Limited/Increment Real World'
 * '<S164>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Serial Tx/Counter Limited/Wrap To Zero'
 * '<S165>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Serial Tx/UART_TX/Debug_Data'
 * '<S166>' : 'dsPIC33CK256MP508_SMO_LVMC/Current Control/Serial Tx/UART_TX/SCI_Tx'
 * '<S167>' : 'dsPIC33CK256MP508_SMO_LVMC/Hardware Init/Model Info'
 * '<S168>' : 'dsPIC33CK256MP508_SMO_LVMC/Heartbeat LED/Counter Free-Running'
 * '<S169>' : 'dsPIC33CK256MP508_SMO_LVMC/Heartbeat LED/Counter Free-Running1'
 * '<S170>' : 'dsPIC33CK256MP508_SMO_LVMC/Heartbeat LED/LED 1'
 * '<S171>' : 'dsPIC33CK256MP508_SMO_LVMC/Heartbeat LED/LED 2'
 * '<S172>' : 'dsPIC33CK256MP508_SMO_LVMC/Heartbeat LED/Counter Free-Running/Increment Real World'
 * '<S173>' : 'dsPIC33CK256MP508_SMO_LVMC/Heartbeat LED/Counter Free-Running/Wrap To Zero'
 * '<S174>' : 'dsPIC33CK256MP508_SMO_LVMC/Heartbeat LED/Counter Free-Running1/Increment Real World'
 * '<S175>' : 'dsPIC33CK256MP508_SMO_LVMC/Heartbeat LED/Counter Free-Running1/Wrap To Zero'
 * '<S176>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/Enable Switch'
 * '<S177>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed'
 * '<S178>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/Speed_Ref_Selector'
 * '<S179>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/Enable Switch/Codegen'
 * '<S180>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/Enable Switch/Codegen/Triggered Subsystem'
 * '<S181>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S182>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S183>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S184>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S185>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S186>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S187>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S188>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S189>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S190>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S191>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S192>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S193>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S194>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S195>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S196>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S197>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S198>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S199>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S200>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S201>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S202>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S203>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S204>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S205>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S206>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S207>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S208>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S209>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S210>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S211>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S212>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S213>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S214>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S215>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S216>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S217>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S218>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S219>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S220>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S221>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S222>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S223>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S224>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S225>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S226>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S227>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S228>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S229>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/Passthrough'
 * '<S230>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S231>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S232>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S233>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S234>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S235>' : 'dsPIC33CK256MP508_SMO_LVMC/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                            /* RTW_HEADER_dsPIC33CK256MP508_SMO_LVMC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
