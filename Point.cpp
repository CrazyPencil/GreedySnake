#include "Point.h"
#include<iostream>

using namespace std;


void Point::PrintSqar()
{
    SetCursorPosition(x, y);
    cout<<"��";
}

void Point::PrintCircle()
{
    SetCursorPosition(x, y);
    cout<<"��";
}

void Point::ClearPoint()
{
    SetCursorPosition(x, y);
    cout<<' ';
}

void Point::ChangePoint(int x, int y)
{
    this->x=x;
    this->y=y;
}



