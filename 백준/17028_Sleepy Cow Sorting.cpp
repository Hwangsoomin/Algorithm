#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int cow[105];
int n, num, ans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cow[i]);
	}
	num = cow[n];
	for (int i = n - 1; i >= 0; i--) {
		if (num < cow[i]) {
			ans = i;
			break;
		}
		else num = cow[i];
	}
	printf("%d\n", ans);
	return 0;
}