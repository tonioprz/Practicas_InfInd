#ifndef PERSON_H
#define PERSON_H
#include<iostream>
using namespace std;

class Person
{
public:
    Person(); //Constructor por defecto
    Person(string name, int age); // Constructor parametrizado
    Person(const Person &person); // Constructor copia
    ~Person(); // Destructor
    string getName();
    void setName(string name);
    int getAge();
    void setAge(int age);

    Person &operator=(const Person &p);

private:
    string _name;
    int _age;
};

#endif // PERSON_H
