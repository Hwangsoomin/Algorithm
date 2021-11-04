#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int t, num;
long long k[70];
int main(void) {
	k[0] = 1, k[1] = 1, k[2] = 2, k[3] = 4;
	scanf("%d", &t);
	for (int i = 4; i <= 67; i++)k[i] = k[i - 1] + k[i - 2] + k[i - 3] + k[i - 4];
	while (t--) {
		scanf("%d", &num);
		printf("%lld\n",k[num]);
	}
	return 0;
}