#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int cnt = 0;
int max0 = 0;
int x[100];
int r[100];
int C [100][100];

int playdp() {
	int j = 1;
	while (C[cnt - 1][j] != 0) {
		if (j < x[cnt] || C[cnt - 1][j] <= C[cnt][j - x[cnt]] + 1)
			C[cnt][j] = C[cnt - 1][j];
		else
			C[cnt][j] = C[cnt][j - x[cnt]] + 1;
		j++;
	}

	while (true) {
		int tmp = 1e4;
		for (int i = 1; i <= cnt; i++) {
			if (tmp > C[cnt][j - x[i]] + 1)
				tmp = C[cnt][j - x[i]] + 1;
			C[cnt][j - x[cnt]];
		}
		if (tmp == 1e4 || tmp > m)
			break;
		else
			C[cnt][j] = tmp;
		j++;
	}
	C[cnt][j] = 0;
	return j - 1;
}

void dfs() {
	if (cnt == n) {
		if (x[cnt] * m < max0)
			return;
		int tmp = playdp();
		if (tmp > max0) {
			max0 = tmp;
			for (int i = 1; i <= n; i++)
				r[i] = x[i];
		}
	} else {
		int tmp = playdp();
		for (int i = x[cnt] + 1; i <= tmp + 1; i++) {
			x[++cnt] = i;
			dfs();
			cnt--;
		}
	}
}



int main() {
	cout<<"请输入邮票种数n与限制张数m:"<<endl;
	cin>>n>>m;
	x[1] = 1;
	cnt = 1;
	dfs();
	cout<<"最大范围是:"<<max0<<endl;
	cout<<"具体选择种类为："<<endl;
	for (int i = 1; i <= m; i++) {
		cout<<r[i]<<" ";
	}
	return 0;
}

