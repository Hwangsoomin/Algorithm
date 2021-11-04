#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n, a, b, g, Max, cnt;
pair<pair<int, int>, int> arr[105];
int ans[5];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a, &b, &g);
		arr[i] = { {a,b},g };
	}
	for (int i = 1; i <= 3; i++) {
		int loc = i;
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			int num1 = arr[j].first.first;
			int num2 = arr[j].first.second;
			int num3 = arr[j].second;
			int temp = num1;
			if (num1 == loc) loc = num2;
			else if (num2 == loc)loc = num1;
			num1 = num2;
			num2 = temp;
			if (loc == num3)cnt++;
		}
		Max = max(Max, cnt);
	}
	printf("%d\n", Max);
	return 0;
}