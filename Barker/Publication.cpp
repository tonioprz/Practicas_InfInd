#include "Publication.hpp"

Publication::~Publication() {}

int Publication::getId()
{
    return _id;
}

unsigned long Publication::getTime()
{
    return _time;
}

PublicUserData *Publication::getUser()
{
    return _user;
}

void Publication::setId(int id)
{
    _id = id;
}

void Publication::setTime(unsigned long time)
{
    _time = time;
}

void Publication::setUser(PublicUserData *user)
{
    _user = user;
}

Publication::Publication(int id, unsigned long time, PublicUserData *user)
{

}

