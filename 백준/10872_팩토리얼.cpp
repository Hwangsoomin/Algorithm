#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, fac = 1;
int main(void) {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) fac *= i;
	printf("%d\n", fac);
	return 0;
}