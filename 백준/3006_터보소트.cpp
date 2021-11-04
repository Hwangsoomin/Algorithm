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
#define num 200005
#define N 49999
using namespace std;
ll tree[num];
ll n, check[100005], arr[100005], a;
ll sum(ll i) {
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(ll i, ll nn) {
	while (i <= n) {
		tree[i] += nn;
		i += (i & -i);
	}
}
int main(void) {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a);
		check[a] = i;
	}
	a = 1;
	for (int i = 1; i <= ((n + 1) / 2); i++) {
		arr[a] = check[i];
		arr[a + 1] = check[(n - i) + 1];
		a += 2;
	}
	for (int i = 1; i <= n; i++)update(i, 1);
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			if (arr[i] == 1)printf("0\n");
			else printf("%lld\n", sum(arr[i] - 1));
			update(arr[i], -1);
		}
		else {
			if (arr[i] == n)printf("0\n");
			else printf("%lld\n", sum(n) - sum(arr[i]));
			update(arr[i], -1);
		}
	}
	return 0;
}