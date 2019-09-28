#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
string str1, str2;
char c;
int Max;
int main(void) {
	int num;
	cin >> str1 >> c >> str2;
	if (str1.size() > str2.size()) {
		num = str1.size() - str2.size();
		Max = str2.size();
	}
	else {
		num = str2.size() - str1.size();
		Max = str1.size();
	}
	if (c == '*') {
		printf("1");
		for (int i = 1; i <= str1.size() + str2.size() - 2; i++)printf("0");
	}
	else {
		if (str1.size() == str2.size()) printf("2");
		else {
			printf("1");
			for (int i = 1; i < num; i++) printf("0");
			printf("1");
		}
		for (int i = 1; i < Max; i++)printf("0");
	}
	return 0;
}