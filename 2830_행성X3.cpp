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
int n, arr[1000005][25], num;
ll sum, nn;
int Max, on, zn, h;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		h = 0;
		while (num > 1) {
			arr[i][h++] = num % 2;
			num /= 2;
		}
		arr[i][h++] = num;
		Max = max(Max, h);
	}
	nn = 1;
	for (int i = 0; i < Max; i++) {
		on = 0; zn = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[j][i] == 1)on += 1;
			else zn += 1;
		}
		if (on != n && zn != n) sum += (nn * zn * on);
		nn *= 2;
	}
	printf("%lld\n", sum);
	return 0;
}