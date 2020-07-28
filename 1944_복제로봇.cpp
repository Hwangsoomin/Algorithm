#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#define MOD 100999
#define ll long long
using namespace std;
int n, m, stx, sty, keynum[55][55], ans, chk[255], knum;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
char arr[55][55];
vector<pair<int, int>> graph[255];
queue<pair<int, int>> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool flag = false;
pair<int, int> key[255];
void bfs(int r, int c, int parent) {
	q.push({ r,c });
	int check[55][55] = { 0, };
	int dist[55][55] = { 0, };
	while (!q.empty()) {
		int nr = q.front().first;
		int nc = q.front().second;
		q.pop();
		check[nr][nc] = 1;
		for (int i = 0; i < 4; i++) {
			int nnr = nr + dr[i];
			int nnc = nc + dc[i];
			if (nnr<1 || nnr>n || nnc<1 || nnc>n)continue;
			if (!check[nnr][nnc] && arr[nnr][nnc] != '1') {
				check[nnr][nnc] = 1;
				dist[nnr][nnc] = dist[nr][nc] + 1;
				if (arr[nnr][nnc] == '0') q.push({ nnr,nnc });
				if (arr[nnr][nnc] == 'K')graph[parent].push_back({ keynum[nnr][nnc], dist[nnr][nnc] });
			}
		}
	}
}
void prim() {
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (chk[here])continue;
		chk[here] = 1;
		ans += cost;
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int nc = graph[here][i].second;
			if (!chk[next])pq.push({ nc,next });
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'S' || arr[i][j] == 'K') {
				knum += 1;
				arr[i][j] = 'K';
				keynum[i][j] = knum;
				key[knum] = { i,j };
			}
		}
	}
	for (int i = 1; i <= knum; i++) {
		int x = key[i].first;
		int y = key[i].second;
		bfs(x, y, i);
	}
	prim();
	for (int i = 1; i <= knum; i++)if (!chk[i])flag = true;
	if (!flag) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}