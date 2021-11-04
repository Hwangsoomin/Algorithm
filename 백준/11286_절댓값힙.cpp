#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n;
priority_queue<pair<int, int>> pq;
int main(void) {
	int x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			if (pq.empty()) {
				printf("0\n");
				continue;
			}
			int ans = pq.top().first;
			int num = pq.top().second;
			if (num == 2) printf("%d\n", ans);
			else printf("%d\n", -ans);
			pq.pop();
		}
		else {
			if (x < 0) pq.push({ x,2 });
			else pq.push({ -x,1 });
		}
	}
	return 0;
}