#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m;
pair<long long, long long> arr[100005];
vector<int> v[100005];
long long maxx, minx = 1e9, maxy, miny = 1e9, ans = 1e9;
int check[100005];
queue<int> q;
void bfs(int num) {
	q.push(num);
	while (!q.empty()) {
		int nn = q.front();
		check[nn] = 1;
		maxx = max(maxx, arr[nn].first);
		minx = min(minx, arr[nn].first);
		maxy = max(maxy, arr[nn].second);
		miny = min(miny, arr[nn].second);
		q.pop();
		for (int i = 0; i < v[nn].size(); i++) {
			int nnn = v[nn][i];
			if (!check[nnn]) {
				check[nnn] = 1;
				q.push(nnn);
			}
		}
	}
}
int main(void) {
	int x, y;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &x, &y);
		arr[i] = { x,y };
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		maxx = 0, minx = 1e9, maxy = 0, miny = 1e9;
		if (!check[i]) {
			bfs(i);
			long long sum = ((maxx - minx) * 2) + ((maxy - miny) * 2);
			ans = min(ans, sum);
		}
	}
	printf("%lld\n", ans);
	return 0;
}