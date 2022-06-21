#include<bits/stdc++.h>
using namespace std;
int greedy(int nums[],int len) {
	int res =-1000;
	int sum = 0;
	for(int i=0; i<len; i++) {
		sum+=nums[i];
		res =max(res,sum);
		if(sum<=0) {
			sum=0;
		}
	}
	return res;
}
int main() {
	int nums[]= {-2,1,-3,4,-1,2,1,-5,4};
	cout<<"当输入数组为[-2,1,-3,4,-1,2,1,-5,4]时，最大连续和为："<<endl;
	cout<<greedy(nums,9);
	return 0;
}

