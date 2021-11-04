#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#define ll long long
using namespace std;
int n, ans;
ll A[500005], B[500005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%lld", &A[i]);
	for (int i = 1; i <= n; i++)scanf("%lld", &B[i]);
	for (int i = 1; i <= n; i++) {
		int l = i + 1, r = n;
		ans = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (B[mid] > A[i]) r = mid - 1;
			if (B[mid] <= A[i]) {
				ans = max(ans, mid);
				l = mid + 1;
			}
		}
		if (ans != 0)printf("%d ", ans - i);
		else printf("0 ");
	}
	return 0;
}