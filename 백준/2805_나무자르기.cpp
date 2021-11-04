#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
long long n, m, sum, Max;
long long tree[1000005];
int main(void) {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &tree[i]);
	}
	sort(tree + 1, tree + 1 + n);
	long long l = 1, r = 2000000005, mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			if (tree[i] > mid)sum += (tree[i] - mid);
		}
		if (sum < m)r = mid - 1;
		else {
			l = mid + 1;
			Max = max(Max, mid);
		}
	}
	printf("%lld\n", Max);
	return 0;
}