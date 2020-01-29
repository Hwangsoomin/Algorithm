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
int n, m, num, t;
bool flag = false;
int arr[1000005];
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i < 1000005; i++)arr[i] = 0;
		for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
		sort(arr + 1, arr + 1 + n);
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d", &num);
			int l = 1, r = n;
			while (l <= r) {
				int mid = (l + r) / 2;
				flag = false;
				if (arr[mid] == num) {
					printf("1\n");
					flag = true;
					break;
				}
				if (arr[mid] < num)l = mid + 1;
				else r = mid - 1;
			}
			if (!flag)printf("0\n");
		}
	}
	return 0;
}