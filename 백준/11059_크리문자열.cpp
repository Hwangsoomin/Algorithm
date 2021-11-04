#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>
#include<unordered_map>
#define ll long long
using namespace std;
string str;
int ans;
unordered_map<string, int> map;
void go(string s) {
	map[s] = 1;
	int size = s.length();
	int l = 0, r = 0;
	for (int i = 0; i < s.length() / 2; i++) {
		l += s[i] - '0';
		r += (s[(s.length() / 2) + i]) - '0';
	}
	if (l == r) ans = max(ans, size);
	else {
		if (map.find(s.substr(0, s.size() - 2)) == map.end())go(s.substr(0, s.size() - 2));
		if (map.find(s.substr(1, s.size() - 2)) == map.end())go(s.substr(1, s.size() - 2));
		if (map.find(s.substr(2, s.size() - 2)) == map.end())go(s.substr(2, s.size() - 2));
	}
	return;
}
int main(void) {
	cin >> str;
	if (str.size() % 2 != 0) {
		go(str.substr(0, str.size() - 1));
		go(str.substr(1, str.size() - 1));
	}
	else go(str);
	printf("%d\n", ans);
	return 0;
}