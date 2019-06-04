#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int t, k, m, p, Max;
vector<int> arr[1005];
queue<int> q;
int check[1005], degree[1005], maxde[1005];
void go() {
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (maxde[num] > 1)check[num] = check[num] + 1;
		Max = max(Max, check[num]);
		for (int i = 0; i < arr[num].size(); i++) {
			int nn = arr[num][i];
			if (check[nn] < check[num]) {
				check[nn] = check[num];
				maxde[nn] = 1;
			}
			else if (check[nn] == check[num]) maxde[nn]++;
			degree[nn]--;
			if (!degree[nn])q.push(nn);
		}
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int a, b;
		memset(degree, 0, sizeof(degree));
		memset(maxde, 0, sizeof(maxde));
		memset(check, 0, sizeof(check));
		Max = 0;
		scanf("%d%d%d", &k, &m, &p);
		for (int i = 1; i <= p; i++) {
			scanf("%d%d", &a, &b);
			arr[a].push_back(b);
			degree[b]++;
		}
		for (int i = 1; i <= m; i++) {
			if (degree[i] == 0) {
				maxde[i] = 1;
				check[i] = 1;
				q.push(i);
			}
		}
		go();
		printf("%d %d\n", k, Max);
		while (!q.empty())q.pop();
		for (int i = 1; i <= m; i++)arr[i].clear();
	}
	return 0;
}