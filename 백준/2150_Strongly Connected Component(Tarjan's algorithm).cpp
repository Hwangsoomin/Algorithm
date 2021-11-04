#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
stack<int> st;
vector<int> arr[10005];
vector<vector<int>> scc;
int check[10005];
int v, e, a, b, low[10005], discoverTime[100005], cnt;
int SCC(int here) {
	discoverTime[here] = ++cnt;
	low[here] = discoverTime[here];
	st.push(here);
	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i];
		if (!discoverTime[next]) {
			low[here] = min(low[here], SCC(next));
		}
		else if (check[next] == -1) {// 교차, 백에지
			low[here] = min(low[here], discoverTime[next]);
		}
	}
	if (low[here] >= discoverTime[here]) {
		vector<int> nscc;
		while (st.size()) {
			int num = st.top();
			st.pop();
			nscc.push_back(num);
			check[num] = 1;
			if (here == num)break;
		}
		sort(nscc.begin(), nscc.end());
		scc.push_back(nscc);
	}
	return low[here];
}
int main(void) {
	memset(check, -1, sizeof(check));
	scanf("%d%d", &v, &e);
	for (int i = 1; i <= e; i++) {
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
	}
	for (int i = 1; i <= v; i++) {
		if (check[i] == -1)SCC(i);
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