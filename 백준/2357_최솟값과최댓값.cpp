#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
using namespace std;
int n, m;
ll a, b;
ll *arr;
vector<pair<ll, ll>> tree;
pair<ll,ll> init(ll* arr, int now, int start, int end) {
	if (start == end)return tree[now] = { arr[start],arr[start] };
	else {
		int mid = (start + end) / 2;
		pair<ll, ll> nn = init(arr, now * 2, start, mid);
		pair<ll, ll> nn1 = init(arr, now * 2 + 1, mid + 1, end);
		return tree[now] = { min(nn.first,nn1.first),max(nn.second,nn1.second) };
	}
}
pair<ll,ll> query(int now, int start, int end, int left, int right) {
	if (right<start || left>end)return { 1e9,0 };
	if (left <= start && end <= right) return tree[now];
	int mid = (start + end) / 2;
	pair<ll, ll> nn = query(now * 2, start, mid, left, right);
	pair<ll, ll> nn1 = query(now * 2 + 1, mid + 1, end, left, right);
	return { min(nn.first,nn1.first),max(nn.second,nn1.second) };
}
int main(void) {
	scanf("%d%d", &n, &m);
	arr = new ll[n + 1];
	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	int tree_size = (1 << ((int)log2(n - 1) + 2));
	tree.resize(tree_size, pair<ll, ll>{(int)1e9, 0});
	for (int i = 0; i < tree_size; i++) tree[i] = { 1e9,0 };
	init(arr, 1, 1, n);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld", &a, &b);
		pair<ll, ll> nn = query(1, 1, n, a, b);
		printf("%lld %lld\n", nn.first, nn.second);
	}
	return 0;
}