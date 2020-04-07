#include <iostream>
#include "point.h"

using namespace std;
using namespace space;

int main(int argc, char **argv) {
    Point P;
    cout << P.getX() << endl;
    cout << P.getY() << endl;

    P.set(10, 10);
    cout << P.getX() << endl;
    cout << P.getY() << endl;
    P.display();
}
