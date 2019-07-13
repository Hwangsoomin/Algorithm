#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, s, e, Min = 1e9, Max;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &s, &e);
		Min = min(Min, e);
		Max = max(Max, s);
	}
	if (Max >= Min)printf("%d\n", Max - Min);
	else printf("0\n");
	return 0;
}