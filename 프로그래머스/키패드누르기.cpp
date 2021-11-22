#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
vector<int> numbers;
string hand;
int n;

string answer;
map<int, pair<int, int>> m;
int main(void) {
    for(int i=0; i<12; i++) {
        scanf("%d", &n);
        numbers.push_back(n);
    }
    cin>>hand;
    
    m[1]={1,1}, m[2]={1,2}, m[3]={1,3}, m[4]={2,1}, m[5]={2,2}, m[6]={2,3}, m[7]={3,1}, m[8]={3,2}, m[9]={3, 3}, m[10]={4,1}, m[0]={4,2}, m[12]={4,3};
    int L=10, R=12;
    for(int i=0; i<numbers.size(); i++) {
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){ answer+='L';
            L=numbers[i];
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){ answer+='R';
            R=numbers[i];
        }
        else {
            int distL = abs(m[numbers[i]].first-m[L].first) + abs(m[numbers[i]].second-m[L].second);
            int distR = abs(m[numbers[i]].first-m[R].first) + abs(m[numbers[i]].second-m[R].second);
            if(distL<distR) {
                answer+='L';
                L=numbers[i];
            }
            else if(distL>distR) {
                answer+='R';
                R=numbers[i];
            }
            else {
                if(hand=="left") {
                    answer+='L';
                    L=numbers[i];
                }
                else {
                    answer+='R';
                    R=numbers[i];
                }
            }
        }
    }
    
    cout<<answer<<endl;
    return 0;
}
