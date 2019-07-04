#ifndef FOOD_H
#define FOOD_H

#include"Snake.h"
#include"Point.h"


class Snake;

class Food
{
public:
    Food() :cnt(0),x(0),y(0){}
    void Draw_food(Snake &csnake);

private:
    int cnt;
    friend class Snake;
    int x,y;
};

#endif // FOOD_H
