//All object functions are built here
#include "Micro.h"

//static variables are used in static functions
static int samplesRead_;
static int bytesAvailable_;
static short sampleBuffer_[256];

//onPDMdata is a function refered from PDM library
//it is necessary to be used as a static function due some problems at compiling
void Micro::onPDMdata(void)
{
  bytesAvailable_ = PDM.available();
  PDM.read(sampleBuffer_, bytesAvailable_);
  samplesRead_ = bytesAvailable_ / 2;
  microphone.sync();
}

//sync is called because private variables don't work with static functions
void Micro::sync(void)
{
  _samplesRead = samplesRead_;
  _bytesAvailable = bytesAvailable_;
}

void Micro::begin(int channels, int sample_rate)
{
  _channels = channels;
  _sample_rate = sample_rate;
  PDM.onReceive(onPDMdata);
  if(PDM.begin(_channels, _sample_rate))
  {
    Serial.println("Microphone OK");;
  }
  else
  {
    Serial.println("Microphone OFFLINE");;
  }
}

void Micro::sound_display(void)
{
  if(_samplesRead)
  {
    if (_state == 1) 
    {
      for (int i = 0; i < _samplesRead; i++) 
      Serial.println(sampleBuffer_[i]);
    }
    _samplesRead = 0;
  }
}

int Micro::sample_rate()const
{
  return _sample_rate;
}

int Micro::channels()const
{
  return _channels;
}

void Micro::start(void)
{
  _state = !_state;
}

//here is declared the name of the class object, which will be used in the main sketch
Micro microphone;
