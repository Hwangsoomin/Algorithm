#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int c, r, cnt = 1, x, y, a, k, ansx, ansy, tx, ty;
int arr[1005][1005];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int main(void) {
	scanf("%d%d", &c, &r);
	scanf("%d", &k);
	tx = r + 1;
	ty = 1;
	a = 0;
	for (int i = 1; i <= c * r; i++) {
		x = tx + dr[a];
		y = ty + dc[a];
		if (arr[x][y] != 0 || x<1 || x>r || y<1 || y>c) {
			a = (a + 1) % 4;
			x = tx + dr[a];
			y = ty + dc[a];
		}
		arr[x][y] = cnt;
		tx = x;
		ty = y;
		if (cnt == k) {
			ansx = tx;
			ansy = ty;
		}
		cnt++;
	}
	if (cnt < k)printf("0\n");
	else printf("%d %d\n", ansy, (r + 1) - ansx);
	return 0;
}