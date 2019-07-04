#include "Opingpipishe.h"


/*void Opingpipishe::snake_show()
{
    int Nsize=movingsnake.size();
    for(int i=0;i<Nsize;i++)
    {
        movingsnake[i].PrintCircle();
        Sleep(80);
    }
}

void Opingpipishe::snake_moving()
{
    for(int threshold=13;12<threshold<57;threshold++)
    {

    }
}  */




void Opingpipishe::text_show()
{
    int Nsize=textsnake.size();
    for(int i=0;i<Nsize;i++)
    {
        if(textsnake[i].GetX()>=0)
        textsnake[i].PrintSqar();
    }
}

void Opingpipishe::text_clear()   //”““∆
{
    int Nsize=textsnake.size();
    for(int i=0;i<Nsize;i++)
    {
        if(textsnake[i].GetX()>=0)
            textsnake[i].ClearPoint();
        textsnake[i].ChangePoint(textsnake[i].GetX()+1,textsnake[i].GetY());
    }
}

void Opingpipishe::OpeningCaton()
{
    while(textsnake[0].GetX()<=33)
    {
       SetCursorPosition(0,0);
       text_clear();
       text_show();
       Sleep(70);
    }
}






