#include <Arduino.h>
#include "Receiver.h"

void Rx::begin(int baudRate)
{
  Serial.begin(baudRate);
  while(!Serial);
  _on = 0;
  _iteration = 0;
  _character = 0;
  _matched = 0;
  _keyword[0] = 's';
  _keyword[1] = 't';
  _keyword[2] = 'a';
  _keyword[3] = 'r';
  _keyword[4] = 't';
  Serial.println("Receiver OK");
}

void Rx::receive(void)
{
  if (Serial.available()) 
  {
    _character = Serial.read();
    Serial.print(_character);
    if(_on == 1)
    {
      if (_character != '$')
      {
        _buffer[_iteration] = _character;
        _iteration++;
      }
      else 
      {
        if(_iteration == 5)
        {
          for (int j = 0; j < 5; j++)
          {
            if(_buffer[j] != _keyword[j])
            {
              _matched = 0;
              Serial.println(j);
              Serial.println("Failed");
            }
            else
            {
              _matched = 1;
              Serial.println(j);
              Serial.println("Correct");
            }
            
          }
        }
        else
        {
          _matched = 0;
          Serial.println();
          Serial.print("wrong command, you typed: ");
          Serial.println(_buffer);
        }
        for(int a = 0; a < _iteration; a++)
        {
          _buffer[a] = 0;
        }
        _on = 0; 
        _iteration = 0;
      }
    }
    else
    {
      if (_character == '/')
      {
        _on = 1;
      }
    }
  }
}

int Rx::matched(void)
{
  int x = _matched;
  _matched = 0;
  return x;
}

//here is declared the name of the class object, which will be used in the main sketch
Rx receiver;
