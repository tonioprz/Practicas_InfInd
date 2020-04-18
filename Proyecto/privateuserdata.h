#ifndef PRIVATEUSERDATA_H
#define PRIVATEUSERDATA_H
#include<iostream>

class PrivateUserData
{
public:

    std::string email() const;
    void setEmail(const std::string &email);

    std::string password() const;
    void setPassword(const std::string &password);

private:
    PrivateUserData();
protected:
    PrivateUserData(const std::string &email, const std::string &pass);
    std::string _email;
    std::string _password;
};

#endif // PRIVATEUSERDATA_H
