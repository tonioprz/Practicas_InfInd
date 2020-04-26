#include "PrivateUserData.h"

PrivateUserData::PrivateUserData(){

}

PrivateUserData::~PrivateUserData(){}

PrivateUserData::PrivateUserData(const string &email, const string &pass){
    _email = email;
    _password = pass;
}

string PrivateUserData::getPassword() const
{
    return _password;
}

void PrivateUserData::setPassword(const string &password)
{
    _password = password;
}

string PrivateUserData::getEmail() const
{
    return _email;
}

void PrivateUserData::setEmail(const string &email)
{
    _email = email;
}
