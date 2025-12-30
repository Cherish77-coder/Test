#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include <string.h>
//char* my_strstr(const char* p1, const char* p2)
//{
//	char* cur = (char*)p1;
//	char* s1, * s2;
//	if (!p2)
//		return ((char*)p1);
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char*)p2;
//		while (*s1 && *s2 && !(*s1 - *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (!*s2)
//			return s1;
//		cur++;
//		
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "hellow bit i am a boy";
//	char* ret = my_strstr(arr1, "am");
//	char arr3[10] = { 0 };
//
//	if (ret == NULL)
//		printf("没找到\n");
//	else
//	{
//		printf("找到了\n");
//		printf("%p\n", arr1);
//		printf("%p", ret);
//	}
//		
//	return 0;
//}
//int main()
//{
//	char str[] = "This is a simple string";
//	char* pch;
//	pch = strstr(str, "simple");
//	strncpy(pch, "sample", 6);
//	printf("%s\n", pch);
//	return 0;
//}
//char* my_strcopy(char* dest, const char* source)
//{
//	assert(dest && source);
//	char* ret = dest;
//	while ((*dest++ = *source++));
//	return ret;
//}
//int main()
//{
//	char a1[20] = { 0 };
//	char a2[15] = "hellow world";
//	my_strcopy(a1, a2);
//	printf("%s", a1);
//	return 0;
//}
//int  my_strcmp(const char* p1, const char* p2)
//{
//	while (*p1++ == *p2++);
//	return *p1 - *p2;
//}
//int main()
//{
//	char a1[] = "abcdef";
//	char a2[] = "abcde";
//	int ret = my_strcmp(a1, a2);
//	if (ret > 0)
//	{
//		printf(">\n");
//	}
//	else if (ret < 0)
//	{
//		printf("<\n");
//	}
//	else
//		printf("=\n");
//	return 0;
//}
//char* my_strcat( char* p1, const char* p2)
//{
//	char* ret = p1;
//	while (*++p1 != '\0')
//	{
//		
//	}
//		;
//	while (*p2 != '\0')
//	{
//		*p1++ = *p2++;
//	}
//	return ret;
//}
//
//int main()
//{
//	char a1[20] = "abcdefg";
//	char a2[10] = "hijklmn";
//	my_strcat(a1, a2);
//	printf("%s", a1);
//	return 0;
//}