#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
#define ll long long
using namespace std;
int n, m, a, b, c, ans, cnt;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int uf[1005], check[1005];
int find(int u) {
	if (uf[u] == u)return u;
	else return uf[u] = find(uf[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	uf[u] = v;
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)uf[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		pq.push({ c,{a,b} });
	}
	while (cnt < n - 1) {
		int cost = pq.top().first;
		int here = pq.top().second.first;
		int next = pq.top().second.second;
		pq.pop();
		if (find(here) != find(next)) {
			cnt += 1;
			ans += cost;
			merge(here, next);
		}
	}
	printf("%d\n", ans);
	return 0;
}