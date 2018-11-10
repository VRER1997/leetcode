//
// Created by wokaka on 2018/8/11.
//
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* init(int arr[], int n){
    ListNode* head = new ListNode(arr[0]);
    ListNode* p = head;
    for(int i = 1; i < n; i++){
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    p->next = NULL;
    return head;
}

void print(ListNode *head){
    ListNode *p = head;
    while(p){
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << " NULL " << endl;
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *ret1 = head;
        ListNode *h2 = head->next;
        ListNode *ret2 = head->next;
        ListNode *p = NULL;
        if(ret2->next) p = ret2->next;

        bool odd = 1;
        while(p){
            if(odd){
                ret1->next = p;
                ret1 = ret1->next;
                odd = 0;
            }else{
                ret2->next = p;
                ret2 = ret2->next;
                odd = 1;
            }
            p = p->next;
        }
        ret1->next = h2;
        ret2->next = NULL;
        return head;


    }
};
int main(){
    int arr[] = {1,2,3,4,5};
    ListNode *head = init(arr, 5);
    print(Solution().oddEvenList(head));
    return 0;
}
