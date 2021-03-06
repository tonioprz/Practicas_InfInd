#include "Bark.hpp"
#include <ctime>

//Getters and Setters
string Bark::getText()
{
    return _text;
}

void Bark::setText(string bark)
{
    _text = bark;
}

//Constructor parametrizado
Bark::Bark(int id, unsigned long time, PublicUserData* user, string bark):Publication(id, time, user)
{
    _text = bark;
}

char Bark::publicationType()
{
    return 'b';
}

string Bark::getBark()
{
    //Se concatena una string con el formato deseado
    long int tim = _time;
    string tiempo = ctime(&tim);
    tiempo.erase(tiempo.end()-1,tiempo.end());

    return _user->getUsername() + " - " + tiempo + ":\n" + _text;
}

//Destructor
Bark::~Bark(){}

