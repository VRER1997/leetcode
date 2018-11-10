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
    bool isBalanced(TreeNode* root){
        srand(time(NULL));
        int l = rand()%2;
        if(l == 1)
            return isBalanced1(root);
        else
            return isBalanced2(root);
    }

    int getHight(TreeNode * root){
        if(root == NULL) return 0;
        return max(getHight(root->left),getHight(root->right)+1);
    }
    bool isBalanced1(TreeNode* root) {
        if(root == NULL) return true;

        int lh = getHight(root->left);
        int rh = getHight(root->right);
        if(isBalanced1(root->left) && isBalanced1(root->right)){
            if(abs(lh-rh) <= 1)
                return true;
        }
        return false;

    }

    int check(TreeNode* root){
        if(root == NULL)
            return 0;
        int l = 0, r = 0;
        l = check(root->left);
        if(l == -1) return -1;
        r = check(root->right);
        if(r == -1) return -1;

        if(abs(l-r) <= 1)
            return max(l,r)+1;
        else
            return -1;

    }

    bool isBalanced2(TreeNode* root){
        return (check(root) != -1);
    }

};