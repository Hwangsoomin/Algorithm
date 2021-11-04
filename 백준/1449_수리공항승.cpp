#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int n, l, pre, cnt = 1;
int arr[1005];
int main(void) {
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	sort(arr + 1, arr + 1 + n);
	pre = arr[1];
	for (int i = 2; i <= n; i++) {
		if (arr[i] - pre + 1 > l) {
			cnt += 1;
			pre = arr[i];
		}
	}
	printf("%d\n", cnt);
	return 0;
}