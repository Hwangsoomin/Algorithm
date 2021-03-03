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
int n;
int arr[30], arr1[30], ans[30];
string str, str1;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		memset(arr, 0, sizeof(arr));
		memset(arr1, 0, sizeof(arr1));
		cin >> str >> str1;
		for (int k = 0; k < str.size(); k++) {
			int here = str[k] - 'a';
			arr[here] += 1;
		}
		for (int k = 0; k < str1.size(); k++) {
			int here = str1[k] - 'a';
			arr1[here] += 1;
		}
		for (int k = 0; k < 26; k++) {
			ans[k] += max(arr[k], arr1[k]);
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}