//
// Created by wokaka on 2018/8/14.
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
    bool isSame(TreeNode *p, TreeNode *q){
        if(p==NULL && q == NULL) return true;
        if(p==NULL && q != NULL) return false;
        if(p!=NULL && q == NULL) return false;

        if(p->val != q->val) return false;
        if(!isSame(p->left,q->right)) return false;
        if(!isSame(p->right,q->left)) return false;
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return isSame(root->left, root->right);
    }
};