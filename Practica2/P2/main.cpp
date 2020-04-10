#include<iostream>
#include "person.h"

using namespace std;

int main(int argc, char *argv[])
{
    Person p1("Antonio",24); //Uso de constructor parametrizado
    cout << "Primer apartado: " << endl;
    cout << "Nombre: " << p1.getName() << endl << "Edad: " << p1.getAge() << endl << endl;

    cout << "Segundo apartado" << endl;
    Person p2(p1); //Uso de constructor copia
    cout << "Nombre: " << p1.getName() << endl << "Edad: " << p1.getAge() << endl;
    cout << "Nombre: " << p2.getName() << endl << "Edad: " << p2.getAge() << endl << endl;

    cout << "Tercer apartado" << endl;
    Person p3; //Uso de constructor vacío
    cout << "Nombre: " << p3.getName() << endl << "Edad: " << p3.getAge() << endl;
    p3.setName("Jose");
    p3.setAge(30);
    cout << "Nombre: " << p3.getName() << endl << "Edad: " << p3.getAge() << endl;

    cout << "Cuarto apartado" << endl;
    Person p4 = p3;
    cout << "Nombre: " << p4.getName() << endl << "Edad: " << p4.getAge() << endl;

    cout << "Quinto apartado" << endl;
    string name4 = p4.getName();
    for(int i=0;i<sizeof(name4);i++){
        if (name4[i] == 's')
        {
            cout << "Contiene la s: " << name4 << endl;
        }
    }

    if(p4.getAge() > 18){
        cout << "Mayor de 18: " << p4.getName() << endl;
    }
    // Igual para el resto de nombres



    return 0;
}
