#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* pf=fopen("test1.txt", "r");
	fseek(pf, 11, SEEK_CUR);
	char ch = 0;
	ch = getc(pf);
	printf("%c", ch);
	return 0;
}
//int main()
//{
//	FILE* pfout=fopen("test1.txt", "r");
//	if (pfout == NULL)
//	{
//		perror("pfout::fopen");
//		return 2;
//	}
//	FILE* pfin = fopen("test2.txt", "w");
//	if (pfin == NULL)
//	{
//		perror("pfin::fopen");
//		return 1;
//	}
//	char ch = 0;
//	while ((ch = fgetc(pfout)) != EOF)
//	{
//		fputc(ch, pfin);
//	}
//	rewind(pfin);
//    fseek(pfout,10,SEEK_SET);
//	int  c = fgetc(pfout);
//	printf("%c\n", c);
//	
//	fclose(pfin);
//	fclose(pfout);
//	pfin = pfout = NULL;
//
//	return 0;
//}