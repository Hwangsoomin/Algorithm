#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
int n, ans[1005][4], Ans = 1e9;
int arr[1005][4];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j == 1)ans[i][j] = min(ans[i - 1][2], ans[i - 1][3]) + arr[i][j];
			if (j == 2)ans[i][j] = min(ans[i - 1][1], ans[i - 1][3]) + arr[i][j];
			if (j == 3)ans[i][j] = min(ans[i - 1][1], ans[i - 1][2]) + arr[i][j];
			if (i == n)Ans = min(Ans, ans[i][j]);
		}
	}
	printf("%d\n", Ans);
	return 0;
}