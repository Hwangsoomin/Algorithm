#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int sum;
int mon;
int arr[7] = { 500,100,50,10,5,1 };
int main(void) {
	scanf("%d", &mon);
	mon = 1000 - mon;
	for (int i = 0; i < 6; i++) {
		sum += (mon / arr[i]);
		mon = mon % arr[i];
	}
	printf("%d\n", sum);
	return 0;
}