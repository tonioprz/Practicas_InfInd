#include "Manager.h"

Manager::Manager()
{
//Inicializacion vector users
    _currentUser = -1;
    _users[_currentUser] = nullptr;
}

Manager::~Manager(){}

bool Manager::createUser(const string email, const string password, const string username, const string bio)
{
    int aux =  _users.size();

    User *newUser = new User(email, password, username, bio);
    _users.push_back(newUser);

    if(aux < _users.size()){
        return true;
    }
    else{
    return false;
    }
}

vector<PublicUserData*> Manager::showUsers()
{
    vector<PublicUserData*> aux;

    for(int i=0; i < _users.size(); i++){
        aux.push_back(_users[i]);
    }
    return aux;

}

void Manager::showUser(string username)
{

}

bool Manager::login(string email, string password)
{

}

bool Manager::isLogged()
{

}

bool Manager::logout()
{

}

User Manager::getCurrentUser()
{

}

bool Manager::editEmail(string nuevo_email)
{

}

bool Manager::editPassword(string nueva_password)
{

}

bool Manager::editUsername(string nuevo_username)
{

}

bool Manager::editBio(string nueva_bio)
{

}

bool Manager::eraseCurrentUser()
{

}

bool Manager::followUser(const string username)
{

}

bool Manager::unfollowUser(const string username)
{

}


