#include "User.hpp"

User::User(const string &email, const string &password, const string &username, const string &bio):
    PrivateUserData(email, password),
    PublicUserData(username, bio)
{
}

User::~User()
{

}

User::User()
{

}

