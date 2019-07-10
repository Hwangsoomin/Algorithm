#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n, x, y, x1, x2, cnt = 1;
pair<int, int> arr[100005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		arr[i] = { x - y ,x + y };
	}
	sort(arr + 1, arr + 1 + n);
	x1 = arr[1].first;
	x2 = arr[1].second;
	for (int i = 2; i <= n; i++) {
		int xx1 = arr[i].first;
		int xx2 = arr[i].second;
		if (x2 < xx2) {
			if (x1 != xx1) cnt++;
			x1 = xx1;
			x2 = xx2;
		}
	}
	printf("%d\n", cnt);
	return 0;
}