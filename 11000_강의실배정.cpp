#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int n, s, t, cnt = 1;
pair<int,int> arr[200005];
priority_queue<int,vector<int>,greater<int>> pq;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &s, &t);
		arr[i] = { s,t };
	}
	sort(arr + 1, arr + 1 + n);
	pq.push(arr[1].second);
	for (int i = 2; i <= n; i++) {
		int here = arr[i].first;
		int pre = pq.top();
		if (pre <= here) pq.pop();
		pq.push(arr[i].second);
	}
	printf("%d\n", pq.size());
	return 0;
}