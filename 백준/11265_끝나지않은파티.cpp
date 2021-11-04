#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
int n, m;
int arr[505][505], dist[505];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void di(int num) {
	dist[num] = 0;
	pq.push({ 0,num });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)continue;
		for (int i = 1; i <= n; i++) {
			int next = i;
			int ncost = arr[here][i];
			if (dist[next] > ncost + cost) {
				dist[next] = ncost + cost;
				pq.push({ dist[next],next });
			}
		}
	}
}
int main(void) {
	int a, b, c;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		for (int x = 1; x <= n; x++) dist[x] = 1e9;
		di(a);
		if (c < dist[b])printf("Stay here\n");
		else printf("Enjoy other party\n");
	}
	return 0;
}