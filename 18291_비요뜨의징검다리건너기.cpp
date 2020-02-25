#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
#define MOD 1000000007
using namespace std;
int t;
ll n, sum;
ll go(ll a, ll b) {
	if (b == 0)return 1;
	ll num = go(a, b / 2) % MOD;
	ll temp = (num * num) % MOD;
	if (b % 2 == 0)return temp % MOD;
	else return (a * temp) % MOD;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		if (n == 1) {
			printf("1\n");
			continue;
		}
		ll ans = go(2, n - 2) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}