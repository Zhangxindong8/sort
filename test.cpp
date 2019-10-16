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

//������ֳ�������
int partition(int *a, int left, int right){
	int j = left;  //������������ 
	int i = j - 1;  //����ָ��С�ڻ�׼Ԫ�ص�λ��
	int key = a[right]; //��׼bn;'
	21.Ԫ��
	//���������˼�룬��ǰ�����Ҵ��ڻ�׼Ԫ�صķŵ��ұ�
	for (; j < right; ++j){
		if (a[j] <= key)
			swap(&a[j], &a[++i]);
	}
	//�ѻ�׼Ԫ�طŵ��м�
	swap(&a[right], &a[++i]);
	//���������м��λ��
	return i;
}

//��������ĺ���
void quicksort(int *a, int left, int right){
	if (left >= right)
		return;
	int mid = partition(a, left, right);
	quicksort(a, left, mid - 1);
	quicksort(a, mid + 1, right);
}
void insertsort(int *a, int n)  //ֱ�Ӳ�������{
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
void shellsort(int *a, int n) //ϣ������������
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
		int key = i;  //��ʱ���������洢��С�ı���
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[key])
				key = j; //�������ҵ���С����ֵ
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

//����������Ѷ���iΪ��ǰ�ڵ㣬nΪ�ѵĴ�С
//    �ӵ�һ����Ҷ�ӽ��i�������ϣ�������������ṹ
//    ���������ӽڵ���ѡ���ϴ�����븸�׽ڵ���бȽ�
//    ������ӽڵ�ȸ��׽ڵ������н���
void creatheap(int *a, int i, int n)
{
	for (; i >= 0; --i)
	{
		int left = i * 2 + 1;  //���������  
		int right = i * 2 + 2; //���������
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

//�ϲ������Ѿ��ź��������
void merge(int *a, int left, int mid, int right)
{
	int len = right - left + 1;  //����ĳ���
	int *temp = new int[len];  //����len�����ȵ���ʱ����
	int k = 0;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		//ѡ���С�Ĵ�����ʱ����
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
	���ʱ�临�Ӷ�ΪO(n^2)��
	ƽ��ʱ�临�Ӷ�ΪO(n^2)��
	�ȶ��ԣ��ȶ���
	�����ռ�O(1)
	*/
	superbubblesort(arr, n);
	/*
	��������ȴ�ͳð�����������Ժ�
	*/
	quicksort(arr, 0, n - 1);
	/*
	���ʱ�临�Ӷȣ�O(n^2)��
	����ʱ�临�Ӷȣ�O(nlogn)��
	ƽ��ʱ�临�Ӷȣ�O(nlogn)��
	�ȶ��ԣ����ȶ��ģ�
	�����ռ䣺O(nlogn)
	*/
	insertsort(arr, n);
	/*
	���ʱ�临�Ӷȣ�O(n^2)��
	����ʱ�临�Ӷȣ�O(n)��
	ƽ��ʱ�临�Ӷȣ�O(n^2)��
	�ȶ��ԣ��ȶ���
	�����ռ䣺O(1)
	*/
	shellsort(arr, n);
	/*
	���ʱ�临�Ӷȣ�O(n^2)��
	����ʱ�临�Ӷȣ�O(n)��
	ƽ��ʱ�临�Ӷȣ�O(n^1.3)��
	�ȶ��ԣ����ȶ��ģ�
	�����ռ䣺O(1)
	*/
	selectsort(arr, n);
	/*
	���ʱ�临�Ӷȣ�O(n^2)��
	����ʱ�临�Ӷȣ�O(n^2)��
	ƽ��ʱ�临�Ӷȣ�O(n^2)��
	�ȶ��ԣ����ȶ��ģ�
	�����ռ䣺O(1)
	*/
	heapsort(arr, n);
	/*
	���ʱ�临�Ӷȣ�O(nlogn)��
	����ʱ�临�Ӷȣ�O(nlogn)��
	ƽ��ʱ�临�Ӷȣ�O(nlogn)��
	�ȶ��ԣ����ȶ��ģ�
	�����ռ䣺O(1)
	*/
	mergesort(arr, 0, n - 1);
	/*
	���ʱ�临�Ӷȣ�O(nlogn)��
	����ʱ�临�Ӷȣ�O(nlogn)��
	ƽ��ʱ�临�Ӷȣ�O(nlogn)��
	�ȶ��ԣ����ȶ��ģ�
	�����ռ䣺O(n)
	*/

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

