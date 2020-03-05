/*
 * GPIO.c
 *
 *  Created on: 2/29/2020
 *      Author: Zhaomeng Zhang
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

#define LAUNCHPAD_S1 BIT1 //P1.1
#define LAUNCHPAD_S2 BIT4 //P1.4
#define BOOSTPACK_S1 BIT1 //P5.1
#define BOOSTPACK_S2 BIT5 //P3.5
#define LED1L        BIT0 //P1.0
#define LED2L_Red    BIT0 //P2.0
#define LED2L_Green  BIT1 //P2.1
#define LED2L_Blue   BIT2 //P2.2
#define LEDB_Red     BIT6 //P2.6
#define LEDB_Green   BIT4 //P2.4
#define LEDB_Blue    BIT6 //P5.6
// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR = P1DIR & ~LAUNCHPAD_S1;
    P1REN = P1REN | LAUNCHPAD_S1;
    P1OUT = P1OUT | LAUNCHPAD_S1;
    // Launchpad S2
    P1DIR = P1DIR & ~LAUNCHPAD_S2;
    P1REN = P1REN | LAUNCHPAD_S2;
    P1OUT = P1OUT | LAUNCHPAD_S2;
    // Boosterpack S1
    P5DIR = P5DIR & ~BOOSTPACK_S1;
    P5REN = P5REN | BOOSTPACK_S1;
    P5OUT = P5OUT | BOOSTPACK_S1;
    // Boosterpack S2
    P3DIR = P3DIR & ~BOOSTPACK_S2;
    P3REN = P3REN | BOOSTPACK_S2;
    P3OUT = P3OUT | BOOSTPACK_S2;
    // Launchpad LED1
    P1DIR = P1DIR | LED1L;
    // Launchpad LED2 Red
    P2DIR = P2DIR | LED2L_Red;
    // Launchpad LED2 Green
    P2DIR = P2DIR | LED2L_Green;
    // Launchpad LED2 Blue
    P2DIR = P2DIR | LED2L_Blue;
    // Boosterpack LED Red
    P2DIR = P2DIR | LEDB_Red;
    // Boosterpack LED Green
    P2DIR = P2DIR | LEDB_Green;
    // Boosterpack LED Blue
    P5DIR = P5DIR | LEDB_Blue;

    // Turn off all LEDs at the start.
    P1OUT = P1OUT & ~LED1L;
    P2OUT = P2OUT & ~LED2L_Red;
    P2OUT = P2OUT & ~LEDB_Red;
    P2OUT = P2OUT & ~LED2L_Blue;
    P5OUT = P5OUT & ~LEDB_Blue;
    P2OUT = P2OUT & ~LED2L_Green;
    P2OUT = P2OUT & ~LEDB_Green;
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & LAUNCHPAD_S1) == LAUNCHPAD_S1);

}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & LAUNCHPAD_S2) == LAUNCHPAD_S2);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & BOOSTPACK_S1) == BOOSTPACK_S1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & BOOSTPACK_S2) == BOOSTPACK_S2);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT | LED1L;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~LED1L;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | LED2L_Red;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LED2L_Red;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT | LED2L_Green;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LED2L_Green;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | LED2L_Blue;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LED2L_Blue;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | LEDB_Red;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~LEDB_Red;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | LEDB_Green;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~LEDB_Green;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | LEDB_Blue;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~LEDB_Blue;
}
