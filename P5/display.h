#ifndef DISPLAY_H
#define DISPLAY_H
#include"output.h"

class Display : public Output
{
public:
    Display();
    Display(const string &name);
    void process(const string &data);
};

#endif // DISPLAY_H
