#include <iostream>
using namespace std;

class Animal {
protected:
    int age;
public:
    Animal(){this->age=-1;}
    Animal(int n){this->age=n;}
    virtual int getAge()=0;
    virtual void print(){cout << "An animal " <<endl;}
    void food() {cout << "not defined yet" << endl;};
    void operator >>(int n){
        this->age=n;
    };

};

class Aquatic : public Animal {
public:
    Aquatic():Animal(0) {}
    Aquatic(int nn):Animal(nn) {}
    int getAge() {
        return this->age;
    }
    void print() {
        cout << "Aquatic Animal: " << this->age << " years old" << endl;
    }
    void food() {
        cout << "little fishes and seaweeds" << endl;
    }

    void operator ++(){this->age++;} //prefix
    void operator ++(int){this->age++;} //postfix
    bool operator>(Aquatic A) {return this->age > A.age;}
};

int main() {

    Aquatic*A= new Aquatic(11);
    cout << "Aquatic:" <<endl;
    A->print();
    A->food();

    Animal *animal = A;
    cout << "Animal:" <<endl;
    animal->print();
    animal->food();


    Aquatic A1(1);
    Aquatic A2(2);
    cout << "A1 age:" <<A1.getAge() << endl;
    cout << "A2 age:" << A2.getAge() << endl;

    if(A1>A2) {
        cout << "A1>A2" << endl;
    }
    else{
        cout << "A1<=A2" << endl;
    }

    ++A1;
    A1++;
    cout << "A1 age:" << A1.getAge() << endl;
    cout << "A2 age:" << A2.getAge() << endl;

    if(A1>A2) {
        cout << "A1>A2 " << endl;
    }
    else {
        cout << "A1<=A2 " << endl;
    }




    cout << "A age: " << animal->getAge() << endl;
    *animal >> 5;
    cout << "A age: " << animal->getAge() << endl;

    return 0;
}
