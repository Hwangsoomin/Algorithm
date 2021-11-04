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
int pap[3005][3005];
int n, ans[5];
int ch(int n1, int n2, int cnt) {
	int p = pap[n1][n2];
	for (int i = n1; i < n1 + cnt; i++) {
		for (int j = n2; j < n2 + cnt; j++) {
			if (p != pap[i][j])return 1;
		}
	}
	return 0;
}
void go(int n1, int n2, int cnt) {
	int num = cnt / 3;
	if (ch(n1, n2, cnt)) {
		go(n1, n2, cnt / 3);
		go(n1, n2 + num, cnt / 3);
		go(n1, n2 + num * 2, cnt / 3);
		go(n1 + num, n2, cnt / 3);
		go(n1 + num, n2 + num, cnt / 3);
		go(n1 + num, n2 + num * 2, cnt / 3);
		go(n1 + num * 2, n2, cnt / 3);
		go(n1 + num * 2, n2 + num, cnt / 3);
		go(n1 + num * 2, n2 + num * 2, cnt / 3);
	}
	else {
		if (pap[n1][n2] == -1)ans[0] += 1;
		else if (pap[n1][n2] == 0)ans[1] += 1;
		else ans[2] += 1;
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &pap[i][j]);
		}
	}
	go(1, 1, n);
	for (int i = 0; i <= 2; i++) printf("%d\n", ans[i]);
	return 0;
}