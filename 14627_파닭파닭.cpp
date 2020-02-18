#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
using namespace std;
ll s, c, Max, sum, ans;
ll ch[1000005];
int main(void) {
	ll l = 0, r = 0;
	scanf("%lld%lld", &s, &c);
	for (ll i = 1; i <= s; i++) scanf("%lld", &ch[i]);
	l = 1; r = 1e10;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if(mid!=0)
		sum = 0; ans = 0;
		for (int i = 1; i <= s; i++) sum += (ch[i] / mid);
		if (sum >= c)l = mid + 1;
		else r = mid - 1;
	}
	sum = 0;
	sort(ch + 1, ch + 1 + s);
	for (int i = 1; i <= s; i++) {
		ll num = (ch[i] / r);
		if (sum + num > c) {
			num = c - sum;
			sum += num;
		}
		else sum += num;
		ans += (ch[i] - (num * r));
	}
	printf("%lld\n", ans);
	return 0;
}