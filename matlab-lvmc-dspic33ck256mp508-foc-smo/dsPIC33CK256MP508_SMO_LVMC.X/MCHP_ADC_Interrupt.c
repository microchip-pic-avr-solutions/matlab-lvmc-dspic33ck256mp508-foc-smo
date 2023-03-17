#include "dsPIC33CK256MP508_SMO_LVMC.h"
#include "dsPIC33CK256MP508_SMO_LVMC_private.h"

void __attribute__((__interrupt__,__auto_psv__)) _ADCAN11Interrupt(void)
{
  unsigned int tmp __attribute__((unused)) = ADCBUF11 ;/* remove cause of interrupt */

  {
    struct {
      unsigned int Flags1 : 1;
      unsigned int Flags2 : 1;
      unsigned int Flags3 : 1;
      unsigned int Flags4 : 1;
    } static volatile Overrun __attribute__ ((near)) ;

    struct {
      unsigned int Flags1 : 1;
      unsigned int Flags2 : 1;
      unsigned int Flags3 : 1;
      unsigned int Flags4 : 1;
    } static volatile event __attribute__ ((near)) ;

    struct {
      uint_T Task1;                 /* 0.0015s periodic task. Max value is 30 */
      uint_T Task2;                 /* 0.005s periodic task. Max value is 100 */
      uint_T Task3;                  /* 0.1s periodic task. Max value is 2000 */
      uint_T Task4;                 /* 0.5s periodic task. Max value is 10000 */
    } static volatile taskCounter __attribute__ ((near)) = {
      .Task1 = 1        /* Offset is 0 (-30 + 1 modulo [30 for pre decrement) */
      , .Task2 = 1    /* Offset is 0 (-100 + 1 modulo [100 for pre decrement) */
      , .Task3 = 1  /* Offset is 0 (-2000 + 1 modulo [2000 for pre decrement) */
      , .Task4 = 1/* Offset is 0 (-10000 + 1 modulo [10000 for pre decrement) */
    };

    _ADCAN11IF = 0;                    /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    taskCounter.Task1--;               /* Decrement task internal counter */
    if (taskCounter.Task1 == 0) {      /* task dropped on overload */
      taskCounter.Task1 = (uint_T) 30;
                                    /* 0.0015s periodic task. Max value is 30 */
      event.Flags1 = 1U;               /* Flag tag to be executed */
    }

    taskCounter.Task2--;               /* Decrement task internal counter */
    if (taskCounter.Task2 == 0) {      /* task dropped on overload */
      taskCounter.Task2 = (uint_T) 100;
                                    /* 0.005s periodic task. Max value is 100 */
      event.Flags2 = 1U;               /* Flag tag to be executed */
    }

    taskCounter.Task3--;               /* Decrement task internal counter */
    if (taskCounter.Task3 == 0) {      /* task dropped on overload */
      taskCounter.Task3 = (uint_T) 2000;
                                     /* 0.1s periodic task. Max value is 2000 */
      event.Flags3 = 1U;               /* Flag tag to be executed */
    }

    taskCounter.Task4--;               /* Decrement task internal counter */
    if (taskCounter.Task4 == 0) {      /* task dropped on overload */
      taskCounter.Task4 = (uint_T) 10000;
                                    /* 0.5s periodic task. Max value is 10000 */
      event.Flags4 = 1U;               /* Flag tag to be executed */
    }

    /* ---------- Handle model base rate Task 0 ---------- */
    LATDbits.LATD8 = 1;       /* pin RD8 = 1 Start/Continue profiling Task D1 */
    dsPIC33CK256MP508_SMO_LVMC_step0();

    /* Get model outputs here */
    LATDbits.LATD8 = 0;                /* pin RD8 = 0 Stop profiling Task D1 */
    if (_ADCAN11IF ) {
      return;                          /* Will re-enter into the interrupt */
    }

    /* Re-Enable Interrupt. IPL value is 2 at this point */
    {
      _IPL0 = 1;
              /* Enable Scheduler re-entrant interrupt. Lower IPL from 2 to 1 */
      _IPL1 = 0;
    }

    /* Step the model for any subrate */
    /* ---------- Handle Task 1 ---------- */
    if (Overrun.Flags1) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    if (event.Flags1) {
      Overrun.Flags1 = 1;
      do {                             /* Execute task tid 1 */
        event.Flags1 = 0U;
        dsPIC33CK256MP508_SMO_LVMC_step1();

        /* Get model outputs here */
      } while (event.Flags1);

      Overrun.Flags1 = 0U;
    }

    /* ---------- Handle Task 2 ---------- */
    if (Overrun.Flags2) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    if (event.Flags2) {
      Overrun.Flags2 = 1;
      do {                             /* Execute task tid 2 */
        event.Flags2 = 0U;
        dsPIC33CK256MP508_SMO_LVMC_step2();

        /* Get model outputs here */
      } while (event.Flags2);

      Overrun.Flags2 = 0U;
    }

    /* ---------- Handle Task 3 ---------- */
    if (Overrun.Flags3) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    if (event.Flags3) {
      Overrun.Flags3 = 1;
      do {                             /* Execute task tid 3 */
        event.Flags3 = 0U;
        dsPIC33CK256MP508_SMO_LVMC_step3();

        /* Get model outputs here */
      } while (event.Flags3);

      Overrun.Flags3 = 0U;
    }

    /* ---------- Handle Task 4 ---------- */
    if (Overrun.Flags4) {
      /* Priority to higher rate steps interrupted */
      return;
    }

    if (event.Flags4) {
      Overrun.Flags4 = 1;
      do {                             /* Execute task tid 4 */
        event.Flags4 = 0U;
        dsPIC33CK256MP508_SMO_LVMC_step4();

        /* Get model outputs here */
      } while (event.Flags4);

      Overrun.Flags4 = 0U;
    }

    /* Disable Interrupt. IPL value is 1 at this point */
    {
      _IPL1 = 1;        /* Disable Scheduler Interrupts. Rise IPL from 1 to 2 */
      _IPL0 = 0;
    }
  }
}
