#include "Manager.hpp"

Manager::Manager()
{
    _currentUser = -1;
}

Manager::~Manager(){
    User* aux;
    for(int i=0; i < _users.size(); i++){
        aux = _users[i];
        _users.erase(_users.begin()+i);
        delete aux;
    }
}

bool Manager::createUser(const string email, const string password, const string username, const string bio)
{
    unsigned int aux =  _users.size();
    User* newUser = new User(email, password, username, bio);

    if(_users.size() == 0){
        _users.push_back(newUser);
        return true;
    } else{
        for(int i=0; i < _users.size(); i++){
            if(newUser->getEmail() == _users[i]->getEmail()){
                return false;
            }
        }
        _users.push_back(newUser);
    }

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

    if(isLogged()){
        return false;
    }

    for(unsigned int i=0; i < _users.size(); i++){
        if(email == _users[i]->getEmail()){
            usuario = _users[i];
            if(usuario->getPassword() == password){
                _currentUser = i;
                return true;
            }else{
                return false;
                }
            }
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
    if(!isLogged()){
        return false;
    }

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
    if(!isLogged()){
        return false;
    }

    for(int i=0; i < _users.size(); i++){
        if(_users[i]->getEmail() == nuevo_email){
            return false;
        }
    }
    _users[_currentUser]->setEmail(nuevo_email);
}

bool Manager::editPassword(string nueva_password)
{
    if(!isLogged()){
        return false;
    }
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
    if(!isLogged()){
        return false;
    }

    for(int i=0; i < _users.size(); i++){
        if(_users[i]->getUsername() == nuevo_username){
            return false;
        }
    }
    _users[_currentUser]->setUsername(nuevo_username);
}

bool Manager::editBio(string nueva_bio)
{
    if(!isLogged()){
        return false;
    }
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
    if(!isLogged()){
        return false;
    }
    User* aux = _users[_currentUser];
    _users.erase(_users.begin()+_currentUser);
    delete aux;
    _currentUser=-1;
    return true;
}

bool Manager::followUser(const string username)
{
    if(!isLogged()){
        return false;
    }

    if(_users[_currentUser]->getUsername() == username){
        return false;
    }

    vector<PublicUserData*> yaseguidos = _users[_currentUser]->getFollowing();
    for(int i=0; i< yaseguidos.size();i++){
        if(yaseguidos[i]->getUsername() == username){
            return false;
        }
    }

    PublicUserData* aseguir = nullptr;
    for(int i=0; i < _users.size(); i++){
        if(_users[i]->getUsername() == username){
            aseguir = _users[i];
        }
    }

    if(aseguir != nullptr){
        _users[_currentUser]->follow(aseguir);
        return true;
    }
    else{
        return false;
    }
}

bool Manager::unfollowUser(const string username)
{
    if(!isLogged()){
        return false;
    }

    if(_users[_currentUser]->getUsername() == username){
        return false;
    }


    vector<PublicUserData*> yaseguidos = _users[_currentUser]->getFollowing();

    for(int i=0; i < yaseguidos.size(); i++){
        if(yaseguidos[i]->getUsername() == username){
            _users[_currentUser]->unfollow(yaseguidos[i]);
            return true;
        }
    }


    return false;
}
