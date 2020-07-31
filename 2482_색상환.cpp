#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#define MOD 1000000003
#define ll long long
using namespace std;
ll n, k, dp[1005][1005];
int main(void) {
	scanf("%lld", &n);
	scanf("%lld", &k);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j == 1)dp[i][j] = i;
			else if (i - 2 > 0)dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
	}
	printf("%lld\n", dp[n][k]);
	return 0;
}