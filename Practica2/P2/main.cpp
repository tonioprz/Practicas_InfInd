#include <QCoreApplication>
#include<iostream>
#include "person.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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



    return a.exec();
}
