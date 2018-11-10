//
// Created by wokaka on 2018/8/21.
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
    TreeNode* generateTree(vector<int> &nums, int l, int r){
        if(l > r)
            return NULL;
        TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
        int mid = (l+r)/2;
        root->val = nums[mid];

        root->left = generateTree(nums, l, mid-1);
        root->right = generateTree(nums, mid+1, r);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return generateTree(nums,0,n-1);
    }
};