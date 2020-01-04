#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
using namespace std;
int n;
int arr[100005];
ll le[100005], ri[100005];
ll *tree;
ll sum;
void update(int now, int start, int end, int idx, int val) {
	if (idx<start || idx>end)return;
	if(start == end) tree[now] += val;
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
	scanf("%d", &n);
	int tree_size = (1 << ((int)log2(n - 1) + 2));
	tree = new ll[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	for (int i = 1; i <= n; i++) {
		le[i] = query(1, 1, n, arr[i] + 1, n);
		update(1, 1, n, arr[i], 1);
	}
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	for (int i = n; i >= 1; i--) {
		ri[i] = query(1, 1, n, 1, arr[i] - 1);
		update(1, 1, n, arr[i], 1);
	}
	for (int i = 1; i <= n; i++) sum += 1ll * le[i] * ri[i];
	printf("%lld\n", sum);
	return 0;
}