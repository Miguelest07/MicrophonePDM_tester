//Arduino NANO 33 BLE SENSE approved
#include <Arduino.h>
#include "Micro.h"
#include "Receiver.h"

void setup() 
{
  receiver.begin(9600);//UART receiver initializer, 9600 baudrate
  microphone.begin(1,16000);//PDM initializer, 1 channel, 16000 sample rate
}

void loop() 
{
  receiver.receive();//UART receiver handler function

  //UART command flag// 
  //IMPORTANT: The command is " /start$ " without "", / is used as a initalizer of the command and $ as the finisher
  //The flag will be set to 1 for a sinlge instance
  if (receiver.matched() == 1)
  {
    //PDM state switch, changes between ON/OFF each time is called
    microphone.start();
  }

  //function handler of microphone serial streaming
  microphone.sound_display();
}
