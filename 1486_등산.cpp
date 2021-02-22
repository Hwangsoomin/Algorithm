#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
#define ll long long
using namespace std;
int n, m, t, d;
int check[30][30];
ll dist[30][30], M[30][30], dist2[30][30], ans;
char arr[30][30];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
void di() {
	pq.push({ 0, {1, 1} });
	dist[1][1] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		pq.pop();
		if (dist[r][c] < cost)continue;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			ll sum = 0;
			if (nr<1 || nr>n || nc<1 || nc>m)continue;
			if (abs(M[r][c] - M[nr][nc]) > t)continue;
			if (M[nr][nc] <= M[r][c])sum = 1;
			else sum = (M[r][c] - M[nr][nc]) * (M[r][c] - M[nr][nc]);
			if (dist[nr][nc] > dist[r][c] + sum) {
				dist[nr][nc] = dist[r][c] + sum;
				pq.push({ dist[nr][nc] , { nr,nc } });
			}
		}
	}
}
void di2() {
	pq.push({ 0, {1, 1} });
	dist2[1][1] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		pq.pop();
		if (dist2[r][c] < cost)continue;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			ll sum = 0;
			if (nr<1 || nr>n || nc<1 || nc>m)continue;
			if (abs(M[r][c] - M[nr][nc]) > t)continue;
			if (M[nr][nc] >= M[r][c])sum = 1;
			else sum = (M[r][c] - M[nr][nc]) * (M[r][c] - M[nr][nc]);
			if (dist2[nr][nc] > dist2[r][c] + sum) {
				dist2[nr][nc] = dist2[r][c] + sum;
				pq.push({ dist2[nr][nc] , { nr,nc } });
			}
		}
	}
}
int main(void) {
	scanf("%d%d%d%d", &n, &m, &t, &d);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = LLONG_MAX;
			dist2[i][j] = LLONG_MAX;
			scanf(" %c", &arr[i][j]);
			if ('A' <= arr[i][j] && arr[i][j] <= 'Z')M[i][j] = arr[i][j] - 'A';
			else M[i][j] = (arr[i][j] - 'a') + 26;
		}
	}
	di();
	di2();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] != LLONG_MAX && dist2[i][j] != LLONG_MAX) {
				if (dist[i][j] + dist2[i][j] <= d)ans = max(ans, M[i][j]);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}