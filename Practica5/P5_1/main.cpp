#include<iostream>
using namespace std;

class Operation {
    // abstract class
public:
    virtual int method(int a, int b)=0;
};

class Addition: public Operation {
public:
    int method(int a, int b) {return a+b;}
    int method(int a, int b, int c) {return a+b+c;}

};

class Subtraction: public Operation {
public:
    int method(int a, int b) {return a-b;}
    int method(int a, int b, int c) {return a-b-c;}
};

int main() {

    int n1, n2, n3;
    cout <<"Introduce tres enteros:" << endl;
    cin >> n1 >> n2 >> n3;
    Addition A;
    Subtraction S;
    cout << "Adding " << n1 << "+" << n2 << "+" << n3 << "=" << A.method(n1,n2,n3) << endl;
    cout << "Subtracting " << n1 << "-" << n2 << "-" << n3 << "=" << S.method(n1,n2,n3) << endl;

    return 0;
}
