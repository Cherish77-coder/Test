#include"stack.h"
void test1()
{
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPop(&st);
	bool ret = STIfNULL(&st);
	printf("%d", (int)ret);
	/*for (int i = 0; i < st.top; i++)
	{
		printf("%d ", st.arr[i]);
	}*/
}
int main()
{
	test1();
	return 0;
}