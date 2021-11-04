#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, x, y, k, num;
int arr[25][25];
int dice[4][3], temp[4][3];
int narr[7];
void ans() {
	if (arr[y][x] != 0) {
		dice[3][1] = arr[y][x];
		arr[y][x] = 0;
	}
	else arr[y][x] = dice[3][1];
	printf("%d\n", dice[1][1]);
}
int main(void) {
	scanf("%d%d%d%d%d", &n, &m, &y, &x, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &num);
		if (num == 1) {
			if (x + 1 < m) {
				temp[1][0] = dice[1][0];
				temp[1][1] = dice[1][1];
				temp[1][2] = dice[1][2];
				temp[3][1] = dice[3][1];
				dice[1][0] = temp[3][1];
				dice[1][1] = temp[1][0];
				dice[1][2] = temp[1][1];
				dice[3][1] = temp[1][2];
				x += 1;
				ans();
			}
		}
		else if (num == 2) {
			if (x - 1 >= 0) {
				temp[1][0] = dice[1][0];
				temp[1][1] = dice[1][1];
				temp[1][2] = dice[1][2];
				temp[3][1] = dice[3][1];
				dice[1][0] = temp[1][1];
				dice[1][1] = temp[1][2];
				dice[1][2] = temp[3][1];
				dice[3][1] = temp[1][0];
				x -= 1;
				ans();
			}
		}
		else if (num == 3) {
			if (y - 1 >= 0) {
				for (int j = 0; j < 4; j++) {
					temp[j][1] = dice[j][1];
				}
				for (int j = 0; j < 4; j++) {
					dice[j][1] = temp[(j + 1) % 4][1];
				}
				y -= 1;
				ans();
			}
		}
		else if (num == 4) {
			if (y + 1 < n) {
				for (int j = 0; j < 4; j++) {
					temp[j][1] = dice[j][1];
				}
				for (int j = 0; j < 4; j++) {
					dice[j][1] = temp[(j + 3) % 4][1];
				}
				y += 1;
				ans();
			}
		}
	}
	return 0;
}