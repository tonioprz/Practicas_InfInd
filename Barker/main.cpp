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
    Manager m;
    m.loadFromFile("test_data.dat");
//    ifstream fs("data.dat");
//    char cadena[128];
//    string linea;
//    fs.getline(cadena, 128);
//    linea = cadena;
//    cout << linea;
}
