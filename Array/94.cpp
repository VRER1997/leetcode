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
struct Command{
    string text;
    TreeNode * node;
    Command(string t, TreeNode * n): text(t),node(n) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<Command> s;
        s.push(Command("go",root));
        while(!s.empty()){
            Command c = s.top();
            s.pop();

            if(c.text == "print"){
                ret.push_back(c.node->val);
            }else{
                if(c.node->right){
                    s.push(Command("go", c.node->right));
                }
                if(c.node->left){
                    s.push(Command("go", c.node->left));
                }
                s.push(Command("print",c.node));
            }
        }
        return ret;
    }
};
int main(){

    return 0;
}