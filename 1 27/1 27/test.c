#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char* my_strcat(char* des, const char* sour)
{
	char* pcur = des;
	while (*pcur != '\0')
		pcur++;
	while (*sour!= '\0'&&pcur)
	{
		*pcur++ = *sour++;
	}
	return des;
}
char* my_strcpy(char* des, const char* sour)
{
	while (*sour != '\0')
	{
		*des++ = *sour++;
	}
	*des = '\0';
	return des;
}
//unsigned int my_strlen(char* s)
//{
//	if (*s == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(s + 1);
//}
//unsigned int my_strlen(char* s)
//{
//	char* tail = s;
//	while (*tail != '\0')
//	{
//		tail++;
//	}
//	return tail - s;
//}
//unsigned int my_strlen(char* s)
//{
//	unsigned int count = 0;
//	while (*s++!= '\0')
//		count++;
//	return count;
//}
int main()
{
	char s[] = "hello world";
	char a[20] = "hi ";
	my_strcat(a, s);
	printf("%s", a);
	return 0;
}