#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
vector<int> arr[100005];
int ans[100005], check[100005];
void dfs(int num) {
	check[num] = 1;
	for (int i = 0; i < arr[num].size(); i++) {
		int nn = arr[num][i];
		if (!check[nn]) {
			check[nn] = 1;
			ans[nn] = num;
			dfs(nn);
		}
	}
}
int main(void) {
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}