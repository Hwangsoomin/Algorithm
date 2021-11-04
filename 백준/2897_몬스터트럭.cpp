#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include <functional>
using namespace std;
int r, c;
char arr[55][55];
int ans[5];
int main(void) {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			int cnt = 0;
			if (arr[i][j] == '#' || arr[i][j + 1] == '#' || arr[i + 1][j] == '#' || arr[i + 1][j + 1] == '#') continue;
			if (arr[i][j] == 'X')cnt++;
			if (arr[i][j + 1] == 'X')cnt++;
			if (arr[i + 1][j] == 'X')cnt++;
			if (arr[i + 1][j + 1] == 'X')cnt++;
			ans[cnt]++;
		}
	}
	for (int i = 0; i < 5; i++)printf("%d\n", ans[i]);
	return 0;
}