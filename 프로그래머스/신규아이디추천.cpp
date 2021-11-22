#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
string new_id;

string answer;
int main(void) {
    cin >> new_id;
    
    for(int i=0; i<new_id.size(); i++) {
        if('A'<=new_id[i] && new_id[i]<='Z') new_id[i] = (new_id[i]-'A')+'a';
    }
    for(int i=0; i<new_id.size(); ) {
        if(('a'<=new_id[i] && new_id[i]<='z') || ('0' <=new_id[i]&&new_id[i]<='9') || new_id[i]=='-' || new_id[i]=='_' || new_id[i]=='.') i+=1;
        else new_id.erase(new_id.begin()+i);
    }
    for(int i=1; i<new_id.size(); ) {
        if(new_id[i]=='.'&&new_id[i-1]=='.') new_id.erase(new_id.begin()+i);
        else i+=1;
    }
    if(new_id[0]=='.') new_id.erase(new_id.begin()+0);
    if(new_id[new_id.length()-1]=='.') new_id.erase(new_id.end()-1);
    if(new_id.length()==0) new_id+='a';
    if(new_id.length()>=16) new_id = new_id.substr(0, 15);
    if(new_id[new_id.length()-1]=='.') new_id.erase(new_id.end()-1);
    if(new_id.length()<=2) {
        while(new_id.length()<3) {
            new_id+=new_id[new_id.length()-1];
        }
    }
    
    cout<<new_id<<endl;
    return 0;
}
