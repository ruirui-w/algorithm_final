#include<bits/stdc++.h>
using namespace std;
int www=3;
int greedy(int ratings[] ) {
	int result[www];
	int count = 0;
	for(int i = 0; i < www; i++) {
		result[i] = 1;
	}
	// ��ǰ������� 
	for(int i = 1; i < www; i++) {
		if(ratings[i] > ratings[i - 1]) {
			result[i] = result[i - 1] + 1;
		}
	}
	// �Ӻ���ǰ����
	for(int j = www - 2; j >= 0; j--) {
		if(ratings[j] > ratings[j + 1] && result[j] <= result[j + 1]) {
			result[j] = result[j + 1] + 1;
		}
	}
	// �������ǹ����ĺ�
	for(int i = 0; i < www; i++) {
		count += result[i];
	}
	return count;
}
int main() {
	int ratings[]={1,2,2,2,3,1,2};
	www=sizeof(ratings)/sizeof(ratings[0]);
	cout<<"�����ķ�������Ϊ[1,2,2,2,3,1,2]ʱ�������ǹ���Ϊ"<<greedy(ratings); 
	return 0;
}


