#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<math.h>
#define ll long long
using namespace std;
int n, m, k;
ll *tree, *arr;
ll init(ll *arr, int now, int start, int end) {
	if (start == end)return tree[now] = arr[start];
	int mid = (start + end) / 2;
	return tree[now] = init(arr, now * 2, start, mid) + init(arr, now * 2 + 1, mid + 1, end);
}
void update(int now, int start, int end, int idx, int val) {
	if (start > idx || idx > end)return;
	if (start == end)tree[now] = val;
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
 }
ll query(int now, int start, int end, int left, int right) {
	if (end<left || start>right)return 0;
	if (left <= start && right >= end)return tree[now];
	int mid = (start + end) / 2;
	return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
}
int main(void) {
	int a, b, c;
	scanf("%d%d%d", &n, &m, &k);
	arr = new ll[n + 1];
	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	int tree_size = (1 << ((int)log2(n - 1) + 2));
	tree = new ll[tree_size + 1];
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	init(arr, 1, 1, n);
	for (int i = 1; i <= m + k; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1)update(1, 1, n, b, c);
		else printf("%lld\n", query(1, 1, n, b, c));
	}
	return 0;
}