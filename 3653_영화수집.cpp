#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
using namespace std;
int t, here;
int n, m, k;
int *tree;
int check[100005];
int query(int now, int start, int end, int left, int right) {
	if (left > end || right < start)return 0;
	if (left <= start && end <= right)return tree[now];
	int mid = (start + end) / 2;
	return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
}
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
int main(void) {
	scanf("%d", &t);
	while (t--) {
		memset(check, 0, sizeof(check));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) check[i] = m + i;
		here = m;
		int tree_size = (1 << (int)log2(m + n - 1) + 2);
		tree = new int[tree_size];	
		for (int i = 0; i < tree_size; i++)tree[i] = 0;
		for (int i = 1; i <= n; i++)update(1, 1, m + n, m + i, 1);
		for (int i = 1; i <= m; i++) {
			scanf("%d", &k);
			printf("%d ", query(1, 1, m + n, 1, check[k] - 1));
			update(1, 1, m + n, check[k], 0);
			update(1, 1, m + n, here, 1);
			check[k] = here;
			here -= 1;
		}
		printf("\n");
	}
	return 0;
}