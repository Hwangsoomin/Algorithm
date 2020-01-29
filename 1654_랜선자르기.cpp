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
using namespace std;
int k, n;
ll line[10005], Max;
int main(void) {
	scanf(" %d%d", &k, &n);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &line[i]);
		Max = max(Max, line[i]);
	}
	ll l = 1, r = Max;
	while (l <= r) {
		ll mid = (l + r) / 2, sum = 0;
		for (int i = 1; i <= k; i++) sum += ((1LL * line[i]) / mid);
		if (sum < n)r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", r);
	return 0;
}