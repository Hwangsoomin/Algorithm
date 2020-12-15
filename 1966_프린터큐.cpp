#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
#define ll long long
using namespace std;
queue<pair<int, int>> q;
priority_queue<int> pq;
int t, n, m, a, ans, cnt;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		cnt = 0; ans = 0;
		while (!q.empty())q.pop();
		while (!pq.empty())pq.pop();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a);
			q.push({ a,i - 1 });
			pq.push(a);
		}
		while (!q.empty()) {
			int hereNum = q.front().first;
			int here = q.front().second;
			q.pop();
			if (hereNum == pq.top()) {
				pq.pop();
				cnt += 1;
				if (here == m) {
					ans = cnt;
					printf("%d\n", ans);
					break;
				}
			}
			else q.push({ hereNum,here });
		}
	}
	return 0;
}
