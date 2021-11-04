#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<string>
#include<map>
#define ll long long
using namespace std;
int *tree;
int n, a, m, b, c, ans;
bool flag = false;
void update(int now, int start, int end, int idx, int val) {
	if (start > idx || end < idx)return;
	if (start == end)tree[now] += val;
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
}
void query(int now, int start, int end, int val, int sum) {
	if (start == end) ans = start;
	else {
		int mid = (start + end) / 2;
		if (sum + tree[now * 2] >= val)query(now * 2, start, mid, val, sum);
		else query(now * 2 + 1, mid + 1, end, val, sum + tree[now * 2]);
	}
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
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d%d", &b, &c);
			update(1, 1, n, b, c);
		}
		else {
			ans = 0;
			scanf("%d", &b);
			query(1, 1, n, b, 0);
			printf("%d\n", ans);
		}
	}
	return 0;
}