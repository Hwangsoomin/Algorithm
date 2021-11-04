#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
ll n, m, R;
int ans;
ll go(ll n1, ll n2) {
	if (n2 == 0)return n1;
	return go(n2, n1 % n2);
}
int main(void) {
	scanf("%lld%lld", &m, &n);
	if (m == 0 && n == 0)ans = 0;
	else {
		ll nm = abs(m);
		ll nn = abs(n);
		ll num = go(nm, nn);
		if (num == 1)ans = 1;
		else ans = 2;
	}
	printf("%d\n", ans);
	return 0;
}