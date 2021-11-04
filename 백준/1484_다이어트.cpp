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
int g;
vector<int> ans;
int main(void) {
	scanf("%d", &g);
	for (int i = 1; i <= 50000; i++) {//현재
		int n1 = i * i;
		if (n1 < g)continue;
		for (int j = 1; j < i; j++) {//기억
			int n2 = j * j;
			if ((n1 - n2) < g)break;
			if ((n1 - n2) == g) {
				ans.push_back(i);
				break;
			}
		}
	}
	if (!ans.size())printf("-1\n");
	else for (int i = 0; i < ans.size(); i++)printf("%d\n", ans[i]);
	return 0;
}