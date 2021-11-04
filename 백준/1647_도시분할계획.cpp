#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#define MOD 100999
#define ll long long
using namespace std;
int n, m, a, b, c, check[100005], ans, Max;
vector<pair<int, int>> arr[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void prim() {
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (check[here])continue;
		ans += cost;
		Max = max(Max, cost);
		check[here] = 1;
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first;
			int nc = arr[here][i].second;
			if (!check[next])pq.push({ nc,next });
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	prim();
	ans -= Max;
	printf("%d\n", ans);
	return 0;
}