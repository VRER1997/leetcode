//
// Created by wokaka on 2018/8/14.
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

    class cmp{
    public:
        bool operator()(const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode h = ListNode(-1);
        ListNode *p = &h;
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(int i = 0; i < n; i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }

        while(!pq.empty()){
            ListNode *t = pq.top();
            pq.pop();
            p->next = t;
            p = p->next;
            if(t->next)
                pq.push(t->next);
        }
        p->next = NULL;
        return h.next;
    }
};
