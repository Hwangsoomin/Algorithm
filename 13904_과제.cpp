#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
int n, d, w, day, ans;
pair<int, int> hw[1005];
priority_queue<int, vector<int>, less<int>> pq;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &d, &w);
		hw[i] = { d,w };
	}
	sort(hw + 1, hw + 1 + n);
	for (int i = n; i >= 1; i--) {
		int hd = hw[i].first;
		int sum = hw[i].second;
		if(day != hd) {
			while (day != hd && !pq.empty()) {
				ans += pq.top();
				pq.pop();
				day -= 1;
			}
			day = hd;
		}
		pq.push(sum);
	}
	if (day != 0) {
		while (day != 0 && !pq.empty()) {
			ans += pq.top();
			pq.pop();
			day -= 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}