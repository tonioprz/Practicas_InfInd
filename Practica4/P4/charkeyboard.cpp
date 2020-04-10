#include "charkeyboard.h"

CharKeyboard::CharKeyboard()
{

}

CharKeyboard::CharKeyboard(const string &name){
    setName(name);
}

void CharKeyboard::process(){
    string aux;
    aux = cin.get();
    cout << "Introduzca un carácter: " << aux << endl;
    _cpu.process(aux);
}
