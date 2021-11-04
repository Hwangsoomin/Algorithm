#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
long long l, p, v, num = 1;
int main(void) {
	while (1) {
		scanf("%lld%lld%lld", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0)break;
		long long cnt = v / p;
		long long sum = (cnt * l);
		if (v % p <= l)sum += (v % p);
		else sum += l;
		printf("Case %lld: %lld\n", num, sum);
		num++;
	}
	return 0;
}