#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int check[10005];
vector<int> answer;
int main(void) {
    for(int i=1; i<=10000; i++){
        int num = i;
        if(!check[i]) {
            check[i] = 1;
            answer.push_back(i);
        }
        while(num<=10000) {
            int pre = num;
            int sum = 0;
            while(pre>0) {
                sum += (pre%10);
                pre /= 10;
            }
            num += sum;
            if(check[num])break;
            check[num] = 1;
        }
    }
    for(int i=0; i<answer.size(); i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}
