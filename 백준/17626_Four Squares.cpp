#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#include<map>
#define MOD 1000000003
#define ll long long
using namespace std;
int n, ans, dp[50005];
int main(void) {
	scanf("%d", &n);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int Min = 1e9;
		for (int j = 1; j < 250; j++) {
			int nnum = j * j;
			if (nnum > i)break;
			Min = min(Min, dp[i - nnum]);
		}
		dp[i] = Min + 1;
	}
	printf("%d\n", dp[n]);
	return 0;
}