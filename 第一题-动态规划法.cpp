#include<bits/stdc++.h>
using namespace std;
int greedy(int nums[],int len) {
	if(len==1)return nums[0];
	int cur =nums[0],res=nums[0];
	for(int i=1; i<len; i++) {
		cur = max(nums[i],cur+nums[i]);
		res = max(res,cur);
	}
	return res;

}
int main() {
	int nums[]= {5,4,-1,7,8};
	cout<<"����������Ϊ[5,4,-1,7,8]ʱ�����������Ϊ��"<<endl;
	cout<<greedy(nums,5);
	return 0;
}

