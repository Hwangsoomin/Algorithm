#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int t, n, sc1, sc2;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int cnt = 1;
		pair<int, int> arr[100005];
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &sc1, &sc2);
			arr[i] = { sc1,sc2 };
		}
		sort(arr + 1, arr + 1 + n);
		int f1 = arr[1].second;
		for (int i = 2; i <= n; i++) {
			if (arr[i].second < f1) {
				cnt++;
				f1 = arr[i].second;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}