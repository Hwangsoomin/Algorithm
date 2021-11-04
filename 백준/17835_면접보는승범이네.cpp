#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
using namespace std;
ll n, m, k, u, v, c, ans;
ll dist[100005], MAX;
vector<pair<ll, ll>> arr[100005];
priority_queue<pair<ll, ll>> pq;
int main(void) {
	scanf("%lld%lld%lld", &n, &m, &k);
	for (ll i = 1; i <= n; i++)dist[i] = 1e18;
	for (ll i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &u, &v, &c);
		arr[v].push_back({ u,c });
	}
	for (ll i = 1; i <= k; i++) {
		scanf("%lld", &u);
		dist[u] = 0;
		pq.push({ 0,u });
	}
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		ll here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)continue;
		for (ll i = 0; i < arr[here].size(); i++) {
			ll next = arr[here][i].first;
			ll nc = arr[here][i].second;;
			if (cost + nc < dist[next]) {
				dist[next] = cost + nc;
				pq.push({ -dist[next],next });
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		if (MAX < dist[i]) {
			MAX = dist[i];
			ans = i;
		}
	}
	printf("%lld\n%lld\n", ans, MAX);
	return 0;
}