#include"queue.h"
int main()
{
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	/*QueueDestory(&q1);*/
	printf("\n");
	printf("%d\n", QueueFront(&q1));
	printf("%d\n", QueueEmpty(&q1));

	return 0;
}