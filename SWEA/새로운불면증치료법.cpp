#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include<cmath>
#include <queue>
using namespace std;
int checkSheep(int N) {
    int sheepNumber = 0;
    int allNumber = 0;
    int Number = 0;
    for(int i=0; i<10; i++) allNumber += (1<<i);
    while(allNumber!=Number) {
        sheepNumber += 1;
        int sheep = N * sheepNumber;
        while(sheep>0) {
            int number = sheep % 10;
            Number = Number | (1 << number);
            sheep = sheep / 10;
        }
    }
    
    return N * sheepNumber;
}
int main(void) {
    int test_case;
    int T, N;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        int answer = checkSheep(N);
        cout << '#' << test_case << ' ' << answer << endl;
    }
    return 0;
}
