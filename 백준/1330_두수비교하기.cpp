#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int a, b;
int main(void) {
    scanf("%d%d", &a, &b);
    if(a>b) printf(">\n");
    else if(a<b) printf("<\n");
    else printf("==\n");
    return 0;
}
