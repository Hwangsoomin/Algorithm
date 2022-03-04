#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> getAnswer(vector<vector<int>>& arr1, vector<vector<int>>& arr2) {
    vector<vector<int>> answer(arr1.size());
    for(int i=0; i<arr1.size(); i++) {
        for(int k=0; k<arr2[1].size(); k++) {
            int num = 0;
            for(int j=0; j<arr1[i].size(); j++) {
                num += arr1[i][j]*arr2[j][k];
            }
            answer[i].push_back(num);
        }
    }
    return answer;
}
int main(void) {
    vector<vector<int>> arr1 = {{1,2,3}, {4,5,6}};
    vector<vector<int>> arr2 = {{1,4}, {2,5}, {3,6}};
    
    vector<vector<int>> answer;
    answer = getAnswer(arr1, arr2);
    
    for(int i=0; i<answer.size(); i++) {
        for(int j=0; j<answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
