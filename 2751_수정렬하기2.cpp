#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#define ll long long
using namespace std;
int num, Max1, Max = -1, n;
int ch1[1000005], ch2[1000005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		if (num < 0) {
			ch1[-num] = 1;
			Max1 = max(Max1, -num);
		}
		else {
			ch2[num] = 1;
			Max = max(Max, num);
		}
	}
	if (Max1 != 0) {
		for (int i = Max1; i > 0; i--) {
			if (ch1[i])printf("%d\n", -i);
		}
	}
	if (Max != -1) {
		for (int i = 0; i <= Max; i++) {
			if (ch2[i])printf("%d\n", i);
		}
	}
	return 0;
}