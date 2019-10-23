#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int t, w, h, pre = 1, pre1;
char arr[1005][1005];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int check[1005][1005];
bool flag = false;
void bfs(queue<pair<pair<int, int>,int>> fq, queue<pair<pair<int, int>, int>> sq) {
	while (1) {
		while (!fq.empty()) {
			int r = fq.front().first.first;
			int c = fq.front().first.second;
			int cnt1 = fq.front().second;
			if (cnt1 != pre)break;
			check[r][c] = 1;
			fq.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr<1 || nr>h || nc<1 || nc>w) continue;
				if (arr[nr][nc] == '.') {
					check[nr][nc] = 1;
					arr[nr][nc] = '*';
					fq.push({ { nr,nc },cnt1 + 1 });
				}
			}
		}
		while (!sq.empty()) {
			int r1 = sq.front().first.first;
			int c1 = sq.front().first.second;
			int cnt = sq.front().second;
			if (cnt != pre1)break;
			sq.pop();
			for (int i = 0; i < 4; i++) {
				int nr1 = r1 + dr[i];
				int nc1 = c1 + dc[i];
				if (nr1<1 || nr1>h || nc1<1 || nc1>w) {
					printf("%d\n", cnt + 1);
					flag = true;
					break;
				}
				if (arr[nr1][nc1] == '.' && !check[nr1][nc1]) {
					check[nr1][nc1] = 1;
					sq.push({ {nr1,nc1},cnt + 1 });
				}
			}
			if (flag)break;
		}
		pre++;
		pre1++;
		if (flag)break;
		if (fq.empty() && sq.empty())break;
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		pre = 1; pre1 = 0;
		queue<pair<pair<int, int>,int>> fq;
		queue<pair<pair<int, int>, int>> sq;
		memset(check, 0, sizeof(check));
		memset(arr, '.', sizeof(arr));
		flag = false;
		scanf("%d%d", &w, &h);
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w;j++) {
				scanf(" %c", &arr[i][j]);
				if (arr[i][j] == '*')fq.push({ { i,j },1 });
				if (arr[i][j] == '@')sq.push({ { i,j },0 });
			}
		}
		bfs(fq, sq);
		if (!flag)printf("IMPOSSIBLE\n");
	}
	return 0;
}