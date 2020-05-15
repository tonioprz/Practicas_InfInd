#include "User.hpp"

User::User(const string &email, const string &password, const string &username, const string &bio):
    PrivateUserData(email, password),
    PublicUserData(username, bio)
{//Se utilizan los constructores de las clases heredadas, por lo que no necesita nada más
}

User::~User()
{

}

