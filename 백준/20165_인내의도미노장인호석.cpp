#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, r, x, y, d, ans;
int arr[105][105], check[105][105];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
void go(int r, int c, int dist) {
	q.push({ r,c });
	ans += 1;
	while (!q.empty()) {
		int nr = q.front().first;
		int nc = q.front().second;
		int nnr = nr;
		int nnc = nc;
		check[nr][nc] = 1;
		q.pop();
		for (int i = 1; i < arr[nr][nc]; i++) {
			int nnnr = nnr + dr[dist];
			int nnnc = nnc + dc[dist];
			if (nnnr<1 || nnnr>n || nnnc<1 || nnnc>m)continue;
			if (!check[nnnr][nnnc]) {
				ans += 1;
				check[nnnr][nnnc] = 1;
				q.push({ nnnr,nnnc });
			}
			nnr = nnnr;
			nnc = nnnc;
		}
	}

}
int main(void) {
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= r; i++) {
		int dist = 0;
		scanf("%d%d", &x, &y);
		scanf(" %c", &d);
		if (d == 'N')dist = 0;
		if (d == 'E')dist = 1;
		if (d == 'S')dist = 2;
		if (d == 'W')dist = 3;
		go(x, y, dist);
		scanf("%d%d", &x, &y);
		check[x][y] = 0;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j]) printf("F ");
			else printf("S ");
		}
		printf("\n");
	}
	return 0;
}