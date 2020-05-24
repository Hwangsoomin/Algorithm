#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#define MOD 100999
using namespace std;
int n, t, k, s, dp[105][10005];
pair<int, int> arr[105];
int go(int here, int sum) {
	int& ret = dp[here][sum];
	if (ret != -1)return dp[here][sum];
	if (here == n)return 0;
	ret = 0;
	if (sum - arr[here + 1].first >= 0)ret = go(here + 1, sum - arr[here + 1].first) + arr[here + 1].second;
	ret = max(ret, go(here + 1, sum));
	return ret;
}
int main(void) {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &k, &s);
		arr[i] = { k,s };
	}
	memset(dp, -1, sizeof(dp));
	int ans = go(0, t);
	printf("%d\n", ans);
	return 0;
}