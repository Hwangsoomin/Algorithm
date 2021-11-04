#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int n, m;
int arr[55], rarr[55], moy[105][55], check[105];
vector<int> ans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = n; i >= 1; i--) {
		if (arr[i] == 1)rarr[n - i + 1] = 3;
		else if (arr[i] == 2)rarr[n - i + 1] = 4;
		else if (arr[i] == 3)rarr[n - i + 1] = 1;
		else rarr[n - i + 1] = 2;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &moy[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		int pt, pt1;
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (moy[i][1] == arr[j]) {
				flag = false;
				pt = 1;
				pt1 = j;
				while (pt < n) {
					if (pt1 > n)pt1 = pt1 % n;
					if (moy[i][pt] != arr[pt1]) {
						flag = true;
						break;
					}
					pt++;
					pt1++;
				}
			}
			if (!flag) {
				check[i] = 1;
				ans.push_back(i);
				break;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (check[i])continue;
		int pt = 1, pt1;
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (moy[i][1] == rarr[j]) {
				pt = 1;
				pt1 = j;
				flag = false;
				while (pt < n) {
					if (pt1 > n)pt1 = pt1 % n;
					if (moy[i][pt] != rarr[pt1]) {
						flag = true;
						break;
					}
					pt++;
					pt1++;
				}
			}
			if (!flag) {
				check[i] = 1;
				ans.push_back(i);
				break;
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		int num = ans[i];
		if (check[num]) {
			for (int j = 1; j <= n; j++)printf("%d ", moy[num][j]);
			printf("\n");
		}
	}
	return 0;
}