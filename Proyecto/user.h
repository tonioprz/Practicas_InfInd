#ifndef USER_H
#define USER_H
#include "publicuserdata.h"
#include "privateuserdata.h"
#include<iostream>
using namespace std;

class User : public PrivateUserData , public PublicUserData
{
private:
    User();

public:

    User(const string &email, const string &password, const string &username, const string &bio);
    ~User();
};

#endif // USER_H
