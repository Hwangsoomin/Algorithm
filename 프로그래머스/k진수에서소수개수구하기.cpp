#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int checkPrimeNumber(long long number) {
    if(number < 2) return 0;
    
    for(long long i=2; i<=sqrt(number); i++) {
        if(number%i == 0) return 0;
    }
    
    return 1;
}
string makeNotation(int n, int k) {
    string nString = "";
    while(n>0) {
        int hereNumber = n%k;
        nString = char(hereNumber+'0') + nString;
        n /= k;
    }
    
    return nString;
}
vector<long long> getNumberWithoutZero(string nString) {
    vector<long long> numbers;
    long long number = 0;
    for(int i=0; i<nString.length(); i++) {
        int here = nString[i]-'0';
        if(here==0) {
            if(number > 1) {
                numbers.push_back(number);
            }
            number = 0;
        }
        else number = (number*10) + here;
    }
    if(number!=0) numbers.push_back(number);
    
    return numbers;
}
int checkPrimeNumberInNumbers(vector<long long> numbers) {
    int answer = 0;
    for(int i=0; i<numbers.size(); i++) {
        answer += checkPrimeNumber(numbers[i]);
    }
    
    return answer;
}
int main(void){
    int n=437674, k=3;
    vector<long long> numbers;
    string nString = "";
    int answer = 0;
    
    nString = makeNotation(n, k);
    numbers = getNumberWithoutZero(nString);
    answer = checkPrimeNumberInNumbers(numbers);
    
    cout << answer << endl;
    return 0;
}
