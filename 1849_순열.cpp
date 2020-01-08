#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
using namespace std;
int n, a, here;
ll* tree;
int ans[100005];
void update(int now, int start, int end, int idx, int val) {
	if (idx<start || idx>end)return;
	if (start == end)tree[now] = val;
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
}
void query(int now, int start, int end, int val, int num, int sum) {
	if (start == end) {
		ans[start] = num;
		here = start;
	}
	else {
		int ss = sum + tree[now * 2];
		int mid = (start + end) / 2;
		if (val > ss)query(now * 2 + 1, mid + 1, end, val, num, ss);
		else query(now * 2, start, mid, val, num, sum);
	}
}
int main(void) {
	scanf("%d", &n);
	int tree_size = (1 << ((int)log2(n - 1) + 2));
	tree = new ll[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	for (int i = 1; i <= n; i++)update(1, 1, n, i, 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		query(1, 1, n, a + 1, i, 0);
		update(1, 1, n, here, 0);
	}
	for (int i = 1; i <= n; i++)printf("%d\n", ans[i]);
	return 0;
}