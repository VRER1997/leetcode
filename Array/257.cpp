//
// Created by wokaka on 2018/8/15.
//
//给定一个二叉树，返回所有从根节点到叶子节点的路径。
#include<bits/stdc++.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<string> ret;
    void dfs(TreeNode *node, string word){
        if(node == NULL)
            return ;
        if(node->left == NULL && node->right == NULL){
            word += to_string(node->val);
            ret.push_back(word);
        }

        word = word + to_string(node->val) + "->";
        dfs(node->left, word);
        dfs(node->right, word);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string word = "";
        dfs(root, word);

        return ret;
    }
};