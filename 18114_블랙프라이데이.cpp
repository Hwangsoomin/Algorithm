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
int n, c;
int product[5005], sum;
bool flag = false;
int main(void) {
	int a = 0;
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &product[i]);
	}
	sort(product + 1, product + 1 + n);
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (product[mid] == c) {
			flag = true;
			break;
		}
		if (product[mid] < c)l = mid + 1;
		else r = mid - 1;
	}
	if (!flag) {
		int num = 0;
		for (int i = 1; i <= n; i++) {
			if (flag)break;
			for (int j = i + 1; j <= n; j++) {
				a += 1;
				sum = product[i] + product[j];
				if (sum == c) {
					flag = true;
					break;
				}
				if (sum > c)break;
				else num = c - sum;
				l = 1, r = n;
				while (l <= r) {
					int mid = (l + r) / 2;
					if (product[mid] == num) {
						if (mid != i && mid != j)flag = true;
						break;
					}
					if (product[mid] < num)l = mid + 1;
					else r = mid - 1;
				}
			}
		}
	}
	if (flag)printf("1\n");
	else printf("0\n");
	return 0;
}