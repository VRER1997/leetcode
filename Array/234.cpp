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
    for(int i = 1; i < n; i++){
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
        p = p->next;
    }
    cout << "NULL" << endl;
    return ;
}

int getLen(ListNode *head){
    ListNode*p = head;
    int cnt = 0;
    while(p){
        cnt++;
        p = p->next;
    }
    return cnt;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode * fast = head, *slow = head;
        int len = getLen(head);
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(len % 2 == 1)slow = slow->next;
        print(slow);
        stack<ListNode*> s;
        while(slow){
            s.push(slow);
            slow = slow->next;
        }
        vector<ListNode*> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        print(head);
        for(int i = 0; i < v.size(); i++){
            cout << v[i]->val << " " << head->val << endl;
            if(v[i]->val != head->val) return false;
            head = head->next;
        }
        return true;
    }
};

int main(){
    int arr[] = {1,1,2};
    cout << Solution().isPalindrome(initList(arr,3)) << endl;
    return 0;
}
