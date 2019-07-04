#ifndef POINT_H
#define POINT_H

#include"Tool.h"

class Point
{
public:
    Point() {}
    Point(int x,int y):x(x),y(y) {}
    void PrintSqar();
    void PrintCircle();
    void ClearPoint();
    bool operator==(Point &point){return (this->x==point.x)&&(this->y==point.y);}//比较二者是否相等
    void ChangePoint(int x,int y);
    int GetX(){return this->x;}
    int GetY(){return this->y;}

private:
    int x;
    int y;
};

#endif // POINT_H
