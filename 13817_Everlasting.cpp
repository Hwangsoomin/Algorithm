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
int a, b;
int check[1000001] = { 0, };
int check1[1000001] = { 0, };
int main(void) {
	while (1) {
		memset(check, 0, sizeof(check));
		memset(check1, 0, sizeof(check1));
		vector<int> ans1, ans2;
		int sum = 0, sum1 = 0, n = 2;
		scanf(" %d%d", &a, &b);
		if (a == 0 && b == 0)break;
		while (a > 1) {
			if (a % n == 0) {
				if (!check[n]) {
					check[n] = 1;
					ans1.push_back(n);
				}
				a /= n;
			}
			else n += 1;
		}
		n = 2;
		while (b > 1) {
			if (b % n == 0) {
				if (!check1[n]) {
					check1[n] = 1;
					ans2.push_back(n);
				}
				b /= n;
			}
			else n += 1;
		}
		sort(ans1.begin(), ans1.end());
		sort(ans2.begin(), ans2.end());
		for (int i = 0; i < ans1.size() - 1; i++)sum += ans1[i];
		for (int i = 0; i < ans2.size() - 1; i++)sum1 += ans2[i];
		if (ans1[ans1.size() - 1] - sum > ans2[ans2.size() - 1] - sum1)printf("a\n");
		else printf("b\n");
	}
	return 0;
}