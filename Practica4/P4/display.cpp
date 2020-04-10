#include "display.h"

Display::Display()
{

}

Display::Display(const string &name){
    setName(name);
}

void Display::process(const string &data){
    cout << data << endl;
}
