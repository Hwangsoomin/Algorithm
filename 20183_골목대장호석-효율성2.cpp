#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#define ll long long
using namespace std;
ll n, m, a, b, c;
int ans = 1e9 + 1, x, y, z;
vector<pair<int, int>> arr[100005];
vector<int> Cost;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
ll dist[100005];
int go(int Mon) {
	for (int i = 1; i <= n; i++)dist[i] = LLONG_MAX;
	dist[a] = 0;
	pq.push({ 0,a });
	while (!pq.empty()) {
		ll cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)continue;
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first;
			ll ncost = arr[here][i].second;
			if (ncost <= Mon && dist[next] > ncost + dist[here]) {
				dist[next] = ncost + dist[here];
				pq.push({ dist[next],next });
			}
		}
	}
	if (dist[b] <= c) return 1;
	else return 0;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%lld%lld%lld%lld%lld", &n, &m, &a, &b, &c);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		arr[x].push_back({ y,z });
		arr[y].push_back({ x,z });
		Cost.push_back(z);
	}
	sort(Cost.begin(), Cost.end());
	ll l = 0, r = Cost.size() - 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (go(Cost[mid])) {
			ans = min(ans, Cost[mid]);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (ans == 1e9 + 1)printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}