#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
int n, w, h, a = -1;
ll pre;
priority_queue<pair<ll, int>> pq;
vector<int> ans[1005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &w, &h);
		ll sum = (w * w) + (h * h);
		pq.push({ sum,i });
	}
	while (!pq.empty()) {
		ll here = pq.top().first;
		ll idx = pq.top().second;
		pq.pop();
		if (here == pre)ans[a].push_back(idx);
		else {
			ans[a + 1].push_back(idx);
			a += 1;
			pre = here;
		}
	}
	for (int i = 0; i <= a; i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d\n", ans[i][j]);
		}
	}
	return 0;
}