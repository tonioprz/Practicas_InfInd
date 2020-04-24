#include "uppercase.h"

Uppercase::Uppercase()
{

}

Uppercase::Uppercase(const string &name)
{
    setName(name);
}

void Uppercase::process(const string &data)
{
    string aux;
    int max = data.size();
    for(int i=0; i<max; i++){
        if(aux[i] >= 97 && aux[i] <= 122){
            aux[i] = data[i] - 32;
        }
    }
    cout << "PROCESSED: " << aux << endl;
}

void Uppercase::process(const string &data, int n)
{
    string aux;
    int max = data.size();
    for(int i=0; i<n; i++){
        if(aux[i] >= 97 && aux[i] <= 122){
            aux[i] = data[i] - 32;
        }
    }
    cout << "PROCESSED: " << aux << endl;

}

