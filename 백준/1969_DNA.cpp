#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int n, m, sum;
int arr[1005][55];
string hc, num[1005];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		string str = "";
		cin >> str;
		for (int j = 0; j < m; j++) arr[j + 1][str[j] - 'A'] += 1;
		num[i] = str;
	}
	for (int i = 1; i <= m; i++) {
		int Max = 0;
		int ans;
		for (int j = 0; j < 26; j++) {
			if (Max < arr[i][j]) {
				Max = arr[i][j];
				ans = j;
			}
		}
		hc += (ans + 'A');
	}
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 0; j < hc.length(); j++) if (num[i][j] != hc[j])ans += 1;
		sum += ans;
	}
	cout << hc << endl;
	printf("%d\n", sum);
	return 0;
}