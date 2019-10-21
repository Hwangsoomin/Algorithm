#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int arr[15], check[15];
int go(int here, int cnt, int sum) {
	if (cnt == 7 && sum == 100) {
		for (int i = 1; i <= 9; i++) if (check[i])printf("%d\n", arr[i]);
		return 1;
	}
	if (cnt > 7 || sum > 100)return 0;
	for (int i = here + 1; i <= 9; i++) {
		if (!check[i]) {
			check[i] = 1;
			if (go(i, cnt + 1, sum + arr[i])) return 1;
			check[i] = 0;
		}
	}
	return 0;
}
int main(void) {
	for (int i = 1; i <= 9; i++) scanf("%d", &arr[i]);
	sort(arr + 1, arr + 10);
	go(0, 0, 0);
	return 0;
}