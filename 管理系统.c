#include <stdio.h>
#include <stdlib.h>											//�õ���exit()��system()����
#include <conio.h>											//�õ���getche()����
#include <string.h>											//�õ���strcmp()����

typedef unsigned char boolean;								//����boolean����ʾ����߼�

#define TRUE	1											//1Ϊ��
#define FALSE	0											//0Ϊ��

typedef struct SCORE										//�洢ѧ���ɼ��Ľṹ��
{
	char name[20];											//����
	char studentID[20];										//ѧ��
	char specialty[20];										//רҵ
	char classAndGrade[10];									//�༶
	int english;											//Ӣ��ɼ�
	int cLanguage;											//C���Գɼ�
	int pe;													//�����ɼ�
	int math;												//�����ɼ�
	int physics;											//��ѧ����ɼ�
	int matlab;												//MATLAB�ɼ�
}SCORE;

boolean loginHead();	 									//��¼���ۺ��˵�¼��ע�Ṧ��
boolean login(FILE *fp);									//��¼����
boolean reg(FILE *fp);										//ע�Ṧ��
int menu();													//�˵�ѡ��
void getFileName(char *filename);							//��ȡҪ�������ļ�·��
void addScore(const char *filename, SCORE score[]);			//ѧ���ɼ����
void showScore(const char *filename, SCORE score[]);		//ѧ���ɼ����
void queryScore(const char *filename, SCORE score[]);		//ѧ���ɼ���ѯ
void sortScore(const char *filename, SCORE score[]);		//ѧ���ɼ�����
void alterScore(const char *filename, SCORE score[]);		//ѧ���ɼ��޸�
void deleteScore(const char *filename, SCORE score[]);		//ѧ���ɼ�ɾ��
void statisticsScore(const char *filename, SCORE score[]);	//ѧ���ɼ�ͳ��
void exitSystem();											//�����˳�

void exitSystem()
{
	printf("\n\t\tллʹ�ã��ټ�!\n");  
	printf("\n\t\t");  
	printf("��������˳���\n");
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
	printf("\t\t *^_^* ѧ���ɼ�ͳ�� *^_^*\n");
	printf("\t\t  ����������������������\n");  
	printf("\t\t  ��1----��ѧӢ��ɼ� ��\n"); 
	printf("\t\t  ��2-------C���Գɼ� ��\n"); 
	printf("\t\t  ��3--------�����ɼ� ��\n"); 
	printf("\t\t  ��4----�ߵ���ѧ�ɼ� ��\n"); 
	printf("\t\t  ��5----��ѧ����ɼ� ��\n");
	printf("\t\t  ��6------MATLAB�ɼ� ��\n");
	printf("\t\t  ��7----------�ܳɼ� ��\n");
	printf("\t\t  ��8--------ƽ���ɼ� ��\n");
    printf("\t\t  ��9------------���� ��\n");  
    printf("\t\t  ����������������������\n");  
    printf("��������Ҫͳ�Ƶķ�ʽ��\n");  
    scanf("%d",&mode);  

	while(mode < 1 || mode > 9)  
	{  
		printf("\t\t����������������룡\n"); 
		printf("\t\t��������Ҫ����ķ�ʽ��"); 
		scanf("%d", &mode);  
	}
	system("cls");

	if ((fp = fopen(filename, "rt")) == NULL)  
	{     
		printf("Sorry, can't open file!\n");   
		printf("��������˳���\n");
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
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n"); 
			printf("\t\t  ��3----���� ��\n"); 
			printf("\t\t  ��4--������ ��\n"); 
			printf("\t\t  ��������������\n");  
			printf("��������Ҫͳ�Ƶķ�ʽ��\n");  
			scanf("%d",&mode);  

			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫͳ�Ƶķ�ʽ��"); 
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
					printf("��ѧӢ��ɼ��������%d�ˣ�\n", num_A);
					break;
				case 2:
					printf("��ѧӢ��ɼ����õ���%d�ˣ�\n", num_B);
					break;
				case 3:
					printf("��ѧӢ��ɼ��������%d�ˣ�\n", num_C);
					break;
				case 4:
					printf("��ѧӢ��ɼ����������%d�ˣ�\n", num_D);
					break;
			}
			break;
		case 2:
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n"); 
			printf("\t\t  ��3----���� ��\n"); 
			printf("\t\t  ��4--������ ��\n"); 
			printf("\t\t  ��������������\n");  
			printf("��������Ҫͳ�Ƶķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫͳ�Ƶķ�ʽ��"); 
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
					printf("C���Գɼ��������%d�ˣ�\n", num_A);
					break;
				case 2:
					printf("C���Գɼ����õ���%d�ˣ�\n", num_B);
					break;
				case 3:
					printf("C���Գɼ��������%d�ˣ�\n", num_C);
					break;
				case 4:
					printf("C���Գɼ����������%d�ˣ�\n", num_D);
					break;
			}
			break;
		case 3:
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n"); 
			printf("\t\t  ��3----���� ��\n"); 
			printf("\t\t  ��4--������ ��\n"); 
			printf("\t\t  ��������������\n");  
			printf("��������Ҫͳ�Ƶķ�ʽ��\n");  
			scanf("%d",&mode);  

			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫͳ�Ƶķ�ʽ��"); 
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
					printf("�����ɼ��������%d�ˣ�\n", num_A);
					break;
				case 2:
					printf("�����ɼ����õ���%d�ˣ�\n", num_B);
					break;
				case 3:
					printf("�����ɼ��������%d�ˣ�\n", num_C);
					break;
				case 4:
					printf("�����ɼ����������%d�ˣ�\n", num_D);
					break;
			}
			break;
		case 4:
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n"); 
			printf("\t\t  ��3----���� ��\n"); 
			printf("\t\t  ��4--������ ��\n"); 
			printf("\t\t  ��������������\n");  
			printf("��������Ҫͳ�Ƶķ�ʽ��\n");  
			scanf("%d",&mode);  
				
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫͳ�Ƶķ�ʽ��"); 
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
					printf("�ߵ���ѧ�ɼ��������%d�ˣ�\n", num_A);
					break;
				case 2:
					printf("�ߵ���ѧ�ɼ����õ���%d�ˣ�\n", num_B);
					break;
				case 3:
					printf("�ߵ���ѧ�ɼ��������%d�ˣ�\n", num_C);
					break;
				case 4:
					printf("�ߵ���ѧ�ɼ����������%d�ˣ�\n", num_D);
					break;
			}
			break;
		case 5:
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n"); 
			printf("\t\t  ��3----���� ��\n"); 
			printf("\t\t  ��4--������ ��\n"); 
			printf("\t\t  ��������������\n");  
			printf("��������Ҫͳ�Ƶķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫͳ�Ƶķ�ʽ��"); 
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
					printf("��ѧ����ɼ��������%d�ˣ�\n", num_A);
					break;
				case 2:
					printf("��ѧ����ɼ����õ���%d�ˣ�\n", num_B);
					break;
				case 3:
					printf("��ѧ����ɼ��������%d�ˣ�\n", num_C);
					break;
				case 4:
					printf("��ѧ����ɼ����������%d�ˣ�\n", num_D);
					break;
			}
			break;
		case 6:
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n"); 
			printf("\t\t  ��3----���� ��\n"); 
			printf("\t\t  ��4--������ ��\n"); 
			printf("\t\t  ��������������\n");  
			printf("��������Ҫͳ�Ƶķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫͳ�Ƶķ�ʽ��"); 
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
					printf("MATLAB�ɼ��������%d�ˣ�\n", num_A);
					break;
				case 2:
					printf("MATLAB�ɼ����õ���%d�ˣ�\n", num_B);
					break;
				case 3:
					printf("MATLAB�ɼ��������%d�ˣ�\n", num_C);
					break;
				case 4:
					printf("MATLAB�ɼ����������%d�ˣ�\n", num_D);
					break;
			}
			break;
		case 7:
			for(i = 0; i < count; i++)
			{
				sum[i] = score[i].english + score[i].cLanguage + score[i].pe + score[i].math + score[i].physics + score[i].matlab;
			}

			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n"); 
			printf("\t\t  ��3----���� ��\n"); 
			printf("\t\t  ��4--������ ��\n"); 
			printf("\t\t  ��������������\n");  
			printf("��������Ҫͳ�Ƶķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫͳ�Ƶķ�ʽ��"); 
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
					printf("�ܳɼ��������%d�ˣ�\n", num_A);
					break;
				case 2:
					printf("�ܳɼ����õ���%d�ˣ�\n", num_B);
					break;
				case 3:
					printf("�ܳɼ��������%d�ˣ�\n", num_C);
					break;
				case 4:
					printf("�ܳɼ����������%d�ˣ�\n", num_D);
					break;
			}
			break;
		case 8:
			for(i = 0; i < count; i++)
			{
				avg[i] = (score[i].english + score[i].cLanguage + score[i].pe + score[i].math + score[i].physics + score[i].matlab) / 6.0;
			}

			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n"); 
			printf("\t\t  ��3----���� ��\n"); 
			printf("\t\t  ��4--������ ��\n"); 
			printf("\t\t  ��������������\n");  
			printf("��������Ҫͳ�Ƶķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2 && mode != 3 && mode != 4)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫͳ�Ƶķ�ʽ��"); 
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
					printf("ƽ���ɼ��������%d�ˣ�\n", num_A);
					break;
				case 2:
					printf("ƽ���ɼ����õ���%d�ˣ�\n", num_B);
					break;
				case 3:
					printf("ƽ���ɼ��������%d�ˣ�\n", num_C);
					break;
				case 4:
					printf("ƽ���ɼ����������%d�ˣ�\n", num_D);
					break;
			}
			break;
		case 9:
			return;
	}

	printf("��������������˵���\n");
	getch();
}

void deleteScore(const char *filename, SCORE score[])		//����ѧ��ɾ��
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
		printf("\t\t *^_^* ѧ���ɼ�ɾ�� *^_^*\n");
		
		i = 0;
		count = 0;
		
		if ((fp = fopen(filename, "rt")) == NULL)  
		{     
			printf("Sorry, can't open file!\n");   
			printf("��������˳���\n");
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
		
		printf("��������Ҫɾ����ѧ����ѧ��(�磺03141321)��");  
		scanf("%s", deleteStudentID);
		
		if ((fp = fopen(filename, "wt")) == NULL)                 
		{  
			printf("Sorry, can't open file!\n");   
			printf("��������˳���\n");
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
			printf("δ�ҵ����ϵ���Ϣ��\n");
		}
		else
		{
			printf("����ɾ���ɹ���\n"); 
		} 
		
		do
		{
			printf("�Ƿ����ɾ����(y/n)\n");
			fflush(stdin);
			scanf("\t%c", &sign);
		}while(sign != 'y' && sign != 'Y' && sign != 'n' && sign != 'N');
	}
	
	printf("��������������˵���\n");
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
		printf("\t\t *^_^* ѧ���ɼ��޸� *^_^*\n"); 
		
		i = 0;
		count = 0;
		
		if ((fp = fopen(filename, "rt")) == NULL)  
		{     
			printf("Sorry, can't open file!\n");   
			printf("��������˳���\n");
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
		
		printf("��������Ҫ�޸ĵ�ѧ����ѧ��(�磺03141320)��");  
		scanf("%s", alterStudentID);
		
		for(i = 0; i < count; i++) 
		{
			if(strcmp(score[i].studentID, alterStudentID) == 0)   
			{
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("%-8s %-10s %-15s %-9s %-6d %-5d %-5d  %-8d %-6d %-8d\n", 
					score[i].name, score[i].studentID, score[i].specialty, score[i].classAndGrade, 
					score[i].english, score[i].cLanguage, score[i].pe, score[i].math, score[i].physics, score[i].matlab); 
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				
				printf("\t\t��������������������������\n");  
				printf("\t\t��1------------ȫ���޸� ��\n");  
				printf("\t\t��2------------�����޸� ��\n");  
				printf("\t\t��3------------ѧ���޸� ��\n");  
				printf("\t\t��4------------רҵ�޸� ��\n");
				printf("\t\t��5------------�༶�޸� ��\n"); 
				printf("\t\t��6----��ѧӢ��ɼ��޸� ��\n"); 
				printf("\t\t��7-------C���Գɼ��޸� ��\n"); 
				printf("\t\t��8--------�����ɼ��޸� ��\n"); 
				printf("\t\t��9----�ߵ���ѧ�ɼ��޸� ��\n"); 
				printf("\t\t��10---��ѧ����ɼ��޸� ��\n");
				printf("\t\t��11-----MATLAB�ɼ��޸� ��\n");
				printf("\t\t��12---------------���� ��\n");  
				printf("\t\t��������������������������\n");  
				printf("\t\t��������Ҫ�޸ĵķ�ʽ��");  
				scanf("%d", &mode);  
				
				while(mode < 1 || mode > 12)  
				{  
					printf("\t\t����������������룡\n"); 
					printf("\t\t��������Ҫ�޸ĵķ�ʽ��"); 
					scanf("%d", &mode);  
				}
				
				switch (mode)
				{
				case 1:
					printf("����(�磺����)��\n"); 
					scanf("\t%s", score[i].name);  
					printf("ѧ��(�磺03141322))��\n");   
					scanf("\t%s", score[i].studentID);  
	
					for(j = 0; j < count; j++)
					{
						if(strcmp(score[i].studentID, score[j].studentID) == 0)  
						{  
							printf("��ѧ���Ѵ��ڣ�\n");  
							fclose(fp);
							printf("��������������˵���\n");
							getch();
							return;
						}  
					}

					printf("רҵ(�磺ͨ�Ź���)��\n");  
					scanf("\t%s", score[i].specialty);  
					printf("�༶(�磺1411))��\n");  
					scanf("\t%s", score[i].classAndGrade);  
					printf("��ѧӢ��ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].english);  
					printf("C���Գɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].cLanguage);
					printf("�����ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].pe);
					printf("�ߵ���ѧ�ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].math);
					printf("��ѧ����ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].physics);
					printf("MATLAB�ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].matlab);
					break;
				case 2:
					printf("����(�磺����)��\n"); 
					scanf("\t%s", score[i].name);
					break;
				case 3:
					printf("ѧ��(�磺03141322))��\n");   
					scanf("\t%s", score[i].studentID);

					for(j = 0; j < count; j++)
					{
						if(strcmp(score[i].studentID, score[j].studentID) == 0)  
						{  
							printf("��ѧ���Ѵ��ڣ�\n");  
							fclose(fp);
							printf("��������������˵���\n");
							getch();
							return;
						}  
					}
					break;
				case 4:
					printf("רҵ(�磺ͨ�Ź���)��\n");  
					scanf("\t%s", score[i].specialty);
					break;
				case 5:
					printf("�༶(�磺1411))��\n");  
					scanf("\t%s", score[i].classAndGrade);
					break;
				case 6:
					printf("��ѧӢ��ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].english); 
					break;
				case 7:
					printf("C���Գɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].cLanguage);
					break;
				case 8:
					printf("�����ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].pe);
					break;
				case 9:
					printf("�ߵ���ѧ�ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].math);
					break;
				case 10:
					printf("��ѧ����ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].physics);
					break;
				case 11:
					printf("MATLAB�ɼ�(0~100)��\n");  
					scanf("\t%d", &score[i].matlab);
					break;
				case 12:
					return;
				}
				
				if ((fp = fopen(filename, "wt")) == NULL)                 
				{  
					printf("Sorry, can't open file!\n");   
					printf("��������˳���\n");
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
			printf("δ�ҵ����ϵ���Ϣ��\n");
		}
		else
		{
			printf("�����޸ĳɹ���\n");
		}
		
		do
		{
			printf("�Ƿ�����޸ģ�(y/n)\n");
			fflush(stdin);
			scanf("\t%c", &sign);
		}while(sign != 'y' && sign != 'Y' && sign != 'n' && sign != 'N');
	}
	
	printf("��������������˵���\n");
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
	printf("\t\t *^_^* ѧ���ɼ����� *^_^*\n");  
	
    printf("\t\t  ����������������������\n");  
	printf("\t\t  ��1----��ѧӢ��ɼ� ��\n"); 
	printf("\t\t  ��2-------C���Գɼ� ��\n"); 
	printf("\t\t  ��3--------�����ɼ� ��\n"); 
	printf("\t\t  ��4----�ߵ���ѧ�ɼ� ��\n"); 
	printf("\t\t  ��5----��ѧ����ɼ� ��\n");
	printf("\t\t  ��6------MATLAB�ɼ� ��\n");
	printf("\t\t  ��7----------�ܳɼ� ��\n");
	printf("\t\t  ��8--------ƽ���ɼ� ��\n");
    printf("\t\t  ��9------------���� ��\n");  
    printf("\t\t  ����������������������\n");  
    printf("��������Ҫ����ķ�ʽ��\n");  
    scanf("%d",&mode);  
	
    while(mode < 1 || mode > 9)  
	{  
		printf("\t\t����������������룡\n"); 
		printf("\t\t��������Ҫ����ķ�ʽ��"); 
		scanf("%d", &mode);  
	}
	system("cls");
	
	if ((fp = fopen(filename, "rt")) == NULL)  
	{     
		printf("Sorry, can't open file!\n");   
		printf("��������˳���\n");
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
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n");  
			printf("\t\t  ��������������\n");  
			printf("��������Ҫ����ķ�ʽ��\n");  
			scanf("%d",&mode);  
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫ����ķ�ʽ��"); 
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
			
			printf("\t\t\t\t*^_^* ���ݴ�ѧӢ��ɼ����� *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n");  
			printf("\t\t  ��������������\n");  
			printf("��������Ҫ����ķ�ʽ��\n");  
			scanf("%d",&mode);  

			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫ����ķ�ʽ��"); 
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
			
			printf("\t\t\t\t*^_^* ����C���Գɼ����� *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n");  
			printf("\t\t  ��������������\n");  
			printf("��������Ҫ����ķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫ����ķ�ʽ��"); 
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
			
			printf("\t\t\t\t*^_^* ���������ɼ����� *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n");  
			printf("\t\t  ��������������\n");  
			printf("��������Ҫ����ķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫ����ķ�ʽ��"); 
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
			
			printf("\t\t\t\t*^_^* ���ݸߵ���ѧ�ɼ����� *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n");  
			printf("\t\t  ��������������\n");  
			printf("��������Ҫ����ķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫ����ķ�ʽ��"); 
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
			
			printf("\t\t\t\t*^_^* ���ݴ�ѧ����ɼ����� *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n");  
			printf("\t\t  ��������������\n");  
			printf("��������Ҫ����ķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫ����ķ�ʽ��"); 
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
			
			printf("\t\t\t\t*^_^* ����MATLAB�ɼ����� *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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

			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n");  
			printf("\t\t  ��������������\n");  
			printf("��������Ҫ����ķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫ����ķ�ʽ��"); 
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
			
			
			printf("\t\t\t\t*^_^* �����ܳɼ����� *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB �ܳɼ�\n");
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
			
			printf("\t\t  ��������������\n");  
			printf("\t\t  ��1----���� ��\n"); 
			printf("\t\t  ��2----���� ��\n");  
			printf("\t\t  ��������������\n");  
			printf("��������Ҫ����ķ�ʽ��\n");  
			scanf("%d",&mode);  
			
			while(mode != 1 && mode != 2)  
			{  
				printf("\t\t����������������룡\n"); 
				printf("\t\t��������Ҫ����ķ�ʽ��"); 
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
			
			printf("\t\t\t\t*^_^* ����ƽ���ɼ����� *^_^*\n");
			printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB ƽ���ɼ�\n");
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
	
	printf("��������������˵���\n");
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
	
	printf("\t\t *^_^* ѧ���ɼ���ѯ *^_^*\n"); 
    printf("\t\t     ����������������\n");  
    printf("\t\t     ��1--ģ����ѯ ��\n");  
    printf("\t\t     ��2------���� ��\n");  
    printf("\t\t     ��3------ѧ�� ��\n");  
	printf("\t\t     ��4------רҵ ��\n");
	printf("\t\t     ��5------�༶ ��\n");
    printf("\t\t     ��6------���� ��\n");  
    printf("\t\t     ����������������\n");  
    printf("\t\t��������Ҫ��ѯ�ķ�ʽ��");  
    scanf("%d", &mode);  
	
	while(mode < 1 || mode > 6)  
	{  
		printf("\t\t����������������룡\n");  
		printf("\t\t��������Ҫ��ѯ�ķ�ʽ��");
		scanf("%d", &mode);  
	}
	
	if ((fp = fopen(filename, "rt")) == NULL)                
	{  
		printf("Sorry, can't open file!\n");   
		printf("��������˳���\n");
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
        printf("\t���������ѯ����(�磺��)��");  
        scanf("%s", temp);  
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
        printf("\t���������ѯ������(�磺����)��");  
        scanf("%s", temp);
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
			printf("\tδ�ҵ����ϵ���Ϣ��\n");  
			printf("��������������˵���\n");
			getch();  
			return;  
		}  
	}  
	
    if(mode == 3)                                                         
	{ 
		handle = 0;
		
		system("cls");
        printf("\t���������ѯ��ѧ��(�磺03141321)��");  
        scanf("%s", temp);
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
			printf("\tδ�ҵ����ϵ���Ϣ��\n");  
			printf("��������������˵���\n");
			getch(); 
			return;  
		}  
	}  
	
	if(mode == 4)                                                         
	{ 
		handle = 0;
		
		system("cls");
        printf("\t���������ѯ��רҵ(�磺ͨ�Ź���)��");  
        scanf("%s", temp);
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
			printf("\tδ�ҵ����ϵ���Ϣ��\n");  
			printf("��������������˵���\n");
			getch();  
			return;  
		}  
	}  
	
	if(mode == 5)                                                         
	{ 
		handle = 0;
		
		system("cls");
        printf("\t���������ѯ�İ༶(�磺1411)��");  
        scanf("%s", temp);
		
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
			printf("\tδ�ҵ����ϵ���Ϣ��\n");  
			printf("��������������˵���\n");
			getch();  
			return;  
		}  
	}  
	
	if(mode == 6)
	{
		return;
	}
	
	printf("��������������˵���\n");
	getch();
}

void showScore(const char *filename, SCORE score[])
{
	FILE *fp;
	int i = 0;
	
	if ((fp = fopen(filename, "rt")) == NULL)  
	{     
		printf("Sorry, can't open file!\n");   
		printf("��������˳���\n");
		getch(); 
		exit(1);
	}
	
	system("cls");
	printf("\t\t\t   *^_^* ѧ���ɼ���� *^_^*\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf(" ����\t   ѧ��\t      רҵ\t    �༶   ��ѧӢ�� C���� ���� �ߵ���ѧ ��ѧ���� MATLAB\n");
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
	printf("��������������˵���\n");
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
		printf("��������˳���\n");
		getch(); 
		exit(1);
	}
	
    while(sign != 'n' && sign != 'N')                     
	{  
		system("cls");
        printf("\t\t *^_^* ѧ���ɼ���� *^_^*\n");  
		printf("����(�磺Remy)��\n"); 
        scanf("\t%s", score[i].name);  
        printf("ѧ��(�磺03141320))��\n");   
        scanf("\t%s", score[i].studentID);  
		
		while(fscanf(fp, "%s %s %s %s %d %d %d %d %d %d", 
			temp.name, temp.studentID, temp.specialty, temp.classAndGrade, 
			&temp.english, &temp.cLanguage, &temp.pe, &temp.math, &temp.physics, &temp.matlab) != EOF)  
		{			
			if(strcmp(score[i].studentID, temp.studentID) == 0)  
			{  
				printf("��ѧ���Ѵ��ڣ�\n");  
				fclose(fp);
				printf("��������������˵���\n");
				getch();
				return;
			}  
		}
		
        printf("רҵ(�磺ͨ�Ź���)��\n");  
        scanf("\t%s", score[i].specialty);  
        printf("�༶(�磺1411))��\n");  
        scanf("\t%s", score[i].classAndGrade);  
        printf("��ѧӢ��ɼ�(0~100)��\n");  
        scanf("\t%d", &score[i].english);  
		printf("C���Գɼ�(0~100)��\n");  
        scanf("\t%d", &score[i].cLanguage);
		printf("�����ɼ�(0~100)��\n");  
        scanf("\t%d", &score[i].pe);
		printf("�ߵ���ѧ�ɼ�(0~100)��\n");  
        scanf("\t%d", &score[i].math);
		printf("��ѧ����ɼ�(0~100)��\n");  
        scanf("\t%d", &score[i].physics);
		printf("MATLAB�ɼ�(0~100)��\n");  
        scanf("\t%d", &score[i].matlab);
		
		do
		{
			printf("�Ƿ�������?(y/n)");
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
	
	printf("��������������˵���\n");
	getch(); 
}

void getFileName(char *filename)  
{  
	system("cls");  
	printf("��������Ҫ�������ļ���·��(�磺F:\\a.txt)��");  
	scanf("%s", filename);  
	printf("�������������\n");
	getch();
}  

int menu()
{
	char ch;  
	
	do{  
        system("cls");  
        printf("\t\t �q�T�T�T�T�T�T�T�T�T���������T�T�T�r\n");  
		printf("\t\t��         ѧ���ɼ�����ϵͳ         ��\n");  
		printf("\t\t�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�s\n");  
        printf("\t\t   ��������������������������������\n");  
        printf("\t\t   �� 1. ��Ӽ�¼    2. ��ʾ��¼ ��\n");  
        printf("\t\t   ��                            ��\n");  
        printf("\t\t   �� 3. ��Ϣ��ѯ    4. �ɼ����� ��\n");  
        printf("\t\t   ��                            ��\n");  
        printf("\t\t   �� 5. �޸ļ�¼    6. ɾ����¼ ��\n");  
        printf("\t\t   ��                            ��\n");  
        printf("\t\t   �� 7. �ɼ�ͳ��    0. �˳����� ��\n");  
        printf("\t\t   ��������������������������������\n");  
        printf("\t\t����ѡ��(0-7):");  
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
		printf("��������˳���\n");
		getch(); 
		exit(1);
	}
	
	printf("�������û�����");
	fflush(stdin);
	scanf("%s", userName);
	printf("���������룺");
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
		printf("\n���벻����Ϊ�գ�\n");
		return FALSE;
	}

	while(!feof(fp))  
	{  
		fscanf(fp, "%s", str);  
		
		if(strcmp(str, userName) == 0)  
		{  
			printf("\n�û�����%s�Ѵ��ڣ�\n", userName);  
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
		printf("��������˳���\n");
		getch();
		exit(1);
	}
	
	printf("�������û�����");
	fflush(stdin);
	scanf("%s", userName);
	printf("���������룺");
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
			printf("\n\n�û�����ȷ��\n");  
			fscanf(fp, "%s", str);  
			if(strcmp(str, password) == 0)  
			{  
				printf("������ȷ��\n");
				fclose(fp);
				return TRUE;
			}
			else  
			{  
				printf("�������\n"); 
				fclose(fp);
				return FALSE;
			}  
		}  
		
		fscanf(fp, "%s", str); 	
	}  
	
	printf("\n�û�����%s�����ڣ�\n", userName);
	fclose(fp);
	
	return FALSE;
}

boolean loginHead()
{
	FILE *fp = NULL;
	char handle;
	
	printf("\t\t �q�T�T�T�T�T�T�T�T�T���������T�T�T�r\n");  
	printf("\t\t��       ѧ���ɼ�����ϵͳ��¼       ��\n");  
	printf("\t\t�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�s\n");  
	printf("\t\t   ��������������������������������\n");  
	printf("\t\t   ��    1����¼    2��ע��      ��\n");  
    printf("\t\t   ��������������������������������\n");  
	printf("\t\t��ѡ����Ҫ���еĲ�����");
	
	handle = getche();
	while (handle != '1' && handle != '2')
	{
		printf("\n\t\t�����������������룺");
		handle = getche();
	}
	
	if(handle == '1')
	{
		system("cls"); 
		
		if(login(fp))
		{
			system("cls");
			printf("��½�ɹ���\n");
			printf("�������������\n");
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
			printf("ע��ɹ���\n");
			printf("�������������\n");
			getch(); 
		}
		
		return FALSE;
	}
	
	return FALSE;
}

int main(void)
{
	char filename[30];		 					 					//�洢�ļ�·��
	SCORE score[100];
	
	while(!loginHead())
		;
	
	getFileName(filename);
	
	while(1)
	{
		switch(menu())												//ʹ��switch-caseѡ��Ҫ���еĲ���
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
