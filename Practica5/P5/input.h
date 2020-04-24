#ifndef INPUT_H
#define INPUT_H
#include "device.h"
#include<iostream>
#include"processor.h"

using namespace std;

class Input : public Device
{
public:
    Input();
    Input(const string & name);
    void connecTo(Processor & P);
    Processor &operator >>(Processor & P);
    virtual void process()=0;
protected:
    Processor *_processor;
};

#endif // INPUT_H
