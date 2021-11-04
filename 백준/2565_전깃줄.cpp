#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, cnt;
pair<int, int> arr[105];
vector<int> ans;
int main(void) {
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		arr[i] = { a,b };
	}
	sort(arr + 1, arr + n + 1);
	ans.push_back(arr[1].second);
	for (int i = 2; i <= n; i++) {
		if (ans.back() <= arr[i].second)ans.push_back(arr[i].second);
		else {
			auto it = lower_bound(ans.begin(), ans.end(), arr[i].second);
			*it = arr[i].second;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}