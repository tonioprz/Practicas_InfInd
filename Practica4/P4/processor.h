#ifndef PROCESSOR_H
#define PROCESSOR_H
#include"device.h"
#include"display.h"
class Processor : public Device
{
public:
    Processor();
    Processor(const string &name);
    void connectTo(Display &disp);
    void process(const string &data);
private:
    Display _disp;
};

#endif // PROCESSOR_H
