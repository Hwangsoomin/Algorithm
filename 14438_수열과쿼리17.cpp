#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#include<map>
#include<climits>
#define ll long long
using namespace std;
int n, m, x, y, a;
int* tree;
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
int query(int now, int start, int end, int left, int right) {
	if (left > end || right < start)return INT_MAX;
	if (left <= start && end <= right)return tree[now];
	int mid = (start + end) / 2;
	return min(query(now * 2, start, mid, left, right), query(now * 2 + 1, mid + 1, end, left, right));
}
int main(void) {
	scanf("%d", &n);
	int tree_size = (1 << ((int)log2(n - 1) + 2));
	tree = new int[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		update(1, 1, n, i, a);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &a);
		if (x == 1)update(1, 1, n, y, a);
		else {
			int ans = query(1, 1, n, y, a);
			printf("%d\n", ans);
		}
	}
	return 0;
}