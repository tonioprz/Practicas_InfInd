#include "privateuserdata.h"

PrivateUserData::PrivateUserData(){

}

PrivateUserData::~PrivateUserData()
{

}

PrivateUserData::PrivateUserData(const string &email, const string &pass){
    _email = email;
    _password = pass;
}

string PrivateUserData::password() const
{
    return _password;
}

void PrivateUserData::setPassword(const string &password)
{
    _password = password;
}

string PrivateUserData::email() const
{
    return _email;
}

void PrivateUserData::setEmail(const string &email)
{
    _email = email;
}
