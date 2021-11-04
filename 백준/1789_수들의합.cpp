#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
long long n, sum, num = 1;
int main(void) {
	scanf("%lld", &n);
	while (1) {
		if (sum + num > n) {
			num--;
			break;
		}
		sum += num;
		num++;
	}
	printf("%lld\n", num);
	return 0;
}