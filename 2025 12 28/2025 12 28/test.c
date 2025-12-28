#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48
//	printf("%d\n", sizeof(a[0][0]));//4
//	printf("%d\n", sizeof(a[0]));//16
//	printf("%d\n", sizeof(a[0] + 1));//表示a[1]地址，是地址所以是4或8
//	printf("%d\n", sizeof(*(a[0] + 1)));//4
//	printf("%d\n", sizeof(a + 1));//？ 数组名表示首元素地址是地址所以是4或8
//	printf("%d\n", sizeof(*(a + 1)));//16
//	printf("%d\n", sizeof(&a[0] + 1));//4
//	printf("%d\n", sizeof(*(&a[0] + 1)));//？=a[1]
//	printf("%d\n", sizeof(*a));//？*a=a[0],16
//	printf("%d\n", sizeof(a[3]));//16
//	return 0;
//}
//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", strlen(p));//6
//	//printf("%d\n", strlen(p + 1));//地址错误
//	//printf("%d\n", strlen(*p));//错误
//	//printf("%d\n", strlen(p[0]));//错误
//	//printf("%d\n", strlen(&p));//错误
//	//printf("%d\n", strlen(&p + 1));//错误
//	//printf("%d\n", strlen(&p[0] + 1));//错误
//	return 0;
//}
//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));//p表示首元素地址是地址所以是4或8
//	printf("%d\n", sizeof(p + 1));//下一个元素地址4或8
//	printf("%d\n", sizeof(*p));//表示首元素1
//	printf("%d\n", sizeof(p[0]));//1
//	printf("%d\n", sizeof(&p));//地址4或8
//	printf("%d\n", sizeof(&p + 1));//下一个数组地址4或8
//	printf("%d\n", sizeof(&p[0] + 1));//表示b的地址4或8
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	//printf("%d\n", strlen(arr));//6
//	//printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//错误
//	printf("%d\n", strlen(arr[1]));//错误
//	//printf("%d\n", strlen(&arr));//错误
//	//printf("%d\n", strlen(&arr + 1));//错误
//	//printf("%d\n", strlen(&arr[0] + 1));//错误
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//printf("%d\n", sizeof(arr));//表示整个元素，包含/0,7
//printf("%d\n", sizeof(arr+0));//表示地址4或8
//printf("%d\n", sizeof(*arr));//表示首元素1
//printf("%d\n", sizeof(arr[1]));//表示第二个元素char，1
//printf("%d\n", sizeof(&arr));//整个数组地址4或8
//printf("%d\n", sizeof(&arr+1));//跳过整个数组的地址，4或8
//printf("%d\n", sizeof(&arr[0]+1));//地址4或8
//	return 0;
//}
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", strlen(arr));//没有\0所以是随机值19
//	//printf("%d\n", strlen(arr + 0));//没有\0，随机值19
//	//printf("%d\n", strlen(*arr));//表示首元素所以是19
//	//printf("%d\n", strlen(arr[1]));//表示第二个元素,没有斜杠0随机值18
//	//printf("%d\n", strlen(&arr));//表示整个素组的地址4或19
//	//printf("%d\n", strlen(&arr + 1));//表示整个元素地址+1跳过整个数组，地址4或8，12
//	//printf("%d\n", strlen(&arr[0] + 1));//表示第二个元素地址4或8，18
//	return 0;
//}
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));//表示整个数组，枚举类型不包含\0，所以是6
//	printf("%d\n", sizeof(arr + 0));//arr+0为int类型，所以是4
//	printf("%d\n", sizeof(*arr));//表示首元素的值1
//	printf("%d\n", sizeof(arr[1]));//表示第二个元素为char，1
//	printf("%d\n", sizeof(&arr));//表示整个元素的地址所以是4或8
//	printf("%d\n", sizeof(&arr + 1));//表示地址4或8
//	printf("%d\n", sizeof(&arr[0] + 1));//表示地址所以是4或8
//	return 0;
//}
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//16
//	printf("%d\n", sizeof(a + 0));//4
//	printf("%d\n", sizeof(*a));//4或8
//	printf("%d\n", sizeof(a + 1));//4
//	printf("%d\n", sizeof(a[1]));//4
//	printf("%d\n", sizeof(&a));//表示整个数组所以是16
//	printf("%d\n", sizeof(*&a));//4
//	printf("%d\n", sizeof(&a + 1));//4或8
//	printf("%d\n", sizeof(&a[0]));//4
//	printf("%d\n", sizeof(&a[0] + 1));//4
//}

