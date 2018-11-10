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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = 0, rh = 0;
        TreeNode *r1 = root, *r2 = root;
        while(r1){
            lh++;
            r1 = r1->left;
        }
        while(r2){
            rh++;
            r2 = r2->right;
        }
        if(lh == rh){
            return pow(2,lh) - 1;
        }
        else
            return countNodes(root->left) + countNodes(root->right) + 1;
    }
};