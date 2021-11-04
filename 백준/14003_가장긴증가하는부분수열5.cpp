#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n, cnt = 1;
int arr[1000005];
vector<pair<int, int>> ans;
vector<int> lis, rans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	ans.push_back({ cnt++,arr[1] });
	lis.push_back(arr[1]);
	for (int i = 2; i <= n; i++) {
		if (lis.back() < arr[i]) {
			ans.push_back({ cnt++,arr[i] });
			lis.push_back(arr[i]);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
			int num = it - lis.begin();
			*it = arr[i];
			ans.push_back({ num + 1,arr[i] });
		}
	}
	cnt--;
	printf("%d\n", lis.size());
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i].first == cnt) {
			rans.push_back(ans[i].second);
			cnt--;
		}
	}
	sort(rans.begin(), rans.end());
	for (int i = 0; i < rans.size(); i++) {
		printf("%d ", rans[i]);
	}
	return 0;
}