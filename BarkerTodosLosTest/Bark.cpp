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
    //La función to_string sirve para convertir de formato int a string

    return _user->getUsername() + " - " + to_string(_time) + ":\n" + _text;
}

//Destructor
Bark::~Bark(){}

