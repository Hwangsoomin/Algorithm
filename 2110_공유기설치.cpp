#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n, c;
long long hou[200005];
int main(void) {
	long long cnt = 0, pre = 1;
	long long l = 1, r = 1000000005, mid = 0, Max = 0;
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &hou[i]);
	}
	sort(hou + 1, hou + 1 + n);
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0, pre = 1;
		for (int i = 2; i <= n; i++) {
			if (hou[i] - hou[pre] >= mid) {
				pre = i;
				cnt++;
			}
		}
		if (cnt >= c - 1) {
			Max = max(Max, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%lld\n", Max);
	return 0;
}