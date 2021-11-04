#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#define ll long long
using namespace std;
int a, b, c, x, y;
ll sum;
int main(void) {
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	int minus = abs(x - y);
	int Min = min(x, y);
	int Max = max(x, y);
	if (2 * c < a + b) {
		if (x < y)sum += (minus * b);
		else sum += (minus * a);
		sum += (Min * 2 * c);
	}
	else sum += ((a * x) + (b * y));
	sum = min(sum, 1ll * 2 * c * Max);
	printf("%lld\n", sum);
	return 0;
}