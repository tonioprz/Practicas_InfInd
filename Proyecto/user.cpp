#include "user.h"

User::User()
{

}

User::User(const string &email, const string &password, const string &username, const string &bio)
{
    _email = email;
    _password = password;
    _username = username;
    _bio = bio;
}
