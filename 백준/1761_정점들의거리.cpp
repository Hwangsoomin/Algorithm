#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#define ll long long
#define num 200005
#define N 49999
using namespace std;
int n, a, b, c, Max, m;
ll ans1, ans2;
vector<pair<int, int>> arr[40005];
int depth[40005], par[40005][25], check[40005], dist[40005][25];
void dfs(int here, int level) {
	depth[here] = level;
	check[here] = 1;
	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i].first;
		int cost = arr[here][i].second;
		if (!check[next]) {
			check[next] = 1;
			dfs(next, level + 1);
			par[next][0] = here;
			dist[next][0] = cost;
		}
	}
}
void LCA(int n1, int n2) {
	if (depth[n1] < depth[n2])swap(n1, n2);
	int diff = depth[n1] - depth[n2];
	for (int i = 0; i <= Max; i++) {
		if (diff & (1 << i)) {
			ans1 += (1LL * dist[n1][i]);
			n1 = par[n1][i];
		}
	}
	if (n1 != n2) {
		for (int i = Max; i >= 0; i--) {
			if (par[n1][i] && par[n1][i] != par[n2][i]) {
				ans1 += (1LL * dist[n1][i]);
				n1 = par[n1][i];
				ans2 += (1LL * dist[n2][i]);
				n2 = par[n2][i];
			}
		}
		ans1 += (1LL * dist[n1][0]);
		ans2 += (1LL * dist[n2][0]);
		n1 = par[n1][0];
	}

}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	a = 1;
	while (a < n) {
		a *= 2;
		Max += 1;
	}
	dfs(1, 1);
	for (int i = 1; i <= Max; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
			if (par[j][i] != 0) dist[j][i] = dist[j][i - 1] + dist[par[j][i - 1]][i - 1];
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		ans1 = 0; ans2 = 0;
		scanf("%d%d", &a, &b);
		LCA(a, b);
		printf("%lld\n", ans1 + ans2);
	}
	return 0;
}