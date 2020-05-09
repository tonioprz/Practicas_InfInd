#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <vector>
#include "User.hpp"
#include "ctime"
#include "Bark.hpp"
#include "Rebark.hpp"
#include "Reply.hpp"

using namespace std;

class Manager
{
public:
    Manager();
    ~Manager();
    //METODOS SI NO HAY NADIE LOGUEADO
    bool createUser(const string email, const string password, const string username, const string bio);
    vector<PublicUserData*> showUsers();
    PublicUserData* showUser(string username);
    bool login(string email, string password);
    //METODOS SI ALGUIEN ESTA LOGUEADO
    bool isLogged();
    bool logout();
    User* getCurrentUser();
    bool editEmail(string nuevo_email);
    bool editPassword(string nueva_password);
    bool editUsername(string nuevo_username);
    bool editBio(string nueva_bio);
    bool eraseCurrentUser();
    bool followUser(const string username);
    bool unfollowUser(const string username);

    vector<Publication*> getUserFeed(string user);
    vector<Publication*> getTimeline();

    bool createBark(string text);
    bool createRebark(int id, string text);
    bool createReply(int id, string text);

private:
    vector<User*> _users;
    int _currentUser;
    int _idultimo = 0;
};

#endif // MANAGER_H
