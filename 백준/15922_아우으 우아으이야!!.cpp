#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
ll n, sum, pre;
pair<ll, ll> line[100005];
int main(void) {
	ll a, b;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a, &b);
		line[i] = { a,b };
	}
	pre = line[1].first;
	for (int i = 1; i <= n; i++) {
		if (pre <=line[i].first)sum += (line[i].second - line[i].first);
		else {
			if (pre < line[i].second)sum += (line[i].second - pre);
		}
		if (pre < line[i].second) pre = line[i].second;
	}
	printf("%lld\n", sum);
	return 0;
}