#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
long long n, sum, num = 1, pre = 1;
int main(void) {
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) {
		if (pre * 10 == i) {
			pre = pre * 10;
			num++;
		}
		sum += num;
	}
	printf("%lld\n", sum);
	return 0;
}