#include "Food.h"
#include"Tool.h"
#include<cstdlib>
#include<iostream>




void Food::Draw_food(Snake &csnake)
{
    while(1)
    {
        int tem_X=rand()%30;
        int tem_Y=rand()%30;
        if(tem_X<2) tem_X+=2;
        if(tem_Y<2) tem_Y+=2;

        bool Eat_flag=false;
        for (auto& point : csnake.snake)
               {
                   if ((point.GetX() == tem_X && point.GetY() == tem_Y)) {
                       Eat_flag = true;
                       break;
                   }
               }

        if(Eat_flag)
            continue;
        x=tem_X;
        y=tem_Y;
        SetCursorPosition(x, y);
        SetFrontColor(13);
        std::cout<< "бя" ;
        break;
    }
}
