#include "PrivateUserData.hpp"

PrivateUserData::PrivateUserData(){ //Constructor por defecto (privado)
}

PrivateUserData::~PrivateUserData(){} //Destructor

PrivateUserData::PrivateUserData(const string &email, const string &pass){//Constructor parametrizado
    _email = email;
    _password = pass;
}

//A continuación getters y setters:
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
