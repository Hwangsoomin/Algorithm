#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n, check[1005][1005], cnt, ans, cnt1, ans1;
char arr[1005][1005];
queue<pair<int, int>> q;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void bfs(int r, int c) {
	cnt = 0, cnt1 = 1;
	q.push({ r,c });
	while (!q.empty()) {
		int nr = q.front().first;
		int nc = q.front().second;
		check[nr][nc] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nnr = nr + dr[i];
			int nnc = nc + dc[i];
			if (nnr < 0 || nnr > n + 1 || nnc < 0 || nnc > n + 1)continue;
			if (arr[nnr][nnc] != '#') cnt++;
			else if (arr[nnr][nnc] == '#' && !check[nnr][nnc]) {
				cnt1++;
				q.push({ nnr,nnc });
				check[nnr][nnc] = 1;
			}
		}
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			arr[i][j] = '.';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!check[i][j] && arr[i][j] == '#') {
				bfs(i, j);
				if (ans1 == cnt1) ans = min(ans, cnt);
				else if (ans1 < cnt1) {
					ans = cnt;
					ans1 = cnt1;
				}
			}
		}
	}
	printf("%d %d\n", ans1, ans);
	return 0;
}