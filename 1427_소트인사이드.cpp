#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, arr[15];
int main(void) {
	int a = 1;
	scanf("%d", &n);
	while (n > 0) {
		arr[a] = n % 10;
		n /= 10;
		a++;
	}
	sort(arr + 1, arr + a);
	for (int i = a - 1; i >= 1; i--)printf("%d", arr[i]);
	return 0;
}