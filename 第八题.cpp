#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
double minlen = 1e5;
double x[maxn], r[maxn];
double bestR[maxn];
int n;

double get_center(int t) {
	double tmp = 0;
	for (int i = 1; i < t; ++i) {
		double now = x[i] + 2.0 * sqrt(r[t] * r[i]);
		tmp = max(tmp, now);
	}
	return tmp;
}

void get_perfect() {
	double left = 0, right = 0;
	for (int i = 1; i <= n ; ++i) {
		if (x[i] - r[i] < left) left = x[i] - r[i];
		if (x[i] + r[i] > right) right = x[i] + r[i];
	}
	if (right - left < minlen) {
		minlen = right - left;
		for (int i = 1; i <= n ; ++i) {
			bestR[i] = r[i];
		}
	}
}


void dfs(int pos) {
	if (pos == n + 1) {
		get_perfect();
	} else {
		for (int i = pos; i <= n; ++i) {
			swap(r[pos], r[i]);
			double X_pos = get_center(pos);
			if (X_pos + r[pos] + r[1] < minlen) {
				x[pos] = X_pos;
				dfs(pos + 1);
			}
			swap(r[pos], r[i]);
		}
	}
}


int main() {
	cout << "输入圆的个数：" << endl;
	cin >> n;
	cout << "依次输入圆的半径" << endl;
	for (int i = 1; i <= n; ++i) {
		cin >> r[i];
	}
	for (int i = 1; i <= n; ++i) {
		cout << "第" << i << "个圆的半径为：" << r[i] << endl;
	}
	dfs(1);
	cout << "矩形框最小长度为：" << minlen << endl;
	cout << "最优圆排列的顺序对应的半径分别为：";
	for (int i = 1; i <= n; ++i) {
		cout << bestR[i] << " ";
	}
	cout << endl;
	return 0;
}
