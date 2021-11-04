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
int m, n, check[200005], x, y, z, ans, Max;
vector<pair<int, int>> arr[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void prim() {
	ans = 0;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (check[here])continue;
		ans += cost;
		check[here] = 1;
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first;
			int nc = arr[here][i].second;
			if (!check[next])pq.push({ nc,next });
		}
	}
}
int main(void) {
	while (1) {
		Max = 0;
		for (int i = 0; i < m; i++) {
			check[i] = 0;
			arr[i].clear();
		}
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0)break;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &x, &y, &z);
			arr[x].push_back({ y,z });
			arr[y].push_back({ x,z });
			Max += z;
		}
		prim();
		ans = Max - ans;
		printf("%d\n", ans);
	}
	return 0;
}