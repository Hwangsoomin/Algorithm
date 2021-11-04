#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n, m, k;
ll *tree;
ll num;
void update(int now, int start, int end, int idx, ll val) {
	if (idx<start || idx>end)return;
	if (start == end)tree[now] = val;
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		tree[now] = ((tree[now * 2] % mod) * (tree[now * 2 + 1] % mod)) % mod;
	}
}
ll query(int now, int start, int end, int left, int right) {
	if (left > end || right < start)return 1;
	if (left <= start && end <= right)return tree[now] % mod;
	int mid = (start + end) / 2;
	return ((query(now * 2, start, mid, left, right) % mod) * (query(now * 2 + 1, mid + 1, end, left, right) % mod)) % mod;
}
int main(void) {
	int a, b, c;
	scanf("%d%d%d", &n, &m, &k);
	int tree_size = (1 << ((int)log2(n - 1) + 2));
	tree = new ll[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &num);
		update(1, 1, n, i, num);
	}
	for (int i = 1; i <= m + k; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1)update(1, 1, n, b, c);
		else {
			ll sum = query(1, 1, n, b, c) % mod;
			printf("%lld\n", sum);
		}
	}
	return 0;
}