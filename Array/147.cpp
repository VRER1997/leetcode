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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *fakeNode = new ListNode(0);
        fakeNode->next = head;
        ListNode *p = head->next, *pre = head;
        while(p){
            if(pre->val > p->val){
                ListNode *last = p->next;

                ListNode *l1 = fakeNode, *l2 = fakeNode->next;
                while(l2->val < p->val &&l2 != pre){
                    l1 = l1->next;
                    l2 = l2->next;
                }

                l1->next = p;
                p->next =l2;
                pre->next = last;

                p = pre->next;
            }else{
                pre = p;
                p = p->next;
            }
        }

        return fakeNode->next;
    }
};
int main(){

}