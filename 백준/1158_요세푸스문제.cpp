#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_NODE 5005
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node node[MAX_NODE];
Node* head;
int nodeCnt;

Node* getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init() {
    nodeCnt = 0;
    head = getNode(0);
}

void addNodeTail(int data) {
    Node* cur = getNode(data);
    Node* here = head;
    if(head->next==nullptr) {
        head->next = cur;
        return;
    }
    
    while(here->next!=nullptr) {
        here = here->next;
    }
    here->next = cur;
}

void makeNode(int N) {
    for(int i=1; i<=N; i++) {
        addNodeTail(i);
    }
}

void removeNode(int data) {
    Node* here = head;
    Node* pre = head;
    bool flag = false;
    while(here->next!=nullptr) {
        if(here->data==data) {
            if(head->next==here) head->next = here->next;
            pre->next = here->next;
            flag = true;
            break;
        }
        pre = here;
        here = here->next;
    }
    if(!flag) pre->next = nullptr;
}

vector<int> getAnswer(int N, int K) {
    vector<int> answer;
    Node* here = head;
    int cnt = 0;
    int hereCnt = 0;
    while(cnt<N) {
        if(head->next==nullptr) {
            answer.push_back(here->data);
            break;
        }
        if(hereCnt==K) {
            answer.push_back(here->data);
            removeNode(here->data);
            hereCnt = 0;
            cnt += 1;
        }
        else {
            if(here->next==nullptr) {
                here = head->next;
            }
            else here = here->next;
            hereCnt += 1;
        }
    }
    
    return answer;
    
}
int main(void) {
    int N, K;
    scanf("%d%d", &N, &K);
    
    init();
    makeNode(N);
    vector<int> answer = getAnswer(N, K);
    
    printf("<");
    for(int i=0; i<answer.size(); i++) {
        if(i==answer.size()-1) printf("%d", answer[i]);
        else printf("%d, ", answer[i]);
    }
    printf(">\n");
    return 0;
}
