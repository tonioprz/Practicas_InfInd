#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <vector>
#include "user.h"
using namespace std;

class Manager
{
public:
    Manager();
    ~Manager();
    //METODOS SI NO HAY NADIE LOGUEADO
    bool createUser(const string email, const string password, const string username, const string bio);
    vector<PublicUserData*> showUsers();
    void showUser(string username);
    bool login(string email, string password);
    //METODOS SI ALGUIEN ESTA LOGUEADO
    bool isLogged();
    bool logout();
    User getCurrentUser();
    bool editEmail(string nuevo_email);
    bool editPassword(string nueva_password);
    bool editUsername(string nuevo_username);
    bool editBio(string nueva_bio);
    bool eraseCurrentUser();
    bool followUser(const string username);
    bool unfollowUser(const string username);


private:
    vector<User*> _users;
    int _currentUser;
};

#endif // MANAGER_H
