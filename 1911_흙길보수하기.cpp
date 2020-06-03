#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
int n, l;
ll a, b, anst, anen, ans, num;
pair<ll, ll> arr[10005];
bool flag = false;
int main(void) {
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		arr[i] = { a,b - 1 };
	}
	sort(arr + 1, arr + 1 + n);
	anst = arr[1].first;
	anen = arr[1].second;
	if ((((anen - anst) + 1) % l) == 0)num = 0;
	else num = l - (((anen - anst) + 1) % l);
	for (int i = 2; i <= n; i++) {
		ll st = arr[i].first;
		ll en = arr[i].second;
		if (st <= anen + num) {
			if (anen <= en)anen = en;
		}
		else {
			ans = ans + (((anen - anst) + 1) / l);
			if ((((anen - anst) + 1) % l) != 0)ans += 1;
			anst = st;
			anen = en;
		}
		if ((((anen - anst) + 1) % l) == 0)num = 0;
		else num = l - (((anen - anst) + 1) % l);
	}
	ans = ans + (((anen - anst) + 1) / l);
	if ((((anen - anst) + 1) % l) != 0)ans += 1;
	printf("%lld\n", ans);
	return 0;
}