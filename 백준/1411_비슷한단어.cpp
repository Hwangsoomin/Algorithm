#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#define ll long long
using namespace std;
int n, ans, sum, sum1, check[35];
char ch[35];
string str[105];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)cin >> str[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			memset(ch, NULL, sizeof(ch));
			memset(check, 0, sizeof(check));
			sum = 0;
			if (str[i].size() != str[j].size())continue;
			for (int k = 0; k < str[i].size(); k++) {
				int n1 = str[i][k] - 'a';
				char n2 = str[j][k];
				if (ch[n1] == NULL && !check[n2-'a']) {
					ch[n1] = n2;
					check[n2 - 'a'] = 1;
					sum += 1;
				}
				else if (ch[n1] != n2)break;
				else sum += 1;
			}
			if (sum == str[i].size())ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}