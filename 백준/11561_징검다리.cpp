#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#define ll long long
#define MAX 141421357
using namespace std;
ll t, n;
int main(void) {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		ll l = 1, r = MAX - 1;
		while (l <= r) {
			ll mid = (l + r) / 2;
			ll aa = (mid * (mid + 1)) / 2;
			if (aa == n) {
				r = mid;
				break;
			}
			if (aa < n)l = mid + 1;
			else r = mid - 1;
		}
		printf("%lld\n", r);
	}
	return 0;
}