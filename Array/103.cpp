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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> levelNode;
        if(root == NULL)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        int cnt = -1;
        while (!q.empty()){
            cnt++;
            int n = q.size();
            TreeNode *tem;
            while(n--){
                tem = q.front();
                q.pop();

                levelNode.push_back(tem->val);
                if(tem->left)
                    q.push(tem->left);
                if(tem->right)
                    q.push(tem->right);
            }
            if(cnt % 2 == 1)
                reverse(levelNode.begin(),levelNode.end());

            ret.push_back(levelNode);
            levelNode.clear();
        }

        return ret;
    }
};
int main(){

    return 0;
}