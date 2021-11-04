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
int n, a, b, M, m;
int depth[100005], check[100005], par[100005][25];
ll Max[100005][25], Min[100005][25];
ll c, ans1, ans2 = 1e9;
vector<pair<int, ll>> arr[100005];
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
			Max[next][0] = cost;
			Min[next][0] = cost;
		}
	}
}
void LCA(int n1, int n2) {
	if (depth[n1] < depth[n2])swap(n1, n2);
	int diff = depth[n1] - depth[n2];
	for (int i = 0; i <= M; i++) {
		if (diff & (1 << i)) {
			ans1 = max(ans1, Max[n1][i]);
			ans2 = min(ans2, Min[n1][i]);
			n1 = par[n1][i];
		}
	}
	if (n1 != n2) {
		for (int i = M; i >= 0; i--) {
			if (par[n1][i] && par[n1][i] != par[n2][i]) {
				ans1 = max(Max[n1][i], ans1);
				ans1 = max(Max[n2][i], ans1);
				ans2 = min(Min[n1][i], ans2);
				ans2 = min(Min[n2][i], ans2);
				n1 = par[n1][i];
				n2 = par[n2][i];
			}
		}
		ans1 = max(Max[n1][0], ans1);
		ans1 = max(Max[n2][0], ans1);
		ans2 = min(Min[n1][0], ans2);
		ans2 = min(Min[n2][0], ans2);
		n1 = par[n1][0];
	}
}
int main(void) {
	for (int i = 1; i < 100005; i++) {
		for (int j = 0; j < 25; j++) {
			Min[i][j] = 1e9;
		}
	}
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf(" %d%d%lld", &a, &b, &c);
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	a = 1;
	while (a < n) {
		a *= 2;
		M += 1;
	}
	dfs(1, 1);
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
			if (par[j][i] != 0) {
				Max[j][i] = max(Max[par[j][i-1]][i-1], Max[j][i-1]);
				Min[j][i] = min(Min[j][i - 1], Min[par[j][i - 1]][i - 1]);
			}
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		ans1 = 0; ans2 = 1e9;
		scanf("%d%d", &a, &b);
		LCA(a, b);
		printf("%lld %lld\n", ans2, ans1);
	}
	return 0;
}