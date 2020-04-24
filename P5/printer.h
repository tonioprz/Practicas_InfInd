#ifndef PRINTER_H
#define PRINTER_H
#include"output.h"

class Printer : public Output
{
public:
    Printer();
    Printer(const string & name);
    void process(const string & data);
};

#endif // PRINTER_H
