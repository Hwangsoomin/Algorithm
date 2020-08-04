#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<string>
#include<cmath>
#include<map>
#define MOD 1000000003
#define ll long long
using namespace std;
map<int, string> Name;
int n, num = 1, Max;
string str;
int arr[1005][25], candidate[25], check[1005];
queue<int> Fir[25];
int main(void) {
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		getline(cin, str);
		Name[i] = str;
	}
	while (cin >> arr[num][1]) {
		Fir[arr[num][1]].push(num);
		candidate[arr[num][1]] += 1;
		Max = max(Max, candidate[arr[num][1]]);
		for (int i = 2; i <= n; i++) {
			scanf("%d", &arr[num][i]);
		}
		num += 1;
	}
	num -= 1;
	double rnum = num / 2.0;
	while (1) {
		bool flag = false;
		vector<int> ans, Minus;
		int Min = 1e9;
		Max = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i])continue;
			Min = min(Min, candidate[i]);
			Max = max(Max, candidate[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (check[i])continue;
			if (Min == candidate[i])Minus.push_back(i);
			if (Max == candidate[i])ans.push_back(i);
		}
		if (Max >= rnum) {
			for (int i = 0; i < ans.size(); i++)cout << Name[ans[i]] << endl;
			break;
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (check[i])continue;
				if (Max != candidate[i]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				for (int i = 0; i < ans.size(); i++)cout << Name[ans[i]] << endl;
				break;
			}
			for (int i = 0; i < Minus.size(); i++) {
				int peo = Minus[i];//최소 후보자
				int here = Fir[peo].front();
				Fir[peo].pop();
				check[peo] = 1;
				int ncan = 0;
				for (int j = 2; j <= n; j++) {
					ncan = arr[here][j];
					if (!check[ncan]) {
						candidate[ncan] += Min;
						break;
					}
				}
			}
		}
	}
	return 0;
}