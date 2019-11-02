#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int n, m, Min = 1e9, ans;
int num[105];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (i != j && i != k && j != k) {
						if (num[i] + num[j] + num[k] <= m) {
							if (Min > abs(m - (num[i] + num[j] + num[k]))) {
								Min = abs(m - (num[i] + num[j] + num[k]));
								ans = num[i] + num[j] + num[k];
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}