#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
int huiyuanhao[50] = {0,1,2,3,4,5,6,7,8,};
int n = 8;
struct jiegou{
	int shu;
	char ming[50][10];
}p1,p2;
int jifen[50] = {0,100,600,500,1000,900,100,100,100,};
char xingming[50][10] = {"0","����","����","����","½��","Ǯ��","��ǿ","С��","����"};
char *xingming1[50]; 
void zhanghaomima(void);
void printmulu(void);
void huiyuanguanli(void);
void shujiguanli(void);
void gouwujiesuan(void);
void zhuxiao(void);
void xianshihuiyuan(void);
void tianjiahuiyuan(void);
void xiugaihuiyuan(void);
void chakanshumu(void);
void tianjiashuji(void);
void shanchushuji(void);
void gouwujiesuan(void);
int p = 8;
int tushuhao[50] = {0,1,2,3,4,5,6,7,8,};
char tushuming[50][50] = {"0","C#2.0����","Java��̻���","J2SE����Ӧ�ó��򿪷�","���ݿ���ƺ�Ӧ��","ˮ�ΰ","��¥��","��������","�����μ�",};
char *tushuming1[50];
int tushujiaqian[50] = {0,88,55,60,45,55,68,78,29};
int main(){
	zhanghaomima();
	return 0;
}
//������� 
void gouwujiesuan(void){
	printf("\nͼ�����۹���ϵͳ >�������\n");
	int i;
	for(i=1;i<=p;i++){
		tushuming1[i] = tushuming[i];
	}
	printf("ͼ���            ͼ����          ͼ���Ǯ\n");
	for(i=0;i<=p;i++){
		if(tushuhao[i] == 0){
			continue;
		}
		printf("%d        %20s        %d\n",tushuhao[i],tushuming1[i],tushujiaqian[i]);
	}
	printf("�������Ա�ţ�");
	int j;
	scanf("%d",&j);
	printf("\n��������Ҫ������鼮��ţ�");
	int bianhao;
	scanf("%d",&bianhao);
	printf("��������Ҫ�����������");
	int shuliang=1;
	scanf("%d",&shuliang);
	printf("\n�������ͼ��Ϊ%s������Ϊ%d���ܶ�Ϊ%d",tushuming[bianhao],shuliang,shuliang*tushujiaqian[bianhao]);
	printf("�Ƿ��������y/n��: ");
	char qw;
	scanf(" %c",&qw);
	if(qw == 'n'){
		printmulu();
	}
	else{
		jifen[j] = jifen[j] - shuliang*tushujiaqian[j];
		printmulu();
	}
	
}
//ɾ���鼮 
void shanchushuji(void){
	printf("\nͼ�����۹���ϵͳ >�鼮����>�鼮�¼�\n");
	printf("������Ҫɾ����ͼ��������");
	char zhetushu[50] = "";
	scanf("%s",zhetushu);
	int i,j=0;
	for(i=1;i<=p;i++){
		if(strcmp(tushuming[i],zhetushu)==0){
			j=i;
		}
	}
	printf("\n�ҵ���ͼ�飬λ��Ϊ��%d\n",j);
	tushuhao[j]=0;
	tushujiaqian[j] = 0;
	char gongjuren[50] = "0";
	strcpy(tushuming[j],gongjuren);
	printf("ɾ���ɹ���"); 
	shujiguanli();
	
	
	
	

}
//����鼮 
void tianjiashuji(void){
	printf("\nͼ�����۹���ϵͳ >�鼮����>����鼮\n");
	p++;
	tushuhao[p] = p;
	printf("������ͼ������");
	scanf("%s",&tushuming[p]);
	printf("\n������ͼ���Ǯ��");
	scanf("%d",&tushujiaqian[p]);
	printf("\n��ӳɹ���\n");
	shujiguanli();

}
//�鿴��Ŀ 
void chakanshumu(void){
	printf("\nͼ�����۹���ϵͳ>�鼮����>�鼮�б�\n");
	int i;
	for(i=1;i<=p;i++){
		tushuming1[i] = tushuming[i];
	}
	printf("ͼ���            ͼ����          ͼ���Ǯ\n");
	for(i=0;i<=p;i++){
		if(tushuhao[i] == 0){
			continue;
		}
		printf("%d        %20s        %d\n",tushuhao[i],tushuming1[i],tushujiaqian[i]);
	}
	shujiguanli();
	
}
//�޸Ļ�Ա 
void xiugaihuiyuan(void){
	printf("\nͼ�����۹���ϵͳ > ��Ա��Ϣ���� >�޸Ļ�Ա��Ϣ\n");
	printf("������Ҫ�޸ĵĻ�Ա�ţ�");
	int j;
	scanf("%d",&j);
	printf("\n������Ҫ�޸ĵĻ�Ա������");
	scanf("%s",xingming1[j]); 
	printf("\n������Ҫ�޸ĵĻ�Ա���֣�");
	scanf("%d",&jifen[j]);
	printf("\n�޸ĳɹ�!\n");
	huiyuanguanli();
}
//���˵� 
void printmulu(void){
	printf("******************************\n*      ͼ�����۹���ϵͳ      *\n*         1.��Ա����         *\n*         2.�鼮����         *\n*         3.�������         *\n*         4.ע��             *\n******************************\n");
	printf("��ѡ���������֣�1-4��: ");
	int shuru;
	scanf("%d",&shuru);
	switch(shuru){
		case 1:
			huiyuanguanli();
			break;
		case 2:
			shujiguanli();
			break;
		case 3:
			gouwujiesuan();
			break;
		case 4:
			zhuxiao();
			break;
	}
}
//��Ա���� 
void huiyuanguanli(void){
	printf("\nͼ�����۹���ϵͳ>��Ա����\n");
	int j = 0;
	printf("******************************\n*         1.��ʾ���л�Ա     *\n*         2.��ӻ�Ա��Ϣ     *\n*         3.�޸Ļ�Ա��Ϣ     *\n*         4.�������˵�       *\n******************************\n");
	printf("��ѡ���������֣�") ;
	scanf("%d",&j);
	int o;
	for(o=0;o<=n;o++){
		xingming1[o] = xingming[o];
	}
	switch(j){
		case 1:
			xianshihuiyuan();
			break;
		case 2:
			tianjiahuiyuan();
			break;
		case 3:
			xiugaihuiyuan();
			break;
		case 4:
			printmulu();
			break;
	}
}
//�鼮���� 
void shujiguanli(void){
	printf("\nͼ�����۹���ϵͳ >�鼮����\n");
	printf("****************\n*  1.�鿴��Ŀ  *\n*  2.����鼮  *\n*  3.ɾ���鼮  *\n*  4.�������˵� *\n****************\n");
	printf("��ѡ���������֣�");
	int j;
	scanf("%d",&j);
	switch(j){
		case 1:
			chakanshumu();
			break;
		case 2:
			tianjiashuji();
			break;
		case 3:
			shanchushuji();
			break;
		case 4:
			printmulu();
	 		break;
}
} 
//ע�� 
void zhuxiao(void){
	exit(1);
}
//�˺����� 
void zhanghaomima(void){
	char biaozhunyonghuming[10] = "admin";
	long biaozhunmima = 123456;
	char yonghuming [10] = "";
	long mima;
	int i = 0;
	printf("�û�����\n");
	scanf("%s",yonghuming);
	printf("���룺\n");
	scanf("%ld",&mima);
	while(strcmp(yonghuming,biaozhunyonghuming)!=0||mima!=biaozhunmima){
	if(i==2){
	printf("�������꣬�˳�ϵͳ");
	exit(1);
	}
	printf("\n�˺Ż�������������ٴ�����\n");

	i++;
	printf("�û�����\n");
	scanf("%s",yonghuming);
	printf("���룺\n");
	scanf("%ld",&mima);
	}
	printmulu();
}
//��ʾ��Ա 
void xianshihuiyuan(void){
	printf("\nͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ��ʾ��Ա��Ϣ\n");
	int i;
	printf("��Ա��\t����\t����\n");
	for(i=1;i<=n;i++){
		printf("%d\t%s\t%d\n",i,xingming1[i],jifen[i]);
	}
	huiyuanguanli();
	
	
}
//��ӻ�Ա 
void tianjiahuiyuan(void){
	printf("\nͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ������Ա��Ϣ\n");
	n++; 
	printf("�������»�Ա������");
	scanf("%s",&xingming[n]);
	printf("\n�������»�Ա���֣�");
	scanf("%d",&jifen[n]);
	printf("\n��ӳɹ���\n");
	huiyuanguanli();
}

