#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
using namespace std;
int x, sum, ans, ans1;
int main(void) {
	int num = 1;
	scanf("%d", &x);
	while (1) {
		sum += num;
		if (sum >= x) break;
		num += 1;
	}
	sum -= num;
	num += 1;
	ans1 = x - sum;
	ans = num - ans1;
	if (num % 2 == 0)printf("%d/%d\n", ans, ans1);
	else printf("%d/%d\n", ans1, ans);
	return 0;
}