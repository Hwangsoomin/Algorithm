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
int n, xL, yL, xB, yB, x, y;
vector<pair<int, int>> arr, arr1;
vector<int> g[100005];
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> q;
pair<int, int> ar[100005];
int cnt[100005];
void bfs() {
	q.push({ {0,0},0 });
	q.push({ {0,0}, 1 });
	cnt[0] = 0;
	while (!q.empty()) {
		int ncnt = q.top().first.first;
		int here = q.top().first.second;
		int pre = q.top().second;
		int r = ar[here].first;
		int c = ar[here].second;
		q.pop();
		if (r == xB && c == yB)continue;
		if (cnt[here] < ncnt)continue;
		for (int i = 0; i < g[here].size(); i++) {
			int next = g[here][i];
			int nr = ar[next].first;
			int nc = ar[next].second;
			if (nr == r) {
				if (pre == 1) {
					if (cnt[next] > ncnt) {
						cnt[next] = ncnt;
						q.push({ {ncnt, next} , 1 });
					}
				}
				else {
					if (cnt[next] > ncnt + 1) {
						cnt[next] = ncnt + 1;
						q.push({ {ncnt + 1, next}, 1 });
					}
				}
			}
			if (nc == c) {
				if (pre == 0) {
					if (cnt[next] > ncnt) {
						cnt[next] = ncnt;
						q.push({ {ncnt, next}, 0 });
					}
				}
				else {
					if (cnt[next] > ncnt + 1) {
						cnt[next] = ncnt + 1;
						q.push({ {ncnt + 1, next}, 0 });
					}
				}
			}
		}
	}
}
int main(void) {
	scanf("%d%d%d%d%d", &n, &xL, &yL, &xB, &yB);
	arr.push_back({ xL, 0 });
	arr1.push_back({ yL, 0 });
	arr.push_back({ xB,1 });
	arr1.push_back({ yB, 1 });
	ar[0] = { xL, yL };
	ar[1] = { xB,yB };
	cnt[1] = 1e9;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		cnt[i + 1] = 1e9;
		ar[i + 1] = { x,y };
		arr.push_back( { x, i + 1 });
		arr1.push_back({ y,i + 1});
	}
	sort(arr.begin(), arr.end());
	sort(arr1.begin(), arr1.end());
	for (int i = 1; i < arr.size(); i++) {
		int r = arr[i - 1].first;
		int nr = arr[i].first;
		int n1 = arr[i - 1].second;
		int n2 = arr[i].second;
		if (r == nr) {
			g[n1].push_back(n2);
			g[n2].push_back(n1);
		}
	}
	for (int i = 1; i < arr1.size(); i++) {
		int c = arr1[i - 1].first;
		int nc = arr1[i].first;
		int n1 = arr1[i - 1].second;
		int n2 = arr1[i].second;
		if (c == nc) {
			g[n1].push_back(n2);
			g[n2].push_back(n1);
		}
	}
	bfs();
	if (cnt[1] != 1e9)printf("%d\n", cnt[1]);
	else printf("-1\n");
	return 0;
}