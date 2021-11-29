#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include<stack>
#define ll long long
using namespace std;
int rows=6, columns=6;
vector<vector<int>> queries={{2,2,5,4}, {3,3,6,6}, {5,1,6,3}};

int arr[105][105], num;
vector<int> answer;
int rotate(int x, int y, int xx, int yy) {
    int temp = arr[x][y];
    int Min = temp;
    for(int i=x; i<xx; i++) {
        Min = min(Min, arr[i+1][y]);
        arr[i][y] = arr[i+1][y];
    }
    for(int i=y; i<yy; i++) {
        Min = min(Min, arr[xx][i+1]);
        arr[xx][i] = arr[xx][i+1];
    }
    for(int i=xx; i>x; i--) {
        Min = min(Min, arr[i-1][yy]);
        arr[i][yy] = arr[i-1][yy];
    }
    for(int i=yy; i>y; i--) {
        Min = min(Min, arr[x][i-1]);
        arr[x][i] = arr[x][i-1];
    }
    arr[x][y+1] = temp;
    return Min;
}
int main(void) {
    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=columns; j++) {
            arr[i][j]=++num;
        }
    }
    for(int i=0; i<queries.size(); i++) {
        int x=queries[i][0];
        int y=queries[i][1];
        int xx=queries[i][2];
        int yy=queries[i][3];
        answer.push_back(rotate(x,y,xx,yy));
    }
    
    for(int i=0; i<answer.size(); i++) printf("%d\n", answer[i]);
    return 0;
}
