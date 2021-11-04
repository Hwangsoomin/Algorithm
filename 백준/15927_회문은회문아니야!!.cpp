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
string str;
bool flag = false;
int main(void) {
	cin >> str;
	char c = str[0];
	for (int i = 1; i < str.size(); i++) {
		if (c != str[i])flag = true;
	}
	if (!flag) {
		printf("-1\n");
		return 0;
	}
	flag = false;
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i])flag = true;
	}
	if (flag)printf("%d\n", str.size());
	else printf("%d\n", str.size() - 1);
	return 0;
}