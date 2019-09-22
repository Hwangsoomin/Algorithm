#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int k, tree[1500], ans[1500], sum = 1;
queue<pair<int, int>> q;
int n = 1;
void go() {
	q.push({ 1, sum - 1});
	while (!q.empty()) {
		int num1 = q.front().first;
		int num2 = q.front().second;
		int mid = (num1 + num2) / 2;
		q.pop();
		ans[n++] = tree[mid];
		if (num1 <= mid - 1) {
			q.push({ num1,mid - 1 });
		}
		if (mid + 1 <= num2) {
			q.push({ mid + 1,num2 });
		}
	}
}
int main(void) {
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)sum = sum * 2;
	for (int i = 1; i < sum; i++) {
		scanf("%d", &tree[i]);
	}
	go();
	int nn = 2;
	for (int i = 1; i < sum; i++) {
		printf("%d ", ans[i]);
		if (i == nn - 1) {
			printf("\n");
			nn= nn * 2;
		}
	}
	return 0;
}