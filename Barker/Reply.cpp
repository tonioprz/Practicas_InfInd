#include "Reply.hpp"
#include <ctime>


string Reply::getBark()
{
    long int tim = _time;
    string tiempo = ctime(&tim);
    tiempo.erase(tiempo.end()-1,tiempo.end());

    return _user->getUsername() + " replied - " + tiempo + ":\n===\n"
            + _publication->getBark() + "\n===\n" + _text;
}

//Getters and Setters
string Reply::getText()
{
    return _text;
}

void Reply::setText(string reply)
{
    _text = reply;
}

//Constructor parametrizado
Reply::Reply(int id, unsigned long time,Publication *publication,
             PublicUserData *user, string reply):Publication(id, time, user)
{
    _text = reply;
    _publication = publication;
}

char Reply::publicationType()
{
    return 'p';
}

Publication *Reply::getPublication()
{
    return _publication;
}

void Reply::setPublication(Publication *publi)
{
    _publication = publi;
}

Reply::~Reply(){}
