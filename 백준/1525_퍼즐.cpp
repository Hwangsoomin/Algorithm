#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
string num;
int arr[5][5], x, y;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int dnum[4] = { -3,1,3,-1 };
queue<pair<pair<string, int>, pair<pair<int, int>, int>>> q;//숫자모음, 횟수, 가로, 세로
set<string> s;
int pre, h;
bool flag = false;
bool aflag = false;
void bfs() {
	q.push({ {num,0},{{x,y},h} });
	while (!q.empty()) {
		string ans = q.front().first.first;
		int cnt = q.front().first.second;
		int r = q.front().second.first.first;
		int c = q.front().second.first.second;
		int here = q.front().second.second;
		pre = ans[0];
		flag = false;
		q.pop();
		if (ans[0] != 0) {
			for (int i = 1; i < ans.length() - 1; i++) {
				if (pre > ans[i]) {
					flag = true;
					break;
				}
				pre = ans[i];
			}
		}
		if (!flag && pre != 0) {
			printf("%d\n", cnt);
			aflag = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			string nstr = ans;
			char cc = nstr[here];
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 1 || nr>3 || nc < 1 || nc>3)continue;
			nstr[here] = nstr[here + dnum[i]];
			nstr[here + dnum[i]] = cc;
			if (s.find(nstr) == s.end()) {
				s.insert(nstr);
				q.push({ {nstr,cnt + 1},{{nr,nc},here + dnum[i]} });
			}
		}
	}
}
int main(void) {
	int n = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &arr[i][j]);
			num += arr[i][j];
			if (arr[i][j] == 0) {
				x = i; y = j;
				h = n;
			}
			n++;
		}
	}
	s.insert(num);
	bfs();
	if (!aflag)printf("-1\n");
	return 0;
}