#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#define MOD 100999
#define ll long long
using namespace std;
int n, m, a, l, r, check[1005], pre, num = 1, ans = 1e10;
int n1, n2 = 1;
vector<pair<int, int>> arr;
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a);
			arr.push_back({ a,i });
		}
	}
	sort(arr.begin(), arr.end());
	l = arr[0].first;
	pre = arr[0].second;
	check[pre] = 1;
	n1 = 0;
	while (n1 < n * m) {
		if (num == n) {
			ans = min(ans, r - l);
			if (check[pre] == 1) num -= 1;
			check[pre] -= 1;
			n1 += 1;
			l = arr[n1].first;
			pre = arr[n1].second;
			continue;
		}
		if (n2 == n * m&& num != n)break;
		if (n2 == n * m)continue;
		r = arr[n2].first;
		int here = arr[n2].second;
		n2 += 1;
		if (check[here] == 0) num += 1;
		check[here] += 1;
	}
	printf("%d\n", ans);
	return 0;
}