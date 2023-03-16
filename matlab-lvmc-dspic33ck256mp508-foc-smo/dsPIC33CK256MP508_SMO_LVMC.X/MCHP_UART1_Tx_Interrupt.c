#include "dsPIC33CK256MP508_SMO_LVMC.h"
#include "dsPIC33CK256MP508_SMO_LVMC_private.h"

/* Declare UART1 Tx Circular Buffer Structure */
MCHP_UART1_TxStr MCHP_UART1_Tx = { .head = 0, .tail = 0 };/* UART1 Tx FIFO */

void __attribute__((__interrupt__,__shadow__,__no_auto_psv__)) _U1TXInterrupt
  (void)
{
  uint_T LocalHead;
  LocalHead = MCHP_UART1_Tx.head;
     /* Head is a volatile variable. Use local variable to speed-up execution */
  _U1TXIF = 0;                         /* Clear Interrupt Flag */
  while ((0U == U1STAHbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
  {
    U1TXREG = MCHP_UART1_Tx.buffer[LocalHead++];
    LocalHead &= (Tx_BUFF_SIZE_UART1-1);
  }

  MCHP_UART1_Tx.head = LocalHead;      /* Push back volatile variable */
}
