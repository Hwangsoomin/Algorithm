#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
using namespace std;
int n;
string str, str1, ans;
bool flag = false;
int main(void) {
	scanf("%d", &n);
	cin >> str >> str1;
	if (n % 2 != 0) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '1')ans += '0';
			else ans += '1';
		}
		if (ans == str1)flag = true;
	}
	else {
		if (str == str1)flag = true;
	}
	if (flag)printf("Deletion succeeded\n");
	else printf("Deletion failed\n");
	return 0;
}