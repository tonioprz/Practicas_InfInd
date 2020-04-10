#ifndef PERSONLIST_H
#define PERSONLIST_H
#include "person.h"

class PersonList
{
public:
    PersonList();
    PersonList(int n, Person v[]);
    PersonList(PersonList &p);
    ~PersonList();
    void readData();
    void display();
    Person &operator[](const int N);
private:
    int _n;
    Person *_v;
};

#endif // PERSONLIST_H
