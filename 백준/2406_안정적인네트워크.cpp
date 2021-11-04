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
int n, m, x, y, check[1005], sum;
vector<pair<int, int>> arr[1005], ans;
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
void prim() {
	pq.push({ {0,2},1 });
	while (!pq.empty()) {
		int cost = pq.top().first.first;
		int here = pq.top().first.second;
		int pre = pq.top().second;
		pq.pop();
		if (check[here])continue;
		check[here] = 1;
		if (cost != 0) {
			sum += cost;
			ans.push_back({ pre,here });
		}
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first;
			int nc = arr[here][i].second;
			if (!check[next])pq.push({ {nc,next},here });
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		arr[x].push_back({ y,0 });
		arr[y].push_back({ x,0 });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			if (i == j || i == 1 || j == 1)continue;
			arr[i].push_back({ j,x });
			arr[j].push_back({ i,x });
		}
	}
	prim();
	int num = ans.size();
	printf("%d %d\n", sum, num);
	for (int i = 0; i < num; i++)printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}