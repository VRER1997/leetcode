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
    vector<int> ret;
    void dfs(TreeNode *node, int sum){

        if(node == NULL)
            return;
        if(node->left == NULL && node->right == NULL){
            sum = sum*10 + node->val;
            ret.push_back(sum);
            return;
        }

        dfs(node->left, sum*10+node->val);
        dfs(node->right, sum*10+node->val);

    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = 0;
        dfs(root,sum);
        int result = 0;
        for(int i = 0; i < ret.size(); i++)
            result += ret[i];

        return result;
    }
};