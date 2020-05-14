#include "Rebark.hpp"

//Rebark::Rebark() {}

string Rebark::getBark()
{
    return _user->getUsername() + " rebarked - " + to_string(_time) + ":\n" + _text
            + "\n***\n" + _publication->getBark() + "\n***";
}

//Getters and Setters
string Rebark::getText()
{
    return _text;
}

void Rebark::setText(string rebark)
{
    _text = rebark;
}

Publication *Rebark::getPublication()
{
    return _publication;
}

void Rebark::setPublication(Publication *publi)
{
    _publication = publi;
}

//Constructor parametrizado
Rebark::Rebark(int id, unsigned long time, Publication *publication,
               PublicUserData *user, string rebark):Publication(id, time, user)
{
    _text = rebark;
    _publication = publication;
}

char Rebark::publicationType()
{
    return 'r';
}

Rebark::~Rebark(){} //Destructor
