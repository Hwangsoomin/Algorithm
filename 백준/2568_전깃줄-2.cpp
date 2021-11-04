#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n, cnt;
int check[500005];
pair<int, int> arr[100005];
vector<pair<int, int>> ans;
vector<int> lis, rans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &arr[i],&arr[i].second);
		check[arr[i].first] = 1;
	}
	sort(arr + 1, arr + 1 + n);
	ans.push_back({ ++cnt,arr[1].first});
	lis.push_back(arr[1].second);
	for (int i = 2; i <= n; i++) {
		if (lis.back() < arr[i].second) {
			ans.push_back({ ++cnt,arr[i].first });
			lis.push_back(arr[i].second);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), arr[i].second);
			int num = it - lis.begin();
			*it = arr[i].second;
			ans.push_back({ num + 1,arr[i].first });
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i].first == cnt) {
			cnt--;
			check[ans[i].second] = 0;
		}
	}
	printf("%d\n", n - lis.size());
	for (int i = 1; i <= 500005; i++) {
		if (check[i] == 1)printf("%d\n", i);
	}
	return 0;
}