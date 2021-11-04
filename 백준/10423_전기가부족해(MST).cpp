#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
#include<stack>
#define ll long long
using namespace std;
int n, m, k, u, v, w, ans;
int power[1005], uf[1005];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int find(int u) {
	if (uf[u] == u)return u;
	else return uf[u] = find(uf[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (power[u])uf[v] = u;
	else uf[u] = v;
}
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)uf[i] = i;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &u);
		power[u] = 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		pq.push({ w,{u,v} });
	}
	while (!pq.empty()) {
		int cost = pq.top().first;
		int fc = pq.top().second.first;
		int sc = pq.top().second.second;
		pq.pop();
		int fp = find(fc);
		int sp = find(sc);
		if (fp == sp)continue;
		if (power[fp] && power[sp])continue;
		merge(fc, sc);
		ans += cost;
	}
	printf("%d\n", ans);
	return 0;
}