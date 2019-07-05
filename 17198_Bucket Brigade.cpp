#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
char arr[15][15];
int check[15][15];
int x, y;
bool flag = false;
queue<pair<pair<int, int>, int>> q;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void bfs() {
	q.push({ { x,y },0 });
	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		check[r][c] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 1 || nr>10 || nc < 1 || nc>10)continue;
			if (!check[nr][nc]) {
				if (arr[nr][nc] == 'B') {
					printf("%d\n", cnt);
					flag = true;
					break;
				}
				if (arr[nr][nc] == '.') {
					check[nr][nc] = 1;
					q.push({ { nr,nc },cnt + 1 });
				}
			}
		}
		if (flag)break;
	}
}
int main(void) {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'L') {
				x = i;
				y = j;
			}
		}
	}
	bfs();
	return 0;
}