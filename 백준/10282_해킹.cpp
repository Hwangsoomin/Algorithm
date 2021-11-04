#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
#define INF 1e9
int t, n, d, c, a, b, s, cnt, ans;
int Time[10005];
vector<pair<int, int>> arr[10005];
priority_queue<pair<int, int>> q;
void go() {
	q.push({ 0,c });
	Time[c] = 0;
	while (!q.empty()) {
		int tt = -q.top().first;
		int nn = q.top().second;
		q.pop();
		if (Time[nn] < tt)continue;
		for (int i = 0; i < arr[nn].size(); i++) {
			int nnn = arr[nn][i].first;
			int ttt = arr[nn][i].second;
			if (Time[nnn] > tt + ttt) {
				Time[nnn] = tt + ttt;
				q.push({ -Time[nnn] , nnn });
			}
		}
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		cnt = 0, ans = 0;
		scanf(" %d%d%d", &n, &d, &c);
		fill(Time, Time + n + 1, INF);
		for (int i = 1; i <= n; i++)arr[i].clear();
		for (int i = 1; i <= n; i++)Time[i] = INF;
		while (!q.empty())q.pop();
		for (int i = 1; i <= d; i++) {
			scanf(" %d%d%d", &a, &b, &s);
			arr[b].push_back({ a,s });
		}
		go();
		for (int i = 1; i <= n; i++) {
			if (Time[i] < 1e9) {
				cnt++;
				ans = max(ans, Time[i]);
			}
		}
		printf("%d %d\n", cnt, ans);
	}
	return 0;
}