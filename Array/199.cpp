//
// Created by wokaka on 2018/8/13.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == NULL)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
               TreeNode * t = q.front();
               q.pop();

               if(i == n-1)
                   ret.push_back(t->val);
               if(t->left)
                   q.push(t->left);
               if(t->right)
                   q.push(t->right);
            }
        }

        return ret;
    }
};
int main(){

    return 0;
}