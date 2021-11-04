#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
int N;
int n1, n2;
int sm = 1e9;
int main(void) {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		int num = i;
		while (num % 5 == 0) {
			n1++;
			num = num / 5;
		}
		while (num % 2 == 0) {
			n2++;
			num = num / 2;
		}
	}
	sm = min(n1, n2);
	printf("%d\n", sm);
	return 0;
}