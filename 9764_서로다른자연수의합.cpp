#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#define MOD 100999
using namespace std;
int t, n, dp[2005][2005];
int go(int here, int sum) {
	if (sum == n)return 1;
	if (here > n)return 0;
	int& ret = dp[here][sum];
	if (ret != -1)return dp[here][sum];
	ret = 0;
	if (sum + (here + 1) <= n)ret += go(here + 1, sum + (here + 1));
	ret += go(here + 1, sum);
	return ret % MOD;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		int ans = go(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}