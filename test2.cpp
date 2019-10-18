//把有10个整数元素的数组用冒泡排序法按从小到大升序排列
#include<iostream>
using namespace std;
int main(){
	const int n = 11;
	int i, j, t;
	int a[n];
    cout << "请输入10个整数：" << endl;
    for (i = 1; i < n; i++){
		cin >> a[i];
	}
    for (j = 1; j < n - 1; j++){
		for (i = 1; i<n - j; i++){
			if (a[i]>a[i + 1]){
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}
	}
    cout << "排序后为：" << endl;
	for (i = 1; i < n; i++){
		cout << "  " << a[i];
	}

	cout << endl;

	return 0;
}
