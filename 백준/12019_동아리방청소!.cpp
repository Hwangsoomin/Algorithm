#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
using namespace std;
int n, m, arr[105];
int dp[105][15][105];
vector<int> ans;
int go(int here, int cnt, int pre, int sum) {
	if (here == n)return dp[here][cnt][pre] = sum * arr[here];
	if (dp[here][cnt][pre] != -1)return dp[here][cnt][pre];
	dp[here][cnt][pre] = 1e9;
	if (cnt != 0)dp[here][cnt][pre] = min(dp[here][cnt][pre], go(here + 1, cnt - 1, here, 0));//청소했을 때
	dp[here][cnt][pre] = min(dp[here][cnt][pre], go(here + 1, cnt, pre, sum + arr[here]));
	return dp[here][cnt][pre] += (sum * arr[here]);
}
int main(void) {
	scanf("%d%d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	go(1, m, 0, 0);
	int now = 1, ncnt = m, npre = 0;
	while (now < n) {
		if (ncnt == 0)break;
		if (dp[now + 1][ncnt][npre] >= dp[now + 1][ncnt - 1][now]) {
			ans.push_back(now);
			ncnt -= 1;
			npre = now;
		}
		now += 1;
	}
	printf("%d\n", dp[1][m][0]);
	for (int i = 0; i < ans.size(); i++)printf("%d ", ans[i]);
	printf("\n");
	return 0;
}