#include "privateuserdata.h"

PrivateUserData::PrivateUserData(){

}

PrivateUserData::PrivateUserData(const std::string &email, const std::string &pass){
    _email = email;
    _password = pass;
}

std::string PrivateUserData::password() const
{
    return _password;
}

void PrivateUserData::setPassword(const std::string &password)
{
    _password = password;
}

std::string PrivateUserData::email() const
{
    return _email;
}

void PrivateUserData::setEmail(const std::string &email)
{
    _email = email;
}
