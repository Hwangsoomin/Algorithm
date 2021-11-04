#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int maxAns, minAns = 1e10;
string str;
int cal(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] - '0') % 2 != 0)cnt += 1;
	}
	return cnt;
}
void go(string s, int cnt) {
	if (s.size() >= 3) {
		for (int i = 1; i < s.size(); i++) {
			for (int j = i + 1; j < s.size(); j++) {
				int fNum = stoi(s.substr(0, i));
				int sNum = stoi(s.substr(i, j - i));
				int tNum = stoi(s.substr(j));
				string ns = to_string(fNum + sNum + tNum);
				go(ns, cnt + cal(ns));
			}
		}
	}
	else if (s.size() >= 2) {
		int fNum = stoi(s.substr(0, 1));
		int sNum = stoi(s.substr(1, 1));
		string ns = to_string(fNum + sNum);
		go(ns, cnt + cal(ns));
	}
	else if(s.size() == 1) {
		minAns = min(minAns, cnt);
		maxAns = max(maxAns, cnt);
		return;
	}
}
int main(void) {
	cin >> str;
	int cnt = cal(str);
	go(str, cnt);
	cout << minAns << " " << maxAns << endl;
	return 0;
}