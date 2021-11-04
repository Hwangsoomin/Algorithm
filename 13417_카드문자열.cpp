#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
#include<stack>
#define ll long long
using namespace std;
int t, n, Min = 1e9;
char str[1005];
string ans;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		bool flag = false;
		ans = "";
		Min = 1e9;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf(" %c", &str[i]);
			int n1 = str[i] - 'A';
			Min = min(Min, n1);
		}
		ans += str[0];
		for (int i = 1; i < n; i++) {
			int fn = ans[0] - 'A';
			int here = str[i] - 'A';
			if (fn < here)ans += str[i];
			else ans = str[i] + ans;
		}
		cout << ans << endl;
	}
	return 0;
}