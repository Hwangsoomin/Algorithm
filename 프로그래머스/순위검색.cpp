#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <deque>
using namespace std;
vector<string> info={"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
vector<string> query={"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

vector<int> arr[4][3][3][3];
vector<int> answer;
int il, ir, jl, jr, kl, kr, ll, lr;
vector<int> split(string str) {
    string temp = "";
    int num = 0;
    vector<int> v;
    for(int i=0; i<str.length(); i++) {
        if(str[i]==' ') {
            if(temp=="cpp" || temp=="backend" || temp=="junior" || temp=="chicken") num = 1;
            else if(temp=="python") num = 3;
            else num = 2;
            v.push_back(num);
            temp = "";
        }
        else temp += str[i];
    }
    int point = stoi(temp);
    v.push_back(point);
    return v;
}
int main(void) {
    for(int i=0; i<info.size(); i++) {
        string str = info[i];
        vector<int> v = split(str);
        arr[v[0]][v[1]][v[2]][v[3]].push_back(v[4]);
    }
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=2; j++) {
            for(int k=1; k<=2; k++) {
                for(int l=1; l<=2; l++) {
                    sort(arr[i][j][k][l].begin(), arr[i][j][k][l].end());
                }
            }
        }
    }
    for(int a=0; a<query.size(); a++) {
        string q = query[a];
        int cnt = 1;
        string temp = "";
        for(int j=0; j<q.length(); j++) {
            if(temp=="and") {
                temp = "";
                continue;
            }
            if(q[j]==' ') {
                if(cnt==1) {
                    if(temp=="c++") il = ir = 1;
                    else if(temp=="java") il = ir = 2;
                    else if(temp=="python") il = ir = 3;
                    else { il = 1; ir = 3; }
                }
                else if(cnt==2) {
                    if(temp=="backend") jl = jr = 1;
                    else if(temp=="frontend")jl = jr = 2;
                    else { jl = 1; jr = 2; }
                }
                else if(cnt==3) {
                    if(temp=="junior") kl = kr = 1;
                    else if(temp=="senior") kl = kr = 2;
                    else { kl = 1; kr = 2; }
                }
                else if(cnt==4){
                    if(temp=="chicken") ll = lr = 1;
                    else if(temp=="pizza") ll = lr = 2;
                    else { ll = 1; lr = 2;}
                }
                temp = "";
                cnt += 1;
            }
            else temp += q[j];
        }
        int num = stoi(temp);
        int sum = 0;
        vector<int>::iterator n;
        for(int i=il; i<=ir; i++) {
            for(int j=jl; j<=jr; j++) {
                for(int k=kl; k<=kr; k++) {
                    for(int l=ll; l<=lr; l++) {
                        int n = arr[i][j][k][l].size();
                        if(!n) continue;
                        auto iter = lower_bound(arr[i][j][k][l].begin(), arr[i][j][k][l].end(), num);
                        
                        if(iter==arr[i][j][k][l].end()) continue;
                        sum += n - (iter - arr[i][j][k][l].begin());
                    }
                }
            }
        }
        answer.push_back(sum);
    }
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
