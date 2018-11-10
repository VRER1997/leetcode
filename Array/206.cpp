//
// Created by wokaka on 2018/8/12.
//
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *virtualHead = new ListNode(0);
        ListNode *p = head;
        while(p){
            ListNode * tem = p->next;
            p->next = virtualHead->next;
            virtualHead->next = p;
            p = tem;
        }

        return virtualHead->next;

    }
};
int main(){

    return 0;
}

