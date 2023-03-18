#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct memberinformation
{
    int id;
    char name[30];
    int points;
} VIP; // 会员信息
VIP vip[100];

typedef struct bookinformation
{
    int id;
    char name[30];
    int sale;
} BOOK; // 图书信息
BOOK book[100];

int LoginSystem();           // 登录系统
int LoginOperator();         // 确认是否登录
int InputAdminAndPassword(); // 输入账号密码

void ShowMainInterface(); // 主页面
char ErrorSettlement();   // 输入错误处理

void MembershipManagement();       // 会员管理模块
void ReadMembers(int *membernum);  // 文件读取会员信息
void PrintMembers(int *membernum); // 打印会员信息
void AddMember(int *membernum);    // 添加会员信息
void ModifyMember(int *membernum); // 修改会员信息

void BooksManagement();                            // 图书管理模块
void ReadBooks(int *booknum);                      // 文件读取图书信息
void PrintBooks(int *booknum);                     // 打印图书信息
void AddBook(int *booknum);                        // 添加书籍
void DeleteBook(int *booknum);                     // 删除书籍模块，先查找再删除
int FindBook(int *delete_id, int *booknum);        // 查找书籍
void DeleteOperator(int *delete_id, int *booknum); // 删除操作

void PurchaseSettlement();                   // 购物结算模块
void ModifyPoints(int *membernum);           // 修改会员积分
void Purchase(int *membernum, int *booknum); // 购买操作
int ReadDigit();                             // 读取数值

int main()
{
    if (LoginSystem()) // 登录系统返回1，退出返回0
    {
        ShowMainInterface();
    }
    return 0;
}

int LoginSystem()
{
    if (LoginOperator()) // 输入1确认登录返回1，输入2退出返回0
    {
        if (InputAdminAndPassword()) // 账号密码正确返回1，否则返回0
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

int LoginOperator() // 输入1或2确认是否登录系统
{
    char login;
    int login_error = 0; // 判断输入错误
    printf("***********************\n");
    printf("*   图书销售管理系统  *\n");
    printf("*      1.登录系统     *\n");
    printf("*      2.退出         *\n");
    printf("***********************\n");
    printf("请选择，输入数字:(1-2)");
    scanf("%c", &login);
    if (getchar() != '\n') // 若输入错误
    {
        login_error = 1;          // 标记错误
        while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
            ;
    }

    while (login != '1' && login != '2' || login_error) // 输入错误处理
    {
        login_error = 0; // 重复使用标记
        printf("输入错误！请输入数字 1 或 2！\n");
        scanf("%c", &login);
        if (login == '2' || login == '1')
        {
            if (getchar() != '\n') // 若输入错误
            {
                login_error = 1;          // 标记错误
                while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
                    ;
            }
            else
            {
                return 1; // 输入正确，返回1
            }
        }
        else
        {
            while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
                ;
        }
    }

    if (login == '2') // 退出
    {
        printf("欢迎再次使用本系统!\n");
        return 0;
    }
    return 1;
}
int InputAdminAndPassword() // 输入账号密码
{
    char admin[6] = "admin";
    char password[7] = "123456";
    char inadmin[100];    // 输入账号
    char inpassword[100]; // 输入密码
    int login_times = 0;  // 登录次数
    do
    {
        int input_error = 0; // 输入长度错误标记
        printf("请输入账号：");
        scanf("%s", inadmin);
        if (getchar() != '\n') // 若输入长度错误
        {
            input_error = 1;          // 标记错误
            while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
                ;
        }
        printf("请输入密码：");
        scanf("%s", inpassword);
        if (getchar() != '\n') // 若输入长度错误
        {
            input_error = 1;          // 标记错误
            while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
                ;
        }
        ++login_times;
        if (input_error) // 若输入长度错误
        {
            input_error = 0;
            printf("对不起，您输入的账号或密码不正确，您还有%d次机会。\n", 3 - login_times);
        }
        else if (strcmp(admin, inadmin) == 0 && strcmp(password, inpassword) == 0)
        {
            printf("登录成功！欢迎您！\n");
            return 1;
        }
        else // 若长度正确但不完全一致
        {
            printf("对不起，您输入的账号或密码不正确，您还有%d次机会。\n", 3 - login_times);
        }
    } while (login_times < 3);
    if (login_times == 3)
    {
        printf("连续三次输入不正确，系统退出！\n");
        return 0;
    }
    return 1;
}

void ShowMainInterface() // 主界面
{
    char op1; // 操作1
    printf("******************************\n");
    printf("*      图书销售管理系统      *\n");
    printf("*         1.会员管理         *\n");
    printf("*         2.书籍管理         *\n");
    printf("*         3.购物结算         *\n");
    printf("*         4.注销             *\n");
    printf("******************************\n");
    printf("请选择，输入数字（1-4）：");
    op1 = ErrorSettlement();
    if (op1 == '1')
    {
        MembershipManagement(); // 会员管理
    }
    else if (op1 == '2')
    {
        BooksManagement(); // 书籍管理
    }
    else if (op1 == '3')
    {
        PurchaseSettlement(); // 购物结算
    }
    else if (op1 == '4')
    {
        if (LoginSystem()) // 注销
        {
            ShowMainInterface();
        }
        return;
    }
}

char ErrorSettlement() // 输入错误处理
{
    char op;
    scanf("%c", &op);
    int op_error = 0;      // 输入错误标记
    if (getchar() != '\n') // 若输入错误
    {
        op_error = 1;             // 标记错误
        while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
            ;
    }
    while (op != '1' && op != '2' && op != '3' && op != '4' || op_error) // 输入错误处理
    {
        op_error = 0; // 重复使用标记
        printf("输入错误！请输入数字 1 或 2 或 3 或 4!\n");
        scanf("%c", &op); // 重新输入
        if (op == '1' || op == '2' || op == '3' || op == '4')
        {
            if (getchar() != '\n') // 若输入错误
            {
                op_error = 1;             // 标记错误
                while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
                    ;
            }
            else
            {
                return op; // 输入正确，返回输入值
            }
        }
        else
        {
            while (getchar() != '\n') // 刷新输入缓冲区并读走换行符，继续重新输入
                ;
        }
    }
    return op;
}
void MembershipManagement() // 会员管理
{
    int op2 = 0;
    int membernum = 0; // 会员数量
    printf("图书销售管理系统>会员管理\n");
    printf("**************************\n");
    printf("*  1.显示所有会员        *\n");
    printf("*  2.添加会员信息        *\n");
    printf("*  3.修改会员信息        *\n");
    printf("*  4.返回主菜单          *\n");
    printf("**************************\n");
    printf("请选择，输入数字：");
    op2 = ErrorSettlement();
    if (op2 == '1')
    {
        ReadMembers(&membernum);  // 读取会员信息
        PrintMembers(&membernum); // 打印会员信息
    }
    else if (op2 == '2')
    {
        AddMember(&membernum); // 填加会员信息
    }
    else if (op2 == '3')
    {
        ModifyMember(&membernum); // 修改会员信息
    }
    else if (op2 == '4')
    {
        ShowMainInterface(); // 返回主菜单
    }
}

void ReadMembers(int *membernum) // 读取会员信息
{
    FILE *fp;
    if ((fp = fopen("vip.txt", "a+")) == NULL) // 打开存储会员信息文件
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    *membernum = 0;
    while (!feof(fp))
    {
        ++*membernum;
        fscanf(fp, "%d%s%d", &vip[*membernum].id, vip[*membernum].name, &vip[*membernum].points); // 按数据块读取会员信息到结构体数组
    }
    if (fclose(fp) == EOF)
    {
        printf("关闭文件失败！");
        exit(0);
    }
}

void PrintMembers(int *membernum) // 打印会员信息
{
    printf("图书销售管理系统 > 会员信息管理 > 显示会员信息\n");
    printf("会员号        姓名\t\t积分\n");
    for (int i = 1; i <= *membernum; ++i)
    {
        printf("  %-12d%-10s%12d\n", vip[i].id, vip[i].name, vip[i].points); // 输出结构体数组
    }
    MembershipManagement(); // 返回会员管理界面
}

void AddMember(int *membernum) // 添加会员信息
{
    ReadMembers(membernum); // 读取会员信息到结构体数组
    ++(*membernum);
    FILE *fp;
    if ((fp = fopen("vip.txt", "a+")) == NULL) // 以a+方式打开，直接在文件末尾添加信息
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    char newname[30];
    int newpoints = 0;
    printf("请输入新会员的名字：");
    scanf("%s", newname);     // 输入新会员名字
    while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
        ;
    printf("请输入新会员积分：");
    newpoints = ReadDigit(); // 读取数值
    fprintf(fp, "\n%-12d%-10s%12d", *membernum, newname, newpoints);
    if (fclose(fp) == EOF)
    {
        printf("关闭文件失败！");
        exit(0);
    }
    printf("添加成功！\n");
    MembershipManagement();
}

void ModifyMember(int *membernum) // 修改会员信息
{
    ReadMembers(membernum); // 读取会员信息到结构体数组
    FILE *fp;
    if ((fp = fopen("vip.txt", "r+")) == NULL) // 以r+方式打开，修改信息后覆盖原文件
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    int modify_times = 0;
    int modify_id = 0; // 要修改的会员号
    do
    {
        ++modify_times;
        printf("请输入要修改的会员号：");
        modify_id = ReadDigit();
        if (modify_id <= *membernum && modify_id > 0) // 若会员号有记录
        {
            printf("请输入要修改的会员姓名：");
            scanf("%s", vip[modify_id].name); // 要修改信息的会员名
            while (getchar() != '\n')         // 刷新输入缓冲区并读走换行符
                ;
            printf("请输入要修改的会员积分：");
            vip[modify_id].points = ReadDigit();      // 修改积分
            for (int i = 1; i <= *membernum - 1; ++i) // 换行符处理，单独打印最后一位会员
            {
                fprintf(fp, "%-12d%-10s%12d\n", i, vip[i].name, vip[i].points);
            }
            fprintf(fp, "%-12d%-10s%12d", *membernum, vip[*membernum].name, vip[*membernum].points); // 最后一个会员信息单独打印，避免打印多余换行
            if (fclose(fp) == EOF)
            {
                printf("关闭文件失败！");
                exit(0);
            }
            printf("修改成功！\n");
            break;
        }
        else
        {
            printf("会员号不合法！修改失败！请重新输入要修改的会员号(您还有%d次机会,退出请输入非数字的任意字母或0)：\n", 3 - modify_times);
            modify_id = ReadDigit();
            if (modify_id == 0)
            {
                fclose(fp);
                break;
            }
        }
    } while (modify_times < 3);
    if (modify_times == 3)
    {
        printf("连续三次输入不正确，返回“会员管理”界面！\n");
    }
    MembershipManagement();
}

void BooksManagement() // 书籍管理模块
{
    int op3 = 0;
    int booknum = 0; // 书籍数量
    printf("图书销售管理系统>书籍管理\n");
    printf("****************\n");
    printf("* 1.查看书目   *\n");
    printf("* 2.添加书籍   *\n");
    printf("* 3.删除书籍   *\n");
    printf("* 4.返回主菜单 *\n");
    printf("****************\n");
    printf("请选择，输入数字：");
    op3 = ErrorSettlement();
    if (op3 == '1')
    {
        ReadBooks(&booknum);  // 读取书籍信息
        PrintBooks(&booknum); // 打印书籍信息
    }
    else if (op3 == '2')
    {
        AddBook(&booknum); // 添加书籍
    }
    else if (op3 == '3')
    {
        DeleteBook(&booknum); // 删除书籍
    }
    else if (op3 == '4')
    {
        ShowMainInterface(); // 返回主菜单
    }
}

void ReadBooks(int *booknum) // 读取书籍信息到结构体数组
{
    FILE *fp;
    if ((fp = fopen("book.txt", "a+")) == NULL)
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    *booknum = 0;
    while (!feof(fp))
    {
        ++*booknum;
        fscanf(fp, "%d%s%d", &book[*booknum].id, book[*booknum].name, &book[*booknum].sale);
    }
    if(fclose(fp)==EOF)
    {
        printf("关闭文件失败！");
        exit(0);
    }
}

void PrintBooks(int *booknum)
{
    ReadBooks(booknum);
    printf("图书销售管理系统>书籍管理>书籍列表\n");
    printf("图书号        图书名\t\t\t图书价钱\n");
    for (int i = 1; i <= *booknum; ++i)
    {
        printf("  %-12d%-25s%9d\n", book[i].id, book[i].name, book[i].sale);
    }
    BooksManagement();
}

void AddBook(int *booknum) // 添加书籍
{
    ReadBooks(booknum); // 读取书籍信息到结构体数组
    ++(*booknum);
    FILE *fp;
    if ((fp = fopen("book.txt", "a+")) == NULL) // 以a+方式打开，直接在文件末尾添加信息
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    char newname[30];
    int newsale = 0;
    printf("请输入新图书的名字：");
    scanf("%s", newname);
    while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
        ;
    printf("请输入新图书的价钱：");
    newsale = ReadDigit();
    fprintf(fp, "\n%-12d%-25s%12d", *booknum, newname, newsale);
    if(fclose(fp)==EOF)
    {
        printf("关闭文件失败！");
        exit(0);
    }
    printf("添加成功！\n");
    BooksManagement();
}

void DeleteBook(int *booknum) // 删除书籍
{
    int delete_id = 0;                 // 要删除的书籍编号
    if (FindBook(&delete_id, booknum)) // 若找到该书籍
    {
        DeleteOperator(&delete_id, booknum); // 删除
    }
    BooksManagement();
}

int FindBook(int *delete_id, int *booknum)
{
    ReadBooks(booknum);
    char delete_name[30];
    printf("请输入要删除的图书名：");
    // getchar();
    scanf("%s", delete_name);
    while (getchar() != '\n') // 刷新输入缓冲区并读走换行符
        ;
    for (int i = 1; i <= *booknum; ++i)
    {
        if (strcmp(delete_name, book[i].name) == 0)
        {
            printf("找到该图书，位置为：%d\n", i);
            *delete_id = i; // 记录该书籍编号
            return 1;       // 找到返回1
        }
        if (i == *booknum) // 到末尾仍未返回，则没有找到
        {
            printf("没有找到该图书！\n");
            return 0; // 未找到
        }
    }
    return 0;
}

void DeleteOperator(int *delete_id, int *booknum)
{
    FILE *fp;
    if ((fp = fopen("book.txt", "w")) == NULL) // 以写的方式打开，修改信息后覆盖原文件
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    for (int i = 1; i <= *booknum - 1; ++i) // 第一本书籍到倒数第二本书籍
    {
        if (i < *delete_id)
        {
            fprintf(fp, "%-12d%-25s%12d", i, book[i].name, book[i].sale); // 编号小于删除书籍编号的，照常打印编号
        }
        else if (i == *delete_id) // 跳过要删除的书籍编号
        {
            continue;
        }
        else if (i > *delete_id)
        {
            fprintf(fp, "%-12d%-25s%12d", i - 1, book[i].name, book[i].sale); // 编号大于删除书籍编号时，编号减1打印到文件以排序
        }
        if (*delete_id == *booknum) // 处理换行符的打印
        {
            if (i < *booknum - 1)
            {
                fprintf(fp, "\n"); // 在打印倒数第二本书籍之前，每次循环都打印换行
            }
        }
        else // 处理换行符的打印
        {
            fprintf(fp, "\n");
        }
    }
    if (*delete_id != *booknum)
    {
        fprintf(fp, "%-12d%-25s%12d", *booknum - 1, book[*booknum].name, book[*booknum].sale);
    }
    if(fclose(fp)==EOF)
    {
        printf("关闭文件失败！");
        exit(0);
    }
    printf("删除成功！\n");
}

void PurchaseSettlement() // 购物结算模块
{
    int membernum = 0;       // 会员数量
    int booknum = 0;         // 书籍数量
    ReadMembers(&membernum); // 读取会员信息到结构体数组
    printf("图书销售管理系统 >购物结算\n");
    ReadBooks(&booknum); // 读取书籍信息到结构体数组
    printf("图书销售管理系统>书籍管理>书籍列表\n");
    printf("图书号        图书名\t\t\t图书价钱\n");
    for (int i = 1; i <= booknum; ++i) // 展示书籍信息
    {
        printf("  %-12d%-25s%12d\n", book[i].id, book[i].name, book[i].sale);
    }
    Purchase(&membernum, &booknum); // 购物功能
    ShowMainInterface();
}

void Purchase(int *membernum, int *booknum) // 购物功能
{
    int member_id = 0;    // 会员号
    int book_id = 0;      // 书籍号
    int purchase_num = 0; // 购买数量
    char chose;           // 是否继续购买
    do
    {
        printf("请输入会员号：");
        member_id = ReadDigit();
        while (member_id <= 0 || member_id > *membernum)
        {
            printf("会员号输入错误！请重新输入（退出请输入非数字的任意字母或0）：");
            member_id = ReadDigit();
            if (member_id == 0)
            {
                return; // 退出购买
            }
        }
        printf("请输入要购买的书籍编号：");
        book_id = ReadDigit();
        while (book_id <= 0 || book_id > *booknum)
        {
            printf("书籍编号输入错误！请重新输入（退出请输入非数字的任意字母或0）：");
            book_id = ReadDigit();
            if (book_id == 0)
            {
                return;
            }
        }
        printf("请输入您要购买的数量：");
        purchase_num = ReadDigit();
        while (purchase_num == 0)
        {
            printf("购买数量输入错误！请重新输入（退出请输入非数字的任意字母或0）：");
            purchase_num = ReadDigit();
            if (purchase_num == 0)
            {
                return;
            }
        }
        int total_money = purchase_num * book[book_id].sale; // 总价格
        if (vip[member_id].points < total_money)
        {
            printf("积分不足！购买失败！返回主界面！\n");
            return;
        }
        else
        {
            vip[member_id].points -= total_money; // 扣除相应积分
            ModifyPoints(membernum);              // 修改文件信息
            printf("购买成功！\n");
            printf("您购买的图书为%s，数量为%d，总额为%d\n", book[book_id].name, purchase_num, purchase_num * book[book_id].sale);
            printf("是否继续?（y/n）：");
            scanf(" %c", &chose);
            getchar(); // 读走换行符
        }
    } while (chose != 'n' && chose != 'N'); // 是否继续
}

int ReadDigit() // 字符读取转换为数值，避免字符输入到整型变量
{
    int x = 0; // 保存数值
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (ch > '9' || ch < '0') // 非数值
        {
            while (getchar() != '\n') // 刷新输入缓冲区
                ;
            return 0; // 返回错误
        }
        else if (ch >= '0' && ch <= '9') // 是数值
        {
            x = x * 10 + ch - '0'; // 转为整型
        }
    }
    return x;
}

void ModifyPoints(int *membernum) // 修改积分
{
    FILE *fp;
    if ((fp = fopen("vip.txt", "r+")) == NULL)
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    for (int i = 1; i <= *membernum - 1; ++i) // 换行符处理，单独打印最后一位会员
    {
        fprintf(fp, "%-12d%-10s%12d\n", i, vip[i].name, vip[i].points);
    }
    fprintf(fp, "%-12d%-10s%12d", *membernum, vip[*membernum].name, vip[*membernum].points);
    if(fclose(fp)==EOF)
    {
        printf("关闭文件失败！");
        exit(0);
    }
}