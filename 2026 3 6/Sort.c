#include"Sort.h"
#include"stack.h"
#include<string.h>

void swap(int* p1, int* p2)
{
	assert(p1 && p2);
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void ArryPrint(int* arr, int size)
{
	assert(arr);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void BubbleSort(int* a, int size)
{
	assert(a);
	int count = 0;
	for (int i = 0; i < size-1; ++i)
	{
		
		for (int j = 0; j <size-i-1 ; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a+j, a+j+1);
				count = 1;
			}
		}
		if (count == 0)
		{
			return;
		}
	}
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2;//假设左孩子大
	while (child<n)
	{
		if (a[child] < a[child + 1])
		{
			child = child + 1;
		}
		if (a[child] > a[parent])
		{
			swap(a + child, a + parent);
		}
		parent = child;
		child = parent * 2;
	}
}
void HeapSort(int* a, int n)
{
	assert(a);
	for (int i = (n - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);//建堆
	}
	int end = n - 1;
	while ( end>0)
	{
		swap(a, a + end);
		--end;
		AdjustDown(a, end, 0);
	}
}
void SelectSort(int* a, int n)
{
	assert(a);
	int left = 0, right = n - 1;
	int maxi, mini;
	while (left < right)
	{
		maxi = mini = left;
		for (int i = left + 1; i <= right; ++i)
		{
			if (a[maxi] < a[i])
				maxi = i;
			if (a[mini] > a[i])
				mini = i;
		}
		swap(a + left, a + mini);
		if (maxi == left)
		{
			maxi = mini;
		}
		swap(a + right, a + maxi);
		++left;
		--right;
	}
}
void InsertSort(int* a, int n)
{
	assert(a);
	int end;
	for (int i = 0; i < n-1; i++)
	{
		end=i;
		while (end >= 0)
		{
			if (a[end + 1] >= a[end])
			{
				break;
			}
			else
			{
				swap(a + end, a + end + 1);
			}
			--end;
		}
	}
}
void ShellSort(int* a, int n)
{
	assert(a);
	int gap=n, end;
	while (gap >1)
	{
		gap = gap / 3 + 1;
			for (int i =0; i < n - gap; i ++)
			{
				end = i;
				while (end >= 0)
				{
					if (a[end + gap] >= a[end])
					{
						break;
					}
					else
					{
						swap(a + end, a + end + gap);
					}
					end -= gap;
				}
			}
	}	
}
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
//	printf("[%d %d]", left, right);
	int keyi = left;
	int begin = keyi, end = right;
	while (begin < end)
	{
		while (begin < end&&a[end]>=a[keyi])//右边先找小的数，确保相遇时的值肯定小于key
		{
			--end;
		}
		while (begin < end && a[begin] <= a[keyi])//找大于key的值
		{
			++begin;
		}
		swap(&a[begin], &a[end]);
	}
	swap(&a[keyi], &a[begin]);
	keyi = begin;
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}
void QuickSort02(int* a, int left, int right)//指针法
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur<=right)
	{
		while (a[cur] < a[keyi] && ++prev != cur)
		{
			//cur先走找小的树，所以prev的值肯定会小于cur
			swap(&a[cur], &a[prev]);//和前一个大于它的交换
		}
		++cur;
	}
	swap(& a[keyi], & a[prev]);
	QuickSort02(a,left,prev-1);
	QuickSort02(a,prev+1,right);
}
void QuickSortNonR(int* a, int left, int right)
{
	ST stack;
	STInit(&stack);
	int end, begin, keyi,rbegin,rend;
	STPush(&stack, right);
	STPush(&stack, left);
	while (!STEmpty(&stack))
	{
		 begin = STTop(&stack);
		STPop(&stack);
		end = STTop(&stack);
		STPop(&stack);
		 keyi = begin;
		 rbegin = begin;
		 rend = end;
		while (begin < end)
		{
			while (begin < end && a[end] >= a[keyi])//右边先找小的数，确保相遇时的值肯定小于key
			{
				--end;
			}
			while (begin < end && a[begin] <= a[keyi])//找大于key的值
			{
				++begin;
			}
			swap(&a[begin], &a[end]);
		}
		swap(&a[keyi], &a[begin]);
		if (begin + 1 < rend)
		{
			STPush(&stack, rend);
			STPush(&stack, begin + 1);
		}
		if(begin-1>rbegin)
		{
			STPush(&stack, begin-1);
			STPush(&stack, rbegin);
		}
	}
	STDestory(&stack);
}
void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
		return;
	//printf("[%d %d]\n", left, right);
	int mid = (left + right) / 2;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
			tmp[i++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + left, tmp + left, (right - left + 1)*sizeof(int));
}
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("MergeSort::malloc fail");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);
}
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("MergeSort::malloc fail");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i <n; i +=2* gap)//模拟分割区间
		{
			int begin1 = i, end1 = i + gap-1;
			int begin2 = i + gap, end2 =i+2*gap-1;
			if (begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n-1;
			}
			int j = i;
			printf("[%d %d] [%d %d]\n", begin1,end1,begin2,end2 );
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	
}
//void InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int temp = a[end + 1];
//		while (end >= 0)
//		{
//			if (a[end] > a[end + 1])
//			{
//				swap(&a[end], &a[end + 1]);
//				--end;
//			}
//			else
//				break;
//		}
//		a[end + 1] = temp;
//	}
//}