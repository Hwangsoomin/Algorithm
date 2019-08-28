#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n, m, Max;
char arr[25][25];
int check[25][25], alpha[25];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void dfs(int r, int c, int cnt) {
	check[r][c] = 1;
	alpha[arr[r][c] - 'A'] = 1;
	Max = max(Max, cnt);
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr<1 || nr>n || nc<1 || nc>m)continue;
		if (!check[nr][nc] && !alpha[arr[nr][nc] - 'A']) {
			dfs(nr, nc, cnt + 1);
			check[nr][nc] = 0;
			alpha[arr[nr][nc] - 'A'] = 0;
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	dfs(1, 1, 1);
	printf("%d\n", Max);
	return 0;
}