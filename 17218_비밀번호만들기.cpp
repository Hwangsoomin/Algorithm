#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#define MOD 100999
#define ll long long
using namespace std;
string str1, str2;
pair<int, string> dp[45][45];
int main(void) {
	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) dp[i + 1][j + 1] = { dp[i][j].first + 1,dp[i][j].second + "" + str1[i] };
			else {
				if (dp[i + 1][j].first < dp[i][j + 1].first)dp[i + 1][j + 1] = { dp[i][j + 1].first,dp[i][j + 1].second };
				else dp[i + 1][j + 1] = { dp[i + 1][j].first, dp[i + 1][j].second };
			}
		}
	}
	cout << dp[str1.size()][str2.size()].second << endl;
	return 0;
}