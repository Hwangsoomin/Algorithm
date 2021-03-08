#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#include<map>
#define ll long long
using namespace std;
int n, q;
ll x, y, a, b;
ll* tree;
void update(int now, int start, int end, int idx, ll val) {
	if (idx<start || idx>end)return;
	if (start == end)tree[now] = val;
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
}
ll query(int now, int start, int end, int left, int right) {
	if (left > end || right < start)return 0;
	if (left <= start && end <= right)return tree[now];
	int mid = (start + end) / 2;
	return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
}
int main(void) {
	scanf("%d%d", &n, &q);
	ll tree_size = (1 << ((int)log2(n -1) + 2));
	tree = new ll[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a);
		update(1, 1, n, i, a);
	}
	for (int i = 1; i <= q; i++) {
		scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
		if (x > y)swap(x, y);
		ll sum = query(1, 1, n, x, y);
		update(1, 1, n, a, b);
		printf("%lld\n", sum);
	}
	return 0;
}