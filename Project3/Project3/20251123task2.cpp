#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int i, b = 0;
	int a[9] = { 1,2,3,4,5,1,2,3,4 };
	for (i = 0; i < 9; i++) {
		b ^= a[i];
	}
	printf("只出现一次的数字是：%d", b);
	return 0;
}