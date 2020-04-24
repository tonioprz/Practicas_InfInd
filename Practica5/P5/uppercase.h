#ifndef UPPERCASE_H
#define UPPERCASE_H
#include"processor.h"
#include<iostream>
using namespace std;

class Uppercase : public Processor
{
public:
    Uppercase();
    Uppercase(const string & name);
    void process(const string &data);
    void process(const string &data, int n);
    ~Uppercase();
};

#endif // UPPERCASE_H
