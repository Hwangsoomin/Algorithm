#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int st;
int arr[305], dp[305];
int main(void) {
	scanf("%d", &st);
	for (int i = 1; i <= st; i++) {
		scanf("%d", &arr[i]);
	}
	dp[1] = arr[1], dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= st; i++)dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	printf("%d\n", dp[st]);
	return 0;
}