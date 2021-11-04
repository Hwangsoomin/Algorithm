#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int k, l, n, num1, num2;
int arr[10005];
vector<int> ans;
bool flag = false;
int main(void) {
	scanf("%d%d%d", &k, &l, &n);
	for (int i = 1; i <= n; i++)scanf("%1d", &arr[i]);
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			num1 += 1;
			num2 = 0;
			if (num1 == k)flag = true;
			continue;
		}
		if (arr[i] == 0) {
			num2 += 1;
			if (!flag)num1 = 0;
		}
		if (num2 == l && flag == true) {
			flag = false;
			num1 = 0;
			num2 = 0;
			ans.push_back(i);
		}
	}
	if (flag)ans.push_back(n + (l - num2));
	if (!ans.size())printf("NIKAD\n");
	else for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i]);
	return 0;
}