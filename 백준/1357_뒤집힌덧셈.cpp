#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int x, y, ans;
int xx1[5], yy1[5], ans1[5];
int main(void) {
	int i = 0, num = 1;
	scanf("%d%d", &x, &y);
	while (x > 0) {
		xx1[i] = x % 10;
		x /= 10;
		i++;
	}
	x = 0;
	for (int j = i - 1; j >= 0; j--) {
		x += xx1[j] * num;
		num *= 10;
	}
	i = 0, num = 1;
	while (y > 0) {
		yy1[i] = y % 10;
		y /= 10;
		i++;
	}
	y = 0;
	for (int j = i - 1; j >= 0; j--) {
		y += yy1[j] * num;
		num *= 10;
	}
	ans = x + y;
	i = 0;
	while (ans > 0) {
		ans1[i] = ans % 10;
		ans /= 10;
		i++;
	}
	num = 1;
	for (int j = i - 1; j >= 0; j--) {
		ans += num * ans1[j];
		num *= 10;
	}
	printf("%d\n", ans);
	return 0;
}