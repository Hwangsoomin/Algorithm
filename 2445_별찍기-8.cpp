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
	a = (n * 2) - 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) printf("*");
		for (int k = 1; k <= a; k++)printf(" ");
		for (int j = 1; j <= i; j++)printf("*");
		a -= 2;
		printf("\n");
	}
	a = 2;
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i; j >= 1; j--)printf("*");
		for (int k = 1; k <= a; k++)printf(" ");
		for (int j = i; j >= 1; j--)printf("*");
		a += 2;
		printf("\n");
	}
	return 0;
}