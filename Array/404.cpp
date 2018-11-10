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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ret = 0;
        if(root->left && root->left->left == NULL && root->left->right == NULL)
            ret += root->left->val;
        ret += sumOfLeftLeaves(root->left);
        ret += sumOfLeftLeaves(root->right);

        return ret;
    }
};