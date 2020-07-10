#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
queue<ll> q;
ll n, cnt, st = 1, en;
void go() {
	while (!q.empty()) {
		ll num = q.front();
		q.pop();
		if (num > en)continue;
		if (st < num && num % 3 == 0)cnt += 1;
		for (int i = 0; i < 3; i++) {
			ll nn = (num * 10) + i;
			if (nn == 0)continue;
			q.push(nn);
		}
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		st *= 10;
	}
	en = st * 10;
	q.push(0);
	go();
	printf("%lld\n", cnt);
	return 0;
}