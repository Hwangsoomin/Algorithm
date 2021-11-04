#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
long long time[100005], ans = LLONG_MAX;
int n, m;
int main(void) {
	long long l = 1, r;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &time[i]);
	sort(time + 1, time + 1 + n);
	r = time[n] * m;
	while (l <= r) {
		long long num = 0;
		long long mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			num += mid / time[i];
		}
		if (num >= m) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}