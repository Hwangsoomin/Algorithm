#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<functional>
using namespace std;
int n, m, k, nx1, ny1, nx2, ny2;
int arr[1025][1025], sum[1025][1025];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = ((sum[i - 1][j] + sum[i][j - 1]) - sum[i - 1][j - 1]) + arr[i][j];
		}
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d%d", &nx1, &ny1, &nx2, &ny2);
		int ans = sum[nx2][ny2] - (sum[nx1 - 1][ny2] + sum[nx2][ny1 - 1] - sum[nx1 - 1][ny1 - 1]);
		printf("%d\n", ans);
	}
	return 0;
}