#include "publicuserdata.h"

PublicUserData::PublicUserData()
{

}

PublicUserData::PublicUserData(const string &username, const string &bio)
{
    _username = username;
    _bio = bio;
    _followers = 0;
}

string PublicUserData::getUsername() const
{
    return _username;
}

void PublicUserData::setUsername(const string &username)
{
    _username = username;
}

string PublicUserData::getBio() const
{
    return _bio;
}

void PublicUserData::setBio(const string &bio)
{
    _bio = bio;
}

int PublicUserData::getFollowers() const
{
    return _followers;
}

void PublicUserData::increaseFollowers()
{
    _followers = _followers + 1;
}

void PublicUserData::decreaseFollowers()
{
    if(_followers > 0){
    _followers = _followers - 1;
    }
}

int PublicUserData::getFollowing() const
{
}
