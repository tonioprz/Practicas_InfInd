#include "PublicUserData.hpp"
#include"Publication.hpp"

PublicUserData::PublicUserData()
{//Constructor por defecto (privado)
}

PublicUserData::~PublicUserData()
{//Destructor
}

PublicUserData::PublicUserData(const string &username, const string &bio)
{//Constructor parametrizado
    _username = username;
    _bio = bio;
    _followers = 0; //Inicializamos los followers a 0
}

//Getters y setters:
string PublicUserData::getUsername() const
{
    return _username;
}

void PublicUserData::setUsername(const string &username)
{
    _username = username;
}

string PublicUserData::getBio() const
{
    return _bio;
}
void PublicUserData::setBio(const string &bio)
{
    _bio = bio;
}

int PublicUserData::getFollowers() const
{
    return _followers;
}

//Aumentamos y decrementamos followers
void PublicUserData::increaseFollowers()
{
    _followers = _followers + 1;
}

void PublicUserData::decreaseFollowers()
{
    if(_followers > 0){ //Nos aseguramos que haya al menos un follower
    _followers = _followers - 1;
    }
}

//Devolvemos la lista de seguidos
vector<PublicUserData*> PublicUserData::getFollowing()
{
    return _following;
}

bool PublicUserData::follow(PublicUserData* user)
{//Se comprueba el tamaño del vector de seguidos
    unsigned int aux = _following.size();
    for(int i=0;i<aux;i++){
        if(_following[i] == user){
            return false; //Si ya está seguido, se devuelve error
        }
    }

    _following.push_back(user); //Se añade el usuario a seguir al vector de seguidos
    user->increaseFollowers(); //Aumentamos la cantidad de followers del usuario seguido
    if(aux < _following.size()){//Si aumentamos el tamaño del vector, ha sido exitosa la operación y devuelve true
        return true;
    }else{
        return false;
    }
}

bool PublicUserData::unfollow(PublicUserData *user)
{
    int aux = _following.size();
    for(int i=0;i<_following.size();i++){
        if(_following[i] == user){//Se comprueba que el usuario siga al otro
            _following.erase(_following.begin()+i); //Se elimina de la lista de seguidos
            user->decreaseFollowers(); // Se reduce el número de seguidores del que recibió unfollow
        }

    }
    if(aux > _following.size()){ //Si se decrementa la cantidad de usuarios seguidos, se devuelve true
        return true;
    }else{
        return false;
    }
}

vector<Publication *> PublicUserData::getPublications()
{
    return _publications;
}

bool PublicUserData::addPublication(Publication *publi)
{
    for(int i=0; i < _publications.size(); i++){
        if(publi->getId() == _publications[i]->getId()){
            return false;
        }
    }
    _publications.push_back(publi);
    return true;
}

bool PublicUserData::removePublication(int id)
{
    for(int i=0; i < _publications.size(); i++){
        if(id == _publications[i]->getId()){
            _publications.erase(_publications.begin()+i);
            return true;
        }
    }
    return false;
}
