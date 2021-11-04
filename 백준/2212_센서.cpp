#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int n, k, sum;
int sen[10005], ans[10005];
int main(void) {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &sen[i]);
	sort(sen + 1, sen + 1 + n);
	sum = abs(sen[n] - sen[1]);
	for (int i = 1; i < n; i++) ans[i] = abs(sen[i + 1] - sen[i]);
	sort(ans + 1, ans + n);
	for (int i = 1; i < n && --k; i++) sum -= ans[n - i];
	printf("%d\n", sum);
	return 0;
}