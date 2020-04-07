#ifndef POINT_H
#define POINT_H

#include<iostream>
using namespace std;


namespace space{
class Point
{
public:
    Point();
    Point(int x, int y); //Constructor parametrizado
    Point(const Point & P); //Constructor copia
    ~Point(); //Destructor
    Point & operator=(const Point &P);
    int getX();
    int getY();
    void set(int x, int y);
    void display();

private:
    int _x,_y;

};
}
#endif // POINT_H
