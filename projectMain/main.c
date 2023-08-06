#include <msp430.h>
#include "globals.h"
#include "button.h"
#include "buzzer.h"
#include "delay.h"
#include "timer.h"
#include "notes.h"

// Define the frequency for the system clock (SMCLK)..
#define SMCLK_FREQ 1000000  // Assuming SMCLK is set to 1MHz

float melody1[] = {
NOTE_F6, NOTE_G6, NOTE_GS6,

NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6,

NOTE_F6, NOTE_G6, NOTE_GS6,

NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6,

NOTE_GS6, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_E6,

NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6,

NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6
};

float melody2[] = {
NOTE_F4, NOTE_G4, NOTE_GS4,

NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4,

NOTE_F4, NOTE_G4, NOTE_GS4,

NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4,

NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4,

NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4,

NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4
};

// Define the duration for each note in the melody
int noteDurations1[] = {
    4,4,4,
    4,4,4,4,4,
    4,4,4,
    4,4,4,4,4,
    4,4,4,4,4,4,
    4,4,4,4,4,
    4,4,4,4,4 // 4 represents a quarter note, 2 represents a half note, etc.
};

int noteDurations2[] = {
    4,4,4,
    4,4,4,4,4,
    4,4,4,
    4,4,4,4,4,
    4,4,4,4,4,4,
    4,4,4,4,4,
    4,4,4,4,4 // 4 represents a quarter note, 2 represents a half note, etc.
};

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
        if ((P2IN & BIT0) == 0) {  // If button on P2.0 is pressed
            // Play melody 1
            for (int i = 0; melody1[i] != -1; i++) {
                playBuzzer(melody1[i], noteDurations1[i]);
                delay_ms(1000 / noteDurations1[i]);
                stopBuzzer();
                delay_ms(250 / noteDurations1[i]);  // Short delay between notes
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
    }

    return 0;
}
