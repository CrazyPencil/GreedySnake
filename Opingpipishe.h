#ifndef OPINGPIPISHE_H
#define OPINGPIPISHE_H

#include<vector>
#include<deque>
#include<Point.h>

class Opingpipishe
{
public:
    Opingpipishe(){
        textsnake.emplace_back(Point(0,12));  //E
        textsnake.emplace_back(Point(0,14));
        textsnake.emplace_back(Point(0,16));
        textsnake.emplace_back(Point(-1,14));
        textsnake.emplace_back(Point(-1,16));
        textsnake.emplace_back(Point(-1,12));
        textsnake.emplace_back(Point(-2,14));
        textsnake.emplace_back(Point(-2,16));
        textsnake.emplace_back(Point(-2,12));
        textsnake.emplace_back(Point(-3,14));
        textsnake.emplace_back(Point(-3,16));
        textsnake.emplace_back(Point(-3,12));
        textsnake.emplace_back(Point(-3,13));
        textsnake.emplace_back(Point(-3,15));

        textsnake.emplace_back(Point(-5,12));   //K
        textsnake.emplace_back(Point(-5,16));
        textsnake.emplace_back(Point(-6,13));
        textsnake.emplace_back(Point(-6,15));
        textsnake.emplace_back(Point(-7,14));
        textsnake.emplace_back(Point(-8,14));
        textsnake.emplace_back(Point(-8,13));
        textsnake.emplace_back(Point(-8,12));
        textsnake.emplace_back(Point(-8,15));
        textsnake.emplace_back(Point(-8,16));

        textsnake.emplace_back(Point(-10,16));   //A
        textsnake.emplace_back(Point(-11,15));
        textsnake.emplace_back(Point(-12,14));
        textsnake.emplace_back(Point(-13,13));
        textsnake.emplace_back(Point(-14,12));
        textsnake.emplace_back(Point(-15,13));
        textsnake.emplace_back(Point(-16,14));
        textsnake.emplace_back(Point(-17,15));
        textsnake.emplace_back(Point(-18,16));
        textsnake.emplace_back(Point(-13,14));
        textsnake.emplace_back(Point(-14,14));
        textsnake.emplace_back(Point(-15,14));

        textsnake.emplace_back(Point(-20,16));  //N
        textsnake.emplace_back(Point(-20,15));
        textsnake.emplace_back(Point(-20,14));
        textsnake.emplace_back(Point(-20,13));
        textsnake.emplace_back(Point(-20,12));
        textsnake.emplace_back(Point(-21,15));
        textsnake.emplace_back(Point(-22,14));
        textsnake.emplace_back(Point(-23,13));
        textsnake.emplace_back(Point(-24,12));
        textsnake.emplace_back(Point(-24,13));
        textsnake.emplace_back(Point(-24,14));
        textsnake.emplace_back(Point(-24,15));
        textsnake.emplace_back(Point(-24,16));

        textsnake.emplace_back(Point(-26,12));   //S
        textsnake.emplace_back(Point(-27,12));
        textsnake.emplace_back(Point(-28,13));
        textsnake.emplace_back(Point(-27,14));
        textsnake.emplace_back(Point(-26,15));
        textsnake.emplace_back(Point(-27,16));
        textsnake.emplace_back(Point(-28,16));


      //  movingsnake.emplace_back(Point(0,14));   //snake
      //  movingsnake.emplace_back(Point(1,15));
      //  movingsnake.emplace_back(Point(2,16));
      //  movingsnake.emplace_back(Point(3,17));
      //  movingsnake.emplace_back(Point(4,18));
      //  movingsnake.emplace_back(Point(5,17));
      //  movingsnake.emplace_back(Point(6,16));
      //  movingsnake.emplace_back(Point(7,15));
      //  movingsnake.emplace_back(Point(8,14));
      //  movingsnake.emplace_back(Point(9,15));
      //  movingsnake.emplace_back(Point(10,16));
      //  movingsnake.emplace_back(Point(11,17));
      //  movingsnake.emplace_back(Point(12,18));


    }
   // void snake_show();
   // void snake_moving();
   // void snake_disappear();
    void text_show();
    void text_clear();
    void OpeningCaton();
private:
    std::vector<Point> textsnake;
    std::deque<Point> movingsnake;

};

#endif // OPINGPIPISHE_H
