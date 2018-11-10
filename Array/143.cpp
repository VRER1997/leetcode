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

ListNode* initList(int arr[], int n){
    ListNode *h = new ListNode(arr[0]);
    ListNode *p = h;
    for(int i = 0; i < n; i++){
        ListNode *t = new ListNode(arr[i]);
        p->next = t;
        p = p->next;
    }
    p = NULL;
    return h;
}

void print(ListNode *head){
    ListNode * p = head ;
    while(p){
        cout << p->val << " ";
    }
    cout << "NULL" << endl;
    return ;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *h1 = new ListNode(0);
        ListNode *h2 = new ListNode(0);

        ListNode *p1 = h1, *p2 = h2;
        ListNode *p = head->next;
        bool odd = false;
        while (p){
            if(!odd){
                p1->next = p;
                p1 = p1->next;
            }else{
                p->next = h2->next;
                h2->next = p;
            }

            odd = !odd;
            p = p->next;
        }

        print(h1->next);
        print(h2->next);
    }
};
int main(){
    int arr[] = {1,2,3,4};
    ListNode *head = initList(arr, 4);
    Solution().reorderList(head);
}
