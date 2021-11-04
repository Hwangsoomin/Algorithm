#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<vector>
#define ll long long
using namespace std;
int n, here, st = 1;
ll ans, arr[100005];
ll* tree;
vector<pair<int, int>> M;
void update(int now, int start, int end) {
	if (start == end)tree[now] = start;
	else {
		int mid = (start + end) / 2;
		update(now * 2, start, mid);
		update(now * 2 + 1, mid + 1, end);
		if (arr[tree[now * 2]] < arr[tree[now * 2 + 1]])tree[now] = tree[now * 2];
		else tree[now] = tree[now * 2 + 1];
	}
}
ll query(int now, int start, int end, int left, int right) {
	if (end < left || right < start)return 1e9;
	if (left <= start && end <= right)return tree[now];
	int mid = (start + end) / 2;
	ll a = query(now * 2, start, mid, left, right);
	ll b = query(now * 2 + 1, mid + 1, end, left, right);
	if (a == 1e9)return b;
	else if (b == 1e9)return a;
	else if (arr[a] < arr[b])return a;
	else if(arr[a] >= arr[b])return b;
}
ll ansM(int now, int start, int end) {
	ll Min = query(1, 1, n, start, end);//현재 제일 작은 값 갖고 있는 위치
	ll Max = arr[Min] * ((end - start + 1) * 1LL);//현재 작은 값 포함한 직사각형 넓이
	if (start <= Min - 1)Max = max(Max, ansM(now * 2, start, Min - 1));
	if (Min + 1 <= end)Max = max(Max, ansM(now * 2 + 1, Min + 1, end));
	return Max;
}
int main(void) {
	scanf("%d", &n);
	int tree_size = (1 << ((int)log2(n - 1) + 2));
	tree = new ll[tree_size];
	for (int i = 0; i < tree_size; i++)tree[i] = 1e9;
	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
	update(1, 1, n);
	ans = ansM(1, 1, n);
	printf("%lld\n", ans);
	return 0;
}