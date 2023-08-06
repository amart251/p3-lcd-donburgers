#include <msp430.h>
#include "globals.h"
#include "button.h"
#include "buzzer.h"
#include "delay.h"
#include "timer.h"
//#include "grlib.h"
#include "darksouls_bonfire.h" 
#include "notes.h"

// Define the frequencies for musical notes
/*#define NOTE_C4  261.63
#define NOTE_D4  293.66
#define NOTE_E4  329.63
#define NOTE_F4  349.23
#define NOTE_G4  392.00
#define NOTE_A4  440.00
#define NOTE_B4  493.88.*/

// Define the frequency for the system clock (SMCLK)..
#define SMCLK_FREQ 1000000  // Assuming SMCLK is set to 1MHz

float melody[] = {
    //NOTE_A4, NOTE_C4, NOTE_G4, NOTE_A4, NOTE_C4, NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4
    //NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4.
NOTE_F6, NOTE_G6, NOTE_GS6,

NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6,

NOTE_F6, NOTE_G6, NOTE_GS6,

NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6,

NOTE_GS6, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_E6,

NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6,

NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6
};

// Define the duration for each note in the melody
int noteDurations[] = {
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 // 4 represents a quarter note, 2 represents a half note, etc.
};

// Main function
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop watchdog timer

    buzzer_init();  // Initialize the buzzer
    button_init();  // Initialize the button
    
    P1DIR |= (BIT0 | BIT2);  // Set P1.0 and P1.2 as outputs
    P1OUT &= ~(BIT0 | BIT2);  // Ensure LEDs are off to start    // Wait for the button to be pressed
    while ((P2IN & BIT0) == BIT0) {  // while button is not pressed
        // do nothing
    }
    Graphics_initialize();
    // Draw the image at the desired coordinates (e.g., x=0, y=0)
    Graphics_drawImage(&darksouls_bonfire4BPP_COMP_RLE4, 0, 0);
    // Once button is pressed, play the melody
    for (int i = 0; melody[i] != -1; i++)
      {
        playBuzzer(melody[i], noteDurations[i]);
        delay_ms(1000 / noteDurations[i]);
        stopBuzzer();
        delay_ms(250 / noteDurations[i]);  // Short delay between notes
    }

    return 0;
}
