#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int n, m, Min = 1e9, cnt, ans, newnum;
int arr[105][105], check[105];
vector<int> rans;
int main(void) {
	int a, b;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 1e9;
			if (i == j)arr[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	for (int x = 1; x <= n; x++) {
		int Max = 0;
		vector<int> num;
		if (!check[x]) {
			check[x] = 1;
			cnt++;
			num.push_back(x);
			for (int y = 1; y <= n; y++) {
				if (arr[x][y] != 1e9) {
					num.push_back(y);
					check[y] = 1;
				}
			}
			Min = 1e9;
			for (int j = 0; j < num.size(); j++) {
				int nn = num[j];
				Max = -1;
				newnum = 0;
				for (int i = 1; i <= n; i++) {
					if (arr[nn][i] != 1e9) {
						if (Max < arr[nn][i]) {
							Max = arr[nn][i];
							newnum = nn;
						}
					}
				}
				if (Min > Max) {
					Min = Max;
					ans = newnum;
				}
			}
			rans.push_back(ans);
		}
	}
	printf("%d\n", cnt);
	sort(rans.begin(), rans.end());
	for (int i = 0; i < rans.size(); i++)printf("%d\n", rans[i]);
	return 0;
}