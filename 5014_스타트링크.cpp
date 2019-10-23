#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int f, s, g, u, d;
int check[1000005];
queue<pair<int, int>> q;
bool flag = false;
int main(void) {
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	q.push({ s,0 });
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		check[here] = 1;
		if (here == g) {
			printf("%d\n", cnt);
			flag = true;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next1 = here + u;
			int next2 = here - d;
			if (!check[next1] && 1 <= next1 && next1 <= f) {
				q.push({ next1,cnt + 1 });
				check[next1] = 1;
			}
			if (!check[next2] && 1 <= next2 && next2 <= f) {
				q.push({ next2,cnt + 1 });
				check[next2] = 1;
			}
		}
	}
	if (!flag)printf("use the stairs\n");
	return 0;
}