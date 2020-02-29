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
int ans;
int main(void) {
	cin >> str;
	for (int i = 0; i < str.size();) {
		int flag = 0;
		if (str[i] == 'c' && str[i + 1] == '=') flag = 2;
		else if (str[i] == 'c' && str[i + 1] == '-') flag = 2;
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') flag = 3;
		else if (str[i] == 'd' && str[i + 1] == '-') flag = 2;
		else if (str[i] == 'l' && str[i + 1] == 'j') flag = 2;
		else if (str[i] == 'n' && str[i + 1] == 'j') flag = 2;
		else if (str[i] == 's' && str[i + 1] == '=') flag = 2;
		else if (str[i] == 'z' && str[i + 1] == '=') flag = 2;
		else flag = 1;
		ans += 1;
		i += flag;
	}
	printf("%d\n", ans);
	return 0;
}