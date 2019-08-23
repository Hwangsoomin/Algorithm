#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int sum, Max, in, out;
int main(void) {
	for (int i = 1; i <= 4; i++) {
		scanf("%d%d", &in, &out);
		int peo = out - in;
		sum += peo;
		Max = max(Max, sum);
	}
	printf("%d\n", Max);
	return 0;
}