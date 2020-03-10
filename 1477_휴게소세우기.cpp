#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define ll long long
using namespace std;
int n, m, l, ans;
int arr[105], num[105];
priority_queue<int> pq;
int main(void) {
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++) {
		num[i] = arr[i] - arr[i - 1];
		ans = max(ans, num[i]);
	}
	num[n + 1] = l - arr[n];
	int l = 1, r = 1000;
	while (l <= r) {
		int mid = (l + r) / 2;
		int sum = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (num[i] % mid == 0) sum += ((num[i] / mid) - 1);
			else sum += (num[i] / mid);
		}
		if (sum <= m) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}