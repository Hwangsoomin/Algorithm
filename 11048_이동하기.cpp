#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<functional>
#define ll long long
using namespace std;
int n, m;
int arr[1005][1005], dp[1005][1005];
int go(int r, int c) {
	int& ret = dp[r][c];
	if (ret != -1)return dp[r][c];
	if (r == n && c == m)return dp[r][c] = arr[r][c];
	ret = 0;
	if (r + 1 <= n)dp[r][c] = max(dp[r][c], arr[r][c] + go(r + 1, c));
	if (c + 1 <= m)dp[r][c] = max(dp[r][c], arr[r][c] + go(r, c + 1));
	if (r + 1 <= n && c + 1 <= m)dp[r][c] = max(dp[r][c], arr[r][c] + go(r + 1, c + 1));
	return dp[r][c];
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = -1;
			scanf("%d", &arr[i][j]);
		}
	}
	go(1, 1);
	printf("%d\n", dp[1][1]);
	return 0;
}