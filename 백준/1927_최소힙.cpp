#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n;
priority_queue<int> pq;
int main(void) {
	int x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			if (pq.empty())printf("0\n");
			else {
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
		else pq.push(-x);
	}
	return 0;
}