#include <iostream>
#include <clocale>

#include "Bark.cpp"
#include "Manager.cpp"
#include "PrivateUserData.cpp"
#include "PublicUserData.cpp"
#include "Publication.cpp"
#include "Rebark.cpp"
#include "Reply.cpp"
#include "User.cpp"

using namespace std;

int main()
{
    int estado = 0; //Estado 0 - Nadie ha iniciado sesion
    char pause;
    Manager manager;
    setlocale(LC_ALL, "es_ES");
    while(1){
        switch(estado){
            case 0:
            {
            std::cout << endl << "Bienvenido a Barker!" << endl;
            cout << "Seleccione la opción que desea realizar:" << endl;
            cout << "1. Registrarse." << endl;
            cout << "2. Iniciar sesion." << endl;
            cout << "3. Mostrar lista de usuarios." << endl;
            cout << "4. Buscar usuario." << endl;
            cout << "5. Cargar archivos." << endl;
            cout << "6. Descargar archivos." << endl;
            cin >>  estado;
            cout << endl << "///////////////////////////////////////////////" << endl;
            }
            break;

            //--------------------------------------------------------

            case 1:
            {
            //Registrarse

            string email, password, username, bio;
            cout << "Por favor, introduzca email:" << endl;
            cin >> email;
            cout << "Por favor, introduzca contraseña:" << endl;
            cin >> password;
            cout << "Por favor, introduzca nombre de usuario:" << endl;
            cin >> username;
            cout << "Por favor, introduzca biografia:" << endl;
            cin >> bio;
            if (manager.createUser(email, password, username, bio)){
                cout << "Registro con exito." << endl;
            }
                else{
                cout << "Registro fallido, intentelo de nuevo." << endl ;
            }
            estado = 0;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 2: // Iniciar sesion
            {
            char pause;
            string email, password;
            cout << endl << "Intruduzca email:" << endl;
            cin >> email;
            cout << "Introduzca contraseña:" << endl;
            cin >> password;
            if (manager.login(email, password)){
                cout << "Inicio de sesion con exito." << endl;
                estado = 7;
            }
                else{
                cout << "Inicio de sesion fallido, intentelo de nuevo." << endl ;
                estado = 0;
            }
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;

            //--------------------------------------------------------

             case 3:  //Lista de usuarios
            {
            char pause;
            vector<PublicUserData*> lista = manager.showUsers();
            cout << endl << "A continuacion se mostrara la lista de usuarios: " << endl;
                for(unsigned int i=0; i<lista.size(); i++){
                cout << "Usuario " << i+1 << ": " << lista[i]->getUsername() << endl << "Biografia: " << lista[i]->getBio() << endl;
                cout << "Seguidores: " << lista[i]->getFollowers() << endl << "Seguidos: " << endl;
                    vector<PublicUserData*> seguidos = lista[i]->getFollowing();
                    for (unsigned int j=0; j<seguidos.size(); j++){
                    cout << j+1 << ": " << seguidos[j]->getUsername() << endl;
                }

            }
            estado = 0;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 4: //Buscar informacion publica de un usuario
            {
            string usuario;
            char pause;
            cout << endl << "Introduzca el usuario que desea visualizar:" << endl;
            cin >> usuario;
            PublicUserData* persona = manager.showUser(usuario);
            cout << "Usuario: " << persona->getUsername() << endl;
            cout << "Biografia: " << persona->getBio() << endl;
            cout << "Seguidores: " << persona->getFollowers() <<endl;
                vector<PublicUserData*> seguidos = persona->getFollowing();
                cout << "Seguidos: " << endl;
                for (unsigned int i = 0; i<seguidos.size(); i++){
                cout << i+1 << ": " << seguidos[i]->getUsername() << endl;
                }
            estado = 0;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una techa para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 5: //Cargar archivo usuarios
                    break;

            //--------------------------------------------------------

            case 6: //Guardar archivo usuarios
                    break;

            //--------------------------------------------------------

            case 7: //Menu tras iniciar sesión
            {
            char pause;
            cout << endl << "Bienvenido!"<< endl;
            int menu1;
            cout << "Seleccione la opcion que desea realizar: " << endl;
            cout << "1. Ajustes de usuario." << endl;
            cout << "2. Seguir a un usuario." << endl;
            cout << "3. Dejar de seguir a un usuario." << endl;
            cout << "4. Publicaciones." << endl;
            cout << "5. Cerrar sesion." << endl;
            cin >> menu1;
            if(menu1 == 1){
                estado = 8;
                }
                 else{
                    if(menu1 == 2){
                         estado = 9;
                     }
                    else {
                        if(menu1 == 3){
                             estado = 10;
                         }
                        else {
                            if(menu1 == 4){
                                estado = 11;
                            }
                            else {
                                 if(menu1 == 5){
                                    estado = 12;
                                 }
                                  else {
                                         cout << "Valor introducido no valido, intentelo de nuevo." << endl;
                                         cout << endl << "///////////////////////////////////////////////" << endl;
                                         cout << "Pulse una techa para continuar" << endl;
                                         cout << endl << "///////////////////////////////////////////////" << endl;
                                         cin >> pause;
                                            estado = 7;
                                      }
                            }
                        }
                    }
                }
            }
            break;

            //--------------------------------------------------------

            case 8: //Menu Ajustes de usuario
            {
            char pause;
            int menu2;
            cout << endl << "Seleccione la opcion que desea realizar: " << endl;
            cout << "1. Informacion de usuario." << endl;
            cout << "2. Darse de baja." << endl;
            cout << "3. Modificar email." << endl;
            cout << "4. Modificar contraseña." << endl;
            cout << "5. Modificar usuario." << endl;
            cout << "6. Modificar biografia." << endl;
            cout << "7. Volver atras." << endl;
            cin >> menu2;
            if(menu2 == 1){
                estado = 13;
                }
                else{
                    if(menu2 == 2){
                         estado = 14;
                    }
                    else{
                         if(menu2 == 3){
                             estado = 15;
                        }
                         else{
                            if(menu2 == 4){
                                estado = 16;
                            }
                            else{
                                if(menu2 == 5){
                                     estado = 17;
                                 }
                                else{
                                    if(menu2 == 6){
                                         estado = 18;
                                    }
                                    else{
                                        if(menu2 == 7){
                                            estado = 7;
                                         }
                                         else {
                                            cout << "Valor introducido no valido, intentelo de nuevo." << endl;
                                            cout << endl << "///////////////////////////////////////////////" << endl;
                                            cout << "Pulse una techa para continuar" << endl;
                                            cout << endl << "///////////////////////////////////////////////" << endl;
                                            cin >> pause;
                                            estado = 8;
                                            }
                                    }
                               }
                         }
                   }
                }
            }
            }
            break;

            //--------------------------------------------------------

            case 9: //seguir un usuario
            {
            char pause;
            string persona;
            cout << endl << "Introduzca el usuario que desea seguir: " << endl;
            cin >> 	persona;
                if (manager.followUser(persona)){
                cout << "Has seguido a " << persona << endl;
                }
                    else {
                    cout << "No se ha podido seguir a " << persona << endl;
                    }
            estado = 7;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl <<"(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 10: //Dejar de seguir un usuario
            {
            char pause;
            string persona;
            cout << endl << "Introduzca el usuario que desea dejar de seguir: " << endl;
            cin >> 	persona;
                if (manager.unfollowUser(persona)){
                cout << "Has dejado de seguir a " << persona << endl;
                }
                    else {
                    cout << "No se ha podido dejar de seguir a " << persona << endl;
                    }
            estado = 7;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
                cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 11: //Menu publicaciones
            {
            int menu3;
            cout << endl << "Seleccione la opcion que desea realizar: " << endl;
            cout << "1. Visualizar publicaciones de un usuario." << endl;
            cout << "2. Visualizar publicaciones de amigos." << endl;
            cout << "3. Añadir publicacion" << endl;
            cout << "4. Eliminar publicacion." << endl;
            cout << "5. Volver atras." << endl;
            cin >> menu3;
            if(menu3 == 1){
                estado = 19;
                }
                else{
                if(menu3 == 2){
                estado = 20;
                }
                    else{
                     if(menu3 == 3){
                     estado = 21;
                     }
                        else{
                        if(menu3 == 4){
                        estado = 22;
                        }
                            else{
                            if(menu3 == 5){
                             estado = 8;
                             }
                                 else {
                                 cout << "Valor introducido no valido, intentelo de nuevo." << endl;
                                 cout << endl << "///////////////////////////////////////////////" << endl;
                                 cout << endl << "(Pulse una tecla para continuar)" << endl;
                                 cout << endl << "///////////////////////////////////////////////" << endl;
                                 cin >> pause;
                                 estado = 11;
                                 }
                             }
                        }

                     }

                }
            }
            break;

            //--------------------------------------------------------

            case 12: //Cerrar sesion
            {
            char pause;
                if(manager.logout()){
                cout << endl << "Cerrado de sesion correcto" << endl;
                estado = 0;
                }
                    else{
                    cout << "No se ha podido cerrar sesion" << endl;
                    estado = 7;
                    }
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 13: // Informacion del usuario
            {
            char pause;
            User* persona = manager.getCurrentUser();
            cout << endl << "Informacion publica: " << endl;
            cout << "Usuario: " << persona->getUsername() << endl;
            cout << "Biografia: " << persona->getBio() << endl;
            cout << "Seguidores: " << persona->getFollowers() <<endl;
                vector<PublicUserData*> seguidos = persona->getFollowing();
                cout << "Seguidos: " << endl;
                for (unsigned int i = 0; i<seguidos.size(); i++){
                cout << i+1 << ": " << seguidos[i]->getUsername() << endl;
                }
            cout << "Informacion oculta: " << endl;
            cout << "Email: " << persona->getEmail() << endl;
            cout << "Constraseña: " << persona->getPassword() << endl;
            estado = 8;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
                cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 14: //Darse de baja
            {
            char pause;
            char respuesta;
            cout << endl << "¿Desea eliminar su usuario? s/n" << endl;
            cin >> respuesta;
                if ('s' == respuesta){
                    if(manager.eraseCurrentUser()){
                    cout << "Usuario eliminado" << endl;
                    estado = 0;
                    }
                        else{
                        cout << "Error al eliminar el usuario" << endl;
                        estado = 8;
                        }
                }
                    else{
                    cout << "Volviendo a ajustes de usuario" << endl;
                    estado = 8;
                        }
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 15: //Modificar email
            {
            char pause;
            string nuevo;
            cout << endl << "Introduzca el nuevo email: " << endl;
            cin >> nuevo;
                if(manager.editEmail(nuevo)){
                cout << "Email modificado" << endl;
                }
                    else{
                    cout << "Email no modificado" << endl;
                    }
            estado = 8;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
                cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 16: //Modificar contraseña
            {
            char pause;
            string nuevo;
            cout << endl << "Introduzca el nueva contraseña: " << endl;
            cin >> nuevo;
                if(manager.editPassword(nuevo)){
                cout << "Contraseña modificada" << endl;
                }
                    else{
                    cout << "Contraseña no modificada" << endl;
                    }
            estado = 8;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una techa para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
                cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 17: //Modificar usuario
            {
            char pause;
            string nuevo;
            cout << endl << "Introduzca el nuevo nombre de usuario: " << endl;
            cin >> nuevo;
                if(manager.editUsername(nuevo)){
                cout << "Nombre de usuario modificado" << endl;
                }
                    else{
                    cout << "Nombre de usuario no modificado" << endl;
                    }
            estado = 8;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una techa para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
                cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 18: //Modificar biografia
            {
            char pause;
            string nuevo;
            cout << endl << "Introduzca la nueva biografia: " << endl;
            cin >> nuevo;
                if(manager.editBio(nuevo)){
                cout << "Biografia modificada" << endl;
                }
                    else{
                    cout << "Biografia no modificada" << endl;
                    }
            estado = 8;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una techa para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
                cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 19: //Visualizar publicaciones de un usuario
            {
            char pause;
            string persona;
            cout << endl << "Introduce el usuario:" << endl;
            cin >> persona;
            cout << "Publicaciones de " << persona << ": " << endl;
            vector<Publication*> publi = manager.getUserFeed(persona);
                for (unsigned int i=0; i<publi.size();i++){
                cout << publi[i]->getBark()<< endl;
                cout << "--------------------------" << endl;
                }
            estado = 11;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una techa para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
                cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 20: //Visualizar publicaciones de amigos
            {
            char pause;
            vector<Publication*> publi = manager.getTimeline();
            cout << endl << "Publicaciones: " << endl;
                for (unsigned int i=0; i<publi.size();i++){
                    cout << publi[i]->getBark() << endl;
                    cout << "--------------------------" << endl;
                }
            estado = 11;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
                cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 21: {// Menu añadir publicacion
            int menu4;
            cout << endl <<"Indique que tipo de publicacion deseas realizar: " << endl;
            cout << "1. Bark. " << endl;
            cout << "2. Rebark. " << endl;
            cout << "3. Reply. " << endl;
            cout << "4. Atras. " << endl;
            cin >> menu4;
                if(menu4 == 1){
                    estado = 23;
                    }
                    else{
                        if(menu4 == 2){
                            estado = 24;
                            }
                            else{
                                if(menu4 == 3){
                                    estado = 25;
                                    }
                                    else{
                                        if(menu4 == 4){
                                            estado =11;
                                            }
                                            else{cout << "Valor introducido no valido, intentelo de nuevo." << endl;
                                                cout << endl << "///////////////////////////////////////////////" << endl;
                                                cout << endl << "(Pulse una techa para continuar)" << endl;
                                                cout << endl << "///////////////////////////////////////////////" << endl;
                                                cin >> pause;
                                                estado = 21;
                                        }
                                    }
                                }
                    }

           }
            break;

            //--------------------------------------------------------

            case 22: {// Eliminar publicacion
            User* usuarioConectado = manager.getCurrentUser();
            vector<Publication*> publicaciones = usuarioConectado->getPublications();
            int id;
            cout << endl << "Introduce id de la publicacion que desea borrar:" << endl;
            cin >> id;
            for(unsigned int i =0; i<publicaciones.size(); i++){
                if (id == publicaciones[i]->getId()){
                    if(usuarioConectado->removePublication(id)){
                        cout << "Publicacion borrada con exito." << endl;

                    }
                    else{
                        cout << "La publicacion no se pudo borrar." << endl;

                    }
                }
            }
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una techa para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            estado = 21;
            }
            break;

            //--------------------------------------------------------

            case 23: { //Crear Bark
            string bark;
            cout << endl << "Introduzca bark: " << endl;
            cin >> bark;
            if(manager.createBark(bark)){
                cout << "Bark creado." << endl;
            }
            else{
                cout << "No se ha creado el Bark." << endl;
            }
            estado = 21;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una techa para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 24: { //Crear Rebark
            string rebark;
            int referencia;
            cout << endl << "Introduzca publicacion de referencia: " << endl;
            cin >> referencia;
            cout << "Introduzca rebark: " << endl;
            cin >> rebark;
            if(manager.createRebark(referencia, rebark)){
                cout << "Rebark creado." << endl;
            }
            else{
                cout << "No se ha creado el Rebark." << endl;
            }
            estado = 21;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una tecla para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;

            //--------------------------------------------------------

            case 25: { //Crear Replay
            string reply;
            int referencia;
            cout << endl << "Introduzca publicacion de referencia: " << endl;
            cin >> referencia;
            cout << "Introduzca reply: " << endl;
            cin >> reply;
            if(manager.createRebark(referencia, reply)){
                cout << "Reply creado." << endl;
            }
            else{
                cout << "No se ha creado el Reply." << endl;
            }
            estado = 21;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cout << endl << "(Pulse una techa para continuar)" << endl;
            cout << endl << "///////////////////////////////////////////////" << endl;
            cin >> pause;
            }
            break;
        }
    }
}
