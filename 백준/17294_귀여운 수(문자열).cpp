#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#define ll long long
using namespace std;
string str;
bool flag = false;
int main(void) {
	cin >> str;
	if (str.size() <= 2)printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n");
	else {
		int num = str[1] - str[0];
		for (int i = 2; i < str.size(); i++) {
			int nnum = str[i] - str[i - 1];
			if (nnum != num) {
				flag = true;
				break;
			}
		}
		if (!flag)printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n");
		else printf("흥칫뿡!! <(￣ ﹌ ￣)>\n");
	}
	return 0;
}