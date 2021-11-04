#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n, paper[105][105], cnt;
int main(void) {
	int a, b, a1, b1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		a1 = a + 10;
		b1 = b + 10;
		for (int j = b1 - 1; j >= b; j--) {
			for (int k = a; k < a1; k++) {
				paper[j][k] = 1;
			}
		}
	}
	for (int i = 1; i <= 104; i++) {
		for (int j = 1; j <= 104; j++) {
			if (paper[i][j])cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}