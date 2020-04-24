#ifndef PROCESSOR_H
#define PROCESSOR_H
#include"device.h"
#include"output.h"
#include<iostream>
using namespace std;

class Processor : public Device
{
public:
    Processor();
    Processor(const string &name);
    void connectTo(Output &O);
    virtual void process(const string &data);
    virtual void process(const string &data, int n);
    Output &operator >>(Output & O);
    ~Processor();
protected:
    Output *_output;
};

#endif // PROCESSOR_H
