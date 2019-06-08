#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
long long a, b;
int t, n, cnt;
int check[65];
int main(void) {
	scanf("%d", &t);
	while (t--) {
		memset(check, 0, sizeof(check));
		cnt = 0;
		scanf(" %d%lld%lld", &n, &a, &b);
		for (int i = 62; i >= 0; i--) {
			long long num = (long long)1 << i;
			if (a >= num) {
				check[i] = 1;
				a = a - num;
			 }
		}
		for (int i = 62; i >= 0; i--) {
			long long num = (long long)1 << i;
			if (b >= num) {
				check[i] = 1;
				b = b - num;
			}
		}
		for (int i = 0; i <= 62; i++) {
			if (check[i])cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}