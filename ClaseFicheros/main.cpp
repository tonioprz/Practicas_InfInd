#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream archivo;
    archivo.open("archivo.txt");

    if(archivo.is_open()){
        string aux;
        archivo >> aux;
        cout << aux << endl;
    }
    archivo.close();
    return 0;
}
