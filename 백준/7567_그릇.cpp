#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
using namespace std;
int calHeight(string bowl) {
    char pre = bowl[0];
    int resultHeight = 10;
    for(int i=1; i<bowl.length(); i++) {
        char next = bowl[i];
        if(pre==next) resultHeight += 5;
        else resultHeight += 10;
        pre = next;
    }
    
    return resultHeight;
}
int main(void) {
    string bowl;
    int answer = 0;
    cin >> bowl;
    
    answer = calHeight(bowl);
    
    cout << answer << endl;
    return 0;
}
