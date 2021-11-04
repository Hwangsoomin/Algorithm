#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#include<map>
#define ll long long
using namespace std;
int n, x, y, p, check[205], ans;
vector<int> arr[205], rans;
pair<pair<int, int>, int> cow[205];
void dfs(int here) {
	rans.push_back(here);
	check[here] = 1;
	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i];
		if (!check[next]) {
			check[next] = 1;
			dfs(next);
		}
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x, &y, &p);
		cow[i] = { {x,y},p };
	}
	for (int i = 1; i <= n; i++) {
		x = cow[i].first.first;
		y = cow[i].first.second;
		p = cow[i].second;
		for (int j = i + 1; j <= n; j++) {
			int nx = cow[j].first.first;
			int ny = cow[j].first.second;
			int np = cow[j].second;
			double sum = sqrt(((x - nx) * (x - nx)) + ((y - ny) * (y - ny)));
			if (sum <= p)arr[i].push_back(j);
			if (sum <= np)arr[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		rans.clear();
		dfs(i);
		int size = rans.size();
		ans = max(ans, size);
	}
	printf("%d\n", ans);
	return 0;
}