#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
pair<int, int> arr[4], ans[3];
int main(void) {
	for (int i = 1; i <= 3; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
	for (int i = 2; i <= 3; i++) {
		int x = arr[i].first - arr[i - 1].first;
		int y = arr[i].second - arr[i - 1].second;
		ans[i - 1] = { x,y };
	}
	int num = ans[1].first * ans[2].second;
	num -= ans[1].second * ans[2].first;
	if (num < 0)printf("-1\n");
	else if (num == 0)printf("0\n");
	else printf("1\n");
	return 0;
}