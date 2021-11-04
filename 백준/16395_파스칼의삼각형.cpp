#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#include<map>
#define MOD 1000000003
#define ll long long
using namespace std;
int n, k;
ll paskal[35][35];
int main(void) {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i)paskal[i][j] = 1;
			else paskal[i][j] = paskal[i - 1][j - 1] + paskal[i - 1][j];
		}
	}
	printf("%lld\n", paskal[n][k]);
	return 0;
}