#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<string>
#include<map>
#define ll long long
using namespace std;
int n, m, t, check[10005], a, b, c, num, ans;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> arr[10005];
int main(void) {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	for (int i = 0; i < arr[1].size(); i++)pq.push({ -arr[1][i].second, arr[1][i].first });
	check[1] = 1;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (check[here])continue;
		check[here] = 1;
		ans += (cost + (num * t));
		num += 1;
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first;
			int nc = arr[here][i].second;
			if (!check[next]) pq.push({ -nc, next });
		}
	}
	printf("%d\n", ans);
	return 0;
}