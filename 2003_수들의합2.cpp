#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define ll long long
using namespace std;
ll n, m, num, sum[10005], ans;
int main(void) {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &num);
		sum[i] = sum[i - 1] + num;
	}
	for (int i = 1; i <= n; i++) {
		ll here = sum[i];
		ll plus = sum[i] - m;
		bool flag = false;
		if (plus != 0) {
			ll l = 1, r = i - 1;
			while (l <= r) {
				ll mid = (l + r) / 2;
				if (sum[mid] == plus) {
					flag = true;
					break;
				}
				else if (sum[mid] < plus)l = mid + 1;
				else r = mid - 1;
			}
		}
		if (flag || plus == 0)ans += 1;
	}
	printf("%lld\n", ans);
	return 0;
}