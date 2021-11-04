#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#define ll long long
using namespace std;
ll n, b, c;
ll sum, num[1000005], Min;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%lld", &num[i]);
	scanf("%lld%lld", &b, &c);
	for (int i = 1; i <= n; i++) {
		ll cn = 1, bn = 0;
		if (num[i] - b > 0) {
			ll bbn = (num[i] - b) % c;
			bn = (num[i] - b) / c;
			if (bbn != 0)Min = cn + bn + 1;
			else Min = cn + bn;
		}
		else Min = 1;
		sum += Min;
	}
	printf("%lld\n", sum);
	return 0;
}