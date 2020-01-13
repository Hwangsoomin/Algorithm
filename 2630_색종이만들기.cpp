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
int n;
int pap[200][200], ans[2];
int ch(int r, int c, int cnt) {
	int p = pap[r][c];
	for (int i = r; i < r + cnt; i++) {
		for (int j = c; j < c + cnt; j++) {
			if (p != pap[i][j])return 1;
		}
	}
	return 0;
}
void go(int r, int c, int cnt) {
	if (ch(r, c, cnt)) {
		int mid = cnt / 2;
		go(r, c, cnt / 2);
		go(r, c + mid, cnt / 2);
		go(r + mid, c, cnt / 2);
		go(r + mid, c + mid, cnt / 2);
	}
	else {
		if (pap[r][c])ans[1] += 1;
		else ans[0] += 1;
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &pap[i][j]);
		}
	}
	go(1, 1, n);
	printf("%d\n%d\n", ans[0], ans[1]);
	return 0;
}