#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n, m, a, b, c;
ll arr[100005];
pair<ll, ll>* tree;
void update(int now, int start, int end, int idx, ll val) {
	if (idx<start || idx>end)return;
	if (start == end) tree[now] = { val,0 };
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid, idx, val);
		update(now * 2 + 1, mid + 1, end, idx, val);
		pair<ll, ll> n1 = tree[now * 2];
		pair<ll, ll> n2 = tree[now * 2 + 1];
		ll Min = min(n1.first, n2.first);
		ll Max = max(n1.second, n2.second);
		tree[now] = { max(n1.first,n2.first),max(Min,Max) };
	}
}
pair<ll,ll> query(int now, int start, int end, int left, int right) {
	if (left > end || right < start)return { 0,0 };
	if (left <= start && end <= right)return tree[now];
	int mid = (start + end) / 2;
	pair<ll, ll> mm = query(now * 2, start, mid, left, right);
	pair<ll, ll> mmm = query(now * 2 + 1, mid + 1, end, left, right);
	ll Min = min(mm.first, mmm.first);
	ll Max = max(mm.second, mmm.second);
	return { max(mm.first,mmm.first),max(Min,Max) };
}
int main(void) {
	scanf("%d", &n);
	int tree_size = (1 << ((int)log2(n - 1) + 2));
	tree = new pair<ll,ll>[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = { 0,0 };
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		update(1, 1, n, i, arr[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1)update(1, 1, n, b, c);
		else {
			pair<ll,ll> M1 = query(1, 1, n, b, c);
			printf("%lld\n", M1.first + M1.second);
		}
	}
	return 0;
}