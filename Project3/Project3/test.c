#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int cmp_int(int*p1,int *p2)
{
	return *p1 - *p2;
}
int cmp_char(char* p1, char* p2)
{
	return*p1 - *p2;
}
struct student
{
	char name[20];
	int age;
	char id[10];
	int height;
};
int cmp_by_name(const void* p1, const void* p2)
{
	return ((struct student*)p2)->name - ((struct student*)p1)->name;
}
int cmp_by_age(const void* p1, const void* p2)
{
	return ((struct student*)p1)->age - ((struct student*)p2)->age;
}
int cmp_by_height(const void* p1, const void* p2)
{
	return ((struct student*)p1)->height - ((struct student*)p2)->height;
}
int main()
{
	struct student std[3] = { {"zhangsan",21,"20252111",180},{"lisi",19,"20210399",178}, { "chenwu",20,"20222134",170 } };
	int len = sizeof(std) / sizeof(std[0]);
	qsort(std, len, sizeof(std[0]), cmp_by_height);
	return 0;
}
//int main()
//{
//	char str[] = "kjsahdkjsnckjfbn";
//	int len = strlen(str);
//	qsort(str, len, sizeof(char), cmp_char);
//	int i = 0;
//	printf("%s\n", str);
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,4,5,6,7,8,5,4 };
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp_int);
//	int ret = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < ret; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//struct student 
//{
//	char name[20];
//	int age;
//	char id[10];
//	int height;
//};
//int cmp_by_name(const void*p1,const void*p2)
//{
//	return ((struct student*)p1)->name - ((struct student*)p2)->name;
//}
// 
//int main()
//{
//	struct student std[3] = { {"zhangsan",19,"20252111",180},{"lisi",20,"20210399",178}, { "chenwu",21,"20222134",170 } };
//	int len = sizeof(std) / sizeof(std[0]);
//	qsort(std, len, sizeof(std[0]), cmp_by_name);
//	return 0;
//}