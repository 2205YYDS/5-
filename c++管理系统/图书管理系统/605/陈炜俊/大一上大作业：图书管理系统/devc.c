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
char xingming[50][10] = {"0","张三","李四","王五","陆六","钱七","大强","小丽","敏敏"};
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
char tushuming[50][50] = {"0","C#2.0宝典","Java编程基础","J2SE桌面应用程序开发","数据库设计和应用","水浒伟","红楼梦","三国演义","地心游记",};
char *tushuming1[50];
int tushujiaqian[50] = {0,88,55,60,45,55,68,78,29};
int main(){
	zhanghaomima();
	return 0;
}
//购物结算 
void gouwujiesuan(void){
	printf("\n图书销售管理系统 >购物结算\n");
	int i;
	for(i=1;i<=p;i++){
		tushuming1[i] = tushuming[i];
	}
	printf("图书号            图书名          图书价钱\n");
	for(i=0;i<=p;i++){
		if(tushuhao[i] == 0){
			continue;
		}
		printf("%d        %20s        %d\n",tushuhao[i],tushuming1[i],tushujiaqian[i]);
	}
	printf("请输入会员号：");
	int j;
	scanf("%d",&j);
	printf("\n请输入您要购买的书籍编号：");
	int bianhao;
	scanf("%d",&bianhao);
	printf("请输入您要购买的数量：");
	int shuliang=1;
	scanf("%d",&shuliang);
	printf("\n您购买的图书为%s，数量为%d，总额为%d",tushuming[bianhao],shuliang,shuliang*tushujiaqian[bianhao]);
	printf("是否继续？（y/n）: ");
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
//删除书籍 
void shanchushuji(void){
	printf("\n图书销售管理系统 >书籍管理>书籍下架\n");
	printf("请输入要删除的图书书名：");
	char zhetushu[50] = "";
	scanf("%s",zhetushu);
	int i,j=0;
	for(i=1;i<=p;i++){
		if(strcmp(tushuming[i],zhetushu)==0){
			j=i;
		}
	}
	printf("\n找到该图书，位置为：%d\n",j);
	tushuhao[j]=0;
	tushujiaqian[j] = 0;
	char gongjuren[50] = "0";
	strcpy(tushuming[j],gongjuren);
	printf("删除成功！"); 
	shujiguanli();
	
	
	
	

}
//添加书籍 
void tianjiashuji(void){
	printf("\n图书销售管理系统 >书籍管理>添加书籍\n");
	p++;
	tushuhao[p] = p;
	printf("请输入图书名：");
	scanf("%s",&tushuming[p]);
	printf("\n请输入图书价钱：");
	scanf("%d",&tushujiaqian[p]);
	printf("\n添加成功！\n");
	shujiguanli();

}
//查看书目 
void chakanshumu(void){
	printf("\n图书销售管理系统>书籍管理>书籍列表\n");
	int i;
	for(i=1;i<=p;i++){
		tushuming1[i] = tushuming[i];
	}
	printf("图书号            图书名          图书价钱\n");
	for(i=0;i<=p;i++){
		if(tushuhao[i] == 0){
			continue;
		}
		printf("%d        %20s        %d\n",tushuhao[i],tushuming1[i],tushujiaqian[i]);
	}
	shujiguanli();
	
}
//修改会员 
void xiugaihuiyuan(void){
	printf("\n图书销售管理系统 > 会员信息管理 >修改会员信息\n");
	printf("请输入要修改的会员号：");
	int j;
	scanf("%d",&j);
	printf("\n请输入要修改的会员姓名：");
	scanf("%s",xingming1[j]); 
	printf("\n请输入要修改的会员积分：");
	scanf("%d",&jifen[j]);
	printf("\n修改成功!\n");
	huiyuanguanli();
}
//主菜单 
void printmulu(void){
	printf("******************************\n*      图书销售管理系统      *\n*         1.会员管理         *\n*         2.书籍管理         *\n*         3.购物结算         *\n*         4.注销             *\n******************************\n");
	printf("请选择，输入数字（1-4）: ");
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
//会员管理 
void huiyuanguanli(void){
	printf("\n图书销售管理系统>会员管理\n");
	int j = 0;
	printf("******************************\n*         1.显示所有会员     *\n*         2.添加会员信息     *\n*         3.修改会员信息     *\n*         4.返回主菜单       *\n******************************\n");
	printf("请选择，输入数字：") ;
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
//书籍管理 
void shujiguanli(void){
	printf("\n图书销售管理系统 >书籍管理\n");
	printf("****************\n*  1.查看书目  *\n*  2.添加书籍  *\n*  3.删除书籍  *\n*  4.返回主菜单 *\n****************\n");
	printf("请选择，输入数字：");
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
//注销 
void zhuxiao(void){
	exit(1);
}
//账号密码 
void zhanghaomima(void){
	char biaozhunyonghuming[10] = "admin";
	long biaozhunmima = 123456;
	char yonghuming [10] = "";
	long mima;
	int i = 0;
	printf("用户名：\n");
	scanf("%s",yonghuming);
	printf("密码：\n");
	scanf("%ld",&mima);
	while(strcmp(yonghuming,biaozhunyonghuming)!=0||mima!=biaozhunmima){
	if(i==2){
	printf("机会用完，退出系统");
	exit(1);
	}
	printf("\n账号或者密码错误，请再次输入\n");

	i++;
	printf("用户名：\n");
	scanf("%s",yonghuming);
	printf("密码：\n");
	scanf("%ld",&mima);
	}
	printmulu();
}
//显示会员 
void xianshihuiyuan(void){
	printf("\n图书销售管理系统 > 会员信息管理 > 显示会员信息\n");
	int i;
	printf("会员号\t姓名\t积分\n");
	for(i=1;i<=n;i++){
		printf("%d\t%s\t%d\n",i,xingming1[i],jifen[i]);
	}
	huiyuanguanli();
	
	
}
//添加会员 
void tianjiahuiyuan(void){
	printf("\n图书销售管理系统 > 会员信息管理 > 新增会员信息\n");
	n++; 
	printf("请输入新会员姓名：");
	scanf("%s",&xingming[n]);
	printf("\n请输入新会员积分：");
	scanf("%d",&jifen[n]);
	printf("\n添加成功！\n");
	huiyuanguanli();
}

