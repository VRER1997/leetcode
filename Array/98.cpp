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
    bool check(TreeNode *root, long minx, long maxx){
        if(root == NULL)
            return true;
        if(root->val <= minx || root->val >= maxx)
        return false;
        return check(root->left,minx,root->val) && check(root->right,root->val,maxx);
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);
    }
};