#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int my_aoti(const char* p1)
{

}
//char* my_memmove(void* dest, void* sour, size_t num)
//{
//	char* p1 = (char*)dest;
//	char* p2 = (char*)sour;
//	while (num--)
//	{
//		*p1++ = *p2++;
//	}
//	return dest;
//}
//int main()
//{
//	char a[] = "hellow world  ";
//	char b[] = "hehehe";
//	my_memmove(a + 7, a, 7);
//	puts(a);
//	return 0;
//}

		//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}
//char* my_strncat(char*dest,char*sour,size_t num)
//{
//	while (*dest != '\0')
//		dest++;
//	while (num--)
//	{
//		if (*sour == '\0')
//		{
//			break;
//		}
//		*dest++ = *sour++;
//	}
//	return dest;
//}
//int main()
//{
//	char a[20] = "hellow ";
//	char b[] = "bit";
//	my_strncat(a, b, 9);
//	printf("%s\n", a);
//	return 0;
//}
//char* my_strncpy(char* dest, char* sour,size_t num)
//{
//	while (num--&&dest)
//	{
//		if (*sour == '\0')
//		{
//			*dest++ = 0;
//		}
//		else
//		*dest++ = *sour++;
//	}
//	return dest;
//}
//int main()
//{
//	char a[10] = { 0 };
//	char b[] = "hellow";
//	my_strncpy(a, b, 7);
//	printf("%s", a);
//	return 0;
//}
//int isret(int num)
//{
//	char n = num;
//	if (n == 1)
//	{
//		printf("Ð¡¶Ë´¢´æ");
//	}
//	if (n == 0)
//	{
//		printf("Ð¡¶Ë´¢´æ");
//	}
//}
//int main()
//{
//	int n = 1;
//    isret(n);
//	return 0;
//}
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* pcur = str1;
//	char* p2 = str2;
//	if (*p2 == ' ')
//	{
//		return str1;
//	}
//	while (pcur != '\0')
//	{
//		p2 = str2;
//		
//		while (*pcur != *p2&&*pcur!='\0')
//		{
//			pcur++;
//		}
//		char* p1= pcur;
//		while (*p1++ == *p2++ && *p2 != '\0'&&*p1!='\0')
//			;
//		if (*p2 == '\0')
//		{
//			return pcur;
//		}
//		else if (*p1 == '\0')
//		{
//			return NULL;
//		}
//			pcur++;
//			
//		
//	}
//	return NULL;
//}
//int main()
//{
//	char a[] = "hellow worldfff";
//	char b[] = "world";
//	char*ret=my_strstr(a, b);
//	printf("%s\n", ret);
//	
//}
//int my_strcmp(char*str1,char*str2)
//{
//	int i = 0;
//	while (str1[i] == str2[i]&&str1[i]!='\0'&&str2[i]!='\0')
//	{
//		i++;
//	}
//	return str1[i] - str2[i];
//}
//int main()
//{
//	char a[10] = "abcdef";
//	char b[10] = "abcde";
//	printf("%d\n", my_strcmp(a, b));
//	return 0;
//}
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char ch = 'a';
//	for (ch = 'a'; ch <= 'z'; ch++)
//	{
//		putc(ch, pf);
//	}
//	fputs("\nhellow world\n", pf);
//	fclose(pf);
//	pf == NULL;
//	FILE* pf2 = fopen("test.txt", "r");
//	if (pf2 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char arr[30] = { 0 };
//	fgets(arr, 27, pf2);
//	fclose(pf2);
//	pf2 == NULL;
//	printf("%s", arr);
//	return 0;
//
//}