#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
int Max;
string n;
int ans[10];
int main(void) {
	cin >> n;
	for(int i = 0; i < n.size(); i++) {
		int num = n[i] - '0';
		if (num == 6 || num == 9) {
			if (ans[6] < ans[9])ans[6] += 1;
			else ans[9] += 1;
		}
		else ans[num] += 1;
	}
	for (int i = 0; i <= 9; i++) Max = max(Max, ans[i]);
	printf("%d\n", Max);
	return 0;
}