#include<bits/stdc++.h>
using namespace std;
int www;
int playdp(int ratings[] ) {
	int n = www;
	int ret = 1;
	int inc = 1, dec = 0, pre = 1;
	for (int i = 1; i < n; i++) {
		if (ratings[i] >= ratings[i - 1]) {
			dec = 0;
			pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
			ret += pre;
			inc = pre;
		} else {
			dec++;
			if (dec == inc) {
				dec++;
			}
			ret += dec;
			pre = 1;
		}
	}
	return ret;
}
int main() {
	int ratings[]= {1,2,2,2,3,1,2};
	www=sizeof(ratings)/sizeof(ratings[0]);
	cout<<"�����ķ�������Ϊ[1,2,2,2,3,1,2]ʱ�������ǹ���Ϊ"<<playdp(ratings);
	return 0;
}


