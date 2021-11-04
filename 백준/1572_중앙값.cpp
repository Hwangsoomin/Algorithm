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
#define num 65537
using namespace std;
ll n, k, ans;
ll* tree;
ll arr[250005];
void update(ll now, ll start, ll end, ll idx, ll val) {
	if (idx<start || idx>end)return;
	if (start == end)tree[now] += val;
	else {
		ll mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
}
void query(ll now, ll start, ll end, ll val, ll sum) {
	if (start == end) ans += start;
	else {
		ll mid = (start + end) / 2;
		ll next = tree[now * 2] + sum;
		if (next < val)query(now * 2 + 1, mid + 1, end, val, next);
		else query(now * 2, start, mid, val, sum);
	}
}
int main(void) {
	scanf("%lld%lld", &n, &k);
	int tree_size = (1 << ((ll)log2(num - 1) + 2));
	tree = new ll[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		update(1, 0, num, arr[i], 1);
		if (tree[1] == k) {
			query(1, 0, num, (k + 1) / 2, 0);
			update(1, 0, num, arr[i - (k - 1)], -1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}