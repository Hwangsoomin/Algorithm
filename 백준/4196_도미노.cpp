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
int t, n, m, a, b, ans, pre, fl;
int check[100005];
vector<int> domi[100005], domi1[100005];
stack<int> st;
vector<int> newscc;
void dfs(int now) {
	check[now] = 1;
	for (int i = 0; i < domi[now].size(); i++) {
		int next = domi[now][i];
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
	for (int i = 0; i < domi1[now].size(); i++) {
		int next = domi1[now][i];
		if (next != pre && check[next])fl = 1;
		if (!check[next]) {
			check[next] = 1;
			dfs2(next);
		}
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		pre = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			domi[a].push_back(b);
			domi1[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				pre = i;
				dfs(i);
			}
		}
		memset(check, 0, sizeof(check));
		while (st.size()) {
			fl = 0;
			int now = st.top(); st.pop();
			if (!check[now]) {
				newscc.clear();
				pre = now;
				dfs2(now);
				if (fl == 0)ans += 1;
			}
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++) {
			domi[i].clear();
			domi1[i].clear();
			check[i] = 0;
		}
		newscc.clear();
	}
	return 0;
}