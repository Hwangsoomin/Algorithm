#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n, m, h, num, num1;
int check[105][105][105], toma[105][105][105];
int dr[6] = { -1,0,1,0 ,-1,1 };
int dc[6] = { 0,1,0,-1,0,0 };
bool flag = false, flag1 = false;
queue<pair<pair<int, int>, pair<int, int>>> q;
void bfs() {
	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int fl = q.front().second.first;
		int cnt = q.front().second.second;
		check[r][c][fl] = 1;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nr = 0, nc = 0, nfl = 0;
			if (i == 5 || i == 4) {
				nfl = fl + dr[i];
				nr = r;
				nc = c;
			}
			else {
				nr = dr[i] + r;
				nc = dc[i] + c;
				nfl = fl;
			}
			if (nr<1 || nr>n || nc<1 || nc>m || nfl > h || nfl < 1) continue;
			if (!check[nr][nc][nfl] && toma[nr][nc][nfl] == 0) {
				check[nr][nc][nfl] = 1;
				num1++;
				q.push({ {nr,nc},{nfl,cnt + 1} });
			}
		}
		if (num1 == num) {
			printf("%d\n", cnt + 1);
			break;
		}
	}
}
int main(void) {
	scanf("%d%d%d", &m, &n, &h);
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &toma[i][j][k]);
				if (toma[i][j][k] == 0)num++;
				if (toma[i][j][k] == 1) {
					q.push({ {i,j},{ k,0 }});
					check[i][j][k] = 1;
				}
			}
		}
	}
	if (num == 0) {
		printf("0\n");
		return 0;
	}
	bfs();
	if (num1 != num)printf("-1\n");
	return 0;
}