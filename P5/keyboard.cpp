#include "keyboard.h"
using namespace std;

Keyboard::Keyboard()
{

}

Keyboard::Keyboard(const string &name){
    setName(name);
}

void Keyboard::process(){
    string aux;
    cout << "Introduzca cadena: ";
    cin >> aux;
    cout << endl;
    _cpu->process(aux);
}
