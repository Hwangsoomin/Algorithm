#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, arr[1005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++)printf("%d\n", arr[i]);
	return 0;
}