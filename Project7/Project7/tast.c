#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
int main()
{
	int a = 0; int b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前a=%d,b=%d\n", a, b);
	swap(&a, &b);
	printf("交换后a=%d,b=%d\n", a, b);
	return 0;
}
//int my_strlen(char* pa)
//{
//	assert(pa);
//	int count = 0;
//	while (*pa)
//	{
//		count++;
//		pa++;
//	}
//	return count;
//}
//int main()
//{
//	char a[] = "asjhduiahgd";
//	int ret=my_strlen(a);
//	printf("字符串数组长度是：%d\n", ret);
//	return 0;
//}
//struct student
//{
//	char name[20];
//	int hight;
//	int height;
//	char card[15];
//} st1;
//struct sex
//{
//	char sex;
//};
//struct student st1 = { "laoda",190,80,"20200129 "  };
//struct student st2 = { .name = "meixi",.hight = 189,.height = 70,.card = "612356721" };
//int main()
//{
//	printf("%s %d %d %s\n",st1.name,st1.hight,st1.height,st1.card );
//	printf("%s %d %d %s\n", st2.name, st2.hight, st2.height, st2.card);
//	return 0;
//}
//int main()
//{
//	int a[10] = { 0 };
//	int* pa = &a;
//	printf("%d", *pa);
//	return 0;
//}
//Print(int* pa)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(pa+i));
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	Print(arr);
//	return 0;
//}
//int main()
//{
//	int a[10] = { 0 };
//	int max = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (int i = 1; i < 10; i++)
//	{
//		max = a[0];
//		if (a[i] > max)
//		{
//			max = a[i];
//		}
//	}
//	printf("%d", max);
//	return 0;
//}
//int main()
//{
//	int i=0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i%4==0&&i%100!=0)||i%400==0)
//			printf("%d ", i);
//		
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 9 == 0)
//		{
//			count++;
//		}
//		
//		
//	}
//	printf("%d\n", count);
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	float sum = 0;
//	for (i = 1; i <=100; i++)
//	{
//		if (i % 2 == 1)
//			sum += 1.0 / i;
//		else
//			sum -= 1.0/i;
//		
//	}
//	printf("%f\n", sum);
//	return 0;
//}
//void Print(int*p,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//}
//void buble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i <= sz - 1; i++)
//	{
//		int j = 0;
//		int count = 1;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			int tmp = arr[j];
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j + 1] = tmp;
//				count = 0;
//			}
//			
//		}
//		if (count == 1)
//			break;
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	buble_sort(arr,sz);
//	Print(arr,sz);
//	return 0;
//}
//int main()
//{
//	int a = 0, b = 0,c = 0;
//	int t = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		t=a;s
//		a = b;
//		b = t;
//	}
//		if (a<c)
//		{
//			t=a;
//			a = c;
//			c = t;
//		}
//		if (c > b)
//		{
//			t = b;
//			b = c;
//			c = t;
//		}
//	
//
//	printf("the max to min rank:%d %d %d ", a, b, c);
//	return 0;
//}
	
//int main()
//{
//	int n = 1;
//	for (n = 1; n <= 100; n++)
//	{
//		if (n % 3 == 0)
//			printf("%d ", n);
//	}
//	return 0;
//}
//int main()
//{
//	int a[10] = { 0 };
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//		sum += a[i];
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	printf("平均数是：%d\n", sum / 10);
//return 0;
//
//}
//int main()
//{
//	int a[] = { 1,2,3,4,54,56,67,7 };
//	int b[] = { 23,5,736,98,43,547,98,90 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	printf("交换前a[]=");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ",a[i]);
//	}
//	printf("\n");
//	printf("交换前b[]=");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	printf("\n");
//	for (int i = 0; i <sz; i++)
//	{
//		int n = a[i];
//		a[i] = b[i];
//		b[i] = n;
//	}
//	printf("交换后a[]=");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	printf("交换后b[]=");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	printf("\n");
//		
//
//	return 0;
//}