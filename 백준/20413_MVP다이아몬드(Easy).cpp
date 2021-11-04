#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>
#include<unordered_map>
#define ll long long
using namespace std;
int n, a, sum, pre;
int arr[5];
string str;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &a);
		arr[i] = a - 1;
	}
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'B') {
			sum += (arr[1] - pre);
			pre = arr[1] - pre;
		}
		else if (str[i] == 'S') {
			sum += (arr[2] - pre);
			pre = arr[2] - pre;
		}
		else if (str[i] == 'G') {
			sum += (arr[3] - pre);
			pre = arr[3] - pre;
		}
		else if (str[i] == 'P') {
			sum += (arr[4] - pre);
			pre = arr[4] - pre;
		}
		else {
			sum += arr[4] + 1;
			pre = arr[4] + 1;
		}
	}
	printf("%d\n", sum);
	return 0;
}