#include "Manager.hpp"

Manager::Manager()
{
//Inicializacion vector users
    _currentUser = -1;
}

Manager::~Manager(){
    for(auto it = _users.begin(); it != _users.end(); it++){
        _users.erase(it);
    }
}

bool Manager::createUser(const string email, const string password, const string username, const string bio)
{
    unsigned int aux =  _users.size();

    User* newUser = new User(email, password, username, bio);
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
    vector<PublicUserData*> vectorPUD;
    PublicUserData* aux;

    for(unsigned int i=0; i < _users.size(); i++){
        aux = _users[i];
        vectorPUD.push_back(aux);
    }
    return vectorPUD;
}

PublicUserData* Manager::showUser(string username)
{
    PublicUserData* aux;

    for(unsigned int i=0; i < _users.size(); i++){
        if(username == _users[i]->getUsername()){
            aux = _users[i];
        }
    }
    return aux;
}

bool Manager::login(string email, string password)
{
    User* usuario = nullptr;

    for(unsigned int i=0; i < _users.size(); i++){
        if(email == _users[i]->getEmail()){
            if(i != _currentUser){
            usuario = _users[i];
            if(usuario->getPassword() == password){
                _currentUser = i;
                continue;
                }
            }
        }
    }

    if(usuario != nullptr){
        return true;
    }
    else{
        return false;
    }
}

bool Manager::isLogged()
{
    if(_currentUser != -1){
        return true;
    } else{
        return false;
    }
}

bool Manager::logout()
{
    _currentUser = -1;

    if(_currentUser == -1){
        return true;
    }else{
        return false;
    }
}

User* Manager::getCurrentUser()
{
    User* aux;
    if(_currentUser != -1){
        aux = _users[_currentUser];
    }else{
        aux = nullptr;
    }
    return aux;
}

bool Manager::editEmail(string nuevo_email)
{
    string email = _users[_currentUser]->getEmail();
    _users[_currentUser]->setEmail(nuevo_email);
    if(nuevo_email != email){
        return true;
    }else{
        return false;
    }
}

bool Manager::editPassword(string nueva_password)
{
    string password = _users[_currentUser]->getPassword();
    _users[_currentUser]->setPassword(nueva_password);
    if(nueva_password != password){
        return true;
    }else{
        return false;
    }
}

bool Manager::editUsername(string nuevo_username)
{
    string username = _users[_currentUser]->getUsername();
    _users[_currentUser]->setUsername(nuevo_username);
    if(nuevo_username != username){
        return true;
    }else{
        return false;
    }
}

bool Manager::editBio(string nueva_bio)
{
    string bio = _users[_currentUser]->getBio();
    _users[_currentUser]->setBio(nueva_bio);
    if(nueva_bio != bio){
        return true;
    }else{
        return false;
    }
}

bool Manager::eraseCurrentUser()
{
    User* ptr = _users[_currentUser];
    delete ptr;
    _users.erase(_users.begin()+_currentUser);
}

bool Manager::followUser(const string username)
{

}

bool Manager::unfollowUser(const string username)
{

}


