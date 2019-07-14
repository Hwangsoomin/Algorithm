#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
int A, B, sum, num, pre, i = 1;
int arr[1005];
bool flag = false;
int main(void) {
	scanf("%d%d", &A, &B);
	pre = 1, num = 1;
	for (int i = 1; i <= 1005; i++)arr[i] = i;
	while(1) {
		num += arr[i];
		if (pre <= B) {
			for (int j = pre; j < num; j++) {
				if (j >= A && j <= B) {
					sum += i;
					if (j == B) {
						flag = true;
						break;
					}
				}
			}
		}
		if (flag)break;
		pre = num;
		i++;
	}
	printf("%d\n", sum);
	return 0;
}