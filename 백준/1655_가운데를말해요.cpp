#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n;
priority_queue<int> Max, Min;
int main(void) {
	int x, num1, num2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		Max.push(x);
		if (Max.size() > Min.size() + 1) {
			num1 = Max.top();
			Max.pop();
			Min.push(-num1);
		}
		if (!Min.empty()) {
			num1 = Max.top();
			num2 = -Min.top();
			if (num1 > num2) {
				Max.pop();
				Min.pop();
				Max.push(num2);
				Min.push(-num1);
			}
		}
		printf("%d\n", Max.top());
	}
	return 0;
}