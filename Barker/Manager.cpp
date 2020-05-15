#include "Manager.hpp"

Manager::Manager() //Constructor de Manager
{
    //Cuando no hay ningún usuario logeado, la variable _currentUser vale -1
    _currentUser = -1;
    _idultimo = 0;
}

Manager::~Manager(){ //Destructor de Manager
    User* aux; //Variable auxiliar tipo puntero a User
    for(int i=0; i < _users.size(); i++){ //Se recorre el vector de todos los usuarios
        aux = _users[i]; //Se asigna a la variable auxiliar
        _users.erase(_users.begin()+i); //Se borra del vector
        delete aux; //Se elimina el contenido del puntero
    }
}

bool Manager::createUser(const string email, const string password, const string username, const string bio)
{
    unsigned int aux =  _users.size(); //Tamaño del vector de usuarios
    User* newUser = new User(email, password, username, bio); //Creamos el nuevo usuario y obtenemos su puntero

    if(_users.size() == 0){ //Si no hay ningún usuario en el vector, se añade
        _users.push_back(newUser);
        return true;
    } else{ //De lo contrario, se comprueba si ya existe otro usuario con el mismo email
        for(int i=0; i < _users.size(); i++){
            if(newUser->getEmail() == _users[i]->getEmail()){
                return false; //Ya está registrado ese email, se devuelve false
            }
        }
        _users.push_back(newUser);
    }

    if(aux < _users.size()){ //Si ha aumentado el tamaño, devuelve true, sino false
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

    for(unsigned int i=0; i < _users.size(); i++){//Se recorre el vector _users
        aux = _users[i];
        vectorPUD.push_back(aux); //Se añade cada User a un vector auxiliar
    }
    return vectorPUD; //Se devuelve este vector
}

PublicUserData* Manager::showUser(string username)
{
    PublicUserData* aux = nullptr;
    //Caso idéntico al anterior, simplemente se busca el usuario en concreto y se devuelve
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

    if(isLogged()){ //Se comprueba si ya hay un usuario logeado
        return false;
    }

    for(unsigned int i=0; i < _users.size(); i++){
        if(email == _users[i]->getEmail()){ //Se comprueba el email
            usuario = _users[i];
            if(usuario->getPassword() == password){//Se comprueba la contraseña
                _currentUser = i; //Se actualiza el usuario actual
                return true; //Se devuelve el correcto
            }else{
                return false;//Si no es correcto, se devuelve falso
                }
            }
        }
    return false; //Si no se ha actualizado _currentUser, se devuelve false
}

bool Manager::isLogged()
{
    if(_currentUser != -1){ //Se comprueba que _currentUser sea -1
        return true;
    } else{
        return false;
    }
}

bool Manager::logout()
{
    if(!isLogged()){//Se comprueba que hay un usuario logeado
        return false;
    }

    _currentUser = -1;//Se coloca el valor a -1 para indicar que no hay ningún usuario logeado

    if(_currentUser == -1){
        return true;
    }else{
        return false;
    }
}

User* Manager::getCurrentUser()
{
    User* aux;
    if(isLogged()){//Se comprueba que haya un usuario logeado
        aux = _users[_currentUser]; //Se obtiene dicho usuario
    }else{
        aux = nullptr;
    }
    return aux; //Se devuelve dicho usuario
}

bool Manager::editEmail(string nuevo_email)
{
    if(!isLogged()){//Se comprueba que haya un usuario logeado
        return false;
    }
    //Se comprueba que el email sea distinto al actual o no esté ya registrado
    for(int i=0; i < _users.size(); i++){
        if(_users[i]->getEmail() == nuevo_email){
            return false;
        }
    }
    _users[_currentUser]->setEmail(nuevo_email); //Se actualiza el email
}

bool Manager::editPassword(string nueva_password)
{
    if(!isLogged()){//Se comprueba que haya un usuario logeado
        return false;
    }
    string password = _users[_currentUser]->getPassword();
    _users[_currentUser]->setPassword(nueva_password);//Se actualiza la password
    if(nueva_password != password){//Se comprueba que sea distinta a la anterior
        return true;
    }else{
        return false;
    }
}

bool Manager::editUsername(string nuevo_username)
{
    if(!isLogged()){//Se comprueba que haya un usuario logeado
        return false;
    }

    for(int i=0; i < _users.size(); i++){//Se comprueba que el username no esté ya en la lista
        if(_users[i]->getUsername() == nuevo_username){
            return false;
        }
    }

    _users[_currentUser]->setUsername(nuevo_username); //Se actualiza el username
    return true;
}

bool Manager::editBio(string nueva_bio)
{
    if(!isLogged()){//Se comprueba que haya un usuario logeado
        return false;
    }

    string bio = _users[_currentUser]->getBio();
    _users[_currentUser]->setBio(nueva_bio); //Se actualiza la bio

    if(nueva_bio != bio){ //Se comprueba que no sea igual a la anterior
        return true;
    }else{
        return false;
    }
}

bool Manager::eraseCurrentUser()
{
    if(!isLogged()){//Se comprueba que haya un usuario logeado
        return false;
    }

    User* aux = _users[_currentUser]; //Se guarda el usuario a borrar
    _users.erase(_users.begin()+_currentUser); //Se quita del vector _users
    delete aux; //Se borra el puntero
    logout(); //Se hace logout
    return true;
}

bool Manager::followUser(const string username)
{
    if(!isLogged()){//Se comprueba que haya un usuario logeado
        return false;
    }

    if(_users[_currentUser]->getUsername() == username){ //Se comprueba que no sea el propio usuario
        return false;
    }

    //Se guarda un vector a punteros de usuarios ya seguidos
    vector<PublicUserData*> yaseguidos = _users[_currentUser]->getFollowing();
    for(int i=0; i< yaseguidos.size();i++){//Se busca ese usuario en nuestra lista de seguidos
        if(yaseguidos[i]->getUsername() == username){
            return false;//Se devuelve error si ya está seguido
        }
    }

    //Se busca el usuario a seguir
    PublicUserData* aseguir = nullptr;
    for(int i=0; i < _users.size(); i++){
        if(_users[i]->getUsername() == username){
            aseguir = _users[i];
        }
    }

    //Si hemos obtenido un puntero de un usuario, lo seguimos con la función follow()
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
    if(!isLogged()){//Se comprueba que haya un usuario logeado
        return false;
    }

    if(_users[_currentUser]->getUsername() == username){ //Se comprueba que no sea el propio usuario
        return false;
    }

    //Se guarda un vector a punteros de usuarios ya seguidos
    vector<PublicUserData*> yaseguidos = _users[_currentUser]->getFollowing();

    //Se busca el usuario en la lista de seguidos
    for(int i=0; i < yaseguidos.size(); i++){
        if(yaseguidos[i]->getUsername() == username){
            _users[_currentUser]->unfollow(yaseguidos[i]);
            return true;//Se da unfollow() y se devuelve true
        }
    }

    //Si no se ha conseguido hacer unfollow en el bucle anterior, se devuelve false;
    return false;
}

vector<Publication *> Manager::getUserFeed(string user)
{
    for(int i = 0; i < _users.size(); i++){
        if(_users[i]->getUsername() == user){
            return _users[i]->getPublications();
        }
    }

}

vector<Publication*> Manager::getTimeline()
{
    if(!isLogged()){
        vector<Publication*> vacio;
        return vacio;
    }
    vector<PublicUserData*> seguidos = _users[_currentUser]->getFollowing();

    vector<Publication*> timeline;
    vector<Publication*> aux;


    for(int i = 0; i < seguidos.size(); i++){
        aux = seguidos[i]->getPublications();
        for(int j=0; j < aux.size(); j++){
            timeline.push_back(aux[j]);
        }
    }
    return timeline;
}

bool Manager::createBark(string text)
{
    if(!isLogged()){//Se comprueba que haya un usuario logeado
        return false;
    }
    unsigned long int tiempo = time(nullptr);
    _idultimo++;
    Bark* bark = new Bark(_idultimo, tiempo, _users[_currentUser], text);

    _users[_currentUser]->addPublication(bark);
    return true;
}

bool Manager::createRebark(int id, string text)
{
    if(!isLogged()){//Se comprueba que haya un usuario logeado
                return false;
    }
    unsigned long int tiempo = time(nullptr);
    vector<Publication*> aux;
    Publication* publi;
    for(unsigned int i=0; i<_users.size(); i++){
        aux = _users[i]->getPublications();
        for(unsigned int j=0; j<aux.size(); j++){
            if(aux[i]->getId() == id){
                publi = aux[i];
            }
        }
    }

    if(publi == nullptr){
        return false;
    }

    _idultimo++;
    Rebark* rebark = new Rebark(_idultimo, tiempo, publi,_users[_currentUser], text);

    _users[_currentUser]->addPublication(rebark);
    return true;
}

bool Manager::createReply(int id, string text)
{
    if(!isLogged()){//Se comprueba que haya un usuario logeado
                return false;
    }
    unsigned long int tiempo = time(nullptr);
    vector<Publication*> aux;
    Publication* publi;
    for(unsigned int i=0; i<_users.size(); i++){
        aux = _users[i]->getPublications();
        for(unsigned int j=0; j<aux.size(); j++){
            if(aux[j]->getId() == id){
                publi = aux[j];
            }
        }
    }

    if(publi == nullptr){
        return false;
    }

    _idultimo++;
    Reply* reply = new Reply(_idultimo, tiempo, publi,_users[_currentUser], text);

    _users[_currentUser]->addPublication(reply);
    return true;
}

bool Manager::saveToFile(string archivo)
{
   ofstream fs(archivo);

   //Se comprueba si se ha abierto correctamente el archivo
   if(fs.bad()){
       cout << "Error al abrir el archivo";
       return false;
   }
   fs << "Fichero de usuarios y publicaciones de Baker" << endl;

   //Se guardan los usuarios
   for(int i=0; i < _users.size(); i++){

       fs << "#" << endl; // Inicio de usuario

       // Se añaden los datos del usuario:
       fs << _users[i]->getEmail() << endl;
       fs << _users[i]->getPassword() << endl;
       fs << _users[i]->getUsername() << endl;
       fs << _users[i]->getBio() << endl;
       fs << _users[i]->getFollowers() << endl;

       // Se añade el username de los usuarios seguidos tras following"
       fs << "following:" << endl;
       vector<PublicUserData*> s = _users[i]->getFollowing();
       for(int j=0; j < s.size(); j++){
           fs << s[j]->getUsername() << endl;
       }

       // Se añade el id de cada publicación
       fs << "publications:" << endl;
       vector<Publication*> p = _users[i]->getPublications();
       for(int j=0; j < p.size(); j++){
           fs << p[j]->getId() << endl;
       }

       fs << "#" << endl; // Fin del usuario
   }

   // Se guardan las publicaciones
   for(int i=0; i < _users.size(); i++){
       vector<Publication*> p = _users[i]->getPublications();
       for(int j=0; j < p.size(); j++){
           //Se comprueba primero el tipo de publicacion
           char tipo = p[j]->publicationType();
           if(tipo == 'b'){
               fs << "$Bark" << endl;
           }
           if(tipo == 'r'){
               fs << "$Rebark" << endl;
           }
           if(tipo == 'p'){
               fs << "$Reply" << endl;
           }
           fs << p[j]->getId() << endl;
           fs << p[j]->getTime() << endl;
           if(tipo == 'r'){
               // Usaremos static_cast para acceder a la información del Rebark
                fs << (static_cast<Rebark*>(p[j])->getPublication())->getId() << endl;
                fs << (p[j]->getUser())->getUsername() << endl;
                fs << static_cast<Rebark*>(p[j])->getText() << endl;
           }
           if(tipo == 'p'){
               // Usaremos static_cast para acceder a la información del Rebark
                fs << (static_cast<Reply*>(p[j])->getPublication())->getId() << endl;
                fs << (p[j]->getUser())->getUsername() << endl;
                fs << static_cast<Reply*>(p[j])->getText() << endl;
           }
           if(tipo == 'b'){
               fs << (p[j]->getUser())->getUsername() << endl;
               fs << static_cast<Bark*>(p[j])->getText() << endl;
           }
       }
   }
   fs.close();
   return true;
}

bool Manager::loadFromFile(string archivo)
{
    // En primer lugar, borramos la base de datos existente para evitar coincidencias
    // Primero borramos las publicaciones:
    for(int i = 0; i < _users.size(); i++){
        vector<Publication*> p = _users[i]->getPublications();
        Publication* pub;
        for(int j = 0; j < p.size(); j++){
            pub = p[j];
            _users[i]->removePublication(p[j]->getId());
            delete pub;
        }
    }

    // Luego se borra el vector de usuarios:
    User* aux; //Variable auxiliar tipo puntero a User
    for(int i=0; i < _users.size(); i++){ //Se recorre el vector de todos los usuarios
        aux = _users[i]; //Se asigna a la variable auxiliar
        _users.erase(_users.begin()+i); //Se borra del vector
        delete aux; //Se elimina el contenido del puntero
    }

    ifstream fs(archivo);

    //Se comprueba si se ha abierto correctamente el archivo
    if(fs.bad()){
        cout << "Error al abrir el archivo";
        return false;
    }

    //Introducimos una serie de variables que serán útiles de cara a la lectura del archivo
    char cadena[128];
    string linea;
    string email;
    string password;
    string username;
    string bio;
    vector<vector<string>> followingtotal;
    vector<vector<string>> idpubstotal;
    int usuario = 0;
    bool finusers = false;
    string id;
    string time;
    string idref;
    string userpub;
    string text;
    Publication* pub;


    while(!fs.eof()){
        fs >> cadena;
        linea = cadena;
        if(linea == "#") //Es un usuario
        {// Obtenemos sus datos
            fs >> cadena;
            email = cadena;
            fs >> cadena;
            password = cadena;
            fs >> cadena;
            username = cadena;
            fs.getline(cadena, 128);
            fs.getline(cadena, 128);
            bio = cadena;
            createUser(email,password,username,bio);
            fs >> cadena; //numero de followers (innecesario)
            fs >> cadena; //following
            linea = cadena;
            vector<string> following;
            vector<string> idpubs;
            //Mientras la siguiente línea no sea publications: serán nuevos usuarios seguidos
            while(linea != "publications:"){
                fs >> cadena;
                linea = cadena;
                if(linea != "publications:") {following.push_back(linea);}
            }
            //A continuación tendremos los ids de las publicaciones hasta que aparezca un #
            while(linea != "#"){
                fs >> cadena;
                linea = cadena;
                if(linea != "#") {idpubs.push_back(linea);}
            }
            followingtotal.push_back(following);
            idpubstotal.push_back(idpubs);
            usuario++;
        }

        // Cuando aparece el primer $ significa que no habrá más usuarios
        // Por lo tanto, comenzaremos a seguir los unos a los otros
        if((linea.compare(0,1, "$") == 0) && !finusers){
            finusers = true;
            for(int i=0; i < _users.size(); i++){ // Para cada usuario
                for(int j=0; j < followingtotal[i].size(); j++){ // Cada username seguido
                    string user = followingtotal[i][j];
                    for(int k=0; k < _users.size(); k++){ // Buscamos la PUD de ese username
                        if(_users[k]->getUsername() == user){
                            _users[i]->follow(_users[k]);
                        }
                    }
                }
            }
        }

        if(linea == "$Bark"){
            //Cargamos los datos del Bark
            getline(fs, id);
            getline(fs, time);
            getline(fs, userpub);
            getline(fs, text);
            //Buscamos al usuario
            for(int i=0; i < _users.size(); i++){
                if(_users[i]->getUsername() == userpub){
                    // Añadimos el Bark
                    Bark* b = new Bark(stoi(id), stol(time),_users[i],text);
                    _users[i]->addPublication(b);
                }
            }
        }

        if(linea == "$Rebark"){
            //Cargamos los datos del Rebark
            getline(fs, id);
            getline(fs, time);
            getline(fs, idref);
            getline(fs, userpub);
            getline(fs, text);
            //Buscamos la publicación a la que hace referencia
            for(int i=0; i < _users.size(); i++){
                vector<Publication*> pubs = _users[i]->getPublications();
                for(int j=0; j < pubs.size(); j++){
                    if(pubs[j]->getId() == stoi(idref)){
                        pub = pubs[j];
                    }
                }
            }
            //Buscamos al usuario
            for(int i=0; i < _users.size(); i++){
                if(_users[i]->getUsername() == userpub){
                    Rebark* b = new Rebark(stoi(id), stol(time),pub,_users[i],text);
                    _users[i]->addPublication(b);
                }
            }
        }

        if(linea == "$Reply"){
            //Cargamos los datos del Reply
            getline(fs, id);
            getline(fs, time);
            getline(fs, idref);
            getline(fs, userpub);
            getline(fs, text);
            //Buscamos la publicación a la que hace referencia
            for(int i=0; i < _users.size(); i++){
                vector<Publication*> pubs = _users[i]->getPublications();
                for(int j=0; j < pubs.size(); j++){
                    if(pubs[j]->getId() == stoi(idref)){
                        pub = pubs[j];
                    }
                }
            }
            //Buscamos al usuario
            for(int i=0; i < _users.size(); i++){
                if(_users[i]->getUsername() == userpub){
                    Reply* b = new Reply(stoi(id), stol(time),pub,_users[i],text);
                    _users[i]->addPublication(b);
                }
            }
        }
    }
    fs.close();
    return true;
}
