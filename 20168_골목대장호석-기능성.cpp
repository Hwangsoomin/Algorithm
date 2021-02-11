#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
int n, m, a, b, c, ans = 1e9;
int x, y, z;
int check[15];
vector<pair<int, int>> arr[15];
void go(int here, int cnt, int Max) {
	check[here] = 1;
	if (here == b) {
		if (cnt <= c) ans = min(ans, Max);
		return;
	}
	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i].first;
		int cost = arr[here][i].second;
		int nMax = max(Max, cost);
		if (!check[next]) {
			check[next] = 1;
			go(next, cnt + cost, nMax);
			check[next] = 0;
		}
	}
}
int main(void) {
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		arr[x].push_back({ y,z });
		arr[y].push_back({ x,z });
	}
	go(a, 0, 0);
	if (ans == 1e9)printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}