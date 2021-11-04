#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int answer;

string str, nanswer;
string arr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string arrNum[10] = { "0", "1", "2", "3","4","5","6","7","8","9" };
bool flag = false;
int main(void) {
	cin >> s;

	for (int i = 0; i < s.length();) {
		str = "";
		flag = false;
		for (int j = i; j < s.length(); j++) {
			str += s[j];
			for (int k = 0; k < 10; k++) {
				if (str == arrNum[k]) {
					nanswer += arrNum[k];
					i = j + 1;
					flag = true;
					break;
				}
				else if (str == arr[k]) {
					nanswer += arrNum[k];
					i = j + 1;
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
	}

	int num = 1;
	for (int i = nanswer.length()-1; i >= 0; i--) {
		answer += (nanswer[i] - '0') * num;
		num *= 10;
	}
	printf("%d\n", answer);
	return 0;
}