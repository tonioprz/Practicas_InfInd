#include "user.h"


User::User(const string &email, const string &pass, const string &username, const string &bio)
{
    PrivateUserData(email, pass);
    PublicUserData(username, bio);
}

User::User()
{

}
