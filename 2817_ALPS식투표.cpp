#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int x, n;
double nx;
vector<pair<double, char>> arr;
int check[30], ans[30];
int main(void) {
	char c;
	int nn, num = 0;
	scanf("%d", &x);
	nx = x * 0.05;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %c%d", &c, &nn);
		if (nn * 1.0 >= nx) {
			arr.push_back({ nn * 1.0,c });
			num++;
		}
	}
	for (int i = 0; i < num; i++) {
		for (int j = 2; j <= 14; j++) {
			int nnn = arr[i].first;
			check[arr[i].second - 'A'] = 1;
			arr.push_back({ (nnn * 1.0 / j),arr[i].second });
		}
	}
	if (arr.size() != 0) {
		sort(arr.begin(), arr.end());
		for (int i = arr.size() - 1; i >= arr.size() - 14; i--) {
			check[arr[i].second - 'A'] = 1;
			ans[arr[i].second - 'A']++;
		}
		for (int i = 0; i < 30; i++) {
			if (check[i] == 1)printf("%c %d\n", i + 'A', ans[i]);
		}
	}
	return 0;
}