#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct {
    int* arr;
    int head;
    int tail;
    int k;
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj;
    obj = malloc(sizeof(MyCircularQueue));
    obj->arr = malloc((k + 1) * sizeof(int));
    obj->head = obj->tail = 0;
    obj->k = k;
    return obj;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->arr[obj->tail] = value;
    obj->tail = (obj->tail + 1) % (obj->k + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->head++;
    obj->head %= (obj->k + 1);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->arr[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->arr[(obj->tail-1+obj->k+1)%(obj->k+1)];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->tail == obj->head;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->tail == (obj->head - 1 + obj->k + 1) % (obj->k + 1);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}
int main()
{
    MyCircularQueue* obj = myCircularQueueCreate(4);
    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 2);
    myCircularQueueEnQueue(obj, 3);
    myCircularQueueEnQueue(obj, 4);
    myCircularQueueRear(obj);
    myCircularQueueIsFull(obj);
    myCircularQueueDeQueue(obj);
    myCircularQueueEnQueue(obj, 5);
    myCircularQueueRear(obj);
    return 0;
}