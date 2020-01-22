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
using namespace std;
int n, Max, a, b, m, x, k, l;
ll c, ans, ans1;
vector<pair<int, ll>> arr[100005];
ll dist[100005][25];
int check[100005], depth[100005], par[100005][25];
void dfs(int here, int level) {
	depth[here] = level;
	check[here] = 1;
	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i].first;
		ll cost = arr[here][i].second;
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
			ans += dist[n1][i];
			n1 = par[n1][i];
		}
	}
	if (n1 != n2) {
		for (int i = Max; i >= 0; i--) {
			if (par[n1][i] && par[n1][i] != par[n2][i]) {
				ans += (dist[n1][i] + dist[n2][i]);
				n1 = par[n1][i];
				n2 = par[n2][i];
			}
		}
		ans += (dist[n1][0] + dist[n2][0]);
		n1 = par[n1][0];
	}
	l = n1;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf(" %d%d%lld", &a, &b, &c);
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
			if (par[j][i] != 0) dist[j][i] = dist[par[j][i - 1]][i - 1] + dist[j][i - 1];
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		ans = 0;
		scanf("%d%d%d", &x, &a, &b);
		if (x == 1) {
			LCA(a, b);
			printf("%lld\n", ans);
		}
		else {
			scanf("%d", &k);
			LCA(a, b);
			int p1 = depth[a] - depth[l] + 1;
			int p2 = depth[b] - depth[l];
			int nn = 0;
			if (p1 >= k) {
				nn = 1;
				ans1 = a;
				for (int j = Max; j >= 0; j--) {
					if ((k - nn) & (1 << j)) {
						nn += (1 << j);
						ans1 = par[ans1][j];
					}
				}
			}
			else {
				ans1 = b;
				k = p2 - (k - p1);
				for (int j = Max; j >= 0; j--) {
					if ((k - nn) & (1<<j)) {
						nn += (1 << j);
						ans1 = par[ans1][j];
					}
				}
			}
			printf("%d\n", ans1);
		}
	}
	return 0;
}