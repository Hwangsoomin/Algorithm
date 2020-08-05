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
int arr[2][15], check[10], num;
pair<int, int> aarr[10];
int sum, sumOne, ans, numC;
int main(void) {
	int a, b;
	for (int i = 1; i <= 9; i++) {
		scanf("%d%d", &a, &b);
		if (!check[b]) {
			check[b] = 1;
			num += 1;
		}
		if (a == 0)arr[0][b] += 1;
		else {
			arr[1][b] += 1;
			sumOne += 1;
		}
		aarr[i] = { a,b };
	}
	for (int i = 1; i <= 9; i++) {
		if (!check[i])numC = i;
	}
	for (int i = 1; i <= 9; i++) {
		int number = aarr[i].first;
		int here = aarr[i].second;
		if (!number) {
			arr[number][here] -= 1;
			arr[1][here] += 1;
			int numO = 0, hereO = 0;
			for (int j = 1; j <= 9; j++) {
				if (arr[1][j] != 0) {
					numO += 1;
					hereO = j;
				}
			}
			if (numO == 1) {
				if (!arr[number][hereO]) {
					sum += 1;
					ans = hereO;
				}
			}
			arr[number][here] += 1;
			arr[1][here] -= 1;
		}
		else {
			arr[number][here] -= 1;
			arr[0][here] += 1;
			int numO = 0, hereO = 0;
			for (int j = 1; j <= 9; j++) {
				if (arr[1][j] != 0) {
					numO += 1;
					hereO = j;
				}
			}
			if (numO == 1) {
				if (!arr[0][hereO]) {
					sum += 1;
					ans = hereO;
				}
			}
			else if (numO == 0) {
				if (num != 9) {
					sum += (9 - num);
					ans = numC;
				}
			}
			arr[number][here] += 1;
			arr[0][here] -= 1;
		}
	}
	if (sum == 1)printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}