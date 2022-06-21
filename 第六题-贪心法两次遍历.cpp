#include<bits/stdc++.h>
using namespace std;
int www=3;
int greedy(int ratings[] ) {
	int result[www];
	int count = 0;
	for(int i = 0; i < www; i++) {
		result[i] = 1;
	}
	// 从前往后遍历 
	for(int i = 1; i < www; i++) {
		if(ratings[i] > ratings[i - 1]) {
			result[i] = result[i - 1] + 1;
		}
	}
	// 从后往前遍历
	for(int j = www - 2; j >= 0; j--) {
		if(ratings[j] > ratings[j + 1] && result[j] <= result[j + 1]) {
			result[j] = result[j + 1] + 1;
		}
	}
	// 计算总糖果数的和
	for(int i = 0; i < www; i++) {
		count += result[i];
	}
	return count;
}
int main() {
	int ratings[]={1,2,2,2,3,1,2};
	www=sizeof(ratings)/sizeof(ratings[0]);
	cout<<"给定的分数数组为[1,2,2,2,3,1,2]时，最少糖果数为"<<greedy(ratings); 
	return 0;
}


