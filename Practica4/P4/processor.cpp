#include "processor.h"
#include"display.h"
Processor::Processor()
{
}

Processor::Processor(const string &name){
    setName(name);
}

void Processor::connectTo(Display &d){
    Display _disp = d;
}

void Processor::process(const string &data){
    string aux;
    for(int i=0;i<sizeof(data);i++){
        aux[0] = data[sizeof(data)-i];
    }
    _disp.process(aux);
}
