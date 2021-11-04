#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
unordered_map<string, int> map;
int n, m, k, ans;
char arr[15][15];
vector<string> str;
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };
queue<pair<pair<int, int>, pair<string, int>>> q;
void go(int r, int c, string here, int cnt, int strIdx, int strCnt) {
	if (cnt == strCnt) {
		if (here == str[strIdx]) ans += 1;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr == n + 1)nr = 1;
		if (nr == 0)nr = n;
		if (nc == m + 1)nc = 1;
		if (nc == 0)nc = m;
		if (nr<1 || nr>n || nc<1 || nc>m)continue;
		string next = here;
		next += arr[nr][nc];
		go(nr, nc, next, cnt + 1, strIdx, strCnt);
	}
}
int main(void) {
	string a;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> a;
		str.push_back(a);
	}
	for (int x = 0; x < k; x++) {
		auto item = map.find(str[x]);
		if (item != map.end()) {
			printf("%d\n", map[str[x]]);
			continue;
		}
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (str[x][0] != arr[i][j])continue;
				string s = "";
				s += arr[i][j];
				go(i, j, s, 1, x, str[x].size());
			}
		}
		map[str[x]] = ans;
		printf("%d\n", ans);
	}
	return 0;
}