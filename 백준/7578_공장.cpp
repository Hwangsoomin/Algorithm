#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#define ll long long
#define num 500000
using namespace std;
int n, a;
ll* tree;
ll sum;
int arr[1000005], arr1[1000005], here[1000005];
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
ll query(int now, int start, int end, int left, int right) {
	if (left > end || right < start)return 0;
	if (left <= start && end <= right)return tree[now];
	int mid = (start + end) / 2;
	return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
}
int main(void) {
	int tree_size = (1 << ((int)log2(num - 1) + 2));
	tree = new ll[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) { 
		scanf("%d", &a);
		arr1[a] = i;
	}
	for (int i = 1; i <= n; i++) here[i] = arr1[arr[i]];
	for (int i = 1; i <= n; i++) {
		if(here[i]!=n) sum += query(1, 1, num, here[i] + 1, num);
		update(1, 1, num, here[i], 1);
	}
	printf("%lld\n", sum);
	return 0;
}