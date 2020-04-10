#include "personlist.h"

PersonList::PersonList(){
    _n = 0;
    _v = 0;
}

PersonList::PersonList(int n, Person v[]){
    _n = n;
    _v = new Person[n];
    for(int i=0;i<n;i++){
        _v[i] = v[i];
    }
}

PersonList::PersonList(PersonList &p){
    _n = p._n;
    _v = new Person[_n];
    for(int i=0;i<_n;i++){
        _v[i] = p._v[i];
    }
}

PersonList::~PersonList(){
    delete[] _v;
}

void PersonList::readData(){
    cout << "¿Cuántas personas quiere introducir? ";
    cin >> _n;
    cout << endl;

    _v = new Person[_n];
    string aux;
    int aux2;
    for(int i=0; i<_n; i++){
        cout << "Persona " << i+1 << endl << "Nombre: ";
        cin >> aux;
        cout << "Edad: ";
        cin >> aux2;
        _v[i].setName(aux);
        _v[i].setAge(aux2);
    }
}

Person &PersonList::operator[](const int N){
    return _v[N];
}

void PersonList::display(){
    for(int i=0;i<_n;i++){
        cout << "Persona " << i+1 << ". Nombre: " << _v[i].getName()
             << ". Edad: " << _v[i].getAge() << endl;
    }
}
