#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, ans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int sum = i;
		int num = i;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum == n) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}