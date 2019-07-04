#include "Snake.h"


void Snake::Snake_init()
{
    int Nsize=snake.size();
    SetFrontColor(14);
    for(int i=0;i<Nsize;i++)
    {
      snake[i].PrintCircle();
    }
}



void Snake::Snake_growth()   //����ʳ��֮�� ����һ���ƶ�
{
    switch(direction)
    {
        case Direction::UP:       snake.emplace_back(Point(snake.back().GetX(),snake.back().GetY()-1));  break;
        case Direction::DOWN:    snake.emplace_back(Point(snake.back().GetX(),snake.back().GetY()+1));  break;
        case Direction::LEFT:    snake.emplace_back(Point(snake.back().GetX()-1,snake.back().GetY()));  break;
        case Direction::RIGHT:   snake.emplace_back(Point(snake.back().GetX()+1,snake.back().GetY()));  break;
        default: break;
     }
    SetFrontColor(14);
    snake.back().PrintCircle();
}




bool Snake::OverEdge()
{
    return (snake.back().GetX()<30)&&(snake.back().GetY()<30)&&(snake.back().GetX()>1)&&(snake.back().GetY()>1);
}





bool Snake::HitItself()
{
    std::deque<Point>::size_type cnt = 1;
    Point *head = new Point(snake.back().GetX(), snake.back().GetY());//���ͷ������
    for (auto& point : snake) //���������������ͷ����ͬ�����겻�����߳�������ζ����ͷ��ײ������
    {
        if ( !(point == *head) )
            ++cnt;
        else
            break;
    }
    delete head;
    if(cnt == snake.size())
        return true;
    else
        return false;
}




bool Snake::Change_direction()
{
    char ch;
    if(kbhit())
    {
        ch=getch();
        switch(ch)
        {
            case -32: ch=getch();
            switch(ch)
            {
               case 72:       //UP
                    if(direction!=Direction::DOWN)
                        direction=UP;
                        break;
                case 80:          //DOWN
                    if(direction!=Direction::UP)
                        direction=DOWN;
                        break;
                case 75:         //LEFT
                    if(direction!=Direction::RIGHT)
                        direction=LEFT;
                        break;
                case 77:            //RIGHT
                    if(direction!=Direction::LEFT)
                        direction=RIGHT;
                        break;
            default:break;
            }
            return true;
        case 27:           //Esc
            return false;

       default:
            return true;
        }
    }
    return  true;
}

bool Snake::Get_food(Food&  cfood)
{
    if(snake.back().GetX()==cfood.x  &&  snake.back().GetY()==cfood.y)
        return true;
    else
        return false;
}





void Snake::Normal_move()     //�����ƶ�
{
    Snake_growth();
    snake.front().ClearPoint();
    snake.pop_front();
}





