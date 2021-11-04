#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#include<map>
#include<climits>
#define ll long long
using namespace std;
int n, pre, ans, a;
vector<int> num;
int arr[500005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		num.push_back(a);
		arr[a] += 1;
	}
	for (int i = 0; i < n; i++) {
		int here = num[i];
		ans = max(ans, arr[here]);
	}
	printf("%d\n", ans);
	return 0;
}