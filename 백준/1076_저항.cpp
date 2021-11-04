#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
string str;
int num1;
long long sum;
int main(void) {
	for (int i = 1; i <= 3; i++) {
		cin >> str;
		if (i != 3) {
			if (str == "black")num1 = 0;
			if (str == "brown")num1 = 1;
			if (str == "red")num1 = 2;
			if (str == "orange")num1 = 3;
			if (str == "yellow")num1 = 4;
			if (str == "green")num1 = 5;
			if (str == "blue")num1 = 6;
			if (str == "violet")num1 = 7;
			if (str == "grey")num1 = 8;
			if (str == "white")num1 = 9;
		}
		else {
			if (str == "black")num1 = 1;
			if (str == "brown")num1 = 10;
			if (str == "red")num1 = 100;
			if (str == "orange")num1 = 1000;
			if (str == "yellow")num1 = 10000;
			if (str == "green")num1 = 100000;
			if (str == "blue")num1 = 1000000;
			if (str == "violet")num1 = 10000000;
			if (str == "grey")num1 = 100000000;
			if (str == "white")num1 = 1000000000;
		}
		if (i == 1)sum = sum + (num1 * 10);
		else if (i == 2)sum += num1;
		else sum = sum * num1;
	}
	printf("%lld\n", sum);
	return 0;
}