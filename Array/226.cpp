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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        if(root->left)
            invertTree(root->left);
        if(root->right)
            invertTree(root->right);
        swap(root->right,root->left);
        return root;
    }
};