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
ll arr[1000005];
int main(void) {
	scanf("%d", &n);
	arr[1] = 1, arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}
	printf("%lld\n", arr[n]);
	return 0;
}