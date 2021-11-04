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
ll x, n;
ll lego[1000005], Max = 0;
pair<ll, ll> ans;
bool flag = false;
int main(void) {
	while (cin >> x) {
		Max = 0;
		flag = false;
		x *= 10000000;
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &lego[i]);
		}
		sort(lego + 1, lego + 1 + n);
		for (int i = 1; i <= n; i++) {
			ll l = 1, r = n;
			ll num = x - lego[i];
			while (l <= r) {
				ll mid = (l + r) / 2;
				if (lego[mid] == num) {
					if (mid != i) {
						if (Max <= abs(lego[i] - lego[mid])) {
							Max = abs(lego[i] - lego[mid]);
							if (lego[i] < lego[mid]) {
								ans.first = lego[i];
								ans.second = lego[mid];
							}
							else {
								ans.first = lego[mid];
								ans.second = lego[i];
							}
						}
						flag = true;
					}
				}
				if (lego[mid] <= num)l = mid + 1;
				else r = mid - 1;
			}
		}
		if (flag)printf("yes %lld %lld\n", ans.first, ans.second);
		else printf("danger\n");
	}
	return 0;
}