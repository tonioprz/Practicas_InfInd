#include "processor.h"

Processor::Processor()
{
}

Processor::Processor(const string & name){
    setName(name);
}

void Processor::connectTo(Output &O){
    _output = &O;
}

void Processor::process(const string &data)
{

}

void Processor::process(const string &data, int n)
{

}

Output &Processor::operator >>(Output &O)
{
    _output = &O;
    return O;
}
