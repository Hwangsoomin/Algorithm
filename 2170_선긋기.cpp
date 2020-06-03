#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
pair<ll, ll> arr[1000005];
int n;
ll a, b, st, en, ans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a, &b);
		arr[i] = { a,b };
	}
	sort(arr + 1, arr + 1 + n);
	st = arr[1].first;
	en = arr[1].second;
	for (int i = 2; i <= n; i++) {
		ll nst = arr[i].first;
		ll nen = arr[i].second;
		if (nst <= en) {
			if (en <= nen) en = nen;
		}
		else {
			ans += (en - st);
			st = nst;
			en = nen;
		}
	}
	ans += (en - st);
	printf("%lld\n", ans);
	return 0;
}