#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
#define MAX 1000000000
using namespace std;
int n, c;
ll hou[200005], Max;
int main(void) {
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++)scanf("%lld", &hou[i]);
	sort(hou + 1, hou + 1 + n);
	ll l = 1, r = MAX;
	while (l <= r) {
		ll mid = (l + r) / 2;
		int cnt = 0, pre = 1;
		for (int i = 2; i <= n; i++) {
			if (hou[i] - hou[pre] >= mid) {
				cnt += 1;
				pre = i;
			}
		}
		if (cnt >= c - 1) l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", r);
	return 0;
}