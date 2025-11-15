#include<stdio.h>
int main() {
	int num,reversed = 0;
	printf("请输入一个正整数");
	scanf("%d", &num);
	int temp = num;
	if (num <= 0) {
		printf("error，请输入一个正整数！\n");
		return 1;
	}
	while (temp> 0) {
		reversed = reversed * 10 + temp % 10;
		temp /= 10;
	}
	printf("翻转后的数字：%d\n",reversed);
	return 0;
}