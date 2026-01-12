#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define NAME 20
typedef struct person
{
	char name[NAME];
	int year;
	int month;
	int day;
}Person;
int PersonCmp(Person* ps1,Person*ps2)
{
	assert(ps1 && ps2);
	return ps1->year - ps2->year;
}
int main()
{
	Person* arr= malloc(100 * sizeof(Person));

	if (arr == NULL)
	{
		perror("maloc");
		return 1;
	}
	int i = 0;
	printf("请输入要输入的数据个数：\n");
	scanf("%d", &i);
	printf("请输入%d组数据，按照姓名，年，月，日\n", i);
	for (int n = 0; n < i; n++)
	{
		scanf("%s %d %d %d", arr[n].name, &arr[n].year, &arr[n].month, &arr[n].day);
	}
	qsort(arr, i, sizeof(Person), PersonCmp);
	for (int j = 0; j < i; j++)
	{
		printf("%s\n",arr[j].name);
	}
	free(arr);
	arr = NULL;

	return 0;
}