#include "linekeyboard.h"

LineKeyboard::LineKeyboard()
{

}

LineKeyboard::LineKeyboard(const string &name){
    setName(name);
}

void LineKeyboard::process(){
    string aux, aux2;
    cout << "Introduzca cadena: ";
    cin >> aux;
    for(int i = 0; i < sizeof(aux); i++){
        aux2[i] = aux[i];
        if(aux[i] == '\n'){continue;}
    }
    cout << endl;
    _cpu.process(aux2);
}
