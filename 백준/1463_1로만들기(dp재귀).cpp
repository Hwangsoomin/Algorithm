#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<functional>
using namespace std;
int n;
int dp[1000005];
int go(int num) {
	int& ret = dp[num];
	if (num == 1)return dp[num] = 0;
	if (ret != 1e9)return dp[num];
	if (num % 3 == 0)dp[num] = min(dp[num], go(num / 3) + 1);
	if (num % 2 == 0)dp[num] = min(dp[num], go(num / 2) + 1);
	dp[num] = min(dp[num], go(num - 1) + 1);
	return dp[num];
}
int main(void) {
	scanf("%d", &n);
	fill(dp, dp + 1000005, 1e9);
	go(n);
	printf("%d\n", dp[n]);
	return 0;
}