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
#include<map>
#define ll long long
using namespace std;
map<string, int> m;
int n, num, a, END, cnt;
int check[2505], Nscc[2505];
ll dp[2505];
string str, str1;
vector<int> arr[2505], arr1[2505];
map<string, int>::iterator here, Next;
stack<int> st;
vector<int> newscc;
void dfs(int here) {
	check[here] = 1;
	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i];
		if (!check[next]) {
			check[next] = 1;
			dfs(next);
		}
	}
	st.push(here);
}
void dfs2(int here) {
	check[here] = 1;
	Nscc[here] = cnt;
	for (int i = 0; i < arr1[here].size(); i++) {
		int next = arr1[here][i];
		if (!check[next]) {
			check[next] = 1;
			dfs2(next);
		}
	}
}
ll go(int num) {
	if (dp[num] != 0)return dp[num] * 1LL;
	dp[num] = 1;
	for (int i = 0; i < arr[num].size(); i++) {
		int nn = arr[num][i];
		if (Nscc[nn] != Nscc[num])dp[num] += go(nn) * 1LL;
		else go(nn);
	}
	return dp[num] * 1LL;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int f, s;
		cin >> str;
		if (m.find(str) == m.end()) {
			a += 1;
			m.insert({ str, a });
		}
		here = m.find(str);
		f = here->second;
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {
			cin >> str1;
			if (m.find(str1) == m.end()) {
				a += 1;
				m.insert({ str1,a });
			}
			Next = m.find(str1);
			s = Next->second;
			arr[f].push_back(s);
			arr1[s].push_back(f);
		}
	}
	cin >> str;
	here = m.find(str);
	END = here->second;
	for (int i = 1; i <= a; i++) {
		if (!check[i]) dfs(i);
	}
	memset(check, 0, sizeof(check));
	while (st.size()) {
		int here = st.top(); st.pop();
		if (!check[here]) {
			cnt += 1;
			dfs2(here);
		}
	}
	go(END);
	printf("%lld\n", dp[END]);
	return 0;
}