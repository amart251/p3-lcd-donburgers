#include "notes.h"
#include "button.h"

void melodies()
{
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
    NOTE_G6, NOTE_G5, NOTE_C6, NOTE_E6, NOTE_DS6, NOTE_G5, 

    NOTE_B6, NOTE_B5, NOTE_A6, NOTE_C6, NOTE_E6, NOTE_A6, 

    NOTE_G6, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_A6, NOTE_C6, 

    NOTE_F6, NOTE_A6, NOTE_GS6, NOTE_C6, NOTE_D6, NOTE_F6, 

    NOTE_E6, NOTE_G5, NOTE_C6, NOTE_E6, NOTE_D6, NOTE_A5, 

    NOTE_B5, NOTE_D6
};

float melody3[] = {

    NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, 

    NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6,

    NOTE_GS6, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_E6,

    NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6,

    NOTE_F6, NOTE_G6, NOTE_GS6,

    NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6,

    NOTE_F6, NOTE_G6, NOTE_GS6

};

float melody4[] = {

    NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C3, NOTE_D3, 

    NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C3, NOTE_D3,

    NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_E3,

    NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C3, NOTE_D3,

    NOTE_F3, NOTE_G3, NOTE_GS3,

    NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C3, NOTE_D3,

    NOTE_F3, NOTE_G3, NOTE_GS3

};
}

void durations()
{
// Define the duration for each note in the melody
// 4 represents a quarter note, 2 represents a half note, etc.

int noteDurations1[] = {
    4,4,4,
    4,4,4,4,4,
    4,4,4,
    4,4,4,4,4,
    4,4,4,4,4,4,
    4,4,4,4,4,
    4,4,4,4,4 
};

int noteDurations2[] = {
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4
};

int noteDurations3[] = {
    4,4,4,4,4,
    4,4,4,4,4,4,
    4,4,4,4,4,
    4,4,4,
    4,4,4,4,4,
    4,4,4
};

int noteDurations4[] = {
    4,4,4,4,4,
    4,4,4,4,4,4,
    4,4,4,4,4,
    4,4,4,
    4,4,4,4,4,
    4,4,4
};
}
