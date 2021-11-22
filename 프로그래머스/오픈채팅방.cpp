#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
vector<string> record;
string str;

vector<pair<string, string>> arr;
map<string, string> m;
vector<string> answer;
int main(void) {
    for(int i=0; i<5; i++) {
        getline(cin, str);
        record.push_back(str);
    }
    
    for(int i=0; i<record.size(); i++) {
        if(record[i][0]=='E') {
            string id = "";
            string name = "";
            bool flag = false;
            for(int j=6; j<record[i].length(); j++) {
                if(record[i][j]==' ') {
                    flag = true;
                    continue;
                }
                if(!flag) id += record[i][j];
                else name += record[i][j];
            }
            m[id] = name;
            arr.push_back({"E", id});
        }
        else if(record[i][0]=='L') {
            string id = "";
            for(int j=6; j<record[i].length(); j++) id += record[i][j];
            arr.push_back({"L", id});
        }
        else {
            string id = "";
            string name = "";
            bool flag = false;
            for(int j=7; j<record[i].length(); j++) {
                if(record[i][j]==' ') {
                    flag = true;
                    continue;
                }
                if(!flag) id += record[i][j];
                else name += record[i][j];
            }
            m[id] = name;
        }
    }
    
    for(int i=0; i<arr.size(); i++) {
        string p = arr[i].first;
        string id = arr[i].second;
        if(p=="E") answer.push_back(m[id]+"님이 들어왔습니다.");
        else if(p=="L") answer.push_back(m[id]+"님이 나갔습니다.");
    }
    
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] <<endl;
    }
    return 0;
}
