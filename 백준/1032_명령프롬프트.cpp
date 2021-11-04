#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define ll long long
using namespace std;
int n;
string str, arr[55], ans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> str;
		arr[i] = str;
	}
	for (int i = 0; i < arr[1].size(); i++) {
		char c = arr[1][i];
		bool flag = false;
		for (int j = 2; j <= n; j++) {
			if (c != arr[j][i])flag = true;
		}
		if (!flag)ans += c;
		else ans += '?';
	}
	cout << ans << "\n";
	return 0;
}