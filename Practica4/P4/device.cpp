#include "device.h"

Device::Device()
{
    _name = " ";
}

Device::Device(string const name){
    _name = name;
}

string Device::getName(){
    return _name;
}
