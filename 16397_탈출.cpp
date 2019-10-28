#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n, t, g;
int check[100005];
queue<pair<int, int>> q;
bool flag = false;
void bfs() {
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == g) {
			printf("%d\n", cnt);
			flag = true;
			break;
		}
		check[num] = 1;
		if (num + 1 <= 99999 && !check[num + 1] && cnt + 1 <= t) {
			q.push({ num + 1,cnt + 1 });
			check[num + 1] = 1;
		}
		int nn = num * 2, here = 1;
		int nnn = nn;
		if (nn < 100000) {
			while (nnn > 0 && nnn >= 10) {
				nnn /= 10;
				here *= 10;
			}
			nn -= here;
			if (!check[nn] && cnt + 1 <= t && nn >= 0) {
				q.push({ nn,cnt + 1 });
				check[nn] = 1;
			}
		}
	}
}
int main(void) {
	scanf("%d%d%d", &n, &t, &g);
	q.push({ n,0 });
	bfs();
	if (!flag)printf("ANG\n");
	return 0;
}