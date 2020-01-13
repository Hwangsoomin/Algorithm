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
ll n, m, k, ans;
ll arr[1000005];
ll tree[1000005];
void update(int i, ll num) {
	while (i <= n) {
		tree[i] += num;
		i += (i & -i);
	}
}
ll query(int i) {
	ll sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}
int main(void) {
	ll a, b, c;
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		update(i, arr[i]);
	}
	for (int i = 1; i <= m + k; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1) {
			ll cha = abs(arr[b] - c);
			if (arr[b] > c) update(b, -cha);
			else update(b, cha);
			arr[b] = c;
		}
		else {
			printf("%lld\n", query(c)-query(b-1));
		}
	}
	return 0;
}