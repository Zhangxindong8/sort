//����10������Ԫ�ص�������ð�����򷨰���С������������
#include<iostream>
using namespace std;
int main(){
	const int n = 11;
	int i, j, t;
	int a[n];
    cout << "������10��������" << endl;
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
    cout << "�����Ϊ��" << endl;
	for (i = 1; i < n; i++){
		cout << "  " << a[i];
	}

	cout << endl;

	return 0;
}
