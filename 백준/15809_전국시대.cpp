#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, o, p, q;
int uf[100005], arr[100005];
vector<int> ans;
int find(int u) {
	if (uf[u] == u)return u;
	else return uf[u] = find(uf[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	uf[u] = v;
	arr[v] += arr[u];
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) uf[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &o);
		arr[i] = o;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &o, &p, &q);
		if (o == 1) merge(p, q);
		else {
			int n1 = find(p);
			int n2 = find(q);
			if (arr[n1] == arr[n2]) {
				arr[n1] = 0;
				arr[n2] = 0;
			}
			if (arr[n1] > arr[n2]) {
				arr[n1] -= arr[n2];
				arr[n2] = 0;
				merge(n2, n1);
			}
			else {
				arr[n2] -= arr[n1];
				arr[n1] = 0;
				merge(n1, n2);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (uf[i] == i && arr[i] != 0)ans.push_back(arr[i]);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%d ", ans[i]);
	return 0;
}