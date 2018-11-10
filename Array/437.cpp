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
    int dfs(TreeNode *node, int sum){
        int ret = 0;
        if(node == NULL)
            return ret;

        if(sum == node->val)
            ret++;
        ret += dfs(node->left, sum-node->val);
        ret += dfs(node->right, sum-node->val);

        return ret;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;

        return dfs(root,sum) + pathSum(root->left, sum)
                + pathSum(root->right, sum);

    }
};