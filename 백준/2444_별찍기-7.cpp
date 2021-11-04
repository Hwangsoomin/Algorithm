#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
int main(void) {
	int a = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int k = n - i; k >= 1; k--) printf(" ");
		for (int j = 1; j <= a + 1; j++) printf("*");
		printf("\n");
		a += 2;
	}
	a -= 2;
	for (int i = n - 1; i >= 1; i--) {
		for (int k = n - i; k >= 1; k--)printf(" ");
		for (int j = a - 1; j >= 1; j--) printf("*");
		printf("\n");
		a -= 2;
	}
	return 0;
}