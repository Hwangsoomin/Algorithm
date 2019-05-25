#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int arr[1000005];
vector<int> ans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	ans.push_back(arr[1]);
	for (int i = 2; i <= n; i++) {
		if (ans.back() < arr[i])ans.push_back(arr[i]);
		else {
			auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
			*it = arr[i];
		}
	}
	printf("%d\n", ans.size());
	return 0;
}