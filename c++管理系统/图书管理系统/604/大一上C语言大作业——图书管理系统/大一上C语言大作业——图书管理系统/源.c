#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int MemberNumber = 8;
int BookNumber = 8;
void MainPage(void);
void LoginSystem(void);
void ManagePage(void);
void MemberManage(void);
void BookManage(void);
void PurchaseCheckout(void);
struct member
{
	int num;
	char name[20];
	int score;
};
struct member membership[20] = {{1,"����",100},{2,"����",600},{3,"����",500},{4,"½��",1000},{5,"Ǯ��",900},{6,"��ǿ",100},{7,"С��",100},{8,"����",600}};
struct book
{
	int num;
	char name[30];
	int price;
};
struct book books[20] = { {1,"C#2.0����",88},{2,"Java��̻���",55},{3,"J2SE����Ӧ�ó��򿪷�",60},{4,"���ݿ���ƺ�Ӧ��",45},{5,"ˮ�ΰ",55},{6,"��¥��",68},{7,"��������",78},{8,"�����μ�",29}};
int main()
{
	MainPage();
	return 0;
}
void MainPage(void)
{
	int choice1 = 0;
	printf("***********************\n*   ͼ�����۹���ϵͳ  *\n*      1.��¼ϵͳ     *\n*      2.�˳�         *\n***********************\n");
	printf("��ѡ����������:(1-2)");
	scanf("%d", &choice1);
	if (choice1 == 2)
	{
		printf("��ӭ�ٴ�ʹ�ñ�ϵͳ��\n");
		system("pause");
		exit(0);
	}
	else if (choice1 == 1)
	{
		LoginSystem();
	}
	else
	{
		system("pause");
		exit(0);
	}
}
void LoginSystem(void)
{
	char password[] = "123456";
	char username[] = "admin";
	char InputPassword[10] = { 0 };
	char InputUsername[10] = { 0 };
	int count = 3;
	while (count != 0)
	{
		printf("�������˺ţ�");
		scanf("%s", InputUsername);
		printf("���������룺");
		scanf("%s", InputPassword);
		if (strcmp(password, InputPassword) == 0 && strcmp(username, InputUsername) == 0)
		{
			break;
		}
		else
		{
			if (count != 1)
			{
				printf("�Բ�������������벻��ȷ��������%d�λ���.\n", count - 1);
			}
			count--;
		}
	}
	if (count != 0)
	{
		printf("��¼�ɹ���\n");
		ManagePage();
	}
	else
	{
		printf("�����������벻��ȷ��ϵͳ�˳���");
		system("pause");
		exit(0);
	}
}
void ManagePage(void)
{
	int choice2 = 0;
	printf("***********************\n");
	printf("*      1.��Ա����     *\n");
	printf("*      2.�鼮����     *\n");
	printf("*      3.�������     *\n");
	printf("*      4.ע��         *\n");
	printf("***********************\n");
	printf("��ѡ��,��������(1-4):");
	scanf("%d", &choice2);
	if (choice2 == 1)
	{
		MemberManage();
	}
	else if (choice2 == 2)
	{
		BookManage();
	}
	else if (choice2 == 3)
	{
		PurchaseCheckout();
	}
	else if (choice2 == 4)
	{
		MainPage();
	}
}
void MemberManage(void)
{
	int choice3 = 0;
	printf("ͼ�����۹���ϵͳ>��Ա����\n");
	printf("**************************\n");
	printf("*  1.��ʾ���л�Ա        *\n");
	printf("*  2.��ӻ�Ա��Ϣ        *\n");
	printf("*  3.�޸Ļ�Ա��Ϣ        *\n");
	printf("*  4.�������˵�          *\n");
	printf("**************************\n");
	printf("��ѡ����������(1-4)��");
	scanf("%d", &choice3);
	if (choice3 == 1)
	{
		printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ��ʾ��Ա��Ϣ\n");
		printf("��Ա��      ����     ����\n");
		for (int i = 0; i < MemberNumber; i++)
		{
			printf("%4d%12s     %d\n", membership[i].num, membership[i].name, membership[i].score);
		}
		MemberManage();
	}
	else if (choice3 == 2)
	{
		char AddName[20] = { 0 };
		int AddScore = 0;
		printf("ͼ�����۹���ϵͳ>��Ա����>��ӻ�Ա��Ϣ\n");
		printf("�������»�Ա����");
		scanf("%s",AddName);
		printf("�������»�Ա����");
		scanf("%d", &AddScore);
		membership[MemberNumber].num = MemberNumber + 1;
		strcpy(membership[MemberNumber].name, AddName);
		membership[MemberNumber].score = AddScore;
		MemberNumber++;
		printf("��ӳɹ���\n");
		MemberManage();
	}
	else if (choice3 == 3)
	{
		char ChangeName[20] = { 0 };
		int ChangeScore = 0;
		int ChangeNum = 0;
		printf("ͼ�����۹���ϵͳ>��Ա����>�޸Ļ�Ա��Ϣ\n");
		printf("������Ҫ�޸ĵĻ�Ա��:");
		scanf("%d", &ChangeNum);
		printf("������Ҫ�޸ĵĻ�Ա��:");
		scanf("%s", ChangeName);
		printf("������Ҫ�޸ĵĻ�Ա����:");
		scanf("%d", &ChangeScore);
		strcpy(membership[ChangeNum-1].name, ChangeName);
		membership[ChangeNum-1].score = ChangeScore;
		printf("�޸ĳɹ���\n");
		MemberManage();
	}
	else if (choice3 == 4)
	{
		ManagePage();
	}
}
void BookManage(void)
{
	int choice4 = 0;
	printf("ͼ�����۹���ϵͳ >�鼮����\n");
	printf("****************\n");
	printf("* 1.�鿴��Ŀ   *\n");
	printf("* 2.����鼮   *\n");
	printf("* 3.ɾ���鼮   *\n");
	printf("* 4.�������˵� *\n");
	printf("****************\n");
	printf("��ѡ����������(1-4)��");
	scanf("%d", &choice4);
	if (choice4 == 1)
	{
		printf("ͼ�����۹���ϵͳ>�鼮����>�鼮�б�\n");
		printf("ͼ���          ͼ����                 ͼ���Ǯ\n");
		for (int j = 0; j < BookNumber; j++)
		{
			printf("%4d            %-27s%d\n", books[j].num, books[j].name, books[j].price);
		}
		BookManage();
	}
	else if (choice4 == 2)
	{
		char AddBook[20] = {0};
		int AddPrice = 0;
		printf("ͼ�����۹���ϵͳ>�鼮����>����鼮\n");
		printf("������ͼ����:");
		scanf("%s", AddBook);
		printf("������ͼ���Ǯ:");
		scanf("%d", &AddPrice);
		books[BookNumber].num = BookNumber + 1;
		strcpy(books[BookNumber].name, AddBook);
		books[BookNumber].price = AddPrice;
		BookNumber++;
		printf("��ӳɹ�!\n");
		BookManage();
	}
	else if (choice4 == 3)
	{
		char DeleteBook[20] = { 0 };
		printf("ͼ�����۹���ϵͳ>�鼮����>ɾ���鼮\n");
		printf("������Ҫɾ����ͼ������:");
		scanf("%s", DeleteBook);
		for (int k = 0; k < BookNumber; k++)
		{
			if (strcmp(books[k].name, DeleteBook) == 0)
			{
				printf("�ҵ���ͼ��,λ��Ϊ:%d\n", books[k].num);
				for (int l = books[k].num - 1; l < (BookNumber - 1); l++)
				{
					books[l].num = books[l + 1].num;
					strcpy(books[l].name, books[l + 1].name);
					books[l].price = books[l + 1].price;
				}
				printf("ɾ���ɹ�!\n");
				BookNumber--;
				BookManage();
			}
			else if (k == BookNumber - 1)
			{
				printf("���鼮�޼�¼!\n");
				BookManage();
			}
		}
	}
	else if (choice4 == 4)
	{
		ManagePage();
	}
}
void PurchaseCheckout(void)
{
	int BuyerNum = 0;
	int BuyBook = 0;
	int quality = 0;
	char judge = 0;
	printf("ͼ�����۹���ϵͳ>�������\n");
	printf("ͼ�����۹���ϵͳ>�鼮����>�鼮�б�\n");
	printf("ͼ���          ͼ����                 ͼ���Ǯ\n");
	for (int j = 0; j < BookNumber; j++)
	{
		printf("%4d            %-27s%d\n", books[j].num, books[j].name, books[j].price);
	}
	printf("�������Ա��:");
	scanf("%d", &BuyerNum);
	printf("��������Ҫ������鼮���:");
	scanf("%d", &BuyBook);
	printf("��������Ҫ���������:");
	scanf("%d", &quality);
	for (int z = 0; z < BookNumber; z++)
	{
		if (books[z].num == BuyBook && (books[z].price * quality) > membership[BuyerNum-1].score)
		{
			printf("��Ļ��ֲ���,���ܹ���!\n");
			ManagePage();
		}
		else if (books[z].num == BuyBook && (books[z].price * quality) <= membership[BuyerNum-1].score)
		{
			printf("��Ҫ������鼮Ϊ%s,����Ϊ%d,�ܶ�Ϊ%d.\n", books[z].name, quality, (books[z].price * quality));
			printf("�Ƿ����?(y/n)");
			getchar();
			char judge = getchar();
			if (judge == 'Y' || judge == 'y')
			{
				membership[BuyerNum-1].score = membership[BuyerNum-1].score - (books[z].price * quality);
				ManagePage();
			}
			else if (judge == 'N' || judge == 'n')
			{
				ManagePage();
			}
		}
	}
}