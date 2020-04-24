#ifndef KEYBOARD_H
#define KEYBOARD_H
#include"processor.h"
#include"input.h"

class Keyboard : public Input
{
public:
    Keyboard();
    Keyboard(const string &name);
    void process();
protected:
    Processor *_cpu;
};

#endif // KEYBOARD_H
