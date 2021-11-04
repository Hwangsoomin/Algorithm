#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int t, n, sx, sy, ex, ey;
queue<pair<pair<int, int>, int>> q;
int check[305][305];
int dr[8] = { -2,-1,1,2,2,1,-1,-2 };
int dc[8] = { 1,2,2,1,-1,-2,-2,-1 };
void bfs() {
	q.push({ {sx,sy},0 });
	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		check[r][c] = 1;
		if (r == ex && c == ey) {
			printf("%d\n", cnt);
			break;
		}
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n)continue;
			if (!check[nr][nc]) {
				check[nr][nc] = 1;
				q.push({ {nr,nc},cnt + 1 });
			}
		}
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		memset(check, 0, sizeof(check));
		scanf("%d", &n);
		scanf("%d%d", &sx, &sy);
		scanf("%d%d", &ex, &ey);
		bfs();
		while (!q.empty())q.pop();
	}
	return 0;
}