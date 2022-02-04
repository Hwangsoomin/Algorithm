#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
map<string, int> declarationCount, user;
int checkReport[1001][1001];
vector<int> reportedUser;
void setUserMap(vector<string> id_list) {
    for(int i=0; i<id_list.size(); i++) {
        user[id_list[i]] = i;
    }
}
void setDeclarationCount(vector<string> report) {
    for(int i=0; i<report.size(); i++) {
        vector<string> persons;
        istringstream r(report[i]);
        string person;
        while(getline(r, person, ' ')) persons.push_back(person);
        
        int reportUserNumer = user[persons[0]];
        int reportedUserNumber = user[persons[1]];
        
        if(declarationCount.find(persons[1]) != declarationCount.end()) {
            if(!checkReport[reportUserNumer][reportedUserNumber]) {
                declarationCount[persons[1]] += 1;
            }
        }
        else declarationCount[persons[1]] = 1;
        
        checkReport[reportUserNumer][reportedUserNumber] = 1;
    }
}
void getDeclarationUser(vector<int> answer, vector<string> id_list, int k) {
    for(int i=0; i<id_list.size(); i++) {
        if(declarationCount[id_list[i]] >= k) reportedUser.push_back(i);
    }
}
vector<int> getMailCount(vector<int> answer, vector<string> id_list, int k) {
    for(int i=0; i<reportedUser.size(); i++) {
        for(int j=0; j<id_list.size(); j++) {
            if(checkReport[j][reportedUser[i]]==1) answer[j] += 1;
        }
    }
    
    return answer;
}
int main(void) {
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k=2;
    
    vector<int> answer(id_list.size(), 0);
    setUserMap(id_list);
    setDeclarationCount(report);
    getDeclarationUser(answer, id_list, k);
    answer = getMailCount(answer, id_list, k);
    
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}
