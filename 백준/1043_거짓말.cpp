#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<string>
#define ll long long
using namespace std;
int n, m, t, ansp[55], ans;
int check[55], pcnt[55];
vector<int> parp[55], tpeo, par[55];
queue<int> q;
int main(void) {
	int peo = 0, party;
	scanf("%d%d", &n, &m);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &peo);
		q.push(peo);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &party);
		for (int j = 1; j <= party; j++) {
			scanf("%d", &peo);
			parp[peo].push_back(i);
			par[i].push_back(peo);
		}
	}
	while (!q.empty()) {
		int tp = q.front();
		q.pop();
		check[tp] = 1;//사람
		for (int i = 0; i < parp[tp].size(); i++) {
			int pa = parp[tp][i];//파티
			ansp[pa] = 1;
			for (int j = 0; j < par[pa].size(); j++) {
				int ntp = par[pa][j];//파티에 속한 사람
				if (!check[ntp]) {
					check[ntp] = 1;
					q.push(ntp);
				}
			}
		}
	}
	for (int i = 1; i <= m; i++)if (!ansp[i])ans += 1;
	printf("%d\n", ans);
	return 0;
}