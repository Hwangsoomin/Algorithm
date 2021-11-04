#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
long long a, b, c;
long long go(long long num) {
	if (num == 1)return a % c;
	if (num % 2 == 0) {
		return ((go(num / 2) % c) * (go(num / 2) % c)) % c;
	}
	else {
		return ((go(num / 2) % c) * (go(num / 2 + 1) % c)) % c;
	}
}
int main(void) {
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld\n",go(b));
	return 0;
}