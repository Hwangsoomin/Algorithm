#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int n, m;
int check[105][105], arr[105][105];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
void bfs() {
	q.push({ 1,1 });
	check[1][1] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr<1 || nr>n || nc<1 || nc>m)continue;
			if (!check[nr][nc] && arr[nr][nc]) {
				check[nr][nc] = check[r][c] + 1;
				q.push({ nr,nc });
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
	printf("%d\n", check[n][m]);
	return 0;
}