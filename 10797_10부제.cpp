#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int day, sum;
int car[6];
int main(void) {
	scanf("%d", &day);
	day = day % 10;
	for (int i = 1; i <= 5; i++)scanf("%d", &car[i]);
	for (int i = 1; i <= 5; i++) if (car[i] == day)sum++;
	printf("%d\n", sum);
	return 0;
}