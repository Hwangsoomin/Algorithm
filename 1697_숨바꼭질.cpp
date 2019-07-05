#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, k;
queue<pair<int, int>> q;
int check[100005];
int main(void) {
	scanf("%d%d", &n, &k);
	q.push({ n,0 });
	while (!q.empty()) {
		int nn = q.front().first;
		int cnt = q.front().second;
		check[nn] = 1;
		if (nn == k) {
			printf("%d\n", cnt);
			break;
		}
		q.pop();
		if(!check[nn-1] && 0 <= nn-1 && nn-1 <= 100000){
			q.push({ nn - 1,cnt + 1 });
			check[nn - 1];
		}
		if (!check[nn + 1] && 0 <= nn + 1 && nn + 1 <= 100000) {
			q.push({ nn + 1,cnt + 1 });
			check[nn + 1] = 1;
		}
		if (!check[2 * nn] && 0 <= nn * 2 && nn * 2 <= 100000) {
			q.push({ 2 * nn,cnt + 1 });
			check[nn * 2] = 1;
		}
	}
	return 0;
}