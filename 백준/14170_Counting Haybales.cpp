#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#define ll long long
using namespace std;
ll n, q, a, b;
vector<ll> arr;
ll L(ll here) {
	ll l = 0, r = arr.size() - 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (arr[mid] >= here) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}
ll R(ll here) {
	ll l = 0, r = arr.size() - 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (arr[mid] > here) r = mid - 1;
		else l = mid + 1;
	}
	return r;
}
int main(void) {
	scanf("%lld%lld", &n, &q);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a);
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i <= q; i++) {
		scanf("%lld%lld", &a, &b);
		ll n1 = L(a);
		ll n2 = R(b);
		if (n1 == arr.size())n1 = arr.size();
		if (n2 == arr.size())n2 = arr.size();
		printf("%lld\n", (n2 - n1) + 1);
	}
	return 0;
}