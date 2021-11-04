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
int v, e, a, b;
stack<int> st;
vector<int> arr[10005], arr1[10005];
int check[10005];
vector<int> newscc;
vector<vector<int>> scc;
void dfs(int now) {
	check[now] = 1;
	for (int i = 0; i < arr[now].size(); i++) {
		int next = arr[now][i];
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
	for (int i = 0; i < arr1[now].size(); i++) {
		int next = arr1[now][i];
		if (!check[next]) {
			check[next] = 1;
			dfs2(next);
		}
	}
}
int main(void) {
	scanf("%d%d", &v, &e);
	for (int i = 1; i <= e; i++) {
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		arr1[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (!check[i]) dfs(i);
	}
	memset(check, 0, sizeof(check));
	while (st.size()) {
		int now = st.top(); st.pop();
		if (!check[now]) {
			newscc.clear();
			dfs2(now);
			sort(newscc.begin(), newscc.end());
			scc.push_back(newscc);
		}
	}
	sort(scc.begin(), scc.end());
	printf("%d\n", scc.size());
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			printf("%d ", scc[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}