#include "Publication.hpp"

//Getters and Setters
int Publication::getId()
{return _id;}

void Publication::setId(int id)
{ _id = id;}

unsigned long Publication::getTime()
{return _time;}

void Publication::setTime(unsigned long int time)
{_time = time;}

PublicUserData* Publication::getUser()
{return _user;}

void Publication::setUser(PublicUserData* user)
{_user = user;}

//Destructor
Publication::~Publication(){}

//Constructor parametrizado
Publication::Publication(int id, unsigned long time, PublicUserData* user)
{
    _id = id;
    _time = time;
    _user = user;
}


