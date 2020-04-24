#ifndef PROCESSOR_H
#define PROCESSOR_H
#include"device.h"
#include"display.h"
#include"output.h"

class Processor : public Device
{
public:
    Processor();
    Processor(const string &name);
    void connectTo(Output &O);
    virtual void process(const string &data);
    virtual void process(const string &data, int n);
    Output &operator >>(Output & O);

protected:
    Output *_output;
};

#endif // PROCESSOR_H
