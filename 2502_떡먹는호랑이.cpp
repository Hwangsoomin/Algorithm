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
using namespace std;
pair<ll, ll> n[35];
ll d, k, ans1, ans2;
int main(void) {
	n[1] = { 1,0 }; n[2] = { 0,1 };
	scanf("%lld%lld", &d, &k);
	for (ll i = 3; i <= d; i++)n[i] = { n[i - 2].first + n[i - 1].first,n[i - 2].second + n[i - 1].second };
	for (ll i = 1; i <= 100000; i++) {
		for (ll j = i; j <= 100000; j++) {
			if (n[d].first * i + n[d].second * j == k) {
				ans1 = i;
				ans2 = j;
			}
			else if (n[d].first * i + n[d].second * j > k)break;
		}
	}
	printf("%lld\n%lld\n", ans1, ans2);
	return 0;
}