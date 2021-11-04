#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#include<map>
#define ll long long
using namespace std;
int n, here, ans;
string s1, s2;
map<string, int> m;
vector<int> arr[680];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		int n1, n2;
		string st1 = s1.substr(0, 2);
		if (st1 == s2)continue;
		if (m.find(st1) == m.end()) {
			here += 1;
			m[st1] = here;
			n1 = here;
		}
		else n1 = m[st1];
		if (m.find(s2) == m.end()) {
			here += 1;
			m[s2] = here;
			n2 = here;
		}
		else n2 = m[s2];
		arr[n1].push_back(n2);
	}
	for (int i = 1; i <= here; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			int num = arr[i][j];
			for (int x = 0; x < arr[num].size(); x++) {
				int nnum = arr[num][x];
				if (nnum == i)ans += 1;
			}
		}
	}
	printf("%d\n", ans / 2);
	return 0;
}