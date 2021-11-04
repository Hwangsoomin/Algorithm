#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int leader[50][50];
int n, m, h, a, b, ans;
bool flag = false;
int ch(int here, int next) {
	for (int i = next; i <= h; i++) {
		if (leader[here][i] != 0) return ch(leader[here][i], i + 1);
	}
	return here;
}
int go(int here, int cnt, int lcnt) {
	flag = false;
	if (cnt == lcnt) {
		for (int i = 1; i <= n; i++) {
			int num = ch(i, 1);
			if (num != i) {
				flag = true;
				break;
			}
		}
		if (!flag) return 1;
		else return 0;
	}
	for (int i = here; i < n; i++) {
		for (int j = 1; j <= h; j++) {
			if (!leader[i][j] && !leader[i + 1][j]) {
				leader[i][j] = i + 1;
				leader[i + 1][j] = i;
				if (go(i, cnt + 1, lcnt)) {
					return 1;
				}
				leader[i][j] = 0;
				leader[i + 1][j] = 0;
			}
		}
	}
	return 0;
}
int main(void) {
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		leader[b][a] = b + 1;
		leader[b + 1][a] = b;
	}
	for (int i = 0; i <= 3; i++) {
		ans += go(1, 0, i);
		if (ans > 0) {
			printf("%d\n", i);
			break;
		}
	}
	if (!ans)printf("-1\n");
	return 0;
}