#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#define ll long long
using namespace std;
int n, check[30], alp[30];
vector<int> newscc, pr[30], rpr[30];
vector<vector<int>> scc;
stack<int> st;
void dfs(int now) {
	check[now] = 1;
	for (int i = 0; i < pr[now].size(); i++) {
		int next = pr[now][i];
		if (!check[next]) {
			check[next] = 1;
			dfs(next);
		}
	}
	st.push(now);
}
void dfs2(int now) {
	check[now] = 1;
	newscc.push_back(now);
	for (int i = 0; i < rpr[now].size(); i++) {
		int next = rpr[now][i];
		if (!check[next]) {
			check[next] = 1;
			dfs2(next);
		}
	}
}
int main(void) {
	while (1) {
		char arr[10];
		scanf("%d", &n);
		if (n == 0)break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 6; j++) {
				scanf(" %c", &arr[j]);
				alp[arr[j] - 'A' + 1] = 1;
			}
			for (int j = 1; j <= 5; j++) {
				int next = arr[j] - 'A' + 1;
				int here = arr[6] - 'A' + 1;
				if (arr[6] == arr[j])continue;
				pr[here].push_back(next);
				rpr[next].push_back(here);
			}
		}
		for (int i = 1; i <= 26; i++) {
			if (alp[i] && !check[i])dfs(i);
		}
		memset(check, 0, sizeof(check));
		while (st.size()) {
			int now = st.top(); st.pop();
			if (!check[now]) {
				check[now] = 1;
				newscc.clear();
				dfs2(now);
				sort(newscc.begin(), newscc.end());
				scc.push_back(newscc);
			}
		}
		sort(scc.begin(), scc.end());
		for (int i = 0; i < scc.size(); i++) {
			for (int j = 0; j < scc[i].size(); j++)printf("%c ", scc[i][j] + 'A' - 1);
			printf("\n");
		}
		for (int i = 1; i <= 26; i++) {
			check[i] = 0;
			alp[i] = 0;
			pr[i].clear();
			rpr[i].clear();
		}
		scc.clear();
		printf("\n");
	}
	return 0;
}