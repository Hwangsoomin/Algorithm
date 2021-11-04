#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
ll t, arr[65][10], ans[65], n;
int main(void) {
	for (int i = 0; i < 10; i++) {
		arr[1][i] = 1;
		ans[1] += 1;
	}
	for (int i = 2; i <= 64; i++) {
		arr[i][0] = ans[i - 1];
		ans[i] = ans[i - 1];
		for (int j = 1; j < 10; j++) {
			arr[i][j] = arr[i][j - 1] - arr[i - 1][j - 1];
			ans[i] += arr[i][j];
		}
	}
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}