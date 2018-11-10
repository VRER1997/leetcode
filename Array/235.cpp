//
// Created by wokaka on 2018/8/15.
//
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            swap(p,q);
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;
        if(root->val > p->val && root->val < q->val) return root;

        if(root->val > q->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        if(root->val < q->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
    }
};