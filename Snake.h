#ifndef SNAKE_H
#define SNAKE_H

#include<deque>
#include<Point.h>
#include<conio.h>
#include <Food.h>


class Food;
class Snake
{
public:
    enum Direction{UP,DOWN,LEFT,RIGHT};
    Snake()
    {
        snake.emplace_back(Point(14,8));
        snake.emplace_back(Point(15,8));
        snake.emplace_back(Point(16,8));
        direction=Direction::DOWN;
     }
    void Snake_init();
    void Normal_move();
    void Snake_growth();
    bool OverEdge();
    bool HitItself();
    bool Change_direction();
    bool Get_food(Food& cfood);


private:
   std::deque<Point> snake;
   Direction direction;
   friend class Food;

};
#endif // SNAKE_H
