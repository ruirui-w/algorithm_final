#include<bits/stdc++.h>
using namespace std;
string centralExtend(string &s) {
	const int length=s.size();
	int maxlength=0;
	int start;

	for(int i=0; i<length; i++) { //����Ϊ����
		int j=i-1,k=i+1;
		while(j>=0&&k<length&&s.at(j)==s.at(k)) {
			if(k-j+1>maxlength) {
				maxlength=k-j+1;
				start=j;
			}
			j--;
			k++;
		}
	}
	for(int i=0; i<length; i++) { //����Ϊż��
		int j=i,k=i+1;
		while(j>=0&&k<length&&s.at(j)==s.at(k)) {
			if(k-j+1>maxlength) {
				maxlength=k-j+1;
				start=j;
			}
			j--;
			k++;
		}
	}
	if(maxlength>0)
		return s.substr(start,maxlength);
	return NULL;
}
int main() {
	char s[1000];
	fgets(s, 1000, stdin);
	string ss;
	ss=s;
	cout << centralExtend(ss);
	return 0;
}


