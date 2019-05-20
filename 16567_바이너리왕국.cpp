#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
int n, m, cnt;
int arr[1000005];
int main(void) {
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			cnt++;
			while (arr[i] == 1)i++;
		}
	}
	while (m--) {
		scanf("%d", &a);
		if (a == 0) {
			printf("%d\n", cnt);
		}
		if (a == 1) {
			scanf(" %d", &b);
			if (!arr[b]) {
				arr[b] = 1;
				if (arr[b - 1] && arr[b + 1])cnt--;
				if (!arr[b - 1] && !arr[b + 1])cnt++;
			}
		}
	}
	return 0;
}