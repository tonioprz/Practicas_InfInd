#include "input.h"

Input::Input()
{

}

Input::Input(const string &name)
{
    setName(name);
}

void Input::connecTo(Processor &P)
{
    _processor = &P;
}

Processor& Input::operator >>(Processor &P)
{
    _processor = &P;
    return P;
}

