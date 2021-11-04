#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#include<map>
#define MOD 1000000003
#define ll long long
using namespace std;
int n, m, anssum, a;
ll c1, c2, P[500005], Q[500005];
ll ans[500005][3];
priority_queue<ll, vector<ll>, greater<ll>> pq;
ll Min = 1e10;
bool flag = false;
int main(void) {
	scanf("%d%d", &n, &m);
	scanf("%lld%lld", &c1, &c2);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &P[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &Q[i]);
	}
	sort(Q + 1, Q + 1 + m);
	for (int i = 1; i <= n; i++) {
		ll here = P[i];
		int position = lower_bound(Q + 1, Q + 1 + m, here) - Q;
		if (Q[position] == here) {
			ans[i][0] = Q[position];
			ans[i][1] = 1e10;
		}
		else {
			if (position == 1)ans[i][0] = 1e10;
			else ans[i][0] = Q[position - 1];
			if (position == m + 1)ans[i][1] = 1e10;
			else ans[i][1] = Q[position];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			ll num = ans[i][j];
			ll sum = abs(P[i] - ans[i][j]);
			pq.push(sum);
		}
	}
	while (!pq.empty()) {
		ll top = pq.top();
		pq.pop();
		if (Min >= top) {
			Min = top;
			anssum += 1;
		}
		else break;
	}
	Min = Min + abs(c1 - c2);
	printf("%lld %d\n", Min, anssum);
	return 0;
}