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

    P2IE |= (BIT0 | BIT1 | BIT2 | BIT3); // Enable interrupt on P2.0 - P2.3
    P2IES |= (BIT0 | BIT1 | BIT2 | BIT3); // Set interrupt edge select to falling edge
    P2IFG &= ~(BIT0 | BIT1 | BIT2 | BIT3); // Clear interrupt flags

    __enable_interrupt(); // Enable global interrupts
}

// Interrupt service routine for button press
#pragma vector=PORT2_VECTOR
__interrupt void button_isr(void)
{
    if (P2IFG & BIT0) // Check if P2.0 interrupt flag is set
    {
        // Your code to handle the button press event on P2.0
        lcd_set_color(RED); // Set the color to red
        lcd_draw_star(); // Draw the star
        P2IFG &= ~BIT0; // Clear interrupt flag
    }

    if (P2IFG & BIT1) // Check if P2.1 interrupt flag is set
    {
        // Your code to handle the button press event on P2.1
        lcd_set_color(BLACK); // Set the color to black
        lcd_draw_star(); // Draw the star
        P2IFG &= ~BIT1; // Clear interrupt flag
    }
    
    if (P2IFG & BIT2) // Check if P2.2 interrupt flag is set
    {
        // Your code to handle the button press event on P2.2
        P2IFG &= ~BIT2; // Clear interrupt flag
    }

    if (P2IFG & BIT3) // Check if P2.3 interrupt flag is set
    {
        // Your code to handle the button press event on P2.3
        P2IFG &= ~BIT3; // Clear interrupt flag
    }
    
}
