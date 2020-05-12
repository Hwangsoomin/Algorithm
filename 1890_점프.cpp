#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<functional>
#define ll long long
using namespace std;
int n, arr[105][105];
ll dp[105][105];
ll go(int r, int c) {
	ll &ret = dp[r][c];
	if (ret != -1)return dp[r][c];
	if (r == n && c == r)return dp[r][c] = 1;
	ret = 0;
	int num = arr[r][c];
	if (r + num <= n)dp[r][c] = dp[r][c] + go(r + num, c);
	if (c + num <= n)dp[r][c] = dp[r][c] + go(r, c + num);
	return dp[r][c];
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = -1;
			scanf("%d", &arr[i][j]);
		}
	}
	go(1, 1);
	printf("%lld\n", dp[1][1]);
	return 0;
}