#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
int main()
{
	int* a = calloc(6, sizeof(int));
	int*o= realloc(a, 200);
	if (o == NULL)
	{
		perror("realloc");
		return 1;
	}
	printf("%p\n", a);
	a = o;
	printf("%p",a);
	return 0;
}
//int main()
//{
//	int(*arr)[5] = malloc(sizeof(int) * 3 * 5);
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			assert(arr);
//			arr[i][j] =i+j;
//			printf("%d ",arr[i][j]);
//		}
//		printf("\n");
//		
//	}
//	return 0;
//}
//char*  GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//		return 0;
//}
//int main()
//{
//	int arr[3] = { 0 };
//
//	return 0;
//
//}
//union a
//{
//	int a;
//	char b;
//}UN;
//int main()
//{
//	UN.a = 0;
//	UN.b = 1;
//	if (UN.a == 1)
//	{
//		printf("小端存储\n");
//	}
//	else
//		printf("大端存储\n");
//}
//int main()
//{
//    unsigned char puc[4];
//    struct tagPIM
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPimData;
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//    pstPimData->ucPim1 = 2;
//    pstPimData->ucData0 = 3;
//    pstPimData->ucData1 = 4;
//    pstPimData->ucData2 = 5;
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    return 0;
//}
//int my_atoi(char* s)
//{
//	assert(s);
//	int ret=0;
//	char* cur = s;
//	while (*cur != '\0')
//	{
//		ret = ret * 10 +( *cur-'0');
//		cur++;
//	}
//	return ret;
//}
//int main()
//{
//	char s[10] = { 0 };
//	printf("请输入字符数字：\n");
//	scanf("%s", s);
//	printf("它是%d", my_atoi(s));
//	return 0;
//}
//int main()
//{
//	float a = 9.0;//00010010 00010000 00000000 00000000
//	printf("");
//	return 0;
//}