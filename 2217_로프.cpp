#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int n, Max;
int arr[100005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++) {
		int sum = (n - i + 1) * arr[i];
		Max = max(Max, sum);
	}
	printf("%d\n", Max);
	return 0;
}