// includes as well as the class object are defined here
#include <PDM.h>
#ifndef MICROPHONE_H
#define MICROPHONE_H

class Micro
{
  public://pubic instances which everyone has access
    void begin(int channels, int sample_rate);
    int sample_rate()const;
    int channels()const;
    void sound_display(void);
    void start(void);
    static void onPDMdata(void);
    
  private://private functions 
    void sync(void);
  
  private://private variables, shown as _example with "_" for difference them between other variables
    int _bytesAvailable;
    int _channels;
    int _sample_rate;
    int _state;
    int _samplesRead;
};

//here is declared the name of the class object, which will be used in the main sketch
extern Micro microphone;
#endif
