#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#include<map>
#include<climits>
#define ll long long
using namespace std;
int n, a, b, c, cnt = 1;
ll ans , pre;
map<double, int> m;
ll arr[500005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0) {
			arr[0] += 1;
			continue;
		}
		if (b == 0) {
			arr[1] += 1;
			continue;
		}
		double here = (double)b / (double)a;
		if (m.find(here) == m.end()) {
			cnt += 1;
			m[here] = cnt;
			arr[m[here]] += 1;
		}
		else arr[m[here]] += 1;
	}
	for (int i = 0; i <= cnt; i++) {
		ll here = (n - pre) - arr[i];
		ans += (here * arr[i]);
		pre += arr[i];
	}
	printf("%lld\n", ans);
	return 0;
}