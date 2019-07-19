#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n, m;
int a[100005], arr[100005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", &arr[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) {
		int num = arr[i];
		int l = 1, r = n, mid = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (a[mid] < num)l = mid + 1;
			else r = mid - 1;
		}
		if (a[l] == num)printf("1\n");
		else printf("0\n");
	}
	return 0;
}