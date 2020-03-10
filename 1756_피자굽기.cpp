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
int d, n, last, Min = 1e10;
int oven[300005], pizza[300005], arr[300005];
using namespace std;
int main(void) {
	scanf("%d%d", &d, &n);
	for (int i = 1; i <= d; i++) {
		scanf("%d", &oven[i]);
		if (Min > oven[i])Min = oven[i];
		arr[i] = Min;
	}
	Min = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &pizza[i]);
	int here = 1;
	for (int i = d; i >= 1; i--) {
		if (pizza[here] <= arr[i]) {
			last = i;
			here += 1;
			Min += 1;
		}
		if (here == n + 1)break;
	}
	if (Min == n)printf("%d\n", last);
	else printf("0\n");
	return 0;
}