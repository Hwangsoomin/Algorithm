#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int t, k, n;
int arr[16][16];
int main(void) {
	scanf("%d", &t);
	for (int i = 1; i <= 15; i++)arr[0][i] = i;
	for (int i = 1; i <= 15; i++) {//Ãþ¼ö
		for (int j = 1; j <= 15; j++) {//È£¼ö
			for (int k = 1; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
			}
		}
	}
	while (t--) {
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", arr[k][n]);
	}
	return 0;
}