#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char buttonHistory = 0xFF;
    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if (timer0Expired())
        {
             count0=count0+1;
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if (timer1Expired())
        {
            buttonHistory = (buttonHistory << 1) | checkStatus_BoosterpackS1();
        }


        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        bool pressed = fsmBoosterpackButtonS1(buttonHistory);


        // TODO: If a completed, debounced button press has occurred, increment count1.
        if(pressed)
          count1=count1+1;

    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    turnOff_LaunchpadLED2Green();
    turnOff_LaunchpadLED2Red();
    turnOff_LaunchpadLED2Blue();
    switch(count%8)
    {
        case 0:
            turnOn_LaunchpadLED2Red();
            break;
        case 1:
            turnOn_LaunchpadLED2Green();
            break;
        case 2:
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            break;
        case 3:
            turnOn_LaunchpadLED2Blue();
            break;
        case 4:
            turnOn_LaunchpadLED2Blue();
            turnOn_LaunchpadLED2Red();
            break;
        case 5:
            turnOn_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            break;
        case 6:
            turnOn_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            turnOn_LaunchpadLED2Red();
            break;
    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    turnOff_BoosterpackLEDGreen();
    turnOff_BoosterpackLEDRed();
    turnOff_BoosterpackLEDBlue();
    switch(count%8)
    {
     case 1:
        turnOn_BoosterpackLEDRed();
        break;
     case 2:
        turnOn_BoosterpackLEDGreen();
        break;
     case 3:
         turnOn_BoosterpackLEDRed();
         turnOn_BoosterpackLEDGreen();
         break;
     case 4:
         turnOn_BoosterpackLEDBlue();
         break;
     case 5:
         turnOn_BoosterpackLEDBlue();
         turnOn_BoosterpackLEDRed();
         break;
     case 6:
         turnOn_BoosterpackLEDBlue();
         turnOn_BoosterpackLEDGreen();
         break;
     case 7:
         turnOn_BoosterpackLEDRed();
         turnOn_BoosterpackLEDBlue();
         turnOn_BoosterpackLEDGreen();
         break;
    }

}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    bool pressed = false;

    static enum { Pressed, Released } State = Released;
    static unsigned char oldHistory = 0xFF;

    switch (State)
    {
    case Released:
        // if previous state is not all 0s and bottonhistory is all 0's then next state is pressed
        if (oldHistory != 0x00 && buttonhistory == 0x00)
        {
            State = Pressed;
            pressed = true;
        }
        break;

    case Pressed:
        // if previous state has zeros and bottonhistory is all 1's then next state is released
        if (oldHistory != 0xFF && buttonhistory == 0xFF)
        {
            State = Released;
        }
        break;
    }

    oldHistory = buttonhistory;
    return pressed;
}
