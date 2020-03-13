#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define ll long long
using namespace std;
int soc[10005], sum, n;
bool flag = false;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &soc[i]);
	sort(soc + 1, soc + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum += soc[i];
		if (sum < ((i - 1) * i) / 2) {
			printf("-1\n");
			flag = true;
			break;
		}
	}
	if (!flag) {
		if (sum == ((n - 1) * n) / 2)printf("1\n");
		else printf("-1\n");
	}
	return 0;
}