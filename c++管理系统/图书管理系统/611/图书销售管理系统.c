#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct memberinformation
{
    int id;
    char name[30];
    int points;
} VIP; // ��Ա��Ϣ
VIP vip[100];

typedef struct bookinformation
{
    int id;
    char name[30];
    int sale;
} BOOK; // ͼ����Ϣ
BOOK book[100];

int LoginSystem();           // ��¼ϵͳ
int LoginOperator();         // ȷ���Ƿ��¼
int InputAdminAndPassword(); // �����˺�����

void ShowMainInterface(); // ��ҳ��
char ErrorSettlement();   // ���������

void MembershipManagement();       // ��Ա����ģ��
void ReadMembers(int *membernum);  // �ļ���ȡ��Ա��Ϣ
void PrintMembers(int *membernum); // ��ӡ��Ա��Ϣ
void AddMember(int *membernum);    // ��ӻ�Ա��Ϣ
void ModifyMember(int *membernum); // �޸Ļ�Ա��Ϣ

void BooksManagement();                            // ͼ�����ģ��
void ReadBooks(int *booknum);                      // �ļ���ȡͼ����Ϣ
void PrintBooks(int *booknum);                     // ��ӡͼ����Ϣ
void AddBook(int *booknum);                        // ����鼮
void DeleteBook(int *booknum);                     // ɾ���鼮ģ�飬�Ȳ�����ɾ��
int FindBook(int *delete_id, int *booknum);        // �����鼮
void DeleteOperator(int *delete_id, int *booknum); // ɾ������

void PurchaseSettlement();                   // �������ģ��
void ModifyPoints(int *membernum);           // �޸Ļ�Ա����
void Purchase(int *membernum, int *booknum); // �������
int ReadDigit();                             // ��ȡ��ֵ

int main()
{
    if (LoginSystem()) // ��¼ϵͳ����1���˳�����0
    {
        ShowMainInterface();
    }
    return 0;
}

int LoginSystem()
{
    if (LoginOperator()) // ����1ȷ�ϵ�¼����1������2�˳�����0
    {
        if (InputAdminAndPassword()) // �˺�������ȷ����1�����򷵻�0
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

int LoginOperator() // ����1��2ȷ���Ƿ��¼ϵͳ
{
    char login;
    int login_error = 0; // �ж��������
    printf("***********************\n");
    printf("*   ͼ�����۹���ϵͳ  *\n");
    printf("*      1.��¼ϵͳ     *\n");
    printf("*      2.�˳�         *\n");
    printf("***********************\n");
    printf("��ѡ����������:(1-2)");
    scanf("%c", &login);
    if (getchar() != '\n') // ���������
    {
        login_error = 1;          // ��Ǵ���
        while (getchar() != '\n') // ˢ�����뻺���������߻��з�
            ;
    }

    while (login != '1' && login != '2' || login_error) // ���������
    {
        login_error = 0; // �ظ�ʹ�ñ��
        printf("����������������� 1 �� 2��\n");
        scanf("%c", &login);
        if (login == '2' || login == '1')
        {
            if (getchar() != '\n') // ���������
            {
                login_error = 1;          // ��Ǵ���
                while (getchar() != '\n') // ˢ�����뻺���������߻��з�
                    ;
            }
            else
            {
                return 1; // ������ȷ������1
            }
        }
        else
        {
            while (getchar() != '\n') // ˢ�����뻺���������߻��з�
                ;
        }
    }

    if (login == '2') // �˳�
    {
        printf("��ӭ�ٴ�ʹ�ñ�ϵͳ!\n");
        return 0;
    }
    return 1;
}
int InputAdminAndPassword() // �����˺�����
{
    char admin[6] = "admin";
    char password[7] = "123456";
    char inadmin[100];    // �����˺�
    char inpassword[100]; // ��������
    int login_times = 0;  // ��¼����
    do
    {
        int input_error = 0; // ���볤�ȴ�����
        printf("�������˺ţ�");
        scanf("%s", inadmin);
        if (getchar() != '\n') // �����볤�ȴ���
        {
            input_error = 1;          // ��Ǵ���
            while (getchar() != '\n') // ˢ�����뻺���������߻��з�
                ;
        }
        printf("���������룺");
        scanf("%s", inpassword);
        if (getchar() != '\n') // �����볤�ȴ���
        {
            input_error = 1;          // ��Ǵ���
            while (getchar() != '\n') // ˢ�����뻺���������߻��з�
                ;
        }
        ++login_times;
        if (input_error) // �����볤�ȴ���
        {
            input_error = 0;
            printf("�Բ�����������˺Ż����벻��ȷ��������%d�λ��ᡣ\n", 3 - login_times);
        }
        else if (strcmp(admin, inadmin) == 0 && strcmp(password, inpassword) == 0)
        {
            printf("��¼�ɹ�����ӭ����\n");
            return 1;
        }
        else // ��������ȷ������ȫһ��
        {
            printf("�Բ�����������˺Ż����벻��ȷ��������%d�λ��ᡣ\n", 3 - login_times);
        }
    } while (login_times < 3);
    if (login_times == 3)
    {
        printf("�����������벻��ȷ��ϵͳ�˳���\n");
        return 0;
    }
    return 1;
}

void ShowMainInterface() // ������
{
    char op1; // ����1
    printf("******************************\n");
    printf("*      ͼ�����۹���ϵͳ      *\n");
    printf("*         1.��Ա����         *\n");
    printf("*         2.�鼮����         *\n");
    printf("*         3.�������         *\n");
    printf("*         4.ע��             *\n");
    printf("******************************\n");
    printf("��ѡ���������֣�1-4����");
    op1 = ErrorSettlement();
    if (op1 == '1')
    {
        MembershipManagement(); // ��Ա����
    }
    else if (op1 == '2')
    {
        BooksManagement(); // �鼮����
    }
    else if (op1 == '3')
    {
        PurchaseSettlement(); // �������
    }
    else if (op1 == '4')
    {
        if (LoginSystem()) // ע��
        {
            ShowMainInterface();
        }
        return;
    }
}

char ErrorSettlement() // ���������
{
    char op;
    scanf("%c", &op);
    int op_error = 0;      // ���������
    if (getchar() != '\n') // ���������
    {
        op_error = 1;             // ��Ǵ���
        while (getchar() != '\n') // ˢ�����뻺���������߻��з�
            ;
    }
    while (op != '1' && op != '2' && op != '3' && op != '4' || op_error) // ���������
    {
        op_error = 0; // �ظ�ʹ�ñ��
        printf("����������������� 1 �� 2 �� 3 �� 4!\n");
        scanf("%c", &op); // ��������
        if (op == '1' || op == '2' || op == '3' || op == '4')
        {
            if (getchar() != '\n') // ���������
            {
                op_error = 1;             // ��Ǵ���
                while (getchar() != '\n') // ˢ�����뻺���������߻��з�
                    ;
            }
            else
            {
                return op; // ������ȷ����������ֵ
            }
        }
        else
        {
            while (getchar() != '\n') // ˢ�����뻺���������߻��з���������������
                ;
        }
    }
    return op;
}
void MembershipManagement() // ��Ա����
{
    int op2 = 0;
    int membernum = 0; // ��Ա����
    printf("ͼ�����۹���ϵͳ>��Ա����\n");
    printf("**************************\n");
    printf("*  1.��ʾ���л�Ա        *\n");
    printf("*  2.��ӻ�Ա��Ϣ        *\n");
    printf("*  3.�޸Ļ�Ա��Ϣ        *\n");
    printf("*  4.�������˵�          *\n");
    printf("**************************\n");
    printf("��ѡ���������֣�");
    op2 = ErrorSettlement();
    if (op2 == '1')
    {
        ReadMembers(&membernum);  // ��ȡ��Ա��Ϣ
        PrintMembers(&membernum); // ��ӡ��Ա��Ϣ
    }
    else if (op2 == '2')
    {
        AddMember(&membernum); // ��ӻ�Ա��Ϣ
    }
    else if (op2 == '3')
    {
        ModifyMember(&membernum); // �޸Ļ�Ա��Ϣ
    }
    else if (op2 == '4')
    {
        ShowMainInterface(); // �������˵�
    }
}

void ReadMembers(int *membernum) // ��ȡ��Ա��Ϣ
{
    FILE *fp;
    if ((fp = fopen("vip.txt", "a+")) == NULL) // �򿪴洢��Ա��Ϣ�ļ�
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    *membernum = 0;
    while (!feof(fp))
    {
        ++*membernum;
        fscanf(fp, "%d%s%d", &vip[*membernum].id, vip[*membernum].name, &vip[*membernum].points); // �����ݿ��ȡ��Ա��Ϣ���ṹ������
    }
    if (fclose(fp) == EOF)
    {
        printf("�ر��ļ�ʧ�ܣ�");
        exit(0);
    }
}

void PrintMembers(int *membernum) // ��ӡ��Ա��Ϣ
{
    printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ��ʾ��Ա��Ϣ\n");
    printf("��Ա��        ����\t\t����\n");
    for (int i = 1; i <= *membernum; ++i)
    {
        printf("  %-12d%-10s%12d\n", vip[i].id, vip[i].name, vip[i].points); // ����ṹ������
    }
    MembershipManagement(); // ���ػ�Ա�������
}

void AddMember(int *membernum) // ��ӻ�Ա��Ϣ
{
    ReadMembers(membernum); // ��ȡ��Ա��Ϣ���ṹ������
    ++(*membernum);
    FILE *fp;
    if ((fp = fopen("vip.txt", "a+")) == NULL) // ��a+��ʽ�򿪣�ֱ�����ļ�ĩβ�����Ϣ
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    char newname[30];
    int newpoints = 0;
    printf("�������»�Ա�����֣�");
    scanf("%s", newname);     // �����»�Ա����
    while (getchar() != '\n') // ˢ�����뻺���������߻��з�
        ;
    printf("�������»�Ա���֣�");
    newpoints = ReadDigit(); // ��ȡ��ֵ
    fprintf(fp, "\n%-12d%-10s%12d", *membernum, newname, newpoints);
    if (fclose(fp) == EOF)
    {
        printf("�ر��ļ�ʧ�ܣ�");
        exit(0);
    }
    printf("��ӳɹ���\n");
    MembershipManagement();
}

void ModifyMember(int *membernum) // �޸Ļ�Ա��Ϣ
{
    ReadMembers(membernum); // ��ȡ��Ա��Ϣ���ṹ������
    FILE *fp;
    if ((fp = fopen("vip.txt", "r+")) == NULL) // ��r+��ʽ�򿪣��޸���Ϣ�󸲸�ԭ�ļ�
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    int modify_times = 0;
    int modify_id = 0; // Ҫ�޸ĵĻ�Ա��
    do
    {
        ++modify_times;
        printf("������Ҫ�޸ĵĻ�Ա�ţ�");
        modify_id = ReadDigit();
        if (modify_id <= *membernum && modify_id > 0) // ����Ա���м�¼
        {
            printf("������Ҫ�޸ĵĻ�Ա������");
            scanf("%s", vip[modify_id].name); // Ҫ�޸���Ϣ�Ļ�Ա��
            while (getchar() != '\n')         // ˢ�����뻺���������߻��з�
                ;
            printf("������Ҫ�޸ĵĻ�Ա���֣�");
            vip[modify_id].points = ReadDigit();      // �޸Ļ���
            for (int i = 1; i <= *membernum - 1; ++i) // ���з�����������ӡ���һλ��Ա
            {
                fprintf(fp, "%-12d%-10s%12d\n", i, vip[i].name, vip[i].points);
            }
            fprintf(fp, "%-12d%-10s%12d", *membernum, vip[*membernum].name, vip[*membernum].points); // ���һ����Ա��Ϣ������ӡ�������ӡ���໻��
            if (fclose(fp) == EOF)
            {
                printf("�ر��ļ�ʧ�ܣ�");
                exit(0);
            }
            printf("�޸ĳɹ���\n");
            break;
        }
        else
        {
            printf("��Ա�Ų��Ϸ����޸�ʧ�ܣ�����������Ҫ�޸ĵĻ�Ա��(������%d�λ���,�˳�����������ֵ�������ĸ��0)��\n", 3 - modify_times);
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
        printf("�����������벻��ȷ�����ء���Ա�������棡\n");
    }
    MembershipManagement();
}

void BooksManagement() // �鼮����ģ��
{
    int op3 = 0;
    int booknum = 0; // �鼮����
    printf("ͼ�����۹���ϵͳ>�鼮����\n");
    printf("****************\n");
    printf("* 1.�鿴��Ŀ   *\n");
    printf("* 2.����鼮   *\n");
    printf("* 3.ɾ���鼮   *\n");
    printf("* 4.�������˵� *\n");
    printf("****************\n");
    printf("��ѡ���������֣�");
    op3 = ErrorSettlement();
    if (op3 == '1')
    {
        ReadBooks(&booknum);  // ��ȡ�鼮��Ϣ
        PrintBooks(&booknum); // ��ӡ�鼮��Ϣ
    }
    else if (op3 == '2')
    {
        AddBook(&booknum); // ����鼮
    }
    else if (op3 == '3')
    {
        DeleteBook(&booknum); // ɾ���鼮
    }
    else if (op3 == '4')
    {
        ShowMainInterface(); // �������˵�
    }
}

void ReadBooks(int *booknum) // ��ȡ�鼮��Ϣ���ṹ������
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
        printf("�ر��ļ�ʧ�ܣ�");
        exit(0);
    }
}

void PrintBooks(int *booknum)
{
    ReadBooks(booknum);
    printf("ͼ�����۹���ϵͳ>�鼮����>�鼮�б�\n");
    printf("ͼ���        ͼ����\t\t\tͼ���Ǯ\n");
    for (int i = 1; i <= *booknum; ++i)
    {
        printf("  %-12d%-25s%9d\n", book[i].id, book[i].name, book[i].sale);
    }
    BooksManagement();
}

void AddBook(int *booknum) // ����鼮
{
    ReadBooks(booknum); // ��ȡ�鼮��Ϣ���ṹ������
    ++(*booknum);
    FILE *fp;
    if ((fp = fopen("book.txt", "a+")) == NULL) // ��a+��ʽ�򿪣�ֱ�����ļ�ĩβ�����Ϣ
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    char newname[30];
    int newsale = 0;
    printf("��������ͼ������֣�");
    scanf("%s", newname);
    while (getchar() != '\n') // ˢ�����뻺���������߻��з�
        ;
    printf("��������ͼ��ļ�Ǯ��");
    newsale = ReadDigit();
    fprintf(fp, "\n%-12d%-25s%12d", *booknum, newname, newsale);
    if(fclose(fp)==EOF)
    {
        printf("�ر��ļ�ʧ�ܣ�");
        exit(0);
    }
    printf("��ӳɹ���\n");
    BooksManagement();
}

void DeleteBook(int *booknum) // ɾ���鼮
{
    int delete_id = 0;                 // Ҫɾ�����鼮���
    if (FindBook(&delete_id, booknum)) // ���ҵ����鼮
    {
        DeleteOperator(&delete_id, booknum); // ɾ��
    }
    BooksManagement();
}

int FindBook(int *delete_id, int *booknum)
{
    ReadBooks(booknum);
    char delete_name[30];
    printf("������Ҫɾ����ͼ������");
    // getchar();
    scanf("%s", delete_name);
    while (getchar() != '\n') // ˢ�����뻺���������߻��з�
        ;
    for (int i = 1; i <= *booknum; ++i)
    {
        if (strcmp(delete_name, book[i].name) == 0)
        {
            printf("�ҵ���ͼ�飬λ��Ϊ��%d\n", i);
            *delete_id = i; // ��¼���鼮���
            return 1;       // �ҵ�����1
        }
        if (i == *booknum) // ��ĩβ��δ���أ���û���ҵ�
        {
            printf("û���ҵ���ͼ�飡\n");
            return 0; // δ�ҵ�
        }
    }
    return 0;
}

void DeleteOperator(int *delete_id, int *booknum)
{
    FILE *fp;
    if ((fp = fopen("book.txt", "w")) == NULL) // ��д�ķ�ʽ�򿪣��޸���Ϣ�󸲸�ԭ�ļ�
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    for (int i = 1; i <= *booknum - 1; ++i) // ��һ���鼮�������ڶ����鼮
    {
        if (i < *delete_id)
        {
            fprintf(fp, "%-12d%-25s%12d", i, book[i].name, book[i].sale); // ���С��ɾ���鼮��ŵģ��ճ���ӡ���
        }
        else if (i == *delete_id) // ����Ҫɾ�����鼮���
        {
            continue;
        }
        else if (i > *delete_id)
        {
            fprintf(fp, "%-12d%-25s%12d", i - 1, book[i].name, book[i].sale); // ��Ŵ���ɾ���鼮���ʱ����ż�1��ӡ���ļ�������
        }
        if (*delete_id == *booknum) // �����з��Ĵ�ӡ
        {
            if (i < *booknum - 1)
            {
                fprintf(fp, "\n"); // �ڴ�ӡ�����ڶ����鼮֮ǰ��ÿ��ѭ������ӡ����
            }
        }
        else // �����з��Ĵ�ӡ
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
        printf("�ر��ļ�ʧ�ܣ�");
        exit(0);
    }
    printf("ɾ���ɹ���\n");
}

void PurchaseSettlement() // �������ģ��
{
    int membernum = 0;       // ��Ա����
    int booknum = 0;         // �鼮����
    ReadMembers(&membernum); // ��ȡ��Ա��Ϣ���ṹ������
    printf("ͼ�����۹���ϵͳ >�������\n");
    ReadBooks(&booknum); // ��ȡ�鼮��Ϣ���ṹ������
    printf("ͼ�����۹���ϵͳ>�鼮����>�鼮�б�\n");
    printf("ͼ���        ͼ����\t\t\tͼ���Ǯ\n");
    for (int i = 1; i <= booknum; ++i) // չʾ�鼮��Ϣ
    {
        printf("  %-12d%-25s%12d\n", book[i].id, book[i].name, book[i].sale);
    }
    Purchase(&membernum, &booknum); // ���﹦��
    ShowMainInterface();
}

void Purchase(int *membernum, int *booknum) // ���﹦��
{
    int member_id = 0;    // ��Ա��
    int book_id = 0;      // �鼮��
    int purchase_num = 0; // ��������
    char chose;           // �Ƿ��������
    do
    {
        printf("�������Ա�ţ�");
        member_id = ReadDigit();
        while (member_id <= 0 || member_id > *membernum)
        {
            printf("��Ա������������������루�˳�����������ֵ�������ĸ��0����");
            member_id = ReadDigit();
            if (member_id == 0)
            {
                return; // �˳�����
            }
        }
        printf("������Ҫ������鼮��ţ�");
        book_id = ReadDigit();
        while (book_id <= 0 || book_id > *booknum)
        {
            printf("�鼮�������������������루�˳�����������ֵ�������ĸ��0����");
            book_id = ReadDigit();
            if (book_id == 0)
            {
                return;
            }
        }
        printf("��������Ҫ�����������");
        purchase_num = ReadDigit();
        while (purchase_num == 0)
        {
            printf("������������������������루�˳�����������ֵ�������ĸ��0����");
            purchase_num = ReadDigit();
            if (purchase_num == 0)
            {
                return;
            }
        }
        int total_money = purchase_num * book[book_id].sale; // �ܼ۸�
        if (vip[member_id].points < total_money)
        {
            printf("���ֲ��㣡����ʧ�ܣ����������棡\n");
            return;
        }
        else
        {
            vip[member_id].points -= total_money; // �۳���Ӧ����
            ModifyPoints(membernum);              // �޸��ļ���Ϣ
            printf("����ɹ���\n");
            printf("�������ͼ��Ϊ%s������Ϊ%d���ܶ�Ϊ%d\n", book[book_id].name, purchase_num, purchase_num * book[book_id].sale);
            printf("�Ƿ����?��y/n����");
            scanf(" %c", &chose);
            getchar(); // ���߻��з�
        }
    } while (chose != 'n' && chose != 'N'); // �Ƿ����
}

int ReadDigit() // �ַ���ȡת��Ϊ��ֵ�������ַ����뵽���ͱ���
{
    int x = 0; // ������ֵ
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (ch > '9' || ch < '0') // ����ֵ
        {
            while (getchar() != '\n') // ˢ�����뻺����
                ;
            return 0; // ���ش���
        }
        else if (ch >= '0' && ch <= '9') // ����ֵ
        {
            x = x * 10 + ch - '0'; // תΪ����
        }
    }
    return x;
}

void ModifyPoints(int *membernum) // �޸Ļ���
{
    FILE *fp;
    if ((fp = fopen("vip.txt", "r+")) == NULL)
    {
        printf("Failure to open vip.txt!\n");
        exit(0);
    }
    for (int i = 1; i <= *membernum - 1; ++i) // ���з�����������ӡ���һλ��Ա
    {
        fprintf(fp, "%-12d%-10s%12d\n", i, vip[i].name, vip[i].points);
    }
    fprintf(fp, "%-12d%-10s%12d", *membernum, vip[*membernum].name, vip[*membernum].points);
    if(fclose(fp)==EOF)
    {
        printf("�ر��ļ�ʧ�ܣ�");
        exit(0);
    }
}