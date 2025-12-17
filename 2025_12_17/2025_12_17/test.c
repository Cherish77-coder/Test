#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void conver(int arr[], int sz)
{
	int i = 0;
	int count = 0;
	for (int j = 0; j < sz; j++)
	{
		int tmp = 0;
		if (arr[j] % 2 == 1)
		{
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
			i++;
		}
	}

}
int main()
{
	int arr[8] = {0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	conver(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//#include<string.h>
//size_t my_strlen(const char * p)
//{
//	char* pa = p;
//	while (*p++ != '\0') 
//	{
//		;
//	}
//	return (p - pa);
//}
//int main()
//{
//	char a[] = "asjhdsjakhdkasjdh";
//	size_t ret=my_strlen(a);
//	printf("%zd\n", ret);
//	return 0;
//}
//void left_string(char a[], char* p, int sz)
//{
//	printf("请输入左旋个数：");
//	int k = 0;
//	scanf("%d",&k);
//	int* pa = p + k;
//	for (int i = 0; i < sz-k; i++)
//	{
//		char n = *(p + i);
//		*(p + i) = *(p + i + k);
//		*(p + i + k) = n;
//	}
//	
//}
//int main()
//{
//	char a[] = "abcdesfghjik";
//	int sz = strlen(a);
//	left_string(a,a, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%c", a[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//void reverse_print(char* p, int sz)
//{
//    char* pa = p + sz;
//    while (p != pa+1)
//    {
//        printf("%c", *pa);
//        pa--;
//    }
//
//}
//int main()
//{
//    char a[1000] = { 0 };
//    fgets(a,999,stdin);
//    int sz = sizeof(a) / sizeof(a[0]);
//    reverse_print(a, sz);
//    return 0;
//}


//int add(int x,int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void calculation(int(*p)(int, int),int x,int y)
//{
//	printf("请输入操作数：\n");
//	scanf("%d %d", &x, &y);
//	int ret=p(x, y);
//	printf("%d\n", ret);
//}
//int main()
//{
//	int n = 0;
//	int a = 0, b = 0;
//	do
//	{
//		printf("            计算器          \n");
//		printf("       1:add    2:sub       \n");
//		printf("       3:mul    4:div       \n");
//		printf("             0:exit         \n");
//		printf("请选择：\n");
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			calculation(add, a, b);
//			break;
//		case 2:
//			calculation(sub, a, b);
//			break;
//		case 3:
//			calculation(mul, a, b);
//			break;
//		case 4:
//			calculation(div, a, b);
//			break;
//		default:
//			printf("输入有误请重新输入：\n");
//			break;
//		case 0:
//			printf("exit\n");
//			break;
//		}
//	} while (n);
//	return 0;
//}