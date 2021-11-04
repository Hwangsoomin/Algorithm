#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n, Max;
int arr[100005];
int main(void) {
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		arr[a]++;
		arr[b]++;
	}
	for (int i = 1; i <= n; i++) {
		Max = max(Max, arr[i]);
	}
	printf("%d\n", Max + 1);
	return 0;
}