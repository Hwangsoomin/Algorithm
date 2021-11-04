#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int v, e, a, b, c;
int m, x, s, y, Min = 1e9;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> arr[10005];
void di(vector<int>& dist, priority_queue<pair<int, int>>& pq) {
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
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
}
int main(void) {
	scanf("%d%d", &v, &e);
	for (int i = 1; i <= e; i++) {
		scanf("%d%d%d", &a, &b, &c);
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	vector<int> distm(v + 1, 1e9), dists(v + 1, 1e9);
	scanf("%d%d", &m, &x);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a);
		distm[a] = 0;
		pq.push({ 0,a});
	}
	di(distm, pq);
	scanf("%d%d", &s, &y);
	for (int i = 1; i <= s; i++) {
		scanf("%d", &a);
		dists[a] = 0;
		pq.push({ 0,a });
	}
	di(dists, pq);
	for (int i = 1; i <= v; i++) {
		if (0 != distm[i] && distm[i] <= x && 0 != dists[i] && dists[i] <= y) Min = min(Min, distm[i] + dists[i]);
	}
	if(Min!=1e9) printf("%d\n", Min);
	else printf("-1\n");
	return 0;
}