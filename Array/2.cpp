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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h = new ListNode(0);
        ListNode *l = h;
        ListNode *p1 = l1, *p2 = l2;
        int digit = 0;
        while(p1&&p2){
            int f = p1->val + p2->val + digit;
            if(f >= 10) digit = 1;
            else digit = 0;
            ListNode * tem = new ListNode(f%10);
            l->next = tem;
            p1 = p1->next;
            p2 = p2->next;
            l = l->next;
        }
        if(p1){
            while(p1){
                int f = p1->val + digit;
                if(f >= 10) digit = 1;
                else digit = 0;
                ListNode * tem = new ListNode(f%10);
                l->next = tem;
                p1 = p1->next;
                l = l->next;
            }
        }
        if(p2){
            while(p2){
                int f = p2->val + digit;
                if(f >= 10) digit = 1;
                else digit = 0;
                ListNode * tem = new ListNode(f%10);
                l->next = tem;
                p2 = p2->next;
                l = l->next;
            }
        }
        if(digit){
            ListNode * tem = new ListNode(1);
            l->next = tem;
            tem->next = NULL;
        }
        return h->next;
    }
};
int main(){

    return 0;
}
