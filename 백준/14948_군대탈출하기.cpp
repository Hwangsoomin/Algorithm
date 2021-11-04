#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
int n, m, check[105][105][2];
ll arr[105][105], ans = 1e10;
int dr[8] = { -2,-1,0,0,2,1,0,0 };
int dc[8] = { 0,0,2,1,0,0,-2,-1 };
priority_queue<pair<pair<ll, int>, pair<int, int>>, vector<pair<pair<ll, int>, pair<int, int>>>, greater<pair<pair<ll, int>, pair<int, int>>>> pq;
void bfs() {
	pq.push({ {arr[1][1],1},{1,1} });
	check[1][1][1] = 1;
	while (!pq.empty()) {
		ll cost = pq.top().first.first;
		int jump = pq.top().first.second;
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		pq.pop();
		if (r == n && c == m) {
			ans = cost;
			break;
		}
		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr<1 || nr>n || nc<1 || nc>m)continue;
			ll ncost = arr[nr][nc];
			if (i % 2 == 0 && jump == 1) {
				if (!check[nr][nc][jump - 1]) {
					check[nr][nc][jump - 1] = 1;
					if (cost < ncost)pq.push({ {ncost,jump - 1},{nr,nc} });
					else pq.push({ {cost,jump - 1},{nr,nc} });
				}
			}
			else if (i % 2 != 0) {
				if (!check[nr][nc][jump]) {
					check[nr][nc][jump] = 1;
					if (cost < ncost)pq.push({ {ncost,jump},{nr,nc} });
					else pq.push({ {cost,jump},{nr,nc} });
				}
			}
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%lld", &arr[i][j]);
		}
	}
	bfs();
	printf("%lld\n", ans);
	return 0;
}