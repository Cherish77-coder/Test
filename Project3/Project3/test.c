#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
struct student 
{
	char name[20];
	int age;
	char id[10];
	int height;
};
int cmp_by_name(const void*p1,const void*p2)
{
	return ((struct student*)p1)->name - ((struct student*)p2)->name;
}
int main()
{
	struct student std[3] = { {"zhangsan",19,"20252111",180},{"lisi",20,"20210399",178}, { "chenwu",21,"20222134",170 } };
	int len = sizeof(std) / sizeof(std[0]);
	qsort(std, len, sizeof(std[0]), cmp_by_name);
	return 0;
}