#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	char arr1[50] = {"***************************************"};
	char arr2[50] = {"   Hellow,its the best time to learn.  "};
	int sz = strlen(arr1);
	int left = 0, right = sz - 1;
	while (left<=right)
	{
		arr1[left] = arr2[left];
		arr1[right] = arr2[right];
		left++;
		right--;
		printf("%s\n", arr1);
		Sleep(300);
		system("cls");

	}
	printf("%s", arr1);
	return 0;
}