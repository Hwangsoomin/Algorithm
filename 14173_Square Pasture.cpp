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
int minX = 1e9, maxX, minY = 1e9, maxY;
int x, y;
int main(void) {
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 2; j++) {
			scanf("%d%d", &x, &y);
			minX = min(minX, x);
			maxX = max(maxX, x);
			minY = min(minY, y);
			maxY = max(maxY, y);
		}
	}
	int ans = max(maxX - minX, maxY - minY);
	printf("%d\n", ans * ans);
	return 0;
}