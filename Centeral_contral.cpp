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
     cout<<"��ѡ����Ϸ�Ѷ�";
     SetCursorPosition(7,22);
     cout<<"<�����¼�ѡ�񣬻س���ȷ��>";

     SetCursorPosition(27,20);
     SetBackColor();
     cout<<"��ģʽ";
     SetFrontColor(3);
     SetCursorPosition(27,23);
     cout<<"��ͨģʽ";
     SetCursorPosition(27,26);
     cout<<"����ģʽ";
     SetCursorPosition(27,29);
     cout<<"����ģʽ";

     int key_value;
     key=1;
     bool Enter_flag=false;

    while((key_value=getch()))
    {
          switch(key_value)
            {
               case 72:       //UP
              if(key>1)    //���ﵱkey=1ʱ��UP����Ч
              {
                  switch(key)
                  {
                     case 2: SetCursorPosition(27,20);
                             SetBackColor();
                             cout<<"��ģʽ";
                             SetCursorPosition(27,23);
                             SetFrontColor(3);
                             cout<<"��ͨģʽ";
                             --key;
                             break;
                     case 3: SetCursorPosition(27,23);
                             SetBackColor();
                             cout<<"��ͨģʽ";
                             SetCursorPosition(27,26);
                             SetFrontColor(3);
                             cout<<"����ģʽ";
                             --key;
                             break;
                     case 4: SetCursorPosition(27,26);
                             SetBackColor();
                             cout<<"����ģʽ";
                             SetCursorPosition(27,29);
                             SetFrontColor(3);
                             cout<<"����ģʽ";
                             --key;
                             break;
                  }
              }
              break;

              case 80:     //DOWN
              if(key<4)    //���ﵱkey=4ʱ��DOWN����Ч
              {
                  switch(key)
                  {
                     case 2: SetCursorPosition(27,26);
                             SetBackColor();
                             cout<<"����ģʽ";
                             SetCursorPosition(27,23);
                             SetFrontColor(3);
                             cout<<"��ͨģʽ";
                              ++key;
                             break;
                     case 3: SetCursorPosition(27,29);
                             SetBackColor();
                             cout<<"����ģʽ";
                             SetCursorPosition(27,26);
                             SetFrontColor(3);
                             cout<<"����ģʽ";
                              ++key;
                             break;
                     case 1: SetCursorPosition(27,23);
                             SetBackColor();
                             cout<<"��ͨģʽ";
                             SetCursorPosition(27,20);
                             SetFrontColor(3);
                             cout<<"��ģʽ";
                              ++key;
                             break;
                  }
              }
              break;

              case 13:     //�س���
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

    //��߷�����
    SetCursorPosition(33,1);
    SetFrontColor(3);
    cout<<"GreadySnake";
    SetCursorPosition(34,2);
    cout<<"̰����";
    SetCursorPosition(31,5);
    cout<<"�Ѷ�:";
    SetCursorPosition(35,6);
    switch(key)
    {
       case 1: cout<<"��ģʽ";break;
       case 2: cout<<"��ͨģʽ";break;
        case 3: cout<<"����ģʽ";break;
        case 4: cout<<"����ģʽ";break;
    default:break;
    }

    SetCursorPosition(31,8);
    cout<<"�÷֣�";
    SetCursorPosition(35,9);
    cout<<score;

    SetCursorPosition(33,11);
    cout<<"������ƶ�";
    SetCursorPosition(33,13);
    cout<<"Esc��ͣ";
}

int Centeral_Contral::Play_game()
{
   Snake *csnake=new Snake();
   Food  *cfood=new Food();
   SetFrontColor(6);
   csnake->Snake_init();
   srand((unsigned)time(NULL));
   cfood->Draw_food(*csnake);

   while(csnake->HitItself()  && csnake->OverEdge())   //��ƤƤ�߻�������ʱ
   {
       if(!csnake->Change_direction())
       {
           int temp=Menu();
           switch(temp)
           {
               case 1: break;
               case 2:  delete csnake;
                        delete cfood;
                        return 1;      //���ص�һ��ѭ����,��ʾ���¿�ʼ

                case 3: delete csnake;
                         delete cfood;
                        return 2;        //���ص��Լ�ѭ���� ��ʾ�˳�

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
        Sleep(speed);//�����ߵ��ƶ�Ч��
   }

   //ƤƤ������
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
    cout<<"�˵�";
    SetBackColor();
    SetCursorPosition(34,19);
    cout<<"������Ϸ";
     SetFrontColor(3);
    SetCursorPosition(34,21);
    cout<<"���¿�ʼ";
    SetCursorPosition(34,23);
    cout<<"�˳���Ϸ";

    //ѡ�񲿷�
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
                            cout<<"���¿�ʼ";
                            SetCursorPosition(34,19);
                            SetBackColor();
                            cout<<"������Ϸ";
                            --Item_value;
                            break;
                   case 3:  SetFrontColor(3);
                            SetCursorPosition(34,23);
                            cout<<"�˳���Ϸ";
                            SetCursorPosition(34,21);
                            SetBackColor();
                            cout<<"���¿�ʼ";
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
                           cout<<"������Ϸ";
                           SetCursorPosition(34,21);
                           SetBackColor();
                           cout<<"���¿�ʼ";
                           ++Item_value;
                           break;
                    case 2:SetFrontColor(3);
                           SetCursorPosition(34,21);
                           cout<<"���¿�ʼ";
                           SetCursorPosition(34,23);
                           SetBackColor();
                           cout<<"�˳���Ϸ";
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
     std::cout <<"|             ���ź�������ˣ�            |";
     SetCursorPosition(11,11);
     std::cout <<"|                                         |";
     SetCursorPosition(11,12);
     std::cout <<"|         ��ķ�����                      |";
     SetCursorPosition(24,12);
     std::cout <<score;
     SetCursorPosition(11,13);
     std::cout <<"|                                         |";
     SetCursorPosition(11,14);
     std::cout <<"|             �Ƿ�����һ�֣�              |";
     SetCursorPosition(11,15);
     std::cout <<"|                                         |";
     SetCursorPosition(11,16);
     std::cout <<"|                                         |";
     SetCursorPosition(11,17);
     std::cout <<"|                                         |";
     SetCursorPosition(11,18);
     std::cout <<"|    �ţ��õģ�    ���ˣ�����ѧϰ����!    |";
     SetCursorPosition(11,19);
     std::cout <<"|                                         |";
     SetCursorPosition(11,20);
     std::cout <<"|                                         |";
     SetCursorPosition(11,21);
     std::cout <<"-------------------------------------------";

     Sleep(100);
     SetCursorPosition(14, 18);
     SetBackColor();
     std::cout << "�ţ��õ�" ;

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
                 std::cout << "�ţ��õ�" ;
                 SetCursorPosition(21, 18);
                 SetFrontColor(11);
                 std::cout << "���ˣ�����ѧϰ����˼��" ;
                 --Iterm_value;
             }
             break;

         case 77:   //RIGHT
             if(Iterm_value<2)
             {
                 SetCursorPosition(14, 18);
                 SetFrontColor(11);
                 std::cout << "�ţ��õ�" ;
                 SetCursorPosition(21, 18);
                 SetBackColor();
                 std::cout << "���ˣ�����ѧϰ����˼��" ;
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
         return 1;//���¿�ʼ
     case 2:
         return 2;//�˳���Ϸ
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
























