#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int arr[105][105], check[105][105];
queue < pair<pair<int, int>, int>> q;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void bfs() {
	q.push({ {1,1},1 });
	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		check[r][c] = 1;
		q.pop();
		if (r == n && c == m) {
			printf("%d\n", cnt);
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr<1 || nr>n || nc<1 || nc>m)continue;
			if (!check[nr][nc] && arr[nr][nc] == 1) {
				check[nr][nc] = 1;
				q.push({ {nr,nc},cnt + 1 });
			}
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	bfs();
	return 0;
}