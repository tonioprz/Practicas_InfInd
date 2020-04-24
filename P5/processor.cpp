#include "processor.h"
#include"display.h"
Processor::Processor()
{
}

Processor::Processor(const string &name){
    setName(name);
}

void Processor::connectTo(Output &O){
    _output = &O;
}

//Output &Processor::operator >>(Output &O)
//{
//    _output = &O;
//    return O;
//}

//void Processor::process(const string &data){
//    string aux = data;
//    int max = data.size();
//    for(int i=0;i<max;i++){
//        aux[i] = data[max-1-i];
//    }
//    _output->process(aux);
//}

//void Processor::process(const string &data, int n){
//    string aux = data;
//    int max = data.size();
//    for(int i=0;i<n;i++){
//        aux[i] = data[n-1-i];
//    }
//    _output->process(aux);
//}
