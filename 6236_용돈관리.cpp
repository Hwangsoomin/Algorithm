#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, mon[100005];
int main(void) {
	int Max = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &mon[i]);
		Max = max(Max, mon[i]);
	}
	long long l = Max, r = 1e13;
	while (l <= r) {
		long long mid = (l + r) / 2;
		int cnt = 1;
		long long tmp = mid;
		for (int i = 1; i <= n; i++) {
			if (tmp < mon[i]) {
				tmp = mid;
				cnt++;
			}
			tmp -= mon[i];
		}
		if (cnt > m)l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", l);
	return 0;
}