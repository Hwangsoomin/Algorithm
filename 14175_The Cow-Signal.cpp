#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<cstring>
#include<vector>
#include<queue> 
#include<cmath>
#define ll long long
using namespace std;
int n, m, k;
char arr[15][15], a;
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		string str = "";
		for (int j = 1; j <= m; j++) {
			for (int r = 1; r <= k; r++) {
				str += arr[i][j];
			}
		}
		for (int c = 1; c <= k; c++)cout << str << endl;
	}
	return 0;
}