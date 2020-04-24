// Example program
#include <iostream>
#include <string>
using namespace std;
int main()
{

    int a = 64;
    int * p = &a;

    cout << a << " " << p << endl;

    delete p;
}
