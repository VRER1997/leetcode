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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode * h = new ListNode(0);
        ListNode *p = h, * p1 = h->next, *p2 = h->next;
        while(p2){
            while(p2->next && p1->val == p2->next->val){
                p2 = p2->next;
            }
            if(!p2->next) break;
            if(p1 == p2){
                p->next = p1;
                p = p->next;
            }
            p1 = p2->next;
            p2 = p2->next;
        }

        if(p1 == p2 && prev != NULL){
            p->next = p1;
        }
        p->next = NULL;

        return h->next;

    }
};
int main(){

    return 0;
}