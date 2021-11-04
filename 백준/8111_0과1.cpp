#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<string>
#define ll long long
#define num 100000
using namespace std;
int t, n;
int p[2] = { 0,1 };
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int check[20005] = { 0, };
		queue<pair<int, string>> q;
		bool flag = false;
		scanf("%d", &n);
		q.push({ 1, "1" });
		while (!q.empty()) {
			int here = q.front().first;
			string str = q.front().second;
			q.pop();
			if (here == 0) {
				cout << str << "\n";
				flag = true;
				break;
			}
			check[here] = 1;
			for (int i = 0; i < 2; i++) {
				int next = (here * 10) + p[i];
				string nstr = str;
				if (i == 0)nstr += "0";
				else nstr += "1";
				int nn = next % n;
				if (!check[nn]) {
					check[nn] = 1;
					q.push({ nn, nstr });
				}
			}
		}
		if (!flag)printf("BRAK\n");
	}
	return 0;
}