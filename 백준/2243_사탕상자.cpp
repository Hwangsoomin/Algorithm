#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
#define num 1000000
using namespace std;
int n, a, b, c;
ll* tree;
int ans;
void update(int now, int start, int end, int idx, int val) {
	if (idx<start || idx>end)return;
	if (start == end)tree[now] += val;
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
}
void query(int now, int start, int end, int val, ll sum) {
	if (start == end) ans = start;
	else {
		int ss = sum + tree[now * 2];
		int mid = (start + end) / 2;
		if (val > ss) query(now * 2 + 1, mid + 1, end, val, ss);
		else query(now * 2, start, mid, val, sum);
	}
}
int main(void) {
	scanf("%d", &n);
	int tree_size = (1 << ((int)log2(num - 1) + 2));
	tree = new ll[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	for (int i = 1; i <= n; i++) {
		scanf(" %d%d", &a, &b);
		if (a == 2) {
			scanf("%d", &c);
			update(1, 1, num, b, c);
		}
		else {
			query(1, 1, num, b, 0);
			printf("%d\n", ans);
			update(1, 1, num, ans, -1);
		}
	}
	return 0;
}