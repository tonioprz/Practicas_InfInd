#include "point.h"

namespace space{
    int Point::getX(){
        return _x;
    }

    int Point::getY(){
        return _y;
    }

    void Point::set(int x, int y){
        _x = x;
        _y = y;
    }

    void Point::display(){
    cout << _x << ", " << _y << endl;
    }
}
