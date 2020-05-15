#ifndef USER_H
#define USER_H
#include "PublicUserData.hpp"
#include "PrivateUserData.hpp"
#include<iostream>
using namespace std;

class User : public PrivateUserData , public PublicUserData
{ //Esta clase simplemente hereda los datos de los anteriores
private:

public:
    //Cuenta con el constructor, que utiliza los constructores heredados
    User(const string &email, const string &password, const string &username, const string &bio);
    ~User();//Destructor de la clase
};

#endif // USER_H
