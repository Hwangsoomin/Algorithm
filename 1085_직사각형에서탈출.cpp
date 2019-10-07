#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
int x, y, w, h, ans = 1e9;
int main(void) {
	scanf("%d%d%d%d", &x, &y, &w, &h);
	if (x < ans)ans = x;
	if (w - x < ans)ans = w - x;
	if (h - y < ans)ans = h - y;
	if (y < ans)ans = y;
	printf("%d\n", ans);
	return 0;
}