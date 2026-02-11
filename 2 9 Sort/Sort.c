#include"Sort.h"
#include"Stack.h"
#include<string.h>
void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		int flag = 0;
		for (int i = 0; i < n-j-1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
void Printf(int*a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void AdjustUp(int* a, int n,int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
			child = child + 1;
		if(a[child]>a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)//堆排序
{
	//建堆向上调整建堆；
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustUp(a, n, i);
	}
	int end = n - 1;
	while(end)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a,end,0);
		end--;
	}
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > a[end + 1])
			{
				Swap(&a[end], &a[end + 1]);
				--end;
			}
			else
				break;
		}
		a[end + 1] = temp;
	}
}
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		// +1保证最后一个gap一定是1
//		// gap > 1时是预排序
//		// gap == 1时是插入排序
//		gap = gap / 3 + 1;
//
//		for (size_t i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)//一次直接排序gap组数据避免再套一层循环
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > a[end + gap])
				{
					Swap(&a[end], &a[end + gap]);
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = temp;
		}
	}
}
void SelectSort(int* a, int n)
{
	int head = 0, tail = n - 1;
	while (head < tail)
	{
		int maxi = head, mini = head;
		for (int i = head; i <= tail; i++)
		{
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{
				mini = i;
			}
		}
		if (head == maxi)//如果交换时那个位置是最大值的话会有问题
		{
			Swap(&a[head], &a[mini]);
			maxi = mini;
		}
		else
			Swap(&a[head], &a[mini]);
		Swap(&a[tail], &a[maxi]);
		head++;
		tail--;
	}
}
int GetMidi(int* a, int left, int right)//改变选择极端值情况
{
	int midi = (left + right) / 2;
	if (a[left] < a[midi])
	{
		if (a[midi] < a[right])
		{
			return midi;
		}
		else if (a[right] < a[left])
		{
			return left;
		}
		else
			return right;
	}
	else//a[midi]>=a[right]
	{
		if (a[right] > a[left])
		{
			return left;
		}
		else if (a[midi] > a[right])
		{
			return midi;
		}
		else
			return right;
	}
}
int PartSort(int* a, int left, int right)
{
	/*if (right - left + 1 < 10)
	{
		InsertSort(a + left, right -left+1);
	}*/
	//else {
		int begin = left, end = right;
		int ret = GetMidi(a, left, right);
		Swap(&a[ret], &a[left]);
		int keyi = left;
		while (begin < end)
		{
			while (begin < end && a[end] >= a[keyi])//右边找小的
			{
				end--;
			}
			while (begin < end && a[begin] <= a[keyi])//左边找大的数
			{
				begin++;
			}
			Swap(&a[begin], &a[end]);
		}
		Swap(&a[keyi], &a[begin]);
		return begin;
	//}
}
int PartSort2(int* a, int left, int right)
{
	int ret = GetMidi(a, left, right);
	Swap(&a[ret], &a[left]);
	int prev = left;
	int cur = prev + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi]&&++prev!=cur)//避免prev==cur指针的自己交换情况
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);//循环结束后要交换keyi和prev的值
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
		/*PartSort(a, keyi, begin, end);*/
	int keyi = PartSort(a, left, right);
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
}
void QuickSort02(int* a, int left, int right)//挖坑法的快速排序
{
	if (left >= right)
		return;
	int begin = left, end = right;
	int temp = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= temp)//找xiao数
		{
			end--;
		}
		a[begin] = a[end];
		while (begin < end && a[begin]<=temp)//找大数
		{
			begin++;
		}
		a[end] = a[begin];
	}
	int mid = begin;
	a[mid] = temp;
	QuickSort02(a, left, mid - 1);
	QuickSort02(a, mid + 1, right);
}
void QuickSortNonR(int* a, int left, int right)//使用栈来模拟递归情况
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);
	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);
		int keyi=PartSort(a, begin, end);//keyi位置已经排好了，把区间分成了[begin,keyi-1][keyi+1,end]
		if (keyi+1 <end)
		{
			STPush(&st,end);
			STPush(&st, keyi + 1);
		}
		if (begin<keyi-1)
		{
			STPush(&st, keyi-1);
			STPush(&st, begin);
		}
		
	}
	STDestroy(&st);
}
void _MergeSort(int* a, int* temp, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left+right) / 2;//分割区间成[left,mid][mid+1,right]
	_MergeSort(a, temp, left,mid);
	_MergeSort(a, temp, mid+1,right);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	
	int i = left;
	while (begin1 <=end1 && begin2<=end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
			temp[i++] = a[begin2++];
	}
	while(begin1 <= end1)
		temp[i++] = a[begin1++];
	while(begin2 <= end2)
		temp[i++] = a[begin2++];
	memcpy(a+left, temp+left, sizeof(int)*(right - left+1));
}
void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		perror("malloc fail:");
		exit(1);
	}
	_MergeSort(a, temp, 0, n - 1);
	free(temp);
	temp = NULL;
}
void MergeSortNonR(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);
	if (temp == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)//[begin1,end1][begin2,end2]
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 =i + 2 * gap - 1;
			if (begin2 >= n)
				break;
			if (end2 >= n)
				end2 = n-1;
			/*printf("[%d %d][%d %d]", begin1, end1, begin2, end2);*/
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					temp[j++] = a[begin1++];
				}
				else
					temp[j++] = a[begin2++];
			}
			while (begin1 <= end1)
				temp[j++] = a[begin1++];
			while (begin2 <= end2)
				temp[j++] = a[begin2++];
			memcpy(a +i, temp + i, sizeof(int) * (end2-i+1));
			
		}
		/*printf("\n");*/
		gap *= 2;
	}
}
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* tmp = calloc(range, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	     int i = 0;
		for (int j = 0; j < range; j++)
		{
			while (tmp[j]--)
			{
				a[i++] = j + min;
			}
	}
}