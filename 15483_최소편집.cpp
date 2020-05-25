#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
using namespace std;
string a, b;
int dp[1005][1005];
int go(int ah, int bh) {
	int& ret = dp[ah][bh];
	if (ah < 0 || bh < 0)return abs(ah - bh);
	if (ret != 1e9)return ret;
	if (a[ah] == b[bh]) ret = min(ret, go(ah - 1, bh - 1));
	else {
		ret = min(ret, go(ah, bh - 1) + 1);
		ret = min(ret, go(ah - 1, bh) + 1);
		ret = min(ret, go(ah - 1, bh - 1) + 1);
	}
	return ret;
}
int main(void) {
	cin >> a >> b;
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < 1005; j++)dp[i][j] = 1e9;
	}
	int n1 = a.length() - 1;
	int n2 = b.length() - 1;
	int ans = go(n1, n2);
	printf("%d\n", ans);
	return 0;
}