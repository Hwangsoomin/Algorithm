#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<string>
#include<map>
#define ll long long
using namespace std;
int n, m, jin, k, a, b, c, Min = 1e9, ans;
char hou[5005];
vector<pair<int, int>> arr[5005];
int dist[5005];
priority_queue<pair<int, int>> pq;
int main(void) {
	scanf("%d%d", &n, &m);
	scanf("%d", &jin);
	scanf("%d", &k);
	for (int i = 0; i < 5005; i++) dist[i] = 1e9;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &a);
		hou[a] = 'A';
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &a);
		hou[a] = 'B';
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	pq.push({ 0,jin });
	dist[jin] = 0;
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[here] < cost)continue;
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first;
			int nc = arr[here][i].second;
			if (dist[next] > cost + nc) {
				dist[next] = cost + nc;
				pq.push({ -dist[next],next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i != jin) {
			if (Min >= dist[i] && (hou[i] =='A' || hou[i]=='B')) {
				if (Min == dist[i])ans = 'A';
				else {
					Min = dist[i];
					ans = hou[i];
				}
			}
		}
	}
	if (Min == 1e9) printf("-1\n");
	else printf("%c\n%d\n", ans, Min);
	return 0;
}