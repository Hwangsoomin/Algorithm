#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define ll long long
using namespace std;
int n, m, check[505][505], dist[505][505], hx, hy;
char arr[505][505];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
priority_queue<pair<int,pair<int, int>>> pq;
bool flag = false;
void bfs() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		check[r][c] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr<1 || nr>n || nc<1 || nc>m)continue;
			if (!check[nr][nc]) {
				dist[nr][nc] = dist[r][c] + 1;
				check[nr][nc] = 1;
				q.push({ nr,nc });
			}
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == '+') {
				q.push({ i, j });
				check[i][j] = 1;
			}
			if (arr[i][j] == 'V') {
				hx = i;
				hy = j;
			}
		}
	}
	bfs();//나무까지의 거리 구하기
	memset(check, 0, sizeof(check));
	pq.push({ dist[hx][hy],{hx,hy} });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		check[r][c] = 1;
		if (arr[r][c] == 'J') {
			printf("%d\n", cost);
			break;
		}
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr<1 || nr>n || nc<1 || nc>m)continue;
			if (!check[nr][nc]) {
				check[nr][nc] = 1;
				int Min = min(cost, dist[nr][nc]);
				pq.push({ Min,{nr,nc} });
			}
		}
	}
	return 0;
}