void bubblesort(int *arr, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (arr[j]>arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//把数组分成两部分
int partition(int *a, int left, int right){
	int j = left;  //用来遍历数组 
	int i = j - 1;  //用来指向小于基准元素的位置
	int key = a[right]; //基准bn;'
	21.元素
	//快速排序的思想，从前往后找大于基准元素的放到右边
	for (; j < right; ++j){
		if (a[j] <= key)
			swap(&a[j], &a[++i]);
	}
	//把基准元素放到中间
	swap(&a[right], &a[++i]);
	//返回数组中间的位置
	return i;
}

//快速排序的函数
void quicksort(int *a, int left, int right){
	if (left >= right)
		return;
	int mid = partition(a, left, right);
	quicksort(a, left, mid - 1);
	quicksort(a, mid + 1, right);
}
void insertsort(int *a, int n)  //直接插入排序{
	int temp = 0;
	for (int i = 1; i < n; i++){
		int j = i - 1;
		if (a[i] < a[j]){
			temp = a[i];
			a[i] = a[j];
			while (temp < a[j - 1]){
				a[j] = a[j - 1];
				j--;
			}
			a[j] = temp;
		}
	}
}
void shellsort(int *a, int n) //希尔排序主函数
{
	int dk = n / 2;
	while (dk > 1)
	{
		shellinsertsort(a, n, dk);
		dk /= 2;
	}
}

void shellinsertsort(int *a, int n, int dk)
{
	for (int i = dk; i < n; i++)
	{
		int j = i - dk;
		if (a[i]<a[j])
		{
			int tmp = a[i];
			a[i] = a[j];
			while (a[j]>tmp)
			{
				a[j + dk] = a[j];
				j -= dk;
			}
			a[j + dk] = tmp;
		}
	}
}
void selectsort(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int key = i;  //临时变量用来存储最小的变量
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[key])
				key = j; //交换，找到最小的数值
		}
		if (key != i)
		{
			int temp = a[key];
			a[key] = a[i];
			a[i] = temp;
		}
	}
}
void heapsort(int *a, int n)
{
	creatheap(a, n / 2 - 1, n);
	for (int j = n - 1; j >= 0; j--)
	{
		int temp = a[0];
		a[0] = a[j];
		a[j] = temp;

		int i = j / 2 - 1;
		creatheap(a, i, j);
	}
}

//　　创建大堆顶，i为当前节点，n为堆的大小
//    从第一个非叶子结点i从下至上，从右至左调整结构
//    从两个儿子节点中选出较大的来与父亲节点进行比较
//    如果儿子节点比父亲节点大，则进行交换
void creatheap(int *a, int i, int n)
{
	for (; i >= 0; --i)
	{
		int left = i * 2 + 1;  //左子树结点  
		int right = i * 2 + 2; //右子树结点
		int j = 0;
		if (right < n)
		{
			a[left]>a[right] ? j = left : j = right;
		}
		else
			j = left;
		if (a[j] > a[i])
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
}
void mergesort(int *a, int left, int right)
{
	if (left > right)
		return;
	int mid = (left + right) / 2;
	mergesort(a, left, mid - 1);
	mergesort(a, mid + 1, right);
	merge(a, left, right, mid);
}

//合并两个已经排好序的数组
void merge(int *a, int left, int mid, int right)
{
	int len = right - left + 1;  //数组的长度
	int *temp = new int[len];  //分配len个长度的临时数组
	int k = 0;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		//选择较小的存入临时数组
		temp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= right)
	{
		temp[k++] = a[j++];
	}
	for (int k = 0; k < len; k++)
	{
		a[left++] = temp[k];
	}

}
#include <iostream>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "InsertSort.h"
#include "SelectSort.h"
#include "MergeSort.h"

using namespace std;

void main()
{

	int arr[] = { 10, 6, 5, 2, 3, 8, 7, 4, 9, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	bubblesort(arr, n);
	/*
	最差时间复杂度为O(n^2)；
	平均时间复杂度为O(n^2)；
	稳定性：稳定；
	辅助空间O(1)
	*/
	superbubblesort(arr, n);
	/*
	这种排序比传统冒泡排序性能稍好
	*/
	quicksort(arr, 0, n - 1);
	/*
	最差时间复杂度：O(n^2)；
	最优时间复杂度：O(nlogn)；
	平均时间复杂度：O(nlogn)；
	稳定性：不稳定的；
	辅助空间：O(nlogn)
	*/
	insertsort(arr, n);
	/*
	最差时间复杂度：O(n^2)；
	最优时间复杂度：O(n)；
	平均时间复杂度：O(n^2)；
	稳定性：稳定；
	辅助空间：O(1)
	*/
	shellsort(arr, n);
	/*
	最差时间复杂度：O(n^2)；
	最优时间复杂度：O(n)；
	平均时间复杂度：O(n^1.3)；
	稳定性：不稳定的；
	辅助空间：O(1)
	*/
	selectsort(arr, n);
	/*
	最差时间复杂度：O(n^2)；
	最优时间复杂度：O(n^2)；
	平均时间复杂度：O(n^2)；
	稳定性：不稳定的；
	辅助空间：O(1)
	*/
	heapsort(arr, n);
	/*
	最差时间复杂度：O(nlogn)；
	最优时间复杂度：O(nlogn)；
	平均时间复杂度：O(nlogn)；
	稳定性：不稳定的；
	辅助空间：O(1)
	*/
	mergesort(arr, 0, n - 1);
	/*
	最差时间复杂度：O(nlogn)；
	最优时间复杂度：O(nlogn)；
	平均时间复杂度：O(nlogn)；
	稳定性：不稳定的；
	辅助空间：O(n)
	*/

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

