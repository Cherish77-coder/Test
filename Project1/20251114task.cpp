#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 1, n=10000;
	float s = 0, an,bn;
	while (i <= n) {
		an = 4.0 / (4*i  - 3);
		bn = -4.0 / (4 * i - 1);
		s+= an+bn;
		i++;
	}
	printf("µ±n=10000Ê±£¬¦°=%.6f\n", s);
	system("pause");
	return 0;
}
