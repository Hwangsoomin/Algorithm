#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int year;
int main(void) {
    scanf("%d", &year);
    if((year%4==0&&year%100!=0) || year%400==0)printf("1\n");
    else printf("0\n");
    return 0;
}
