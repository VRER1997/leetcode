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
struct Process{
    string text; // print / go
    TreeNode *p;
    Process(string text, TreeNode *p): text(text), p(p) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == NULL)
            return ret;
        stack<Process> s;
        s.push(Process("go",root));
        while(!s.empty()){
            Process p = s.top();
            s.pop();
            if(p.text == "print"){
                ret.push_back(p.p->val);
            }else{
                if(p.p->right)
                    s.push(Process("go",p.p->right));
                if(p.p->left)
                    s.push(Process("go",p.p->left));
                s.push(Process("print",p.p));
            }
        }
        return ret;
    }
};
int main(){

    return 0;
}