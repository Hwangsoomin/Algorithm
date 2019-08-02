#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
string name;
int sum, n;
int sc[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };
int main(void) {
	scanf("%d", &n);
	cin >> name;
	for (int i = 0; i < name.size(); i++) {
		char nn = name[i];
		sum += sc[nn - 'A'];
	}
	printf("%d\n", sum);
	return 0;
}