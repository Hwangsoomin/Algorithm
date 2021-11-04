#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#define MOD 100999
#define ll long long
using namespace std;
int t, n, m, a, b;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)scanf("%d%d", &a, &b);
		printf("%d\n", n - 1);
	}
	return 0;
}