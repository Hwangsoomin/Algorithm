#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
string st1, st2, st3;
int num1, num2;
int main(void) {
	cin >> st1 >> st2 >> st3;
	if (st1 == "true")num1 = 1;
	else if (st1 == "false")num1 = 0;
	if (st3 == "true")num2 = 1;
	else if (st3 == "false")num2 = 0;
	if (st2 == "AND") {
		if (num1 + num2 == 2)printf("true\n");
		else printf("false\n");
	}
	else if (st2 == "OR") {
		if (num1 + num2 == 0)printf("false\n");
		else printf("true\n");
	}
	return 0;
}