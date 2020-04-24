#ifndef OUTPUT_H
#define OUTPUT_H
#include"device.h"

class Output : public Device
{
public:
    Output();
    Output(const string & name);
    void process();
};

#endif // OUTPUT_H
