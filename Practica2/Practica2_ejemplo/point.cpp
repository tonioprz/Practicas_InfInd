#include "point.h"

namespace space{
    Point::Point(){
    _x = 0;
    _y = 0;
    }

    Point::Point(int x, int y){
        _x = x;
        _y = y;
    }

    Point::Point(const Point &P){
        _x = P._x;
        _y = P._y;
    }

    Point::~Point(){}

    Point &Point::operator=(const Point &P){
        _x = P._x;
        _y = P._y;

        return *this;
    }

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
