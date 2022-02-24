#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int checkTime(pair<int, int> inTime, pair<int, int> outTime) {
    pair<int, int> t;
    if(outTime.second<inTime.second) {
        outTime.second = outTime.second + 60;
        outTime.first -= 1;
    }
    
    t.second = outTime.second - inTime.second;
    t.first = outTime.first - inTime.first;
    
    int allTime = (t.first*60) + t.second;
    return allTime;
}
int getAllTime(vector<int> carAllTime) {
    int allTime = 0;
    for(int i=0; i<carAllTime.size(); i++) {
        allTime += carAllTime[i];
    }
    
    return allTime;
}
int main(void){
    vector<int> fees={180, 5000, 10, 600};
    vector<string> records={"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    int carCnt = 0;
    pair<int, int> carTime[1005];
    vector<int> carAllTime[1005];
    vector<string> car;
    vector<int> answer;
    map<string, int> carMap;
    int checkCarOut[1005] = {0, };
    
    for(int i=0; i<records.size(); i++) {
        string carNumber = records[i].substr(6, 4);
        if(carMap.find(carNumber)==carMap.end()) {
            carMap[carNumber] = ++carCnt;
            car.push_back(carNumber);
        }
        string hourStr = records[i].substr(0,2);
        string minuteStr = records[i].substr(3,2);
        pair<int, int> time = {stoi(hourStr), stoi(minuteStr)};
        
        if(records[i][11]=='I') {
            carTime[carMap[carNumber]] = time;
            checkCarOut[carMap[carNumber]] = 0;
        }
        else {
            pair<int, int> inTime = carTime[carMap[carNumber]];
            int allTime = checkTime(inTime, time);
            carAllTime[carMap[carNumber]].push_back(allTime);
            checkCarOut[carMap[carNumber]] = 1;
        }
    }
    for(int i=1; i<=carCnt; i++) {
        if(checkCarOut[i]==0) {
            int allTime = checkTime(carTime[i], {23, 59});
            carAllTime[i].push_back(allTime);
        }
    }
    sort(car.begin(), car.end());
    for(int i=0; i<car.size(); i++) {
        int carNum = carMap[car[i]];
        int allTime = getAllTime(carAllTime[carNum]);
        int ans = fees[1];
        if(allTime>fees[0]){
            ans += ceil((allTime-fees[0])/(fees[2]*1.0))*fees[3];
        }
        answer.push_back(ans);
    }
    
    for(int i=0; i<answer.size(); i++) cout << answer[i] << endl;
    return 0;
}
