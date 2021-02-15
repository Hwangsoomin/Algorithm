#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, m, a, b, num;
int uf[1000005];
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
	for (int i = 1; i <= n; i++) uf[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &num, &a, &b);
		if (num == 0) merge(a, b);
		else {
			if (find(a) == find(b))printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}