#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int t, a, b;
int check[10005];
queue<pair<int, string>> q;
void bfs(int num) {
	string str = "";
	q.push({ num,str });
	while (!q.empty()) {
		int n = q.front().first;
		string s = q.front().second;
		q.pop();
		if (n == b) {
			cout << s << endl;
			break;
		}
		check[n] = 1;
		int nn = (2 * n) % 10000;
		if (!check[nn]) {
			check[nn] = 1;
			q.push({ nn,s + "D" });
		}
		if (n == 0)nn = 9999;
		else nn = n - 1;
		if (!check[nn]) {
			check[nn] = 1;
			q.push({ nn,s + "S" });
		}
		int d4 = n % 10;
		n = n / 10;
		int d3 = n % 10;
		n = n / 10;
		int d2 = n % 10;
		n = n / 10;
		int d1 = n % 10;
		nn = (d2 * 1000) + (d3 * 100) + (d4 * 10) + d1;
		if (!check[nn]) {
			check[nn] = 1;
			q.push({ nn,s + "L" });
		}
		nn = (d4 * 1000) + (d1 * 100) + (d2 * 10) + d3;
		if (!check[nn]) {
			check[nn] = 1;
			q.push({ nn,s + "R" });
		}
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf(" %d%d", &a, &b);
		memset(check, 0, sizeof(check));
		bfs(a);
		while (!q.empty()) {
			q.pop();
		}
	}
	return 0;
}