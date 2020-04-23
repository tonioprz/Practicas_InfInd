#include "processor.h"
#include"display.h"
Processor::Processor()
{
}

Processor::Processor(const string &name){
    setName(name);
}

void Processor::connectTo(Display *d){
    _disp = d;
}

void Processor::process(const string &data){
    string aux = data;
    int max = data.size();
    for(int i=0;i<max;i++){
        aux[i] = data[max-1-i];
    }
    _disp->process(aux);
}
