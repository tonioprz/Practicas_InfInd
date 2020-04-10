#ifndef DISPLAY_H
#define DISPLAY_H
#include"device.h"

class Display : public Device
{
public:
    Display();
    Display(const string &name);
    void process(const string &data);
};

#endif // DISPLAY_H
