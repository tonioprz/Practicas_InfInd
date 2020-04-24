#ifndef PRIVATEUSERDATA_H
#define PRIVATEUSERDATA_H
#include<iostream>
using namespace std;
class PrivateUserData
{
private:

protected:
    PrivateUserData();

    PrivateUserData(const string &email, const string &pass);
    string _email;
    string _password;
    ~PrivateUserData();

public:

    string getEmail() const;
    void setEmail(const string &email);

    string getPassword() const;
    void setPassword(const string &password);

};

#endif // PRIVATEUSERDATA_H
