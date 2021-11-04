#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, a;
int arr[205][205], uf[205];
vector<int> route;
bool flag = false;
int find(int u) {
	if (uf[u] == u)return u;
	else return uf[u] = find(uf[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	uf[u] = v;
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)uf[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &arr[i][j]);
			if (arr[i][j]) merge(i, j);
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &a);
		route.push_back(a);
	}
	int ans = find(route[0]);
	for (int i = 1; i < route.size(); i++) {
		int here = find(route[i]);
		if (ans != here) {
			flag = true;
			break;
		}
	}
	if (!flag)printf("YES\n");
	else printf("NO\n");
	return 0;
}