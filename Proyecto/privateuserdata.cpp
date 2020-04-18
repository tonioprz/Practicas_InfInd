#include "privateuserdata.h"

PrivateUserData::PrivateUserData(){

}

PrivateUserData::PrivateUserData(std::string email, std::string pass){
    _email = email;
    _password = pass;
}

void PrivateUserData::setEmail(std::string email){
    _email = email;
}

std::string PrivateUserData::getEmail(){
    return _email;
}

void PrivateUserData::setPassword(std::string password){
    _password = password;
}

std::string PrivateUserData::getPassword(){
    return _password;
}
