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
int n, ans, check[30];
string str;
bool flag;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> str;
		flag = false;
		memset(check, 0, sizeof(check));
		for (int j = 0; j < str.size(); j++) {
			if (j != 0 && str[j - 1] != str[j] && check[str[j] - 'a']) {
				flag = true;
				break;
			}
			check[str[j] - 'a'] = 1;
		}
		if (!flag)ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}