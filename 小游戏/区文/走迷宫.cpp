#include<stdio.h>
typedef struct bird
{
    COORD pos;
    int score;
} BIRD;
//小鸟的初始位置和分数
BIRD bird = {{22, 10}, 0};
//3个柱子的初始位置和高度
COORD wall[3] = {{40, 10},{60, 6},{80, 8}};
int main(void)
{
    BIRD bird = {{22, 10}, 0};//小鸟的初始位置
    COORD wall[3] = {{40, 10},{60, 6},{80, 8}}; //柱子的初始位置和高度
    int i;
    char ch;
    while (CheckWin(wall, &bird)) //未发生碰撞
    {
        Begin(&bird);   //清屏并显示上下边界和分数
        CheckWall(wall);//显示柱子
        PrtBird(&bird); //显示小鸟
        Sleep(200);
        if (kbhit())     //检测到有键盘输入
        {
            ch = getch(); //输入的字符存入ch
            if (ch == ' ')//输入的是空格
            {
                bird.pos.Y -= 1; //小鸟向上移动一格
            }
        }
        else //未检测到键盘输入
        {
            bird.pos.Y += 1; //小鸟向下移动一格
        }
        for (i=0; i<3; i++)
        {
            wall[i].X--;  //柱子向左移动一格
        }
    }
    return 0;
}
void CheckWall(COORD wall[]) //显示柱子
{
    int i;
    srand(time(NULL));
    COORD temp = {wall[2].X + DIS, rand() % 13 + 5};//随机产生一个新柱子

    if (wall[0].X < 10)  //超出预设的左边界
    {
        wall[0] = wall[1];//最左侧的柱子消失，第二个柱子变成第一个
        wall[1] = wall[2];//第三个柱子变成第二个
        wall[2] = temp;   //新产生的柱子变成第三个
    }
    for (i=0; i<3; i++) //循环显示三个柱子
    {
        //显示上半部分柱子
        temp.X = wall[i].X + 1;//向右缩进一格显示图案
        SetConsoleColor(0x0C); //黑背景红色前景
        for (temp.Y=2; temp.Y<wall[i].Y; temp.Y++)//从第2行开始显示
        {
            Gotoxy(temp.X, temp.Y);
            printf("■■■■■■");
        }

        temp.X--;//向左移动一格显示图案
        Gotoxy(temp.X, temp.Y);
        printf("■■■■■■■");
        
        //显示下半部分柱子
        temp.Y += BLAN;
        Gotoxy(temp.X, temp.Y);
        printf("■■■■■■■");

        temp.X++; //向右缩进一格显示图案
        temp.Y++; //在下一行显示下面的图案
        for (; (temp.Y)<26; temp.Y++)//一直显示到第25行
        {
            Gotoxy(temp.X, temp.Y);
            printf("■■■■■■");
        }
    }
}



