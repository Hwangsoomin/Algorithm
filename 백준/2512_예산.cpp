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
int n, Max;
int money[10005];
ll m;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &money[i]);
		Max = max(Max, money[i]);
	}
	scanf("%lld", &m);
	int l = 1, r = Max;
	while (l <= r) {
		ll sum = 0;
		int mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			if (mid > money[i])sum += (money[i] * 1LL);
			else sum += (mid * 1LL);
		}
		if (sum > m)r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", r);
	return 0;
}