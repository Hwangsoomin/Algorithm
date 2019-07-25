#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int h, w;
char arr[105][105];
int main(void) {
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	for (int i = 1; i <= h; i++) {
		int cnt = 0;
		bool flag = false;
		for (int j = 1; j <= w; j++) {
			if (arr[i][j] == 'c') {
				cnt = 0;
				flag = true;
				printf("0 ");
			}
			else if (arr[i][j] == '.') {
				if (!flag) printf("-1 ");
				else {
					cnt = cnt + 1;
					printf("%d ", cnt);
				}
			}
		}
		printf("\n");
	}
	return 0;
}