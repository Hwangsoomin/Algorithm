#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
#define MAX 1000000000
using namespace std;
int n, Min, Max;
int arr[50005], sum[50005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			Min = min((sum[j - 1] - sum[i - 1]), (sum[n] - (sum[j - 1] - sum[i - 1])));
			Max = max(Max, Min);
		}
	}
	printf("%d\n", Max);
	return 0;
}