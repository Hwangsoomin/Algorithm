#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int n, k, cnt;
int mon[15];
int main(void) {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &mon[i]);
	sort(mon + 1, mon + 1 + n);
	for (int i = n; i >= 1; i--) {
		if (k / mon[i] != 0) {
			cnt += (k / mon[i]);
			k = k % mon[i];
		}
	}
	printf("%d\n", cnt);
	return 0;
}