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
    vector<vector<int>> ret;
    void dfs(TreeNode* root, int sum, vector<int> path){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            if(sum-root->val == 0){
                path.push_back(root->val);
                ret.push_back(path);
            }
        }

        path.push_back(root->val);
        dfs(root->left, sum-root->val, path);
        dfs(root->right, sum-root->val, path);

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return ret;
        vector<int> path;
        dfs(root, sum, path);
        return ret;
    }
};