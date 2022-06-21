#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include <cstring>
using namespace std;
int greedy(string s) {
	unordered_map<char, int>map;
	int ans = 0;
	for (auto& ch : s) {
		map[ch]++;
	}
	for (auto ch : map) {
		int num = ch.second;
		ans = ans + (num / 2) * 2;
		if (num % 2 == 1 && ans % 2 == 0) {
			ans++;
		}
	}
	return ans;
}

int main() {
	char s[1000];
	fgets(s, 1000, stdin);
	cout << greedy(s);
	return 0;
}

