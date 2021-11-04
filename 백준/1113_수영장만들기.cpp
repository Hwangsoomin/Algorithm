#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
int n, m, arr[55][55], Max, ans;
queue < pair<int, int>> q;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void bfs(int num) {
	q.push({ 0,0 });
	arr[0][0] = num;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr<0 || nr>n + 1 || nc<0 || nc>m + 1)continue;
			if (arr[nr][nc] < num) {
				arr[nr][nc] = num;
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
			Max = max(Max, arr[i][j]);
		}
	}
	for (int i = 1; i <= Max; i++) {
		bfs(i);
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) {
				if (arr[x][y] < i) {
					ans += 1;
					arr[x][y] += 1;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}