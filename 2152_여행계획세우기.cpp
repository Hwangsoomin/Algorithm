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
int n, m, s, t, a, b, cnt, Start, End, ans;
int check[10005], sn[10005], csn[10005], Maxtr[10005], outde[10005], go[10005], htr[10005];
vector<int> tr[10005], rtr[10005], newscc, str[10005];
vector<vector<int>> scc;
stack<int> st;
queue<int> q;
void dfs(int now) {
	check[now] = 1;
	for (int i = 0; i < tr[now].size(); i++) {
		int next = tr[now][i];
		if (!check[next]) {
			check[next] = 1;
			dfs(next);
		}
	}
	st.push(now);
}
void dfs2(int now) {
	check[now] = 1;
	sn[now] = cnt;
	newscc.push_back(now);
	for (int i = 0; i < rtr[now].size(); i++) {
		int next = rtr[now][i];
		if (!check[next]) {
			check[next] = 1;
			dfs2(next);
		}
	}
}
int main(void) {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		tr[a].push_back(b);
		rtr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i])dfs(i);
	}
	memset(check, 0, sizeof(check));
	while (st.size()) {
		int now = st.top(); st.pop();
		if (!check[now]) {
			cnt += 1;
			newscc.clear();
			dfs2(now);
			scc.push_back(newscc);
		}
	}
	for (int i = 1; i <= n; i++) {
		int si = sn[i];//scc¹øÈ£
		if (i == s)Start = si;
		if (i == t)End = si;
		htr[si] += 1;
		for (int j = 0; j < tr[i].size(); j++) {
			int ei = tr[i][j];
			if (si == sn[ei])continue;
			str[si].push_back(sn[ei]);
			outde[sn[ei]] += 1;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		Maxtr[i] = htr[i];
		if (outde[i] == 0)q.push(i);
		if (i == Start)go[i] = 1;
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < str[here].size(); i++) {
			int next = str[here][i];
			if (go[here]) {
				Maxtr[next] = max(Maxtr[next], Maxtr[here] + htr[next]);
				go[next] = 1;
			}
			outde[next] -= 1;
			if (outde[next] == 0)q.push(next);
		}
	}
	if (go[End]) printf("%d\n", Maxtr[End]);
	else printf("0\n");
	return 0;
}