#include <QCoreApplication>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int *v;
    int size;

    cout << "Introzca tamaño del vector: ";
    cin >> size;
    cout << endl;

    v = new int[size];
    for(int i=0; i<size; i++){
        cout << "Entero número " << i+1 << ":";
        cin >> v[i];
        cout << endl;
    }

    int aux = 0;
    for(int i=0; i<size; i++){
        aux = aux + v[i];
    }

    cout << "Total: " << aux << endl;

    return a.exec();
}
