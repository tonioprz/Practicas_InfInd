#ifndef DEVICE_H
#define DEVICE_H

#include<iostream>
using namespace std;

class Device
{
public:
    Device();
    Device(string const name);
    string getName();
private:
    string _name;
};

#endif // DEVICE_H
