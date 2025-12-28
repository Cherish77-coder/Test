#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* p1,const char* p2)
{
	char* ret = p1;
	while (*p1!='\0')
		p1++;
	assert(p1 && p2);
	while ((*p1++ = *p2++))
	{
	};
	return ret;
}
int main()
{
	char arr1[10] = "abc";
	char arr2[4] = "def";
	my_strcat(arr1, arr2);
	printf("%s", arr1);
	return 0;
}


//int main()
//{
//	FILE* pf = fopen("test.txt", "w+");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int i = 0;
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//	char arr[28] = { 0 };
//	fprintf(pf,"%s","a");
//	return 0;
//}
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror(pf);
//		return 1;
//	}
//	int i = 0;
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//	fclose(pf);
//	pf = NULL;
//	FILE*pf2=fopen("test.txt", "r");
//	if (pf2 == NULL)
//	{
//		perror(pf2);
//		return 1;
//	}
//	char a[33] = { 0 };
//	for (i = 0; i <25; i++)
//	{
//		a[i] = getc(pf2);
//		printf("%c", a[i]);
//	}	
//	
//	fclose(pf2);
//	pf2 = NULL;
//	return 0;
//}
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror(pf);
//		return 1;
//	}
//	fprintf(pf, "%s", "abcdefgh");
//	fclose(pf);
//	pf = NULL;
//	FILE* p2 = fopen("test.txt", "r");
//	if(p2==NULL)
//		{
//		perror(p2);
//		return 2;
//		}
//	int i = 0;
//	
//		char c[10] = { 0 };
//	  fgets(c, 9, p2);
//		printf("%s\n", c);
//	fclose(p2);
//	p2 = NULL;
//	return 0;
//}