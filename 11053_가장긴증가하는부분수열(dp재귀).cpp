#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<functional>
using namespace std;
int n, ans;
int arr[1005], dp[1005];
int go(int here) {
	int& ret = dp[here];
	if (ret != -1)return dp[here];
	for (int i = here + 1; i <= n; i++) {
		if (arr[here] < arr[i])  dp[here] = max(dp[here], go(i) + 1);
	}
	return dp[here] = max(dp[here], 1);
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		if(dp[i]==-1)go(i);
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}