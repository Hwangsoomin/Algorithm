#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
void makeNameTable(map<string, int>& nameTable, vector<string>& enroll) {
    int cnt = 0;
    for(int i=0; i<enroll.size(); i++) {
        string name = enroll[i];
        nameTable[name] = ++cnt;
    }
}
void makeOrganizationChart(map<string, int>& nameTable, vector<string>& enroll, vector<string>& referral, vector<int> organizationChart[]) {
    for(int i=0; i<referral.size(); i++) {
        int parent = nameTable[referral[i]];
        int child = nameTable[enroll[i]];
        organizationChart[child].push_back(parent);
    }
}
void calculateAmount(map<string, int>& nameTable, vector<string>& seller, vector<int>& amount, vector<int> organizationChart[], int money[]) {
    for(int i=0; i<seller.size(); i++) {
        int hereName = nameTable[seller[i]];
        int hereAmount = amount[i]*100;
        
        while(hereAmount>0) {
            int hereMoney = hereAmount;
            if(hereMoney>=10) hereMoney = hereAmount - int(hereAmount*0.1);
            hereAmount *= 0.1;
            money[hereName] += hereMoney;
            if(organizationChart[hereName].size()==0) break;
            hereName = organizationChart[hereName][0];
        }
    }
}
void getAnswer(map<string, int>& nameTable, vector<string>& enroll, int money[], vector<int>& answer) {
    for(int i=0; i<enroll.size(); i++) {
        int name = nameTable[enroll[i]];
        answer.push_back(money[name]);
    }
}
int main(void) {
    vector<string> enroll = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> referral = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> seller = {"young", "john", "tod", "emily", "mary"};
    vector<int> amount = {12, 4, 2, 5, 10};
    
    map<string, int> nameTable;
    vector<int> organizationChart[10001];
    int money[10001] = {0,};
    vector<int> answer;
    makeNameTable(nameTable, enroll);
    makeOrganizationChart(nameTable, enroll, referral, organizationChart);
    calculateAmount(nameTable, seller, amount, organizationChart, money);
    getAnswer(nameTable, enroll, money, answer);
    
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return 0;
}
