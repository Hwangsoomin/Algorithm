#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
int n, degree[1005], degree2[1005], m, cc[1005], way[1005], Max, ans1, away1[1005], sum;
vector<pair<int, int>> arr[1005];
vector<int> ans, aans;
queue<int> q;
void go(int num) {
	q.push(num);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == 1 && num != 1)continue;
		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first;
			int ncost = arr[here][i].second;
			if (next == 1 && num == 1)continue;
			if (cc[next] < cc[here] + ncost) {
				cc[next] = cc[here] + ncost;
				way[next] = here;
			}
			degree[next] -= 1;
			if (degree[next] == 0)q.push(next);
		}
	}
}
int main(void) {
	int p = 0, q = 0, r = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &p, &q, &r);
		arr[p].push_back({ q, r });
		degree[q] += 1;
		degree2[q] += 1;
	}
	go(1);
	for (int i = 2; i <= n; i++) {
		if (Max < cc[i]) {
			ans1 = i;
			Max = cc[i];// µµÂø
		}
	}
	for (int i = 1; i <= n; i++) {
		away1[i] = way[i];
		degree[i] = degree2[i];
	}
	memset(cc, 0, sizeof(cc));
	memset(way, 0, sizeof(way));
	go(ans1);
	sum = Max + cc[1];
	int here = ans1;
	while (here != 1) {
		ans.push_back(here);
		here = away1[here];
	}
	ans.push_back(1);
	here = 1;
	while (here != ans1) {
		aans.push_back(here);
		here = way[here];
	}
	printf("%d\n", sum);
	for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
	for (int i = aans.size() - 1; i >= 0; i--)printf("%d ", aans[i]);
	return 0;
}