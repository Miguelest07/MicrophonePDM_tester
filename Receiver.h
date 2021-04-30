#ifndef UART_RECEIVER_H
#define UART_RECEIVER_H

class Rx
{
  public://pubic instances which everyone has access
    void begin(int baudRate);
    void receive(void);
    int matched(void);
  
  private://private variables, shown as _example with "_" for difference them between other variables
    char _buffer[20];
    int _on;
    int _iteration;
    char _character;
    int _matched;
    char _keyword[5];
};

//here is declared the name of the class object, which will be used in the main sketch
extern Rx receiver;
#endif
