#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#include<map>
#define ll long long
using namespace std;
int n, x, y, uf[1005];
ll ans;
pair<int, int> arr[1005];
priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
int find(int u) {
	if (uf[u] == u)return uf[u];
	else return uf[u] = find(uf[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	uf[u] = v;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		arr[i] = { x,y };
		uf[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		x = arr[i].first;
		y = arr[i].second;
		for (int j = i + 1; j <= n; j++) {
			int nx = arr[j].first;
			int ny = arr[j].second;
			ll sum = ((nx - x) * (nx - x)) + ((ny - y) * (ny - y));
			pq.push({ sum, {i,j} });
		}
	}
	while (!pq.empty()) {
		ll cost = pq.top().first;
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		pq.pop();
		if (find(n1) != find(n2)) {
			merge(n1, n2);
			ans = max(ans, cost);
		}
	}
	printf("%lld\n", ans);
	return 0;
}