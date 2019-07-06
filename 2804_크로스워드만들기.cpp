#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
string str1, str2;
int ans1, ans2;
bool flag = false;
int main(void) {
	cin >> str1;
	cin >> str2;
	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) {
				ans1 = i;
				ans2 = j;
				flag = true;
				break;
			}
		}
		if (flag)break;
	}
	for (int i = 0; i < str2.size(); i++) {
		for (int j = 0; j < str1.size(); j++) {
			if (j == ans1)printf("%c", str2[i]);
			else if (i == ans2)printf("%c", str1[j]);
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}