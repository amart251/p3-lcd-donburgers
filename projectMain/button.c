#include <msp430.h>
#include "button.h"

// Initialize button on P2.0
void button_init(void)
{
    P2DIR &= ~BIT0;  // Set P2.0 as input
    P2REN |= BIT0;  // Enable pull-up resistor on P2.0
    P2OUT |= BIT0;  // Set pull-up resistor to pull-up mode

    P2DIR &= ~BIT1;  // Set P2.1 as input
    P2REN |= BIT1;  // Enable pull-up resistor on P2.1
    P2OUT |= BIT1;  // Set pull-up resistor to pull-up mode

    P2DIR &= ~BIT2;  // Set P2.2 as input
    P2REN |= BIT2;  // Enable pull-up resistor on P2.2
    P2OUT |= BIT2;  // Set pull-up resistor to pull-up mode

    P2DIR &= ~BIT3;  // Set P2.3 as input
    P2REN |= BIT3;  // Enable pull-up resistor on P2.3
    P2OUT |= BIT3;  // Set pull-up resistor to pull-up mode
}
