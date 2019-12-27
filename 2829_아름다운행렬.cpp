#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, Max;
int arr[405][405];
int arr1[405][405], arr2[405][405];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr1[i][j] = arr1[i - 1][j - 1] + arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			arr2[i][j] = arr2[i - 1][j + 1] + arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k < n; k++) {
				int n1 = i + k; 
				int n2 = j + k;
				if (n1 > n || n2 > n)break;
				else {
					int nn1 = i - 1;
					int nn2 = n2 + 1;
					int s1 = arr1[n1][n2] - arr1[i - 1][j - 1];
					int s2 = arr2[n1][j] - arr2[nn1][nn2];
					Max = max(Max, s1 - s2);
				}
			}
		}
	}
	printf("%d\n", Max);
	return 0;
}