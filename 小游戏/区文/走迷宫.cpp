#include<stdio.h>
typedef struct bird
{
    COORD pos;
    int score;
} BIRD;
//С��ĳ�ʼλ�úͷ���
BIRD bird = {{22, 10}, 0};
//3�����ӵĳ�ʼλ�ú͸߶�
COORD wall[3] = {{40, 10},{60, 6},{80, 8}};
int main(void)
{
    BIRD bird = {{22, 10}, 0};//С��ĳ�ʼλ��
    COORD wall[3] = {{40, 10},{60, 6},{80, 8}}; //���ӵĳ�ʼλ�ú͸߶�
    int i;
    char ch;
    while (CheckWin(wall, &bird)) //δ������ײ
    {
        Begin(&bird);   //��������ʾ���±߽�ͷ���
        CheckWall(wall);//��ʾ����
        PrtBird(&bird); //��ʾС��
        Sleep(200);
        if (kbhit())     //��⵽�м�������
        {
            ch = getch(); //������ַ�����ch
            if (ch == ' ')//������ǿո�
            {
                bird.pos.Y -= 1; //С�������ƶ�һ��
            }
        }
        else //δ��⵽��������
        {
            bird.pos.Y += 1; //С�������ƶ�һ��
        }
        for (i=0; i<3; i++)
        {
            wall[i].X--;  //���������ƶ�һ��
        }
    }
    return 0;
}
void CheckWall(COORD wall[]) //��ʾ����
{
    int i;
    srand(time(NULL));
    COORD temp = {wall[2].X + DIS, rand() % 13 + 5};//�������һ��������

    if (wall[0].X < 10)  //����Ԥ�����߽�
    {
        wall[0] = wall[1];//������������ʧ���ڶ������ӱ�ɵ�һ��
        wall[1] = wall[2];//���������ӱ�ɵڶ���
        wall[2] = temp;   //�²��������ӱ�ɵ�����
    }
    for (i=0; i<3; i++) //ѭ����ʾ��������
    {
        //��ʾ�ϰ벿������
        temp.X = wall[i].X + 1;//��������һ����ʾͼ��
        SetConsoleColor(0x0C); //�ڱ�����ɫǰ��
        for (temp.Y=2; temp.Y<wall[i].Y; temp.Y++)//�ӵ�2�п�ʼ��ʾ
        {
            Gotoxy(temp.X, temp.Y);
            printf("������������");
        }

        temp.X--;//�����ƶ�һ����ʾͼ��
        Gotoxy(temp.X, temp.Y);
        printf("��������������");
        
        //��ʾ�°벿������
        temp.Y += BLAN;
        Gotoxy(temp.X, temp.Y);
        printf("��������������");

        temp.X++; //��������һ����ʾͼ��
        temp.Y++; //����һ����ʾ�����ͼ��
        for (; (temp.Y)<26; temp.Y++)//һֱ��ʾ����25��
        {
            Gotoxy(temp.X, temp.Y);
            printf("������������");
        }
    }
}



