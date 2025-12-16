#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n = 0, i;
	scanf("%d",&n);
	int arr[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		int repeat = 0;
		for (int j = 0; j < n&&j!=i; j++)
		{
			if (arr[i] == arr[j])
				repeat = 1;
			break;
		}
		if(repeat==0)
		printf("%d ", arr[i]);
	}
	return 0;
}






//int main()
//{
//    int m, n, i, j, min;
//    scanf("%d %d", &m, &n);
//    int a[m][n];
//    for (i = 0; i < m; i++)
//        for (j = 0; j < n; j++)
//            scanf("%d", &a[i][j]);
//    for (j = 0; j < n; j++)
//    {
//        int min = a[0][j];
//        for (i = 1; i < m; i++)
//        {
//            if (min >= a[i][j])
//                min = a[i][j];
//        }
//        printf("%d", min);
//        if (j  != n-1)
//        printf("\n");
//    }
//
//    return 0;
//}