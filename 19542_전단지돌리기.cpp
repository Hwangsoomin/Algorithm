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
int n, s, d, x, y, depth[100005], check[100005], ans, visit[100005];
vector<int> road[100005];
void dfs(int here) {
	check[here] = 1;
	for (int i = 0; i < road[here].size(); i++) {
		int next = road[here][i];
		if (!check[next]) {
			check[next] = 1;
			dfs(next);
			depth[here] = max(depth[here], (depth[next] + 1));
			visit[here] = max(visit[here], visit[next]);
		}
	}
	if (depth[here] == d) visit[here] = 1;
}
int main(void) {
	scanf("%d%d%d", &n, &s, &d);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		road[x].push_back(y);
		road[y].push_back(x);
	}
	dfs(s);
	for (int i = 1; i <= n; i++) {
		if (visit[i])ans += 1;
	}
	ans -= 1;
	ans *= 2;
	if (ans < 0)ans = 0;
	printf("%d\n", ans);
	return 0;
}