#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n, er, ans, root;
int tree[55], check[55], visit[55];
vector<int> arr[55];
bool flag;
void dfs(int num) {
	visit[num] = 1;
	flag = false;
	for (int i = 0; i < arr[num].size(); i++) {
		int nn = arr[num][i];
		if (!visit[nn] && !check[nn]) {
			visit[nn] = 1;
			dfs(nn);
			flag = true;
		}
	}
	if (!flag)ans++;
}
int main(void) {
	int num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num == -1) {
			root = i;
			continue;
		}
		arr[num].push_back(i);
	}
	scanf("%d", &er);
	check[er] = 1;
	for (int i = 0; i < n; i++) {
		if (check[i]) {
			for (int j = 0; j < arr[i].size(); j++) {
				check[arr[i][j]] = 1;
			}
		}
	}
	if (check[root])printf("0\n");
	else {
		dfs(root);
		printf("%d\n", ans);
	}
	return 0;
}