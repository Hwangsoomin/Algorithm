#include<iostream>
#include <string>
#include <vector>
using namespace std;
int price, money, cnt;

long long answer, sum;
int main(void) {
	scanf("%d%d%d", &price, &money, &cnt);

	for (int i = 1; i <= cnt; i++) {
		sum += (price * i) * 1LL;
	}
	answer = sum - money;
	if (answer < 0)answer = 0;
	printf("%lld\n", answer);
	return 0;
}