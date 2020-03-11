#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define ll long long
using namespace std;
int J, A, b, ans;
int check[1000005];
char a, js[1000005];
vector<pair<int, char>> arr;
int main(void) {
	scanf("%d%d", &J, &A);
	for (int i = 1; i <= J; i++) {
		scanf(" %c", &js[i]);
	}
	for (int i = 1; i <= A; i++) {
		scanf(" %c%d", &a, &b);
		arr.push_back({ b,a });
	}
	for (int i = 0; i < A; i++) {
		int num = arr[i].first;
		char si = arr[i].second;
		if (si == 'M') {
			if (js[num] == 'S')continue;
		}
		if (si == 'L') {
			if (js[num] == 'S' || js[num] == 'M')continue;
		}
		if (!check[num]) {
			check[num] = 1;
			ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}