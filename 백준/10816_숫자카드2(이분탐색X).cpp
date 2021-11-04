#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#define ll long long
using namespace std;
ll n, num, m, a = 1;
ll arr1[10000005], arr[10000005], check[500005];
bool flag = false;
int main(void) {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &check[i]);
		if (check[i] < 0) arr1[-check[i]] += 1;
		else arr[check[i]] += 1;
	}
	scanf("%lld", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &num);
		if (num < 0) {
			if (arr1[-num] != 0)printf("%lld ", arr1[-num]);
			else printf("0 ");
		}
		else {
			if (arr[num] != 0)printf("%lld ", arr[num]);
			else printf("0 ");
		}
	}
	return 0;
}