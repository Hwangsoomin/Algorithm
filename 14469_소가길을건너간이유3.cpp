#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#define ll long long
using namespace std;
int n, a;
ll b, sum;
vector<pair<int, ll>> cow;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %d%lld", &a, &b);
		cow.push_back({ a,b });
	}
	sort(cow.begin(), cow.end());
	for (int i = 0; i < cow.size(); i++) {
		int num = cow[i].first;
		ll nn = cow[i].second;
		if (sum < num) {
			ll nnn = 1ll * num - sum;
			sum += nnn;
		}
		sum += nn;
	}
	printf("%lld\n", sum);
	return 0;
}