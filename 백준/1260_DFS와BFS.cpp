#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, v, m, a, b;
vector<int> arr[1005];
int check[1005];
queue<int> q;
void dfs(int here) {
	check[here] = 1;
	printf("%d ", here);
	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i];
		if (!check[next]) {
			check[next] = 1;
			dfs(next);
		}
	}
}
void bfs() {
	q.push(v);
	while (!q.empty()) {
		int here = q.front();
		printf("%d ", here);
		check[here] = 1;
		q.pop();
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i];
			if (!check[next]) {
				check[next] = 1;
				q.push(next);
			}
		}
	}
}
int main(void) {
	scanf("%d%d%d", &n, &m, &v);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)sort(arr[i].begin(), arr[i].end());
	dfs(v);
	memset(check, 0, sizeof(check));
	printf("\n");
	bfs();
	return 0;
}