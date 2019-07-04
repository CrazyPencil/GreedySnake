#include "Centeral_contral.h"
#include <time.h>






using namespace std;
void Centeral_Contral::Game_stare()
{
    SetWindowSize();
    SetFrontColor(2);
    Opingpipishe *M=new   Opingpipishe;
    M->OpeningCaton();
    delete M;
    SetCursorPosition(11,23);
    cout<<"Please any key to continue......"<<endl;
    SetCursorPosition(11,24);
    system("pause");
}


void Centeral_Contral::Modol_seclect()
{
     SetCursorPosition(11,23);
     cout<<"                                        ";
     SetCursorPosition(11,24);
     cout <<"                                       ";
     SetFrontColor(3);
     SetCursorPosition(7,21);
     cout<<"请选择游戏难度";
     SetCursorPosition(7,22);
     cout<<"<按上下键选择，回车键确认>";

     SetCursorPosition(27,20);
     SetBackColor();
     cout<<"简单模式";
     SetFrontColor(3);
     SetCursorPosition(27,23);
     cout<<"普通模式";
     SetCursorPosition(27,26);
     cout<<"困难模式";
     SetCursorPosition(27,29);
     cout<<"地狱模式";

     int key_value;
     key=1;
     bool Enter_flag=false;

    while((key_value=getch()))
    {
          switch(key_value)
            {
               case 72:       //UP
              if(key>1)    //这里当key=1时，UP键无效
              {
                  switch(key)
                  {
                     case 2: SetCursorPosition(27,20);
                             SetBackColor();
                             cout<<"简单模式";
                             SetCursorPosition(27,23);
                             SetFrontColor(3);
                             cout<<"普通模式";
                             --key;
                             break;
                     case 3: SetCursorPosition(27,23);
                             SetBackColor();
                             cout<<"普通模式";
                             SetCursorPosition(27,26);
                             SetFrontColor(3);
                             cout<<"困难模式";
                             --key;
                             break;
                     case 4: SetCursorPosition(27,26);
                             SetBackColor();
                             cout<<"困难模式";
                             SetCursorPosition(27,29);
                             SetFrontColor(3);
                             cout<<"地狱模式";
                             --key;
                             break;
                  }
              }
              break;

              case 80:     //DOWN
              if(key<4)    //这里当key=4时，DOWN键无效
              {
                  switch(key)
                  {
                     case 2: SetCursorPosition(27,26);
                             SetBackColor();
                             cout<<"困难模式";
                             SetCursorPosition(27,23);
                             SetFrontColor(3);
                             cout<<"普通模式";
                              ++key;
                             break;
                     case 3: SetCursorPosition(27,29);
                             SetBackColor();
                             cout<<"地狱模式";
                             SetCursorPosition(27,26);
                             SetFrontColor(3);
                             cout<<"困难模式";
                              ++key;
                             break;
                     case 1: SetCursorPosition(27,23);
                             SetBackColor();
                             cout<<"普通模式";
                             SetCursorPosition(27,20);
                             SetFrontColor(3);
                             cout<<"简单模式";
                              ++key;
                             break;
                  }
              }
              break;

              case 13:     //回车键
                   Enter_flag=true;
                      break;

                default :  break;
            }

          if(Enter_flag==true)
              break;
    }
             SetCursorPosition(0,0);
           switch(key)
           {
               case 1: speed=135;break;
               case 2: speed=100;break;
               case 3: speed=60;break;
               case 4: speed=30;break;
           default : break;
           }
}



void Centeral_Contral::Draw_game()
{
    system("CLS");
    Map *tem_map=new Map;
    tem_map->InitMap();
    delete tem_map;

    //侧边分数栏
    SetCursorPosition(33,1);
    SetFrontColor(3);
    cout<<"GreadySnake";
    SetCursorPosition(34,2);
    cout<<"贪吃蛇";
    SetCursorPosition(31,5);
    cout<<"难度:";
    SetCursorPosition(35,6);
    switch(key)
    {
       case 1: cout<<"简单模式";break;
       case 2: cout<<"普通模式";break;
        case 3: cout<<"困难模式";break;
        case 4: cout<<"地狱模式";break;
    default:break;
    }

    SetCursorPosition(31,8);
    cout<<"得分：";
    SetCursorPosition(35,9);
    cout<<score;

    SetCursorPosition(33,11);
    cout<<"方向键移动";
    SetCursorPosition(33,13);
    cout<<"Esc暂停";
}

int Centeral_Contral::Play_game()
{
   Snake *csnake=new Snake();
   Food  *cfood=new Food();
   SetFrontColor(6);
   csnake->Snake_init();
   srand((unsigned)time(NULL));
   cfood->Draw_food(*csnake);

   while(csnake->HitItself()  && csnake->OverEdge())   //当皮皮蛇还有生命时
   {
       if(!csnake->Change_direction())
       {
           int temp=Menu();
           switch(temp)
           {
               case 1: break;
               case 2:  delete csnake;
                        delete cfood;
                        return 1;      //返回到一级循环中,表示重新开始

                case 3: delete csnake;
                         delete cfood;
                        return 2;        //返回到以及循环中 表示退出

           default:break;
           }
       }
        if(csnake->Get_food(*cfood))
        {
            csnake->Snake_growth();
            Updatescore();
            cfood->Draw_food(*csnake);
        }
        else
            csnake->Normal_move();
        Sleep(speed);//制造蛇的移动效果
   }

   //皮皮蛇死亡
   delete csnake;
   delete cfood;
   int tem=Game_over();
   switch(tem)
   {
       case 1:return 1;
   case 2:return 2;
   default :return 2;
   }
}

int Centeral_Contral::Menu()
{
    SetFrontColor(3);
    SetCursorPosition(35,17);
    cout<<"菜单";
    SetBackColor();
    SetCursorPosition(34,19);
    cout<<"继续游戏";
     SetFrontColor(3);
    SetCursorPosition(34,21);
    cout<<"重新开始";
    SetCursorPosition(34,23);
    cout<<"退出游戏";

    //选择部分
    int key_value;
    int Item_value=1;
    bool  flag=false;
    while(key_value=getch())
    {
        switch(key_value)
        {
           case 72:
            if(Item_value>1)
            {
                switch(Item_value)
                {
                   case 2:  SetFrontColor(3);
                            SetCursorPosition(34,21);
                            cout<<"重新开始";
                            SetCursorPosition(34,19);
                            SetBackColor();
                            cout<<"继续游戏";
                            --Item_value;
                            break;
                   case 3:  SetFrontColor(3);
                            SetCursorPosition(34,23);
                            cout<<"退出游戏";
                            SetCursorPosition(34,21);
                            SetBackColor();
                            cout<<"重新开始";
                            --Item_value;
                            break;
                    default : break;
                }
            }
            break;

        case 80:
            if(Item_value<3)
            {
                switch(Item_value)
                {
                   case 1: SetFrontColor(3);
                           SetCursorPosition(34,19);
                           cout<<"继续游戏";
                           SetCursorPosition(34,21);
                           SetBackColor();
                           cout<<"重新开始";
                           ++Item_value;
                           break;
                    case 2:SetFrontColor(3);
                           SetCursorPosition(34,21);
                           cout<<"重新开始";
                           SetCursorPosition(34,23);
                           SetBackColor();
                           cout<<"退出游戏";
                           ++Item_value;
                           break;
                }
            }
            break;
        case  13:
            flag=true;
             break;
        default:break;

        }
        if(flag)
            break;
         SetCursorPosition(0, 31);
    }
     if(Item_value==1)
     {

         SetFrontColor(3);
         SetCursorPosition(35,17);
         cout<<"Fighing! ";
         SetCursorPosition(34,19);
         cout<<"           ";
         SetCursorPosition(34,21);
         cout<<"           ";
         SetCursorPosition(34,23);
         cout<<"           ";
     }
     return Item_value;
}

void Centeral_Contral::Updatescore()
{
    score+=key*1;
    SetFrontColor(11);
    SetCursorPosition(35,9);
    cout<<score;
}

int Centeral_Contral::Game_over()
{
     SetFrontColor(11);
     SetCursorPosition(11,7);
     std::cout << "-------------------------------------------" ;
     SetCursorPosition(11,8);
     std::cout <<"|              Game over!!!               |";
     SetCursorPosition(11,9);
     std::cout <<"|                                         |";
     SetCursorPosition(11,10);
     std::cout <<"|             很遗憾，你挂了！            |";
     SetCursorPosition(11,11);
     std::cout <<"|                                         |";
     SetCursorPosition(11,12);
     std::cout <<"|         你的分数：                      |";
     SetCursorPosition(24,12);
     std::cout <<score;
     SetCursorPosition(11,13);
     std::cout <<"|                                         |";
     SetCursorPosition(11,14);
     std::cout <<"|             是否再来一局？              |";
     SetCursorPosition(11,15);
     std::cout <<"|                                         |";
     SetCursorPosition(11,16);
     std::cout <<"|                                         |";
     SetCursorPosition(11,17);
     std::cout <<"|                                         |";
     SetCursorPosition(11,18);
     std::cout <<"|    嗯，好的！    不了，还是学习有意!    |";
     SetCursorPosition(11,19);
     std::cout <<"|                                         |";
     SetCursorPosition(11,20);
     std::cout <<"|                                         |";
     SetCursorPosition(11,21);
     std::cout <<"-------------------------------------------";

     Sleep(100);
     SetCursorPosition(14, 18);
     SetBackColor();
     std::cout << "嗯，好的" ;

     int ch;
     int Iterm_value=1;
     bool flag;
     while(ch=getch())
     {
         switch(ch)
         {
            case 75:   //LEFT
             if(Iterm_value>1)
             {
                 SetCursorPosition(14, 18);
                 SetBackColor();
                 std::cout << "嗯，好的" ;
                 SetCursorPosition(21, 18);
                 SetFrontColor(11);
                 std::cout << "不了，还是学习有意思！" ;
                 --Iterm_value;
             }
             break;

         case 77:   //RIGHT
             if(Iterm_value<2)
             {
                 SetCursorPosition(14, 18);
                 SetFrontColor(11);
                 std::cout << "嗯，好的" ;
                 SetCursorPosition(21, 18);
                 SetBackColor();
                 std::cout << "不了，还是学习有意思！" ;
                 ++Iterm_value;
             }
             break;

         case 13:  flag=true;
             break;
         default:break;
         }

         if(flag)
              break;
     }

     SetFrontColor(11);
     switch (Iterm_value)
     {
     case 1:
         return 1;//重新开始
     case 2:
         return 2;//退出游戏
     default:
         return 1;
     }


}

void Centeral_Contral::Game()
{

    while(true)
    {
        Game_stare();
        Modol_seclect();

        Draw_game();
        int tem=Play_game();
        if(tem==1)
        {
            score=0;
            system("cls");
             system("color 07");
            continue;
        }
        else if(tem==2)
        {
            break;
        }
         else
            break;
    }
}
























