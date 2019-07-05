#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> arr[105];
int check[105];
int n;
void dfs(int num) {
	check[num] = 1;
	for (int i = 0; i < arr[num].size(); i++) {
		int nn = arr[num][i];
		if (!check[nn]) {
			check[nn] = 1;
			dfs(nn);
		}
	}
}
int main(void) {
	int a, b, cnt, ans = 1e9;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		cnt = 0;
		dfs(i);
		for (int i = 1; i <= n; i++) {
			if (check[i])cnt++;
		}
		if (cnt == n)ans = min(ans, i);
	}
	if (ans == 1e9)printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}