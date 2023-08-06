#include <msp430.h>
#include "globals.h"
#include "button.h"
#include "buzzer.h"
#include "delay.h"
#include "timer.h"
#include "notes.h"
#include "melodies.h"

// Define the frequency for the system clock (SMCLK)..
#define SMCLK_FREQ 1000000  // Assuming SMCLK is set to 1MHz


// Main function
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop watchdog timer

    buzzer_init();  // Initialize the buzzer
    button_init();  // Initialize the button
    
    
    P1DIR |= (BIT0 | BIT2);  // Set P1.0 and P1.2 as outputs
    P1OUT &= ~(BIT0 | BIT2);  // Ensure LEDs are off to start
        // Wait for a button to be pressed
    while (1) {
        //melodies();
        if ((P2IN & BIT0) == 0) {  // If button on P2.0 is pressed
            for (int i = 0; melody1(i) != -1; i++) {
                playBuzzer(melody1(i), noteDurations1(i));
                delay_ms(1000 / noteDurations1(i));
                stopBuzzer();
                delay_ms(250 / noteDurations1(i));  // Short delay between notes
            }
        }
        else if ((P2IN & BIT1) == 0) {  // If button on P2.1 is pressed
            // Play melody 2
            for (int i = 0; melody2[i] != -1; i++) {
                playBuzzer(melody2[i], noteDurations2[i]);
                delay_ms(1000 / noteDurations2[i]);
                stopBuzzer();
                delay_ms(250 / noteDurations2[i]);  // Short delay between notes
            }
        }
        else if ((P2IN & BIT3) == 0) {  // If button on P2.1 is pressed
            // Play melody 3
            for (int i = 0; melody3[i] != -1; i++) {
                playBuzzer(melody3[i], noteDurations3[i]);
                delay_ms(1000 / noteDurations3[i]);
                stopBuzzer();
                delay_ms(250 / noteDurations3[i]);  // Short delay between notes
            }
        }
        else if ((P2IN & BIT3) == 0) {  // If button on P2.1 is pressed
            // Play melody 4
            for (int i = 0; melody4[i] != -1; i++) {
                playBuzzer(melody4[i], noteDurations4[i]);
                delay_ms(1000 / noteDurations4[i]);
                stopBuzzer();
                delay_ms(250 / noteDurations4[i]);  // Short delay between notes
            }
        }
    }

    return 0;
}
