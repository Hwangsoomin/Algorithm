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
int n;
ll fibo[120];
int main(void) {
	scanf("%d", &n);
	fibo[1] = 1, fibo[2] = 1, fibo[3] = 1;
	for (int i = 4; i <= n; i++) {
		fibo[i] = fibo[i - 3] + fibo[i - 1];
	}
	printf("%lld\n", fibo[n]);
	return 0;
}