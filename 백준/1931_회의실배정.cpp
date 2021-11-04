#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int n, pre, cnt = 1;
pair<int, int> arr[100005];
int main(void) {
	int a, b, s;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		arr[i] = { b,a };
	}
	sort(arr + 1, arr + 1 + n);
	pre = arr[1].first;
	for (int i = 2; i <= n; i++) {
		int here = arr[i].second;
		if (pre <= here) {
			cnt += 1;
			pre = arr[i].first;
		}
	}
	printf("%d\n", cnt);
	return 0;
}