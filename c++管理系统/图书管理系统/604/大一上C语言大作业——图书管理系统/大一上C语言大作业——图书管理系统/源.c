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
struct member membership[20] = {{1,"张三",100},{2,"李四",600},{3,"王五",500},{4,"陆六",1000},{5,"钱七",900},{6,"大强",100},{7,"小丽",100},{8,"敏敏",600}};
struct book
{
	int num;
	char name[30];
	int price;
};
struct book books[20] = { {1,"C#2.0宝典",88},{2,"Java编程基础",55},{3,"J2SE桌面应用程序开发",60},{4,"数据库设计和应用",45},{5,"水浒伟",55},{6,"红楼梦",68},{7,"三国演义",78},{8,"地心游记",29}};
int main()
{
	MainPage();
	return 0;
}
void MainPage(void)
{
	int choice1 = 0;
	printf("***********************\n*   图书销售管理系统  *\n*      1.登录系统     *\n*      2.退出         *\n***********************\n");
	printf("请选择，输入数字:(1-2)");
	scanf("%d", &choice1);
	if (choice1 == 2)
	{
		printf("欢迎再次使用本系统！\n");
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
		printf("请输入账号：");
		scanf("%s", InputUsername);
		printf("请输入密码：");
		scanf("%s", InputPassword);
		if (strcmp(password, InputPassword) == 0 && strcmp(username, InputUsername) == 0)
		{
			break;
		}
		else
		{
			if (count != 1)
			{
				printf("对不起，您输入的密码不正确，您还有%d次机会.\n", count - 1);
			}
			count--;
		}
	}
	if (count != 0)
	{
		printf("登录成功！\n");
		ManagePage();
	}
	else
	{
		printf("连续三次输入不正确，系统退出！");
		system("pause");
		exit(0);
	}
}
void ManagePage(void)
{
	int choice2 = 0;
	printf("***********************\n");
	printf("*      1.会员管理     *\n");
	printf("*      2.书籍管理     *\n");
	printf("*      3.购物结算     *\n");
	printf("*      4.注销         *\n");
	printf("***********************\n");
	printf("请选择,输入数字(1-4):");
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
	printf("图书销售管理系统>会员管理\n");
	printf("**************************\n");
	printf("*  1.显示所有会员        *\n");
	printf("*  2.添加会员信息        *\n");
	printf("*  3.修改会员信息        *\n");
	printf("*  4.返回主菜单          *\n");
	printf("**************************\n");
	printf("请选择，输入数字(1-4)：");
	scanf("%d", &choice3);
	if (choice3 == 1)
	{
		printf("图书销售管理系统 > 会员信息管理 > 显示会员信息\n");
		printf("会员号      姓名     积分\n");
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
		printf("图书销售管理系统>会员管理>添加会员信息\n");
		printf("请输入新会员姓名");
		scanf("%s",AddName);
		printf("请输入新会员积分");
		scanf("%d", &AddScore);
		membership[MemberNumber].num = MemberNumber + 1;
		strcpy(membership[MemberNumber].name, AddName);
		membership[MemberNumber].score = AddScore;
		MemberNumber++;
		printf("添加成功！\n");
		MemberManage();
	}
	else if (choice3 == 3)
	{
		char ChangeName[20] = { 0 };
		int ChangeScore = 0;
		int ChangeNum = 0;
		printf("图书销售管理系统>会员管理>修改会员信息\n");
		printf("请输入要修改的会员号:");
		scanf("%d", &ChangeNum);
		printf("请输入要修改的会员名:");
		scanf("%s", ChangeName);
		printf("请输入要修改的会员积分:");
		scanf("%d", &ChangeScore);
		strcpy(membership[ChangeNum-1].name, ChangeName);
		membership[ChangeNum-1].score = ChangeScore;
		printf("修改成功！\n");
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
	printf("图书销售管理系统 >书籍管理\n");
	printf("****************\n");
	printf("* 1.查看书目   *\n");
	printf("* 2.添加书籍   *\n");
	printf("* 3.删除书籍   *\n");
	printf("* 4.返回主菜单 *\n");
	printf("****************\n");
	printf("请选择，输入数字(1-4)：");
	scanf("%d", &choice4);
	if (choice4 == 1)
	{
		printf("图书销售管理系统>书籍管理>书籍列表\n");
		printf("图书号          图书名                 图书价钱\n");
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
		printf("图书销售管理系统>书籍管理>添加书籍\n");
		printf("请输入图书名:");
		scanf("%s", AddBook);
		printf("请输入图书价钱:");
		scanf("%d", &AddPrice);
		books[BookNumber].num = BookNumber + 1;
		strcpy(books[BookNumber].name, AddBook);
		books[BookNumber].price = AddPrice;
		BookNumber++;
		printf("添加成功!\n");
		BookManage();
	}
	else if (choice4 == 3)
	{
		char DeleteBook[20] = { 0 };
		printf("图书销售管理系统>书籍管理>删除书籍\n");
		printf("请输入要删除的图书书名:");
		scanf("%s", DeleteBook);
		for (int k = 0; k < BookNumber; k++)
		{
			if (strcmp(books[k].name, DeleteBook) == 0)
			{
				printf("找到该图书,位置为:%d\n", books[k].num);
				for (int l = books[k].num - 1; l < (BookNumber - 1); l++)
				{
					books[l].num = books[l + 1].num;
					strcpy(books[l].name, books[l + 1].name);
					books[l].price = books[l + 1].price;
				}
				printf("删除成功!\n");
				BookNumber--;
				BookManage();
			}
			else if (k == BookNumber - 1)
			{
				printf("该书籍无记录!\n");
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
	printf("图书销售管理系统>购物结算\n");
	printf("图书销售管理系统>书籍管理>书籍列表\n");
	printf("图书号          图书名                 图书价钱\n");
	for (int j = 0; j < BookNumber; j++)
	{
		printf("%4d            %-27s%d\n", books[j].num, books[j].name, books[j].price);
	}
	printf("请输入会员号:");
	scanf("%d", &BuyerNum);
	printf("请输入你要购买的书籍编号:");
	scanf("%d", &BuyBook);
	printf("请输入你要购买的数量:");
	scanf("%d", &quality);
	for (int z = 0; z < BookNumber; z++)
	{
		if (books[z].num == BuyBook && (books[z].price * quality) > membership[BuyerNum-1].score)
		{
			printf("你的积分不够,不能购买!\n");
			ManagePage();
		}
		else if (books[z].num == BuyBook && (books[z].price * quality) <= membership[BuyerNum-1].score)
		{
			printf("你要购买的书籍为%s,数量为%d,总额为%d.\n", books[z].name, quality, (books[z].price * quality));
			printf("是否继续?(y/n)");
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