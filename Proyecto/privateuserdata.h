#ifndef PRIVATEUSERDATA_H
#define PRIVATEUSERDATA_H
#include<iostream>

class PrivateUserData
{
public:
    void setEmail(std::string email);
    std::string getEmail();
    void setPassword(std::string password);
    std::string getPassword();
private:
    PrivateUserData();
protected:
    PrivateUserData(std::string email, std::string pass);
    std::string _email;
    std::string _password;
};

#endif // PRIVATEUSERDATA_H
