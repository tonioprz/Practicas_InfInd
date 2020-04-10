#ifndef KEYBOARD_H
#define KEYBOARD_H
#include"device.h"
#include"processor.h"
class Keyboard : public Device
{
public:
    Keyboard();
    Keyboard(const string &name);
    void connecTo(Processor &cpu);
    void process();
protected:
    Processor _cpu;
};

#endif // KEYBOARD_H
