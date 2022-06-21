#include<bits/stdc++.h>
using namespace std;
int Union(int nums[] , int left, int mid, int right) {
	int leftSum =-1000;
	int tempSum = 0;
	for (int i = mid; i >=left; i--) {
		tempSum+=nums[i];
		leftSum = max(tempSum,leftSum);
	}
	tempSum = 0;
	int rightSum=-1000;
	for(int i = mid + 1; i <=right; i++) {
		tempSum+=nums[i];
		rightSum = max(rightSum, tempSum);
	}
	return leftSum+rightSum;
}
int maxSubArrayPart(int nums[] , int left, int right) {
	if (left == right) return nums[left];
	int mid = (left+right)/2;
	return max(maxSubArrayPart(nums,left,mid),max(maxSubArrayPart(nums,mid+1,right),Union(nums,left,mid,right)));
}
int main() {
	int nums[]= {5,4,-1,7,8,-1,3,-1,2};
	cout<<"当输入数组为[5,4,-1,7,8,-1,3,-1,2]时，最大连续和为："<<endl;
	cout<<maxSubArrayPart(nums, 0, 8);
	return 0;
}

