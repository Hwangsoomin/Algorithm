#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int a[100005], arr[100005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= m; i++) {
		int l = 1, r = n, mid = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (a[mid] == arr[i])break;
			else if (a[mid] < arr[i])l = mid + 1;
			else r = mid - 1;
		}
		if (a[mid] == arr[i])printf("1\n");
		else printf("0\n");
	}
	return 0;
}