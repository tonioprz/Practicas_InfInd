#include <iostream>

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
    while(1){
        switch(estado){
            case 0:
            {
            std::cout << "Bienvenido a Barker!" << endl;
            cout << "Seleccione la opción que desea realizar:" << endl;
            cout << "1. Registrarse." << endl;
            cout << "2. Iniciar sesion." << endl;
            cout << "3. Mostrar lista de usuarios." << endl;
            cout << "4. Buscar usuario." << endl;
            cin >>  estado;
            }break;

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
            cout << "Pulse una techa para continuar" << endl;
            cin >> pause;
            }break;

            case 2:
            {
            // Iniciar sesion
            string email, password;
            cout << "Intruduzca email:" << endl;
            cin >> email;
            cout << "Introduzca contraseña:" << endl;
            cin >> password;
            if (manager.login(email, password)){
                cout << "Inicio de sesion con exito." << endl;
                estado = 3;
            }
                else{
                cout << "Inicio de sesion fallido, intentelo de nuevo." << endl ;
            }
            estado = 0;
            }break;
        }
    }
}
