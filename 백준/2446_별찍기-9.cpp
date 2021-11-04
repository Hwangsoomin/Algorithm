#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
int main(void) {
	int a;
	scanf("%d", &n);
	a = (2 * n) - 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k < i; k++)printf(" ");
		for (int j = 1; j <= a; j++)printf("*");
		a -= 2;
		printf("\n");
	}
	a += 4;
	for (int i = n - 1; i >= 1; i--) {
		for (int k = i - 1; k >= 1; k--)printf(" ");
		for (int j = a; j >= 1; j--)printf("*");
		a += 2;
		printf("\n");
	}
	return 0;
}