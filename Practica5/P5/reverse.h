#ifndef REVERSE_H
#define REVERSE_H
#include"processor.h"

class Reverse : public Processor
{
public:
    Reverse();
    Reverse(const string & name);
    void process(const string &data);
    void process(const string &data, int n);
};

#endif // REVERSE_H
