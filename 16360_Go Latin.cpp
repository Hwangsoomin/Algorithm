#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<limits.h>
#include<string>
using namespace std;
int n;
int main(void) {
	scanf("%d", &n);
	while (n--) {
		string str = "", nstr = "";
		cin >> str;
		int End = str.size() - 1;
		nstr = str.substr(0, End);
		if (str[End] == 'n')nstr += "anes";
		else if (str[End] == 'a')nstr += "as";
		else if (str[End] == 'i' || str[End] == 'y')nstr += "ios";
		else if (str[End] == 'l')nstr += "les";
		else if (str[End] == 'o')nstr += "os";
		else if (str[End] == 'r')nstr += "res";
		else if (str[End] == 't')nstr += "tas";
		else if (str[End] == 'u')nstr += "us";
		else if (str[End] == 'v')nstr += "ves";
		else if (str[End] == 'w')nstr += "was";
		else {
			nstr = str.substr(0, str.size());
			nstr += "us";
		}
		if (str[End - 1] == 'n') {
			if (str[End] == 'e') {
				nstr = str.substr(0, End - 1);
				nstr += "anes";
			}
		}
		cout << nstr << endl;
	}
	return 0;
}