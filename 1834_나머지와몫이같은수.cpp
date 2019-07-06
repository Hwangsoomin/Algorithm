#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
long long n, sum, mok, Mod;
int main(void) {
	scanf("%lld", &n);
	for (long long i = n + 1; i <= n * n - 1;) {
		sum += i;
		i += (n + 1);
	}
	printf("%lld\n", sum);
	return 0;
}