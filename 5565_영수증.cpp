#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int sum, bsum;
int main(void) {
	int a;
	scanf("%d", &sum);
	for(int i = 1; i <= 9; i++) {
		scanf("%d", &a);
		bsum += a;
	}
	printf("%d\n", sum - bsum);
	return 0;
}