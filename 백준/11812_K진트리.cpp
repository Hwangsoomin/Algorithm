#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<string>
#define ll long long
using namespace std;
ll n, k, q, num;
ll x, y, ans;
int main(void) {
	scanf("%lld%lld%lld", &n, &k, &q);
	num = k - 2;
	while (q--) {
		ans = 0;
		scanf("%lld%lld", &x, &y);
		if (k == 1) {
			if (x < y)ans = y - x;
			else ans = x - y;
		}
		else {
			while (x != y) {
				if (x < y)y = (y + num) / k;
				else x = (x + num) / k;
				ans += 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}