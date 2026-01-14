#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {

	int a[4][4] = { {1,2,3,4},{5,6,7,8},{11,12,13,14},{15,16,17,18}};
	int i = 0, j = 0, s = 0;
	while (i++ < 4) {//第一次这的判断条件(i++<4)时i=0;判断完了之后i=1;
		//举个例子i=0;
		//a=i++；b=i；
		// a=0；b=1；
		// 那么a=0；
		//

		if (i == 2 || i == 4)continue;

		j = 0;

		do {

			s += a[i][j];

			j++;

		} while (j < 4);
		

	}
	printf("%d\n", s);
	return 0;
}