#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define ll long long
#define num 100000
using namespace std;
ll n, m;
ll *arr, *tree;
void update(int now, int start, int end, int idx, int val) {
	if (idx<start || idx>end)return;
	if (start == end)tree[now] = val;
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
	}
}
ll query(int now, int start, int end, int left, int right) {
	if (right < start || end < left)return 1e10;
	if (left <= start && end <= right)return tree[now];
	int mid = (start + end) / 2;
	return min(query(now * 2, start, mid, left, right), query(now * 2 + 1, mid + 1, end, left, right));
}
int main(void) {
	int a, b;
	scanf("%lld%lld", &n, &m);
	arr = new ll[n + 1];
	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	int tree_size = (1 << ((int)log2(num - 1) + 2));
	tree = new ll[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 1e10;
	for (int i = 1; i <= n; i++)update(1, 1, num, i, arr[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		ll ans = query(1, 1, num, a, b);
		printf("%lld\n", ans);
	}
	return 0;
}