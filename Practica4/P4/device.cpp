#include "device.h"

Device::Device()
{
    _name = " ";
}

Device::Device(string const &name){
    _name = name;
}

const string & Device::getName(){
    return _name;
}

void Device::setName(string const &name){
    _name = name;
}


Device::~Device(){}
