#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<functional>
#define ll long long
using namespace std;
int n, m, a, b;
int arr[2005], dp[2005][2005];
int go(int st, int en) {
	int& ret = dp[st][en];
	if (ret != -1)return dp[st][en];
	if (st == en)return dp[st][en] = 1;
	ret = 0;
	if (1 <= en - 1 && st + 1 <= n) {
		if (go(st + 1, en - 1) || st + 1 == en) {
			if (arr[st] == arr[en])dp[st][en] = 1;
		}
	}
	if (st + 1 <= n) go(st + 1, en);
 	if (1 <= en - 1) go(st, en - 1);
	return dp[st][en];

}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	for (int i = 1; i < 2005; i++) {
		for (int j = 1; j < 2005; j++) {
			dp[i][j] = -1;
		}
	}
	go(1, n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
	return 0;
}