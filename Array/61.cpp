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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        ListNode *p = head;
        int len = 0;
        while(p){
            len++;
            p = p->next;
        }
        p->next = head;
        int num = len - (k%len) -1;
        while(num--){
            head = head->next;
        }
        ListNode *tem = head;
        head = head->next;
        tem->next = NULL;

        return head;
    }
};

int main(){

}