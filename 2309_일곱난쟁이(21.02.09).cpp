#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ans;
int check[10], arr[10];
int go(int here, int cnt, int sum) {
	if (cnt == 7) {
		if (sum == 100) {
			for (int j = 1; j <= 9; j++) {
				if (check[j])ans.push_back(arr[j]);
			}
			sort(ans.begin(), ans.end());
			for (int j = 0; j < ans.size(); j++) {
				printf("%d\n", ans[j]);
			}
			return 1;
		}
		else return 0;
	}
	for (int i = here; i <= 9; i++) {
		if (!check[i]) {
			check[i] = 1;
			if (go(i + 1, cnt + 1, sum + arr[i])) break;
			check[i] = 0;
		}
	}
	return 0;
}
int main(void) {
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &arr[i]);
	}
	go(1, 0, 0);
	return 0;
}