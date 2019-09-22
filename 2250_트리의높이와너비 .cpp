#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
struct {
	int left;
	int right;
}tree[10005];
int n, arr[10005], sum = 1, Max, ans, ans1 = 1e9, root;
int nsum[10005];
vector<int> hei[10005], ntree[10005];
int check[10005];
void in(int num) {
	if (num == -1)return;
	int le = tree[num].left;
	int ri = tree[num].right;
	in(le);
	arr[num] = sum++;
	in(ri);
}
void dfs(int h, int num) {
	Max = max(Max, h);
	hei[h].push_back(num);
	check[num] = 1;
	for (int i = 0; i < ntree[num].size(); i++) {
		int nn = ntree[num][i];
		if (nn == -1)continue;
		if (!check[nn]) {
			check[nn] = 1;
			dfs(h + 1, nn);
		}
	}
}
int main(void) {
	int n1, n2, n3;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &n1, &n2, &n3);
		tree[n1].left = n2;
		tree[n1].right = n3;
		ntree[n1].push_back(n2);
		ntree[n1].push_back(n3);
		nsum[n1]++;
		nsum[n2]++;
		nsum[n3]++;
	}
	for (int i = 1; i <= n; i++) {
		if (nsum[i] == 1)root = i;
	}
	in(root);
	dfs(1, root);
	for (int i = 1; i <= Max; i++) {
		int la = hei[i].size() - 1;
		int le = hei[i][0];
		int ri = hei[i][la];
		if (ans < arr[ri] - arr[le] + 1) {
			ans = arr[ri] - arr[le] + 1;
			ans1 = i;
		}
	}
	printf("%d %d\n", ans1, ans);
	return 0;
}