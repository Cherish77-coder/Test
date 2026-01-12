#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int yhtangle(int i,int j)//递归形式输出杨辉三角
//{
//	if (j == 0 || i == j)
//		return 1;
//	else
//		return yhtangle(i - 1, j - 1) + yhtangle(i - 1, j);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - i; j++)
//		{
//			printf("   ");
//		}
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%-6d", yhtangle(i, j));
//		}
//		printf("\n");
//	}
//	return 0;
//}
//void yhtangle(int n)
//{
//	int arr[15][15] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - i; j++)//打印空格符合三角形特征；
//		{
//			printf("   ");
//		}
//		for (int j = 0; j <=i; j++)
//		{
//			if (j == 0 || j == i)
//			{
//				arr[i][j] = 1;
//			}
//			else if (i >= 2)
//			{
//				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];//杨辉三角性质；
//			}
//			printf("%-6d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	yhtangle(n);
//	return 0;
//}
//void count(char arr[])//统计字符串中各种类型数据个数
//{
//	int countnum = 0, countchar = 0, counti = 0,countspace = 0;
//	for (int i = 0; arr[i+1] != '\0'; i++)
//	{
//		if (arr[i] >= '0' && arr[i] <= '9')
//		{
//			countnum++;
//		}
//		else if (arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= 'a' && arr[i] <= 'z')
//			countchar++;
//		else if (arr[i] == ' ')
//			countspace++;
//		else
//			counti++;
//	}
//	printf("数字个数是:%d \n字母个数是:%d \n空格个数是:%d\n其它字符个数是:%d\n	",countnum,countchar,countspace,counti);
//}
//int main()
//{
//	char arr[200] = { 0 };
//	fgets(arr, 199, stdin);
//	count(arr);
//}
//int count_word(char a[],int sz)//统计单词个数
//{
//	if (a[0] == ' ' && a[1] == ' ')//判断全为空格的情况；
//		return 0;
//	int count = 0;
//	for (int i = 0; a[i+1] != '\0'; i++)
//	{
//		
//		if (a[i] == ' ' && a[i + 1] == ' ')
//		{
//			continue;
//		}
//			if ( a[i] == ' ')
//				count++;
//	}
//	count++;
//	return count;
//}
//int main()
//{
//	char a[100] = { 0 };
//	fgets(a, 99, stdin);
//	int sz = strlen(a);
//	int ret=count_word(a,sz);
//	return 0;
//}
//int max_sample(int *p, int sz)//子数组求最大值
//{
//	int max = p[0];
//	int temp = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		for (int j = 0; j < sz-i; j++)
//		{
//			temp += *(p+j);
//			if (max < temp)
//				max = temp;
//		}
//		p++;
//		temp = 0;
//	}
//	return max;
//}
//int main()
//{
//	int a[] = { -2, 3, -8, 6, 9, -12 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int ret = max_sample(a, sz);
//	return 0;
//}
//void buble_sort(int* p,int sz)//冒泡排序数组；
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		for (int j = 0; j <sz-i-1 ; j++)
//		{
//			if (*(p + j) > *(p + j + 1))
//			{
//				int temp = *(p + j);
//				*(p + j) = *(p + j + 1);
//				*(p + j + 1) = temp;
//			}
//
//		}
//	}
//	return;
//}
//void print(int arr[],int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return;
//}
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1 ,0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	buble_sort(arr,sz);
//	print(arr, sz);
//	return 0;
//}

//int main()//输入10个数找出最值
//{
//	int max=0, min=0;
//	scanf("%d", &max);
//	min = max;
//	for (int i = 0; i < 9; i++)
//	{
//		int n=0;
//		scanf("%d", &n);
//		if (max < n)
//		{
//			max = n;
//		}
//		if (min > n)
//		{
//			min = n;
//		}
//		
//	}
//	printf("max=%d min=%d\n", max, min);
//	return 0;
//}
//void fun(int n)//查找1到100质数；
//{
//	int count = 0;
//	for (int i = 2; i < n ; i++)
//	{
//		for (int j = 2; j < i/2; j++)
//		{
//			if (i % j == 0)
//			{
//				count++;
//				break;
//			}
//			else
//				count = 0;
//				
//		}
//		if (count == 0)
//			printf("%d ", i);
//		
//	}
//}
//int main()
//{
//	int n = 100;
//	fun(n);
//	return 0;
//}
//int main()//计算圆周率
//{
//	int n = 1;
//	scanf("%d", &n);
//	float pi = 0, an, bn;
//	for (int i = 1; i <= n ; i++)
//	{
//	 an = -(4.0 / (4 * i - 1));
//	 bn = (4.0 / (4 * i - 3));
//		pi += an + bn;
//	}
//	printf("n=%d 时 Π=%f\n", n, pi);
//	return 0;
//}
//int main()//逆序输出数
//{
//	int n;
//	scanf("%d", &n);
//	int reverse = 0;
//	while (n)
//	{
//		reverse = reverse * 10 + n % 10;
//		n=n / 10;
//	}
//	printf("%d", reverse);
//	return 0;
//}
//int main()//判断奇数和偶数；
//{
//	int n;
//	scanf("%d", &n);
//	if (n % 2 == 0)
//	{
//		printf("偶数\n");
//	}
//	else
//		printf("奇数\n");
//	return 0;
//}
//int main()//判断是不是闰年
//{
//	
//	int year;
//	scanf("%d", &year);
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		printf("%d 是闰年\n", year);
//	}
//	else
//	{
//		printf("%d 不是闰年\n", year);
//	}
//	return 0;
//}
//int main()//输入四个数选出最大值
//{
//	int a, max;
//	scanf("%d", &max);
//	for (int i = 0; i < 3; i++)
//	{
//		scanf("%d", &a);
//		if (max < a)
//		{
//			max = a;
//		}
//	}
//	printf("the max number is %d\n", max);
//	return 0;
//}
////简单计算器的实现
//int main() {
//	char optr, opnd1, opnd2; /* operator, operand 1 and 2 */
//	int result;              /* result of the calculation */
//
//	printf("Please input the first operand\n");
//	scanf("%c", &opnd1);
//	getchar();
//
//	printf("Please input the operator\n");
//	scanf("%c", &optr);
//	getchar();
//
//	printf("Please input the second operand\n");
//	scanf("%c", &opnd2);
//	getchar();
//	if (opnd1 < '0' || opnd1>'9' || opnd2 < '0' || opnd2>'9')
//	{
//		printf("pond1 and pond2 must in 1-9;\n");
//		return 1;
//	}
//	switch (optr)
//	{
//	case'+':
//		result = opnd1 + opnd2-2*'0';
//		printf("%d\n", result);
//		break;
//	case'-':
//		result = (int)opnd1 - (int)opnd2;
//		printf("%d\n", result);
//		break;
//	case'*':
//		result = (opnd1-'0') * (opnd2-'0');
//		printf("%d\n", result);
//		break;
//	case'/':
//		result = (opnd1 - '0') / (opnd2 - '0');
//		printf("%d\n", result);
//		break;
//	default:
//		printf("error\n");
//		break;
//	}
//}
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//typedef struct ListNode ListNode;
//ListNode* buynode(int x)
//{
//    ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
//    if (ret == NULL)
//    {
//        exit(1);
//    }
//    else {
//        ret->val = x;
//        ret->next = NULL;
//        return ret;
//    }
//  
//}
//ListNode* ysfcreate(int n)
//{
//    ListNode* head = buynode(1);
//    ListNode* tail = head;
//    for (int i = 2; i <= n; i++)
//    {
//        tail->next = buynode(i);
//        tail = tail->next;
//    }
//    tail->next = head;
//    return tail;
//}
//int ysf(int n, int m) {
//    ListNode* prev = ysfcreate(n); //创建n个元素
//    int count = 1;
//    ListNode* pcur = prev->next;
//    while (pcur->next != pcur)
//    {
//        if (count == m)
//        {
//            prev->next = pcur->next;
//            free(pcur);
//            pcur = prev->next;
//            count = 1;
//        }
//        else {
//            prev = pcur;
//            pcur = pcur->next;
//            count++;
//        }
//    }
//
//    return pcur->val;
//    // write code here
//}
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//   int ret= ysf(n, m);
//   printf("%d\n", ret);
//    return 0;
//}