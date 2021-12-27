#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <deque>
#define ll long long
using namespace std;
vector<string> orders={"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
vector<int> course={2,3,5};

vector<string> answer, nOrders;
map<string, int> courseMap;
int check[15], countMax[15];
vector<string> Course[15];
void makeCorse(int here, string hereOrder, string order, int cnt) {
    if(hereOrder.length()==cnt) {
        if(courseMap.find(hereOrder)!=courseMap.end()) courseMap[hereOrder] = courseMap[hereOrder] + 1;
        else {
            courseMap[hereOrder] = 1;
            Course[cnt].push_back(hereOrder);
        }
        countMax[cnt] = max(countMax[cnt], courseMap[hereOrder]);
        return;
    }
    for(int i=here; i<order.length(); i++) {
        if(!check[i]) {
            check[i] = 1;
            makeCorse(i+1, hereOrder+order[i], order, cnt);
            check[i] = 0;
        }
    }
}
int main(void) {
    for(int i=0; i<orders.size(); i++) {
        string str = orders[i];
        vector<char> arr;
        for(int j=0; j<str.length(); j++) {
            arr.push_back(str[j]);
        }
        sort(arr.begin(), arr.end());
        string o = "";
        for(int j=0; j<arr.size(); j++) {
            o += arr[j];
        }
        nOrders.push_back(o);
    }
    for(int i=0; i<nOrders.size(); i++) {
        string order = nOrders[i];
        for(int j=0; j<course.size(); j++) {
            if(course[j]>order.length()) break;
            makeCorse(0, "", order, course[j]);
        }
    }
    for(int i=0; i<course.size(); i++) {
        int num = course[i];
        for(int j=0; j<Course[num].size(); j++) {
            string c = Course[num][j];
            if(countMax[num]==courseMap[c] && countMax[num]>=2) answer.push_back(c);
        }
    }
    sort(answer.begin(), answer.end());
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
