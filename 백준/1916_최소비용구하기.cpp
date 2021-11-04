#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define INF 1e10
vector<pair<int,int>> arr[1005];
int n, m, A, B;
long long dist[1005], check[10005];
priority_queue<pair<long long, int>> pq;
void di() {
	pq.push({ 0,A });
	while (!pq.empty()) {
		long long cost = -pq.top().first;
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
	int a, b, c;
	scanf("%d", &n);
	scanf("%d", &m);
	fill(dist, dist + n + 1, INF);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		arr[a].push_back({ b,c });
	}
	scanf("%d%d", &A, &B);
	dist[A] = 0;
	di();
	printf("%d\n", dist[B]);
	return 0;
}