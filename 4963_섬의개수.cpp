#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int w, h, cnt;
int arr[55][55], check[55][55];
queue<pair<int, int>> q;
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };
void bfs(int r, int c) {
	q.push({ r,c });
	while (!q.empty()) {
		int nr = q.front().first;
		int nc = q.front().second;
		check[nr][nc] = 1;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nnr = nr + dr[i];
			int nnc = nc + dc[i];
			if (nnr<1 || nnr>h || nnc<1 || nnc>w)continue;
			if (!check[nnr][nnc] && arr[nnr][nnc] == 1) {
				check[nnr][nnc] = 1;
				q.push({ nnr,nnc });
			}
		}
	}
}
int main(void) {
	while (1) {
		memset(check, 0, sizeof(check));
		memset(arr, 0, sizeof(arr));
		cnt = 0;
		scanf("%d%d", &w, &h);
		if (w == 0 && h == 0)break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (!check[i][j] && arr[i][j] == 1) {
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