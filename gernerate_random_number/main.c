#include <windows.h>
#include <stdio.h>
#include <tchar.h>  
#include <ShlObj.h> 
#include <Shlwapi.h>//PathAppendW  
#pragma comment (lib, "shlwapi.lib")

void print_result(unsigned char n,double res,unsigned char is_last)
{
	if (n < 0)
		return;
	else if (n == 0)
	{
		if (is_last == 0)
			printf("%d ",(int)res);
		else
			printf("%d\r\n",(int)res);
	}
	else if (n == 1)
	{
		if (is_last == 0)
			printf("%.1f ",res);
		else
			printf("%.1f\r\n",res);
	}
	else if (n == 2)
	{
		if (is_last == 0)
			printf("%.2f ",res);
		else
			printf("%.2f\r\n",res);
	}
	else if (n == 3)
	{
		if (is_last == 0)
			printf("%.3f ",res);
		else
			printf("%.3f\r\n",res);
	}
	else if (n == 4)
	{
		if (is_last == 0)
			printf("%.4f ",res);
		else
			printf("%.4f\r\n",res);
	}
}

void fprint_result(FILE *f,unsigned char n,double res,unsigned char is_last)
{
	if (n < 0)
		return;
	else if (n == 0)
	{
		if (is_last == 0)
			//fprintf(fp,"%f ",result[i]);
			fprintf(f,"%d\t",(int)res);
		else
			fprintf(f,"%d\r\n",(int)res);
	}
	else if (n == 1)
	{
		if (is_last == 0)
			fprintf(f,"%.1f\t",res);
		else
			fprintf(f,"%.1f\r\n",res);
	}
	else if (n == 2)
	{
		if (is_last == 0)
			fprintf(f,"%.2f\t",res);
		else
			fprintf(f,"%.2f\r\n",res);
	}
	else if (n == 3)
	{
		if (is_last == 0)
			fprintf(f,"%.3f\t",res);
		else
			fprintf(f,"%.3f\r\n",res);
	}
	else if (n == 4)
	{
		if (is_last == 0)
			fprintf(f,"%.4f\t",res);
		else
			fprintf(f,"%.4f\r\n",res);
	}
}

void main(int argc,char *argv[])
{
	//if (argc == 0)
		//printf("USEAGE : \r\n");

	double start_num;
	double end_num;
	unsigned char digit;
	unsigned int total_nums,i;
	double result[65535] = {0};
	unsigned char user_choosen = 'y';

	printf("��������ʼֵ��\r\n");
	scanf("%lf",&start_num);
	if (start_num >= 65535.0)
	{
		printf("��ʼֵ̫��\r\n");
		goto end;
	}
	else if (start_num < 0.0)
	{
		printf("��ʼֵ̫С��\r\n");
		goto end;
	}

	printf("���������ֵ��\r\n");
	scanf("%lf",&end_num);
	if (end_num >= 65535.0)
	{
		printf("����ֵ̫��\r\n");
		goto end;
	}
	else if (end_num < 0.0)
	{
		printf("����ֵ̫С��\r\n");
		goto end;
	}

	printf("������С��λ����\r\n");
	scanf("%d",&digit);
	if (digit >= 5)
	{
		printf("С��λ��̫��\r\n");
		goto end;
	}
	else if (digit < 0)
	{
		printf("С��λ��̫С��\r\n");
		goto end;
	}
	
	printf("���������ɸ�����\r\n");
	scanf("%d",&total_nums);
	if (total_nums >= 65534)
	{
		printf("���ɸ���̫�࣡\r\n");
		goto end;
	}
	else if (total_nums <= 0)
	{
		printf("���ɸ���̫С��\r\n");
		goto end;
	}
	
	if (start_num >= end_num)
	{
		goto end;
	}
	else
	{
		
		srand((unsigned)time(NULL)); 
		//k=rand()%(Y-X+1)+X;
		printf("���ɽ����\r\n");
		for(i = 0;i < total_nums;i ++)
		{
			result[i] = rand()%((int)(end_num-start_num+1))+start_num+((double)(rand()%101)/101);
			#ifdef enter
			if ((i % 5 == 0) && (i != 0))
			{
				printf("\r\n");
			}
			#endif
			if (i != total_nums-1)
				print_result(digit,result[i],0);
			else
				print_result(digit,result[i],1);
		}
		getchar();
		printf("�Ƿ����ɽ���������ı��ĵ��У�(y/n)\r\n");
		user_choosen = getchar();
		//scanf("%c",&user_choosen);
		printf("���룺%c\r\n",user_choosen);
		if (user_choosen == 'y')
		{
			unsigned int i;
			TCHAR szPath[MAX_PATH]={0};
			FILE *fp;

			//setlocale(LC_ALL,"chs");
			SHGetSpecialFolderPath(NULL, szPath,0, FALSE);
			lstrcat(szPath,L"\\random_numbers.txt");
			
			fp=_wfopen(szPath,L"w+");
			for (i = 0;i < total_nums; i++)
			{
				if (i != total_nums-1)
					fprint_result(fp,digit,result[i],0);
				else
					fprint_result(fp,digit,result[i],1);
			}
			//fputs("this is a test text.",fp);
			//fputs("\n����һ�β����ı���",fp);
			fclose(fp);
			printf("\r\n�ļ��ѱ��������棡�ļ���random_nums.txt��\r\n");
			system("pause");
			return 0;
		}
		else if (user_choosen == 'n')
		{
			printf("��ѡ���˲����棡\r\n");
			system("pause");
			exit(0);
		}
		else
		{
			printf("���벻�Ϸ���ǿ���˳���\r\n");
			system("pause");
			exit(0);
		}
		system("pause");
		exit(0);
	}
	
	#if 0
	int i ,k ,range ;
	int rain, max ;
	double j ;
	min=1; /* 1 is the minimum number allowed */ 
	max=44; /* 44 is the maximum number allowed */ 
	range=max-min; /* r is the range allowed; 1 to 44 */ 
	i=rand(); /* use the above example in this slot */ 
	/* Normalize the rand() output (scale to 0 to 1) */
	/* RAND_MAX is defined in stdlib, h */ 
	j= ((double)i/(double)RAND_MAX); /* Scale the output to 1 to 44 */ 
	i= (int)(j * (double)range); 
	i+ =min;
	#endif
	
	end:
	{
		printf("������������˳���\r\n");
		system("pause");
	}
}