#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
int n;
ll arr[1005][10];
ll sum;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		arr[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % 10007;
		}
	}
	for (int i = 0; i < 10; i++) {
		sum = (sum + arr[n][i]) % 10007;
	}
	printf("%lld\n", sum);
	return 0;
}