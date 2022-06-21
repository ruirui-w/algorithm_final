#include<bits/stdc++.h>
using namespace std;
double playdp(long long n) {
	int dp[10000];
	dp[1] = 1;
	dp[2] = 2;
	for( int i = 3; i <= n; ++i ) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}
int main() {
	int n;
	cin>>n;
	cout<<playdp(n);
	return 0;
}

