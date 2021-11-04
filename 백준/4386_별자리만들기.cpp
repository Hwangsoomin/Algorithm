#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
#include<stack>
#include<cmath>
#define ll long long
using namespace std;
int n, uf[105];
pair<double, double> arr[105];
double x, y, ans;
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
int find(int u) {
	if (uf[u] == u)return u;
	else return uf[u] = find(uf[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	uf[u] = v;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &x, &y);
		arr[i] = { x,y };
		uf[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		double fx = arr[i].first;
		double fy = arr[i].second;
		for (int j = i + 1; j <= n; j++) {
			double sx = arr[j].first;
			double sy = arr[j].second;
			double num = sqrt(((fx - sx) * (fx - sx)) + ((fy - sy) * (fy - sy)));
			pq.push({ num,{i,j} });
			pq.push({ num, {j,i} });
		}
	}
	while (!pq.empty()) {
		double cost = pq.top().first;
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		pq.pop();
		if (find(r) != find(c)) {
			merge(r, c);
			ans += cost;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}