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
int n, a, b, Max = 1, m;
vector<int> arr[100005];
int depth[100005], par[100005][25], check[100005];
void dfs(int here, int level) {
	depth[here] = level;
	check[here] = 1;
	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i];
		if (!check[next]) {
			check[next] = 1;
			dfs(next, level + 1);
			par[next][0] = here;
		}
	}
}
int LCA(int n1, int n2) {
	if (depth[n1] < depth[n2])swap(n1, n2);
	int diff = depth[n1] - depth[n2];
	for (int i = 0; i <= Max; i++) if (diff & (1 << i))n1 = par[n1][i];
	if (n1 != n2) {
		for (int i = Max; i >= 0; i--) {
			if (par[n1][i] && par[n1][i] != par[n2][i]) {
				n1 = par[n1][i];
				n2 = par[n2][i];
			}
		}
		n1 = par[n1][0];
	}
	return n1;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	a = 1;
	while (a < n) {
		Max += 1;
		a *= 2;
	}
	dfs(1, 1);
	for (int i = 1; i <= Max; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
	return 0;
}