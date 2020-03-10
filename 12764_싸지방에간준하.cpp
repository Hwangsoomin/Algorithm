#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define ll long long
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> nhere;
int n, check[100005], Max;
pair<int, int> com[100005];
int main(void) {
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		com[i] = { a,b };
	}
	sort(com + 1, com + 1 + n);
	for (int i = 1; i <= n; i++) {
		while (!pq.empty()) {
			int Mtop = pq.top().first;
			int here = pq.top().second;
			if (Mtop <= com[i].first) {
				nhere.push(here);
				pq.pop();
			}
			else break;
		}
		if (!nhere.empty()) {
			pq.push({ com[i].second,nhere.top() });
			check[nhere.top()] += 1;
			nhere.pop();
		}
		else {
			int seat = pq.size() + 1;
			pq.push({ com[i].second,seat });
			check[seat] += 1;
		}
	}
	printf("%d\n", pq.size() + nhere.size());
	for (int i = 1; i <= pq.size() + nhere.size(); i++)printf("%d ", check[i]);
	return 0;
}