#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int num[15];
int ans;
int main(void) {
	for (int i = 1; i <= 10; i++) scanf("%d", &num[i]);
	for (int i = 1; i <= 10; i++) {
		ans += num[i];
		if (ans == 100)break;
		if (ans > 100) {
			if (ans - 100 > 100 - (ans - num[i])) {
				ans -= num[i];
			}
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}