#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
int n, m, k;
ll ans;
int dev[1005], check[1005];
vector<pair<int, int>> arr[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void di() {
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (check[here])continue;
		check[here] = 1;
		ans += cost;
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first;
			int ncost = arr[here][i].second;
			pq.push({ ncost,next });
		}
	}
}
int main(void) {
	int u, v, w;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &dev[i]);
		pq.push({ 0, dev[i] });
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		arr[u].push_back({ v,w });
		arr[v].push_back({ u,w });
	}
	di();
	printf("%lld\n", ans);
	return 0;
}