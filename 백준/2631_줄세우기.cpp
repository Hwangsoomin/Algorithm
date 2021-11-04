#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
int n, cnt;
int arr[205];
vector<int> ans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	ans.push_back(0);
	for (int i = 1; i <= n; i++) {
		if (ans.back() < arr[i])ans.push_back(arr[i]);
		else {
			auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
			*it = arr[i];
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}