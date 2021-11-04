#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
string str, ans, ans1;
int num[30], Min = 1e9;
int main(void) {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		int n = str[i] - 'A';
		num[n] += 1;
	}
	for (int i = 0; i < 30; i++) {
		if ((num[i] / 2) >= 1) {
			int nn = num[i];
			for (int j = 1; j <= nn / 2; j++) {
				ans += (i + 'A');
				num[i] = num[i] - 2;
			}
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)ans1 += ans[i];
	for (int i = 0; i < 30; i++) {
		if (num[i] >= 1) {
			ans += (i + 'A');
			break;
		}
	}
	if (ans.size() != 0 && ans.size() + ans1.size() == str.size()) cout << ans << ans1 << endl;
	else printf("I'm Sorry Hansoo\n");
	return 0;
}