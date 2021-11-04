#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int t, m, n, k, x, y, cnt;
int arr[55][55], check[55][55];
queue<pair<int, int>> q;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void bfs(int r, int c) {
	q.push({ r,c });
	while (!q.empty()) {
		int nr = q.front().first;
		int nc = q.front().second;
		check[nr][nc] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nnr = nr + dr[i];
			int nnc = nc + dc[i];
			if (nnr<0 || nnr >= m || nnc<0 || nnc >= n)continue;
			if (!check[nnr][nnc] && arr[nnr][nnc] == 1) {
				check[nnr][nnc] = 1;
				q.push({ nnr,nnc });
			}
		}
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		memset(check, 0, sizeof(check));
		memset(arr, 0, sizeof(arr));
		cnt = 0;
		scanf("%d%d%d", &m, &n, &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d%d", &x, &y);
			arr[x][y] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1 && !check[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		while (!q.empty())q.pop();
	}
	return 0;
}