//��Ƴ����ҳ�1-100�����������ʾ����
#include<iostream>
using namespace std;
int _main(){
	int n, m;
	for (n = 2; n <= 100; n++){
		for (m = 2; m <= n; m++){
			if (n % m == 0)
				break;
		}
		if (n == m){
			cout << n << endl;
		}
	}
    return 0;
}