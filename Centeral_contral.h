#ifndef CENTERAL_CONTRAL_H
#define CENTERAL_CONTRAL_H

#include"Opingpipishe.h"
#include<windows.h>
#include<iostream>
#include<Tool.h>
#include<conio.h>
#include<Map.h>
#include<Snake.h>
#include<Food.h>

class Centeral_Contral
{
public:
    Centeral_Contral():speed(200),score(0),key(1) {}
    void Game_stare();
    void Modol_seclect();
    void Draw_game();
    int Play_game();
    int Menu();
    void Updatescore();
    int Game_over();
    void Game();

private:
    int speed;     //�ߵ��ٶ�
    int score;
    int key;  //�Ѷ�ֵ
};

#endif // CENTERAL_CONTRAL_H
