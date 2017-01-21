#include <stdio.h>
#include <stdlib.h>											//用到了exit()、system()函数
#include <conio.h>											//用到了getche()函数
#include <string.h>											//用到了strcmp()函数

typedef unsigned char boolean;								//定义boolean，表示真或者假

#define TRUE	1											//1为真
#define FALSE	0											//0为假

typedef struct SCORE										//存储学生成绩的结构体
{
	char name[20];											//姓名
	char studentID[20];										//学号
	char specialty[20];										//专业
	char classAndGrade[10];									//班级
	int english;											//英语成绩
	int cLanguage;											//C语言成绩
	int pe;													//体育成绩
	int math;												//高数成绩
	int physics;											//大学物理成绩
	int matlab;												//MATLAB成绩
}SCORE;

boolean loginHead();	 									//登录框，综合了登录和注册功能
boolean login(FILE *fp);									//登录功能
boolean reg(FILE *fp);										//注册功能
int menu();													//菜单选择
void getFileName(char *filename);							//获取要操作的文件路径
void addScore(const char *filename, SCORE score[]);			//学生成绩添加
void showScore(const char *filename, SCORE score[]);		//学生成绩浏览
void queryScore(const char *filename, SCORE score[]);		//学生成绩查询
void sortScore(const char *filename, SCORE score[]);		//学生成绩排序
void alterScore(const char *filename, SCORE score[]);		//学生成绩修改
void deleteScore(const char *filename, SCORE score[]);		//学生成绩删除
void statisticsScore(const char *filename, SCORE score[]);	//学生成绩统计
void exitSystem();											//程序退出

void exitSystem()
{
	printf("\n\t\t谢谢使用，再见!\n");  
	printf("\n\t\t");  
	printf("按任意键退出！\n");
	getch();
	exit(1);
}

void statisticsScore(const char *filename, SCORE score[])
{
	FILE *fp;
	int mode;
	int num_A = 0, num_B = 0, num_C = 0,num_D = 0;
	int sum[100];	
	double avg[100];
	int i = 0;
	int count = 0;

	system("cls");
	printf("\t\t *^_^* 学生成绩统计 *^_^*\n");
	printf("\t\t  ┌─────────┐\n");  
	printf("\t\t  │1----大学英语成绩 │\n"); 
	printf("\t\t  │2-------C语言成绩 │\n"); 
	printf("\t\t  │3--------体育成绩 │\n"); 
	printf("\t\t  │4----高等数学成绩 │\n"); 
	printf("\t\t  │5----大学物理成绩 │\n");
	printf("\t\t  │6------MATLAB成绩 │\n");
	printf("\t\t  │7----------总成绩 │\n");
	printf("\t\t  │8--------平均成绩 │\n");
    printf("\t\t  │9------------返回 │\n");  
    printf("\t\t  └─────────┘\n");  
    printf("请输入你要统计的方式：\n");  
    scanf("%d",&mode);  

	while(mode < 1 || mode > 9)  
	{  
		printf("\t\t输入错误，请重新输入！\n"); 
		printf("\t\t请输入你要排序的方式："); 
		scanf("%d", &mode);  
	}
	system("cls");

	if ((fp = fopen(filename, "rt")) == NULL)  
	{     
		printf("Sorry, can't open file!\n");   
		printf("按任意键退出！\n");
		getch();
		exit(1);
	}
	
	while(fscanf(fp, "%s %s %s %s %d %d %d %d %d %d", 
		score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
		&score[i].english, &score[i].cLanguage, &score[i].pe, &score[i].math, &score[i].physics, &score[i].matlab) != EOF)
	{
		i++;
		count++;
	}
	fclose(fp);

	switch (mode)
	{
		case 1:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----优秀 │\n"); 
			printf("\t\t  │2----良好 │\n"); 
			printf("\t\t  │3----及格 │\n"); 
			printf("\t\t  │4--不及格 │\n"); 
			printf("\t\t  └─────┘\n");  
			printf("请输入你要统计的方式：\n");  
			scanf("%d",&mode);  

			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要统计的方式："); 
				scanf("%d", &mode);  
			}

			for (i = 0; i < count; i++)
			{
				if(score[i].english >= 90)
					num_A++;
				else if(score[i].english >= 70)
					num_B++;
				else if(score[i].english >= 60)
					num_C++;
				else
					num_D++;
			}

			switch (mode)
			{
				case 1:
					printf("大学英语成绩优秀的有%d人！\n", num_A);
					break;
				case 2:
					printf("大学英语成绩良好的有%d人！\n", num_B);
					break;
				case 3:
					printf("大学英语成绩及格的有%d人！\n", num_C);
					break;
				case 4:
					printf("大学英语成绩不及格的有%d人！\n", num_D);
					break;
			}
			break;
		case 2:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----优秀 │\n"); 
			printf("\t\t  │2----良好 │\n"); 
			printf("\t\t  │3----及格 │\n"); 
			printf("\t\t  │4--不及格 │\n"); 
			printf("\t\t  └─────┘\n");  
			printf("请输入你要统计的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要统计的方式："); 
				scanf("%d", &mode);  
			}
			
			for (i = 0; i < count; i++)
			{
				if(score[i].cLanguage >= 90)
					num_A++;
				else if(score[i].cLanguage >= 70)
					num_B++;
				else if(score[i].cLanguage >= 60)
					num_C++;
				else
					num_D++;
			}
			
			switch (mode)
			{
				case 1:
					printf("C语言成绩优秀的有%d人！\n", num_A);
					break;
				case 2:
					printf("C语言成绩良好的有%d人！\n", num_B);
					break;
				case 3:
					printf("C语言成绩及格的有%d人！\n", num_C);
					break;
				case 4:
					printf("C语言成绩不及格的有%d人！\n", num_D);
					break;
			}
			break;
		case 3:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----优秀 │\n"); 
			printf("\t\t  │2----良好 │\n"); 
			printf("\t\t  │3----及格 │\n"); 
			printf("\t\t  │4--不及格 │\n"); 
			printf("\t\t  └─────┘\n");  
			printf("请输入你要统计的方式：\n");  
			scanf("%d",&mode);  

			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要统计的方式："); 
				scanf("%d", &mode);  
			}

			for (i = 0; i < count; i++)
			{
				if(score[i].pe >= 90)
					num_A++;
				else if(score[i].pe >= 70)
					num_B++;
				else if(score[i].pe >= 60)
					num_C++;
				else
					num_D++;
			}

			switch (mode)
			{
				case 1:
					printf("体育成绩优秀的有%d人！\n", num_A);
					break;
				case 2:
					printf("体育成绩良好的有%d人！\n", num_B);
					break;
				case 3:
					printf("体育成绩及格的有%d人！\n", num_C);
					break;
				case 4:
					printf("体育成绩不及格的有%d人！\n", num_D);
					break;
			}
			break;
		case 4:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----优秀 │\n"); 
			printf("\t\t  │2----良好 │\n"); 
			printf("\t\t  │3----及格 │\n"); 
			printf("\t\t  │4--不及格 │\n"); 
			printf("\t\t  └─────┘\n");  
			printf("请输入你要统计的方式：\n");  
			scanf("%d",&mode);  
				
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要统计的方式："); 
				scanf("%d", &mode);  
			}
			
			for (i = 0; i < count; i++)
			{
				if(score[i].math >= 90)
					num_A++;
				else if(score[i].math >= 70)
					num_B++;
				else if(score[i].math >= 60)
					num_C++;
				else
					num_D++;
			}
			
			switch (mode)
			{
				case 1:
					printf("高等数学成绩优秀的有%d人！\n", num_A);
					break;
				case 2:
					printf("高等数学成绩良好的有%d人！\n", num_B);
					break;
				case 3:
					printf("高等数学成绩及格的有%d人！\n", num_C);
					break;
				case 4:
					printf("高等数学成绩不及格的有%d人！\n", num_D);
					break;
			}
			break;
		case 5:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----优秀 │\n"); 
			printf("\t\t  │2----良好 │\n"); 
			printf("\t\t  │3----及格 │\n"); 
			printf("\t\t  │4--不及格 │\n"); 
			printf("\t\t  └─────┘\n");  
			printf("请输入你要统计的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要统计的方式："); 
				scanf("%d", &mode);  
			}
			
			for (i = 0; i < count; i++)
			{
				if(score[i].physics >= 90)
					num_A++;
				else if(score[i].physics >= 70)
					num_B++;
				else if(score[i].physics >= 60)
					num_C++;
				else
					num_D++;
			}
			
			switch (mode)
			{
				case 1:
					printf("大学物理成绩优秀的有%d人！\n", num_A);
					break;
				case 2:
					printf("大学物理成绩良好的有%d人！\n", num_B);
					break;
				case 3:
					printf("大学物理成绩及格的有%d人！\n", num_C);
					break;
				case 4:
					printf("大学物理成绩不及格的有%d人！\n", num_D);
					break;
			}
			break;
		case 6:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----优秀 │\n"); 
			printf("\t\t  │2----良好 │\n"); 
			printf("\t\t  │3----及格 │\n"); 
			printf("\t\t  │4--不及格 │\n"); 
			printf("\t\t  └─────┘\n");  
			printf("请输入你要统计的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要统计的方式："); 
				scanf("%d", &mode);  
			}
			
			for (i = 0; i < count; i++)
			{
				if(score[i].matlab >= 90)
					num_A++;
				else if(score[i].matlab >= 70)
					num_B++;
				else if(score[i].matlab >= 60)
					num_C++;
				else
					num_D++;
			}
			
			switch (mode)
			{
				case 1:
					printf("MATLAB成绩优秀的有%d人！\n", num_A);
					break;
				case 2:
					printf("MATLAB成绩良好的有%d人！\n", num_B);
					break;
				case 3:
					printf("MATLAB成绩及格的有%d人！\n", num_C);
					break;
				case 4:
					printf("MATLAB成绩不及格的有%d人！\n", num_D);
					break;
			}
			break;
		case 7:
			for(i = 0; i < count; i++)
			{
				sum[i] = score[i].english + score[i].cLanguage + score[i].pe + score[i].math + score[i].physics + score[i].matlab;
			}

			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----优秀 │\n"); 
			printf("\t\t  │2----良好 │\n"); 
			printf("\t\t  │3----及格 │\n"); 
			printf("\t\t  │4--不及格 │\n"); 
			printf("\t\t  └─────┘\n");  
			printf("请输入你要统计的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要统计的方式："); 
				scanf("%d", &mode);  
			}
			
			for (i = 0; i < count; i++)
			{
				if(sum[i] >= 540)
					num_A++;
				else if(sum[i] >= 420)
					num_B++;
				else if(sum[i] >= 360)
					num_C++;
				else
					num_D++;
			}
			
			switch (mode)
			{
				case 1:
					printf("总成绩优秀的有%d人！\n", num_A);
					break;
				case 2:
					printf("总成绩良好的有%d人！\n", num_B);
					break;
				case 3:
					printf("总成绩及格的有%d人！\n", num_C);
					break;
				case 4:
					printf("总成绩不及格的有%d人！\n", num_D);
					break;
			}
			break;
		case 8:
			for(i = 0; i < count; i++)
			{
				avg[i] = (score[i].english + score[i].cLanguage + score[i].pe + score[i].math + score[i].physics + score[i].matlab) / 6.0;
			}

			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----优秀 │\n"); 
			printf("\t\t  │2----良好 │\n"); 
			printf("\t\t  │3----及格 │\n"); 
			printf("\t\t  │4--不及格 │\n"); 
			printf("\t\t  └─────┘\n");  
			printf("请输入你要统计的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要统计的方式："); 
				scanf("%d", &mode);  
			}
			
			for (i = 0; i < count; i++)
			{
				if(sum[i] >= 90)
					num_A++;
				else if(sum[i] >= 70)
					num_B++;
				else if(sum[i] >= 60)
					num_C++;
				else
					num_D++;
			}
			
			switch (mode)
			{
				case 1:
					printf("平均成绩优秀的有%d人！\n", num_A);
					break;
				case 2:
					printf("平均成绩良好的有%d人！\n", num_B);
					break;
				case 3:
					printf("平均成绩及格的有%d人！\n", num_C);
					break;
				case 4:
					printf("平均成绩不及格的有%d人！\n", num_D);
					break;
			}
			break;
		case 9:
			return;
	}

	printf("按任意键返回主菜单！\n");
	getch();
}

void deleteScore(const char *filename, SCORE score[])		//按照学号删除
{
	FILE *fp;
	int i = 0;
	int count = 0;
	int flag;
	int handle;
	char deleteStudentID[20];
	char sign = 'y';
	
	while(sign != 'n' && sign != 'N')                     
	{  
		system("cls");
		printf("\t\t *^_^* 学生成绩删除 *^_^*\n");
		
		i = 0;
		count = 0;
		
		if ((fp = fopen(filename, "rt")) == NULL)  
		{     
			printf("Sorry, can't open file!\n");   
			printf("按任意键退出！\n");
			getch();
			exit(1);
		}
		
		while(fscanf(fp, "%s %s %s %s %d %d %d %d %d %d", 
			score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
			&score[i].english, &score[i].cLanguage, &score[i].pe, &score[i].math, &score[i].physics, &score[i].matlab) != EOF)
		{
			i++;
			count++;
		}
		
		fclose(fp);
		
		printf("请输入需要删除的学生的学号(如：03141321)：");  
		scanf("%s", deleteStudentID);
		
		if ((fp = fopen(filename, "wt")) == NULL)                 
		{  
			printf("Sorry, can't open file!\n");   
			printf("按任意键退出！\n");
			getch();
			exit(1);	
		}  
		
		flag = 1;
		handle = 1;
		
		for(i = 0; i < count; i++) 
		{
			if((flag = strcmp(score[i].studentID, deleteStudentID)) != 0)   
			{
				fprintf(fp, "%-10s %-10s %-10s %-10s %-6d %-6d %-6d %-6d %-6d %-6d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab);
			}
			
			if(flag == 0)
				handle = flag;
		}
		fclose(fp);
		
		if(handle)
		{
			printf("未找到符合的信息！\n");
		}
		else
		{
			printf("数据删除成功！\n"); 
		} 
		
		do
		{
			printf("是否继续删除？(y/n)\n");
			fflush(stdin);
			scanf("\t%c", &sign);
		}while(sign != 'y' && sign != 'Y' && sign != 'n' && sign != 'N');
	}
	
	printf("按任意键返回主菜单！\n");
	getch();
}

void alterScore(const char *filename, SCORE score[])
{
	FILE *fp;
	int mode;
	int i = 0;
	int j;
	int count = 0;
	char alterStudentID[20];
	char sign = 'y';
	
	while(sign != 'n' && sign != 'N')                     
	{  
		system("cls"); 
		printf("\t\t *^_^* 学生成绩修改 *^_^*\n"); 
		
		i = 0;
		count = 0;
		
		if ((fp = fopen(filename, "rt")) == NULL)  
		{     
			printf("Sorry, can't open file!\n");   
			printf("按任意键退出！\n");
			getch();
			exit(1);
		}
		
		while(fscanf(fp, "%s %s %s %s %d %d %d %d %d %d", 
			score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
			&score[i].english, &score[i].cLanguage, &score[i].pe, &score[i].math, &score[i].physics, &score[i].matlab) != EOF)
		{
			i++;
			count++;
		}
		
		fclose(fp);
		
		printf("请输入需要修改的学生的学号(如：03141320)：");  
		scanf("%s", alterStudentID);
		
		for(i = 0; i < count; i++) 
		{
			if(strcmp(score[i].studentID, alterStudentID) == 0)   
			{
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab); 
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				
				printf("\t\t┌───────────┐\n");  
				printf("\t\t│1------------全部修改 │\n");  
				printf("\t\t│2------------姓名修改 │\n");  
				printf("\t\t│3------------学号修改 │\n");  
				printf("\t\t│4------------专业修改 │\n");
				printf("\t\t│5------------班级修改 │\n"); 
				printf("\t\t│6----大学英语成绩修改 │\n"); 
				printf("\t\t│7-------C语言成绩修改 │\n"); 
				printf("\t\t│8--------体育成绩修改 │\n"); 
				printf("\t\t│9----高等数学成绩修改 │\n"); 
				printf("\t\t│10---大学物理成绩修改 │\n");
				printf("\t\t│11-----MATLAB成绩修改 │\n");
				printf("\t\t│12---------------返回 │\n");  
				printf("\t\t└───────────┘\n");  
				printf("\t\t请输入你要修改的方式：");  
				scanf("%d", &mode);  
				
				while(mode < 1 || mode > 12)  
				{  
					printf("\t\t输入错误，请重新输入！\n"); 
					printf("\t\t请输入你要修改的方式："); 
					scanf("%d", &mode);  
				}
				
				switch (mode)
				{
				case 1:
					printf("姓名(如：吕兴)：\n"); 
					scanf("\t%s", score[i].name);  
					printf("学号(如：03141322))：\n");   
					scanf("\t%s", score[i].studentID);  
	
					for(j = 0; j < count; j++)
					{
						if(strcmp(score[i].studentID, score[j].studentID) == 0)  
						{  
							printf("该学生已存在！\n");  
							fclose(fp);
							printf("按任意键返回主菜单！\n");
							getch();
							return;
						}  
					}

					printf("专业(如：通信工程)：\n");  
					scanf("\t%s", score[i].specialty);  
					printf("班级(如：1411))：\n");  
					scanf("\t%s", score[i].classAndGrade);  
					printf("大学英语成绩(0~100)：\n");  
					scanf("\t%d", &score[i].english);  
					printf("C语言成绩(0~100)：\n");  
					scanf("\t%d", &score[i].cLanguage);
					printf("体育成绩(0~100)：\n");  
					scanf("\t%d", &score[i].pe);
					printf("高等数学成绩(0~100)：\n");  
					scanf("\t%d", &score[i].math);
					printf("大学物理成绩(0~100)：\n");  
					scanf("\t%d", &score[i].physics);
					printf("MATLAB成绩(0~100)：\n");  
					scanf("\t%d", &score[i].matlab);
					break;
				case 2:
					printf("姓名(如：吕兴)：\n"); 
					scanf("\t%s", score[i].name);
					break;
				case 3:
					printf("学号(如：03141322))：\n");   
					scanf("\t%s", score[i].studentID);

					for(j = 0; j < count; j++)
					{
						if(strcmp(score[i].studentID, score[j].studentID) == 0)  
						{  
							printf("该学生已存在！\n");  
							fclose(fp);
							printf("按任意键返回主菜单！\n");
							getch();
							return;
						}  
					}
					break;
				case 4:
					printf("专业(如：通信工程)：\n");  
					scanf("\t%s", score[i].specialty);
					break;
				case 5:
					printf("班级(如：1411))：\n");  
					scanf("\t%s", score[i].classAndGrade);
					break;
				case 6:
					printf("大学英语成绩(0~100)：\n");  
					scanf("\t%d", &score[i].english); 
					break;
				case 7:
					printf("C语言成绩(0~100)：\n");  
					scanf("\t%d", &score[i].cLanguage);
					break;
				case 8:
					printf("体育成绩(0~100)：\n");  
					scanf("\t%d", &score[i].pe);
					break;
				case 9:
					printf("高等数学成绩(0~100)：\n");  
					scanf("\t%d", &score[i].math);
					break;
				case 10:
					printf("大学物理成绩(0~100)：\n");  
					scanf("\t%d", &score[i].physics);
					break;
				case 11:
					printf("MATLAB成绩(0~100)：\n");  
					scanf("\t%d", &score[i].matlab);
					break;
				case 12:
					return;
				}
				
				if ((fp = fopen(filename, "wt")) == NULL)                 
				{  
					printf("Sorry, can't open file!\n");   
					printf("按任意键退出！\n");
					getch();
					exit(1);	
				}  
				
				for(j = 0; j < count; j++) 
				{
					fprintf(fp, "%-10s %-10s %-10s %-10s %-6d %-6d %-6d %-6d %-6d %-6d\n", 
						score[j].name, score[j].studentID, score[j].specialty, score[j].classAndGrade, 
						score[j].english, score[j].cLanguage, score[j].pe, score[j].math, score[j].physics, score[j].matlab);
				}
				fclose(fp);
				
				break;
			}
		}
		
		if(i == count)
		{
			printf("未找到符合的信息！\n");
		}
		else
		{
			printf("数据修改成功！\n");
		}
		
		do
		{
			printf("是否继续修改？(y/n)\n");
			fflush(stdin);
			scanf("\t%c", &sign);
		}while(sign != 'y' && sign != 'Y' && sign != 'n' && sign != 'N');
	}
	
	printf("按任意键返回主菜单！\n");
	getch();
}

void sortScore(const char *filename, SCORE score[])
{
	FILE *fp;  
    SCORE temp;  
	int mode;
	int i = 0;
	int j = 0;
	int count = 0;
	int sum[100];
	int sumTemp;
	double avg[100];
	double avgTemp;
	
    system("cls");  
	printf("\t\t *^_^* 学生成绩排序 *^_^*\n");  
	
    printf("\t\t  ┌─────────┐\n");  
	printf("\t\t  │1----大学英语成绩 │\n"); 
	printf("\t\t  │2-------C语言成绩 │\n"); 
	printf("\t\t  │3--------体育成绩 │\n"); 
	printf("\t\t  │4----高等数学成绩 │\n"); 
	printf("\t\t  │5----大学物理成绩 │\n");
	printf("\t\t  │6------MATLAB成绩 │\n");
	printf("\t\t  │7----------总成绩 │\n");
	printf("\t\t  │8--------平均成绩 │\n");
    printf("\t\t  │9------------返回 │\n");  
    printf("\t\t  └─────────┘\n");  
    printf("请输入你要排序的方式：\n");  
    scanf("%d",&mode);  
	
    while(mode < 1 || mode > 9)  
	{  
		printf("\t\t输入错误，请重新输入！\n"); 
		printf("\t\t请输入你要排序的方式："); 
		scanf("%d", &mode);  
	}
	system("cls");
	
	if ((fp = fopen(filename, "rt")) == NULL)  
	{     
		printf("Sorry, can't open file!\n");   
		printf("按任意键退出！\n");
		getch();
		exit(1);
	}
	
	while(fscanf(fp, "%s %s %s %s %d %d %d %d %d %d", 
		score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
		&score[i].english, &score[i].cLanguage, &score[i].pe, &score[i].math, &score[i].physics, &score[i].matlab) != EOF)
	{
		i++;
		count++;
	}
	fclose(fp);
	
	switch (mode)
	{
		case 1:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----升序 │\n"); 
			printf("\t\t  │2----降序 │\n");  
			printf("\t\t  └─────┘\n");  
			printf("请输入你要排序的方式：\n");  
			scanf("%d",&mode);  
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要排序的方式："); 
				scanf("%d", &mode);  
			}
			if(mode == 1)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].english > score[j+1].english)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}

			if(mode == 2)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].english < score[j+1].english)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			printf("\t\t\t\t*^_^* 根据大学英语成绩排序 *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			for(i = 0; i < count; i++)
			{
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab); 
			}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			break;
		case 2:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----升序 │\n"); 
			printf("\t\t  │2----降序 │\n");  
			printf("\t\t  └─────┘\n");  
			printf("请输入你要排序的方式：\n");  
			scanf("%d",&mode);  

			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要排序的方式："); 
				scanf("%d", &mode);  
			}

			if(mode == 1)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].cLanguage > score[j+1].cLanguage)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}

			if(mode == 2)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].cLanguage < score[j+1].cLanguage)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			printf("\t\t\t\t*^_^* 根据C语言成绩排序 *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			for(i = 0; i < count; i++)
			{
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab); 
			}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			break;
		case 3:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----升序 │\n"); 
			printf("\t\t  │2----降序 │\n");  
			printf("\t\t  └─────┘\n");  
			printf("请输入你要排序的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要排序的方式："); 
				scanf("%d", &mode);  
			}
			
			if(mode == 1)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].pe > score[j+1].pe)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			if(mode == 2)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].pe < score[j+1].pe)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			printf("\t\t\t\t*^_^* 根据体育成绩排序 *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			for(i = 0; i < count; i++)
			{
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab); 
			}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			break;
		case 4:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----升序 │\n"); 
			printf("\t\t  │2----降序 │\n");  
			printf("\t\t  └─────┘\n");  
			printf("请输入你要排序的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要排序的方式："); 
				scanf("%d", &mode);  
			}
			
			if(mode == 1)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].math > score[j+1].math)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			if(mode == 2)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].math < score[j+1].math)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			printf("\t\t\t\t*^_^* 根据高等数学成绩排序 *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			for(i = 0; i < count; i++)
			{
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab); 
			}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			break;
		case 5:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----升序 │\n"); 
			printf("\t\t  │2----降序 │\n");  
			printf("\t\t  └─────┘\n");  
			printf("请输入你要排序的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要排序的方式："); 
				scanf("%d", &mode);  
			}
			
			if(mode == 1)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].physics > score[j+1].physics)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			if(mode == 2)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].physics < score[j+1].physics)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			printf("\t\t\t\t*^_^* 根据大学物理成绩排序 *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			for(i = 0; i < count; i++)
			{
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab); 
			}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			break;
		case 6:
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----升序 │\n"); 
			printf("\t\t  │2----降序 │\n");  
			printf("\t\t  └─────┘\n");  
			printf("请输入你要排序的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要排序的方式："); 
				scanf("%d", &mode);  
			}
			
			if(mode == 1)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].matlab > score[j+1].matlab)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			if(mode == 2)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(score[j].matlab < score[j+1].matlab)
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
						}
					}
				}
			}
			
			printf("\t\t\t\t*^_^* 根据MATLAB成绩排序 *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			for(i = 0; i < count; i++)
			{
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab); 
			}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			break;
		case 7:
			for(i = 0; i < count; i++)
			{
				sum[i] = score[i].english + score[i].cLanguage + score[i].pe + score[i].math + score[i].physics + score[i].matlab;
			}

			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----升序 │\n"); 
			printf("\t\t  │2----降序 │\n");  
			printf("\t\t  └─────┘\n");  
			printf("请输入你要排序的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要排序的方式："); 
				scanf("%d", &mode);  
			}
			
			if(mode == 1)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(sum[j] > sum[j+1])
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
							
							sumTemp = sum[j];
							sum[j] = sum[j+1];
							sum[j+1] = sumTemp;
						}
					}
				}
			}
			
			if(mode == 2)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(sum[j] < sum[j+1])
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
							
							sumTemp = sum[j];
							sum[j] = sum[j+1];
							sum[j+1] = sumTemp;
						}
					}
				}
			}
			
			
			printf("\t\t\t\t*^_^* 根据总成绩排序 *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB 总成绩\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			for(i = 0; i < count; i++)
			{
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d%d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab, sum[i]); 
			}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			break;
		case 8:
			for(i = 0; i < count; i++)
			{
				avg[i] = (score[i].english + score[i].cLanguage + score[i].pe + score[i].math + score[i].physics + score[i].matlab) / 6.0;
			}
			
			printf("\t\t  ┌─────┐\n");  
			printf("\t\t  │1----升序 │\n"); 
			printf("\t\t  │2----降序 │\n");  
			printf("\t\t  └─────┘\n");  
			printf("请输入你要排序的方式：\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t输入错误，请重新输入！\n"); 
				printf("\t\t请输入你要排序的方式："); 
				scanf("%d", &mode);  
			}
			
			if(mode == 1)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(avg[j] > avg[j+1])
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
							
							avgTemp = avg[j];
							avg[j] = avg[j+1];
							avg[j+1] = avgTemp;
						}
					}
				}
			}

			if(mode == 2)
			{
				for(i = 0; i < count - 1; i++)
				{
					for(j = 0; j < count - 1 - i; j++)
					{
						if(avg[j] < avg[j+1])
						{
							temp = score[j];
							score[j] = score[j+1];
							score[j+1] = temp;
							
							avgTemp = avg[j];
							avg[j] = avg[j+1];
							avg[j+1] = avgTemp;
						}
					}
				}
			}
			
			printf("\t\t\t\t*^_^* 根据平均成绩排序 *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB 平均成绩\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			for(i = 0; i < count; i++)
			{
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-7d%.2f\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab, avg[i]); 
			}
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			break;
		case 9:
			return;
	}
	
	printf("按任意键返回主菜单！\n");
	getch();
}

void queryScore(const char *filename, SCORE score[])
{
	FILE *fp;
	int mode;
	int i = 0;
	int count = 0;
	int handle;
	char temp[20];
	
	system("cls"); 
	
	printf("\t\t *^_^* 学生成绩查询 *^_^*\n"); 
    printf("\t\t     ┌──────┐\n");  
    printf("\t\t     │1--模糊查询 │\n");  
    printf("\t\t     │2------姓名 │\n");  
    printf("\t\t     │3------学号 │\n");  
	printf("\t\t     │4------专业 │\n");
	printf("\t\t     │5------班级 │\n");
    printf("\t\t     │6------返回 │\n");  
    printf("\t\t     └──────┘\n");  
    printf("\t\t请输入你要查询的方式：");  
    scanf("%d", &mode);  
	
	while(mode < 1 || mode > 6)  
	{  
		printf("\t\t输入错误，请重新输入！\n");  
		printf("\t\t请输入你要查询的方式：");
		scanf("%d", &mode);  
	}
	
	if ((fp = fopen(filename, "rt")) == NULL)                
	{  
		printf("Sorry, can't open file!\n");   
		printf("按任意键退出！\n");
		getch();
		exit(1);  
	}  
	
	while(fscanf(fp, "%s %s %s %s %d %d %d %d %d %d", 
		score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
		&score[i].english, &score[i].cLanguage, &score[i].pe, &score[i].math, &score[i].physics, &score[i].matlab) != EOF)
	{
		i++;
		count++;
	}
	
	fclose(fp); 
	
	if(mode == 1)                                                
	{    
        system("cls");  
        printf("\t请输入想查询的姓(如：李)：");  
        scanf("%s", temp);  
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        for(i=0; i < count; i++)                                               
        {  			
			if((score[i].name[0] == temp[0] && score[i].name[1] == temp[1]) || 
				(score[i].name[0] == temp[0] && score[i].name[1] == temp[1] && score[i].name[2] == temp[2] && score[i].name[3] == temp[3]))             
            {  
                printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab);  
            }  
        }  
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}  
	
    if(mode == 2)                                           
	{  
		handle = 0;
		
		system("cls");
        printf("\t请输入想查询的姓名(如：吕兴)：");  
        scanf("%s", temp);
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        for(i=0; i < count; i++)                                               
        {  			
			if(!strcmp(score[i].name, temp))             
            {  
                printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab);
				handle++;
            }  
        }  
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		
		if(handle == 0)  
		{  
			printf("\t未找到符合的信息！\n");  
			printf("按任意键返回主菜单！\n");
			getch();  
			return;  
		}  
	}  
	
    if(mode == 3)                                                         
	{ 
		handle = 0;
		
		system("cls");
        printf("\t请输入想查询的学号(如：03141321)：");  
        scanf("%s", temp);
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        for(i=0; i < count; i++)                                               
        {  			
			if(!strcmp(score[i].studentID, temp))             
            {  
                printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab);
				handle++;
            }  
        }  
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		
		if(handle == 0)  
		{  
			printf("\t未找到符合的信息！\n");  
			printf("按任意键返回主菜单！\n");
			getch(); 
			return;  
		}  
	}  
	
	if(mode == 4)                                                         
	{ 
		handle = 0;
		
		system("cls");
        printf("\t请输入想查询的专业(如：通信工程)：");  
        scanf("%s", temp);
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        for(i=0; i < count; i++)                                               
        {  
			if(!strcmp(score[i].specialty, temp))             
            {  
                printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab);
				handle++;
            }  
        }  
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		
		if(handle == 0)  
		{  
			printf("\t未找到符合的信息！\n");  
			printf("按任意键返回主菜单！\n");
			getch();  
			return;  
		}  
	}  
	
	if(mode == 5)                                                         
	{ 
		handle = 0;
		
		system("cls");
        printf("\t请输入想查询的班级(如：1411)：");  
        scanf("%s", temp);
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        for(i=0; i < count; i++)                                               
        {  
			
			if(!strcmp(score[i].classAndGrade, temp))             
            {  
                printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab);
				handle++;
            }  
        }  
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		
		if(handle == 0)  
		{  
			printf("\t未找到符合的信息！\n");  
			printf("按任意键返回主菜单！\n");
			getch();  
			return;  
		}  
	}  
	
	if(mode == 6)
	{
		return;
	}
	
	printf("按任意键返回主菜单！\n");
	getch();
}

void showScore(const char *filename, SCORE score[])
{
	FILE *fp;
	int i = 0;
	
	if ((fp = fopen(filename, "rt")) == NULL)  
	{     
		printf("Sorry, can't open file!\n");   
		printf("按任意键退出！\n");
		getch(); 
		exit(1);
	}
	
	system("cls");
	printf("\t\t\t   *^_^* 学生成绩浏览 *^_^*\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf(" 姓名\t   学号\t      专业\t    班级   大学英语 C语言 体育 高等数学 大学物理 MATLAB\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	
	while(fscanf(fp, "%s %s %s %s %d %d %d %d %d %d", 
		score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
		&score[i].english, &score[i].cLanguage, &score[i].pe, &score[i].math, &score[i].physics, &score[i].matlab) != EOF)
	{
		printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
			score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
			score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab);
		i++;
	}
	
	fclose(fp);
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("按任意键返回主菜单！\n");
	getch();
}

void addScore(const char *filename, SCORE score[])
{
	FILE *fp;
	SCORE temp;
	char sign = 'y';
	int i = 0;
	int j = 0;
	int count = 0;
	
	if ((fp = fopen(filename, "a+")) == NULL)  
	{     
		printf("Sorry, can't open file!\n");   
		printf("按任意键退出！\n");
		getch(); 
		exit(1);
	}
	
    while(sign != 'n' && sign != 'N')                     
	{  
		system("cls");
        printf("\t\t *^_^* 学生成绩添加 *^_^*\n");  
		printf("姓名(如：Remy)：\n"); 
        scanf("\t%s", score[i].name);  
        printf("学号(如：03141320))：\n");   
        scanf("\t%s", score[i].studentID);  
		
		while(fscanf(fp, "%s %s %s %s %d %d %d %d %d %d", 
			temp.name, temp.studentID, temp.specialty, temp.classAndGrade, 
			&temp.english, &temp.cLanguage, &temp.pe, &temp.math, &temp.physics, &temp.matlab) != EOF)  
		{			
			if(strcmp(score[i].studentID, temp.studentID) == 0)  
			{  
				printf("该学生已存在！\n");  
				fclose(fp);
				printf("按任意键返回主菜单！\n");
				getch();
				return;
			}  
		}
		
        printf("专业(如：通信工程)：\n");  
        scanf("\t%s", score[i].specialty);  
        printf("班级(如：1411))：\n");  
        scanf("\t%s", score[i].classAndGrade);  
        printf("大学英语成绩(0~100)：\n");  
        scanf("\t%d", &score[i].english);  
		printf("C语言成绩(0~100)：\n");  
        scanf("\t%d", &score[i].cLanguage);
		printf("体育成绩(0~100)：\n");  
        scanf("\t%d", &score[i].pe);
		printf("高等数学成绩(0~100)：\n");  
        scanf("\t%d", &score[i].math);
		printf("大学物理成绩(0~100)：\n");  
        scanf("\t%d", &score[i].physics);
		printf("MATLAB成绩(0~100)：\n");  
        scanf("\t%d", &score[i].matlab);
		
		do
		{
			printf("是否继续添加?(y/n)");
			fflush(stdin);
			scanf("\t%c", &sign);
		}while(sign != 'y' && sign != 'Y' && sign != 'n' && sign != 'N');
		
        i++;
		count++;
        system( "cls ");  
	} 
	
	for(i = 0; i < count; i++)
	{
		if(!fprintf(fp, "%-10s %-10s %-10s %-10s %-6d %-6d %-6d %-6d %-6d %-6d\n", 
			score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
			score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab))
		{
			printf("Sorry, file write error!\n");
		}
	}
	
	fclose(fp);
	
	printf("按任意键返回主菜单！\n");
	getch(); 
}

void getFileName(char *filename)  
{  
	system("cls");  
	printf("请输入你要操作的文件的路径(如：F:\\a.txt)：");  
	scanf("%s", filename);  
	printf("按任意键继续！\n");
	getch();
}  

int menu()
{
	char ch;  
	
	do{  
        system("cls");  
        printf("\t\t ╭═════════■□■□═══╮\n");  
		printf("\t\t│         学生成绩管理系统         │\n");  
		printf("\t\t╰═══■□■□══════════╯\n");  
        printf("\t\t   ┌─────────────—┐\n");  
        printf("\t\t   │ 1. 添加记录    2. 显示记录 │\n");  
        printf("\t\t   │                            │\n");  
        printf("\t\t   │ 3. 信息查询    4. 成绩排序 │\n");  
        printf("\t\t   │                            │\n");  
        printf("\t\t   │ 5. 修改记录    6. 删除记录 │\n");  
        printf("\t\t   │                            │\n");  
        printf("\t\t   │ 7. 成绩统计    0. 退出程序 │\n");  
        printf("\t\t   └─────────────—┘\n");  
        printf("\t\t请您选择(0-7):");  
        ch = getchar();  
	}while(ch < '0' || ch > '7');  
	
	return (ch - '0');                          
}

boolean reg(FILE *fp)
{
	char userName[20];
	char password[20];
	char str[20];
	int i;
	
	if ((fp = fopen("Login Information.txt", "a+")) == NULL)  
    {     
        printf("Sorry, can't open file!\n");   
		printf("按任意键退出！\n");
		getch(); 
		exit(1);
	}
	
	printf("请输入用户名：");
	fflush(stdin);
	scanf("%s", userName);
	printf("请输入密码：");
	fflush(stdin);
	for(i = 0; i < 20; i++)
	{
		password[i] = getch();
		if(password[i] == '\r')
			break;
		printf("*");
	}
	password[i] = '\0';

	if(!strcmp(password, ""))
	{
		printf("\n密码不能能为空！\n");
		return FALSE;
	}

	while(!feof(fp))  
	{  
		fscanf(fp, "%s", str);  
		
		if(strcmp(str, userName) == 0)  
		{  
			printf("\n用户名：%s已存在！\n", userName);  
			fclose(fp);
			return FALSE;
		}  
		
		fscanf(fp, "%s", str); 	
	}
	
	fprintf(fp, "%s %s\n", userName, password);
	fclose(fp);
	
	return TRUE;
}

boolean login(FILE *fp)
{
	char userName[20];
	char password[20];
	char str[20];
	int i;
	
	if ((fp = fopen("Login Information.txt", "a+")) == NULL)  
    {     
        printf("Sorry, can't open file!\n");   
		printf("按任意键退出！\n");
		getch();
		exit(1);
	}
	
	printf("请输入用户名：");
	fflush(stdin);
	scanf("%s", userName);
	printf("请输入密码：");
	fflush(stdin);
	for(i = 0; i < 20; i++)
	{
		password[i] = getch();
		if(password[i] == '\r')
			break;
		printf("*");
	}
	password[i] = '\0';
	
	while(!feof(fp))  
	{  
		fscanf(fp, "%s", str);  
		
		if(strcmp(str, userName) == 0)  
		{  
			printf("\n\n用户名正确！\n");  
			fscanf(fp, "%s", str);  
			if(strcmp(str, password) == 0)  
			{  
				printf("密码正确！\n");
				fclose(fp);
				return TRUE;
			}
			else  
			{  
				printf("密码错误！\n"); 
				fclose(fp);
				return FALSE;
			}  
		}  
		
		fscanf(fp, "%s", str); 	
	}  
	
	printf("\n用户名：%s不存在！\n", userName);
	fclose(fp);
	
	return FALSE;
}

boolean loginHead()
{
	FILE *fp = NULL;
	char handle;
	
	printf("\t\t ╭═════════■□■□═══╮\n");  
	printf("\t\t│       学生成绩管理系统登录       │\n");  
	printf("\t\t╰═══■□■□══════════╯\n");  
	printf("\t\t   ┌─────────────—┐\n");  
	printf("\t\t   │    1、登录    2、注册      │\n");  
    printf("\t\t   └─────────────—┘\n");  
	printf("\t\t请选择您要进行的操作：");
	
	handle = getche();
	while (handle != '1' && handle != '2')
	{
		printf("\n\t\t输入有误，请重新输入：");
		handle = getche();
	}
	
	if(handle == '1')
	{
		system("cls"); 
		
		if(login(fp))
		{
			system("cls");
			printf("登陆成功！\n");
			printf("按任意键继续！\n");
			getch();
			
			return TRUE;
		}
		
		return FALSE;
	}
	
	if(handle == '2')
	{
		system("cls");
		
		if(reg(fp))
		{
			system("cls");
			printf("注册成功！\n");
			printf("按任意键继续！\n");
			getch(); 
		}
		
		return FALSE;
	}
	
	return FALSE;
}

int main(void)
{
	char filename[30];		 					 					//存储文件路径
	SCORE score[100];
	
	while(!loginHead())
		;
	
	getFileName(filename);
	
	while(1)
	{
		switch(menu())												//使用switch-case选择要进行的操作
		{  
			case 1:
				addScore(filename, score);
				break;  
			case 2: 
				showScore(filename, score);
				break;  
			case 3:    
				queryScore(filename, score);
				break;  
			case 4:  
				sortScore(filename, score);
				break;  
			case 5:  
				alterScore(filename, score);
				break;  
			case 6:  
				deleteScore(filename, score);
				break;  
			case 7:
				statisticsScore(filename, score);
				break;
			case 0: 
				exitSystem();
				break;  
		}  
	}
	
	return 0;
}
