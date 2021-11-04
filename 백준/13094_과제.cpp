#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
using namespace std;
int n, d, w, sum, Min, here;
pair<int,int> arr[1005];
int check[1005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &d, &w);
		arr[i] = { d,w };
	}
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++) {
		int num = arr[i].first;
		int cost = arr[i].second;
		bool flag = false;
		if (!check[num]) {
			check[num] = cost;
			sum += cost;
		}
		else {
			Min = cost;
			for (int j = 1; j <= num; j++) {
				if (check[j] < Min && check[j] < cost) {
					Min = check[j];
					here = j;
					flag = true;
				}
			}
			if (flag) {
				sum -= check[here];
				check[here] = cost;
				sum += cost;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}