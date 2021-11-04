#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
using namespace std;
int n, k;
ll *tree, *arr;
string str;
ll init(ll* arr, int now, int start, int end) {
	if (start == end) {
		if (arr[start] == 0)tree[now] = 0;
		else if (arr[start] > 0)tree[now] = 1;
		else tree[now] = -1;
		return tree[now];
	}
	int mid = (start + end) / 2;
	return tree[now] = init(arr, now * 2, start, mid) * init(arr, now * 2 + 1, mid + 1, end);
}
void update(int now, int start, int end, int idx, int val) {
	if (start > idx || idx > end)return;
	if (start == end) {
		if (val == 0)tree[now] = 0;
		else if (val > 0)tree[now] = 1;
		else tree[now] = -1;
	}
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		tree[now] = tree[now * 2] * tree[now * 2 + 1];
	}
}
ll query(int now, int start, int end, int left, int right) {
	if (left > end || right < start)return 1;
	if (left <= start && end <= right) return tree[now];
	int mid = (start + end) / 2;
	return query(now * 2, start, mid, left, right) * query(now * 2 + 1, mid + 1, end, left, right);
}
int main(void) {
	while (scanf("%d%d", &n, &k) != EOF) {
		int a, b;
		char c;
		str = "";
		arr = new ll[n + 1];
		int tree_size = (1 << ((int)log2(n - 1) + 2));
		tree = new ll[tree_size];
		for (int i = 1; i <= n; i++)scanf("%lld", &arr[i]);
		init(arr, 1, 1, n);
		for (int i = 1; i <= k; i++) {
			scanf(" %c%d%d", &c, &a, &b);
			if (c == 'C') update(1, 1, n, a, b);
			else {
				ll num = query(1, 1, n, a, b);
				if (num == 0)str += '0';
				else if (num > 0)str += '+';
				else str += '-';
			}
		}
		cout << str << endl;
	}
	return 0;
}