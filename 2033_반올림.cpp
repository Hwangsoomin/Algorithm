#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
long long n;
int arr[10];
int main(void) {
	int a = 0, num = 10, num1 = 1;
	scanf("%lld", &n);
	while (n > num) {
		long long tmp = n % num;
		if (tmp >= 5 * num1) {
			n = n - tmp;
			n += num;
		}
		else n = n - tmp;
		num *= 10;
		num1 *= 10;
	}
	printf("%lld\n", n);

	return 0;
}