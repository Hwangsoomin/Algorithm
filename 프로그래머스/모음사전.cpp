#include<iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;
string word;

int answer, cnt;
char alpha[5] = { 'A', 'E','I','O','U' };
void go(string str) {
	if (str == word) {
		answer = cnt;
		return;
	}
	if (str.length() == 5)return;

	for (int i = 0; i < 5; i++) {
		string nstr = str + alpha[i];
		cnt += 1;
		go(nstr);
	}
}
int main(void) {
	cin >> word;

	 go("");

	printf("%d\n", answer);
	return 0;
}