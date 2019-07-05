#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, num1, num2;
int check[105];
vector<int> arr[105];
bool flag = false;
void dfs(int num, int cnt) {
	check[num] = 1;
	if (num == num2) {
		printf("%d\n", cnt);
		flag = true;
		return;
	}
	for (int i = 0; i < arr[num].size(); i++) {
		int nn = arr[num][i];
		if (!check[nn]) {
			check[nn] = 1;
			dfs(nn, cnt + 1);
		}
	}
}
int main(void) {
	int a, b;
	scanf("%d", &n);
	scanf("%d%d", &num1, &num2);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(num1, 0);
	if (!flag)printf("-1\n");
	return 0;
}