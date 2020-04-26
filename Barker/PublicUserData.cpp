#include "PublicUserData.hpp"

PublicUserData::PublicUserData()
{

}

PublicUserData::~PublicUserData()
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

vector<PublicUserData*> PublicUserData::getFollowing()
{

    return _following;
}

bool PublicUserData::follow(PublicUserData* user)
{
    unsigned int aux = _following.size();
    for(int i=0;i<aux;i++){
        if(_following[i] == user){
            _following.push_back(user);
        }
    }

    if(aux < _following.size()){
        return true;
    }else{
        return false;
    }
}

bool PublicUserData::unfollow(PublicUserData *user)
{
    int aux = _following.size();
    PublicUserData* usuario;
    for(int i=0;i<_following.size();i++){
        if(_following[i] == user){
            _following.erase(_following.begin()+i);
        }
    }
    if(aux > _following.size()){
        return true;
    }else{
        return false;
    }
}
