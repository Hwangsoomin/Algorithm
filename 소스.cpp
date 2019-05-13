#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
int v, Max;
int check[100005], ans[100005];
vector<pair<int, int>> arr[100005];
void dfs(int num) {
	check[num] = 1;
	for (int i = 0; i < arr[num].size(); i++) {
		int nn = arr[num][i].first;
		int ns = arr[num][i].second;
		if (!check[nn]) {
			check[nn] = 1;
			dfs(nn);
			ans[num] += ans[nn] + ns;
		}
	}
}
int main(void) {
	int a, c, num;
	scanf("%d", &v);
	for (int i = 1; i <= v; i++) {
		scanf("%d", &num);
		while (1) {
			scanf("%d", &a);
			if (a == -1)break;
			scanf("%d", &c);
			arr[num].push_back({ a,c });
		}
	}
	//bfs(1);
	dfs(1);
	for (int i = 1; i <= v; i++) {
		Max = max(Max, ans[i]);
	}
	printf("%d\n", Max);
	return 0;
}