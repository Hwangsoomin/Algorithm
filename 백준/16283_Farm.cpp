#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#include<map>
#define MOD 1000000003
#define ll long long
using namespace std;
int a, b, n, w;
int ans1, ans2;
bool flag = false;
int main(void) {
	scanf(" %d%d%d%d", &a, &b, &n, &w);
	for (int i = 1; i <= 1000; i++) {
		int num1 = i;
		int num2 = n - i;
		if (num2 <= 0)break;
		int sum = (a * num1) + (b * num2);
		if (sum == w) {
			if (flag) {
				flag = false;
				break;
			}
			flag = true;
			ans1 = num1;
			ans2 = num2;
		}
	}
	if (!flag)printf("-1\n");
	else printf("%d %d\n", ans1, ans2);
	return 0;
}