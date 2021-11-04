#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n, m, k, a;
double b, sum;
int check[105];
priority_queue<pair<double, int>> pq;
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d%lf", &a, &b);
			pq.push({ b,a });
		}
	}
	while (!pq.empty() && k != 0) {
		int peo = pq.top().second;
		double num = pq.top().first;
		pq.pop();
		if (!check[peo]) {
			check[peo] = 1;
			sum += num;
			k -= 1;
		}
	}
	printf("%.1lf\n", sum);
	return 0;
}