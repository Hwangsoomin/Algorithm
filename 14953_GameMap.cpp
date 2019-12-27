#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, a, b, Max;
int num[100005];
vector<int> arr[100005];
int ans[100005];
int go(int nn) {
	if (ans[nn] == 0)ans[nn] = 1;
	else return ans[nn];
	for (int i = 0; i < arr[nn].size(); i++) {
		int nnn = arr[nn][i];
		if (num[nn] < num[nnn]) {
			ans[nn] = max(ans[nn], go(nnn) + 1);
		}
	}
	return ans[nn];
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
		num[a] += 1;
		num[b] += 1;
	}
	for (int i = 0; i < n; i++) {
		go(i);
	}
	for (int i = 0; i < n; i++)Max = max(Max, ans[i]);
	printf("%d\n", Max);
	return 0;
}