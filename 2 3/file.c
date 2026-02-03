#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define DEBUG_PRINT printf("file:%s\tline:%d\t date:%s\ttime:%s\n" ,__FILE__,__LINE__ , __DATE__, __TIME__)
#define SQUARE(x) (x)*(x)
#define MAX(a,b) (a)>(b)?(a):(b)
#define OFFSETOF(type,member) (size_t)&(((type*)0)->member)//取地址操作符
#define SWAPB(x) ((x<<1)&(0xaaaaaaaa))+((x>>1)&(0x55555555))
int main()
{
	int s = 100;
	printf("%d\n", SWAPB(s));
	return 0;
}
//int main()
//{
//	struct a
//	{
//		char b;
//		char name[10];
//		int score;
//	};
//	int a = 5;
//	struct a stu = { 'c',"hehe",100 };
//	printf("%zd\n", OFFSETOF(struct a, score));
//	printf("%d \n", MAX(9+1,3+9));
//	int s = SWAPB(a);
//	printf("%zd \n", s);
//	/*DEBUG_PRINT;*/
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3 ,4 ,5 ,6 ,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(arr, sizeof(int), sz, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* pf = NULL;
//	pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("open fail:");
//		return 1;
//	}
//	char ch;
//	while (fscanf(pf, "%c", &ch) != EOF)
//	{
//		printf("%c",ch);
//	}
//	printf("\n");
//	if (feof(pf))
//	{
//		printf("end by eof");
//	}
//	if (ferror(pf))
//	{
//		printf("end by error");
//	}
//	return 0;
//}
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("open fail:");
//		return 1;
//	}
//	char s[] = "hello world";
//	fprintf(pf,"%s",s);
//	/*rewind(pf);*/
//	fseek(pf, -2, SEEK_CUR);
//	printf("%d ", ftell(pf));
//	fclose(pf);
//	return 0;
//}
//typedef struct stu {
//	char name[20];
//	int year;
//	char gender[8];
//}stu;
//int main()
//{
//	stu s1 = { "张三",18,"male" };
//	/*FILE* pf = fopen("test.txt", "w");
//		if (pf == NULL)
//		{
//			perror("open fail:");
//			return 1;
//		}
//		fprintf(pf,"%s %d %s", s1.name, s1.year, s1.gender);
//		fclose(pf);
//		pf = NULL;*/
//		FILE* pfout = fopen("test.txt", "r");
//		if (pfout == NULL)
//		{
//			perror("open fail:");
//			return 1;
//		}
//		stu a = { 0 };
//		fscanf(pfout,"%s %d %s", a.name, &(a.year), a.gender);
//		fclose(pfout);
//		pfout = NULL;
//		printf("%s %d %s\n", a.name, a.year, a.gender);
//		return 0;
//}
//int main()
//{
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("open fail:");
//		return 1;
//	}
//	for (int i = 0; i < 100; i++)
//	{
//		fprintf(pf, "%c ", i);
//	}
//	fclose(pf);
//	pf == NULL;
//}
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen:");
//		return 1;
//	}
//	for (char i = 'a'; i < 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//	return 0;
//}
//int main()
//{
//	FILE* pfin = fopen("copy.txt", "w");
//	if (pfin == NULL)
//	{
//		perror("fopen fail:");
//		return 1;
//	}
//	FILE* pfout = fopen("test.c", "r");
//	if (pfout == NULL)
//	{
//		perror("fopen fail:");
//		return 2;
//	}
//	char ch = 0;
//	while (fscanf(pfout, "%c", &ch) != EOF)
//	{
//		fprintf(pfin, "%c", ch);
//	}
//	return 0;
//}