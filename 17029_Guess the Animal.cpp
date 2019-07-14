#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
int n, cnt, pre, Max;
vector<string> arr[105];
int check[105][105];
bool flag = false;
int main(void) {
	int a;
	string str = "", str1 = "";
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> str1;
		scanf("%d", &a);
		for (int j = 1; j <= a; j++) {
			cin >> str;
			arr[i].push_back(str);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			cnt = 0;
			for (int k = 0; k < arr[j].size(); k++) {
				str = arr[j][k];
				for (int k1 = 0; k1 < arr[i].size(); k1++) {
					str1 = arr[i][k1];
					if (str == str1)cnt++;
				}
			}//2마리
			Max = max(Max, cnt);
		}
	}
	printf("%d\n", Max + 1);
	return 0;
}