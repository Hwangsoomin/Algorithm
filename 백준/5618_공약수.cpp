#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include <functional>
using namespace std;
int n, Min = 1e9;
int arr[5];
bool flag = false;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		Min = min(Min, arr[i]);
	}
	for (int i = 1; i <= Min; i++) {
		flag = false;
		for (int j = 1; j <= n; j++) if (arr[j] % i != 0)flag = true;
		if (!flag)printf("%d\n", i);
	}
	return 0;
}