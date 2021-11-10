#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
string a, b, newA, newB;
int main(void) {
    cin >> a >> b;
    for(int i=0; i<a.length(); i++) {
        newA += a[2-i];
        newB += b[2-i];
    }
    if(newA<newB)cout << newB << endl;
    else cout<< newA << endl;
    return 0;
}
